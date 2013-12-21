/* Math using the standard library, if the precision is less than 13 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "yacasprivate.h"
#include "yacasbase.h"
#include "lispobject.h"
#include "lispatom.h"
#include "lispenvironment.h"
#include "numbers.h"
#include "platmath.h"
#include "errors.h"

#include <bitset>
#include <iostream>

double GetDouble(LispObject* aInteger)
{
  BigNumber* number = aInteger->Number(0);
  if (!number)
  {
    RaiseError("Argument is not a number: %s",aInteger->String());
  }
  return number->Double();
}

LispObject* Double(LispEnvironment& aEnvironment,double aValue)
{
  char buf[150];
#ifdef HAVE_VSNPRINTF
    snprintf(buf,150,"%g",aValue);
#else
    sprintf(buf,"%g",aValue);
#endif
  return LispAtom::New(aEnvironment,buf);
}


LispObject* PlatArcSin(LispEnvironment& aEnvironment,LispObject* int1, LispInt aPrecision)
{
  return Double(aEnvironment, asin(GetDouble(int1)));
}

LispObject* PlatLn(LispEnvironment& aEnvironment,LispObject* int1, LispInt aPrecision)
{
  return Double(aEnvironment, log(GetDouble(int1)));
}

LispObject* PlatPower(LispEnvironment& aEnvironment,LispObject* int1, LispObject* int2, LispInt aPrecision)
{
  return Double(aEnvironment, pow(GetDouble(int1),GetDouble(int2)));
}

LispObject* PlatDiv(LispEnvironment& aEnvironment,LispObject* int1, LispObject* int2,LispInt aPrecision)
{
  return Double(aEnvironment,((long)GetDouble(int1))/((long)GetDouble(int2)));
}

namespace {
    static const std::size_t MAX_SMALL_PRIME = 65537;

    static std::bitset<MAX_SMALL_PRIME / 2 + 1> _primes_table;

    static class InitPrimesTable {
    public:
        InitPrimesTable();
    } _init_primes_table;

    InitPrimesTable::InitPrimesTable()
    {
        for (std::size_t i = 3; i < MAX_SMALL_PRIME; i += 2) {
            if (_primes_table.test(i / 2))
                continue;
            for (std::size_t j = 3; j < MAX_SMALL_PRIME / i; j += 2)
                _primes_table.set((i * j) / 2);
        }
    }
}

unsigned primes_table_check(unsigned long p)
{
    if (p==0)
        return MAX_SMALL_PRIME;

    if (p == 2)
        return 1;

    if (p < 2 || p > MAX_SMALL_PRIME || (p & 1) == 0)
        return 0;

    return !_primes_table.test(p / 2);
}

LispObject* PlatIsPrime(LispEnvironment& aEnvironment,LispObject* int1, LispInt aPrecision)
{
    return Double(aEnvironment, primes_table_check((unsigned long)(GetDouble(int1))));
}
