
#ifndef __mathcommands_h__
#define __mathcommands_h__

#include "yacasbase.h"
#include "lispenvironment.h"
#include "lispevalhash.h"
#include "lispobject.h"
#include "lispglobals.h"


#define CORE_FUNCTION(NAME) void NAME(LispEnvironment& aEnvironment, LispPtr& aResult, LispPtr& aArguments);

#define CORE_KERNEL_FUNCTION(iname,fname,nrargs,flags) void fname(LispEnvironment& aEnvironment, LispInt aStackTop);
#define CORE_KERNEL_FUNCTION_ALIAS(iname,fname,nrargs,flags) 

#include "corefunctions.h"
#undef CORE_KERNEL_FUNCTION
#undef CORE_KERNEL_FUNCTION_ALIAS

//
// Evaluation direction.
//
//DONE CORE_FUNCTION(LispQuote)
//DONE CORE_FUNCTION(LispEval)

//
// Input/output functions
//
/*DONE
CORE_FUNCTION(LispWrite)
CORE_FUNCTION(LispWriteString)
CORE_FUNCTION(LispFullForm)
CORE_FUNCTION(LispDefaultDirectory)
CORE_FUNCTION(LispFromFile)
CORE_FUNCTION(LispFromString)
CORE_FUNCTION(LispRead)
CORE_FUNCTION(LispReadToken)
CORE_FUNCTION(LispToFile)
CORE_FUNCTION(LispToString)
CORE_FUNCTION(LispLoad)
*/

//
// Variable setting/clearing
//
/*
CORE_FUNCTION(LispSetVar)
CORE_FUNCTION(LispMacroSetVar)
CORE_FUNCTION(LispClearVar)
CORE_FUNCTION(LispMacroClearVar)
CORE_FUNCTION(LispNewLocal)
CORE_FUNCTION(LispMacroNewLocal)
*/
//
// List and compound object manipulation
//
/*
CORE_FUNCTION(LispNth)
CORE_FUNCTION(LispTail)
CORE_FUNCTION(LispDestructiveReverse)
CORE_FUNCTION(LispLength)
CORE_FUNCTION(LispList)
CORE_FUNCTION(LispUnList)
CORE_FUNCTION(LispListify)
CORE_FUNCTION(LispConcatenate)
CORE_FUNCTION(LispConcatenateStrings)
*/

