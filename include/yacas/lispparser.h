/** \file lispparser.h
 *  parsing and printing in the old-fashioned lisp style
 *
 */

#ifndef YACAS_LISPPARSER_H
#define YACAS_LISPPARSER_H

#include "yacasbase.h"
#include "lispobject.h"
#include "tokenizer.h"
#include "lispio.h"
#include "evalfunc.h"

class LispParser : public YacasBase
{
public:
    LispParser(LispTokenizer& aTokenizer, LispInput& aInput,
               LispEnvironment& aEnvironment);
    virtual ~LispParser();
    virtual void Parse(LispPtr& aResult );
protected:
    void ParseList(LispPtr& aResult);
    void ParseAtom(LispPtr& aResult,LispString * aToken);

public:
    LispTokenizer& iTokenizer;
    LispInput& iInput;
    LispEnvironment& iEnvironment;
    LispInt iListed;
};




class LispPrinter : public YacasBase
{
public:
    virtual ~LispPrinter();

    virtual void Print(
        const LispPtr& aExpression,
        LispOutput& aOutput,
        LispEnvironment& aEnvironment);

    virtual void RememberLastChar(LispChar aChar);

private:
    void PrintExpression(
        const LispPtr& aExpression,
        LispOutput& aOutput,
        LispEnvironment& aEnvironment,
        LispInt aDepth=0);

    void Indent(LispOutput& aOutput, LispInt aDepth);
};


#endif