/*
CORE_FUNCTION(LispDelete)
CORE_FUNCTION(LispDestructiveDelete)
CORE_FUNCTION(LispInsert)
CORE_FUNCTION(LispDestructiveInsert)
CORE_FUNCTION(LispReplace)
CORE_FUNCTION(LispDestructiveReplace)
CORE_FUNCTION(LispAtomize)
CORE_FUNCTION(LispStringify)
CORE_FUNCTION(LispFlatCopy)

//???CORE_FUNCTION(LispNoCacheConcatenateStrings)

//
// Program control flow
//
CORE_FUNCTION(LispProgBody)
CORE_FUNCTION(LispWhile)
CORE_FUNCTION(LispIf)
CORE_FUNCTION(LispCheck)
//
// User function definition
//
CORE_FUNCTION(LispPreFix)
CORE_FUNCTION(LispInFix)
CORE_FUNCTION(LispPostFix)
CORE_FUNCTION(LispBodied)
CORE_FUNCTION(LispRuleBase)
CORE_FUNCTION(LispMacroRuleBase)
CORE_FUNCTION(LispRuleBaseListed)
CORE_FUNCTION(LispMacroRuleBaseListed)
CORE_FUNCTION(LispDefMacroRuleBase)
CORE_FUNCTION(LispDefMacroRuleBaseListed)
CORE_FUNCTION(LispHoldArg)
CORE_FUNCTION(LispNewRule)
CORE_FUNCTION(LispMacroNewRule)
CORE_FUNCTION(LispUnFence)
CORE_FUNCTION(LispRetract)
//
// Predicates
//
CORE_FUNCTION(LispNot)
CORE_FUNCTION(LispLazyAnd)
CORE_FUNCTION(LispLazyOr)
CORE_FUNCTION(LispEquals)
CORE_FUNCTION(LispLessThan)
CORE_FUNCTION(LispGreaterThan)
CORE_FUNCTION(LispIsFunction)
CORE_FUNCTION(LispIsAtom)
CORE_FUNCTION(LispMathLibName)
CORE_FUNCTION(LispVersion)
CORE_FUNCTION(LispIsNumber)
CORE_FUNCTION(LispIsInteger)
CORE_FUNCTION(LispIsList)
CORE_FUNCTION(LispIsString)
CORE_FUNCTION(LispIsBound)
//
// Math functions (REQUIRING number inputs).
//
CORE_FUNCTION(LispMultiply)
CORE_FUNCTION(LispAdd)
CORE_FUNCTION(LispSubtract)
CORE_FUNCTION(LispDivide)
CORE_FUNCTION(LispSin)
CORE_FUNCTION(LispCos)
CORE_FUNCTION(LispTan)
CORE_FUNCTION(LispArcSin)
CORE_FUNCTION(LispArcCos)
CORE_FUNCTION(LispArcTan)
CORE_FUNCTION(LispPrecision)
CORE_FUNCTION(LispGetExactBits)
CORE_FUNCTION(LispSetExactBits)
CORE_FUNCTION(LispSqrt)
CORE_FUNCTION(LispFloor)
CORE_FUNCTION(LispCeil)
CORE_FUNCTION(LispAbs)
CORE_FUNCTION(LispMod)
CORE_FUNCTION(LispDiv)
CORE_FUNCTION(LispLog)
CORE_FUNCTION(LispExp)
CORE_FUNCTION(LispPower)
CORE_FUNCTION(LispPi)
CORE_FUNCTION(LispGcd)
CORE_FUNCTION(LispSystemCall)
CORE_FUNCTION(LispFastSin)
CORE_FUNCTION(LispFastCos)
CORE_FUNCTION(LispFastTan)
CORE_FUNCTION(LispFastArcSin)
CORE_FUNCTION(LispFastArcCos)
CORE_FUNCTION(LispFastArcTan)
CORE_FUNCTION(LispFastExp)
CORE_FUNCTION(LispFastLog)
CORE_FUNCTION(LispFastPower)
CORE_FUNCTION(LispFastSqrt)
CORE_FUNCTION(LispFastPi)
CORE_FUNCTION(LispFastFloor)
CORE_FUNCTION(LispFastCeil)
CORE_FUNCTION(LispFastMod)
CORE_FUNCTION(LispFastAbs)
CORE_FUNCTION(LispShiftLeft)
CORE_FUNCTION(LispShiftRight)
CORE_FUNCTION(LispFromBase)
CORE_FUNCTION(LispToBase)
CORE_FUNCTION(LispMaxEvalDepth)
CORE_FUNCTION(LispDefLoad)
CORE_FUNCTION(LispUse)
CORE_FUNCTION(LispRightAssociative)
CORE_FUNCTION(LispLeftPrecedence)
CORE_FUNCTION(LispRightPrecedence)
CORE_FUNCTION(LispIsBodied)
CORE_FUNCTION(LispIsInFix)
CORE_FUNCTION(LispIsPreFix)
CORE_FUNCTION(LispIsPostFix)
CORE_FUNCTION(LispGetPrecedence)
CORE_FUNCTION(LispGetLeftPrecedence)
CORE_FUNCTION(LispGetRightPrecedence)
CORE_FUNCTION(LispGetPrecision)
CORE_FUNCTION(LispBitAnd)
CORE_FUNCTION(LispBitOr)
CORE_FUNCTION(LispBitXor)
CORE_FUNCTION(LispSecure)
CORE_FUNCTION(LispFindFile)
CORE_FUNCTION(LispFindFunction)
// Generic objecs support 
CORE_FUNCTION(LispIsGeneric)
CORE_FUNCTION(LispGenericTypeName)
CORE_FUNCTION(GenArrayCreate)
CORE_FUNCTION(GenArraySize)
CORE_FUNCTION(GenArrayGet)
CORE_FUNCTION(GenArraySet)
CORE_FUNCTION(LispCustomEval)
CORE_FUNCTION(LispCustomEvalExpression)
CORE_FUNCTION(LispCustomEvalResult)
CORE_FUNCTION(LispCustomEvalLocals)
CORE_FUNCTION(LispCustomEvalStop)

CORE_FUNCTION(LispTraceRule)
CORE_FUNCTION(LispTraceStack)
CORE_FUNCTION(LispReadLisp)
CORE_FUNCTION(LispReadLispListed)
CORE_FUNCTION(LispType)
CORE_FUNCTION(LispStringMid)
CORE_FUNCTION(LispSetStringMid)
// Pattern matching 
CORE_FUNCTION(GenPatternCreate)
CORE_FUNCTION(GenPatternMatches)
CORE_FUNCTION(LispRuleBaseDefined)
CORE_FUNCTION(LispDefLoadFunction)
CORE_FUNCTION(LispRuleBaseArgList)
CORE_FUNCTION(LispNewRulePattern)
CORE_FUNCTION(LispMacroNewRulePattern)
CORE_FUNCTION(LispSubst)
CORE_FUNCTION(LispLocalSymbols)
CORE_FUNCTION(LispFastIsPrime)
CORE_FUNCTION(LispFac)
CORE_FUNCTION(LispApplyPure)
CORE_FUNCTION(LispPrettyPrinter)
CORE_FUNCTION(LispGarbageCollect)
CORE_FUNCTION(LispLazyGlobal)
CORE_FUNCTION(LispPatchLoad)
CORE_FUNCTION(LispPatchString)
CORE_FUNCTION(LispDllLoad)
CORE_FUNCTION(LispDllUnload)
CORE_FUNCTION(LispDllEnumerate)
CORE_FUNCTION(LispSetExtraInfo)
CORE_FUNCTION(LispGetExtraInfo)
CORE_FUNCTION(LispBerlekamp)
CORE_FUNCTION(LispDefaultTokenizer)
CORE_FUNCTION(LispCommonLispTokenizer)
CORE_FUNCTION(LispCTokenizer)
CORE_FUNCTION(LispXmlTokenizer)
CORE_FUNCTION(LispExplodeTag)
CORE_FUNCTION(LispFastAssoc)
CORE_FUNCTION(LispCurrentFile)
CORE_FUNCTION(LispCurrentLine)
CORE_FUNCTION(LispBackQuote)

*/

#endif
