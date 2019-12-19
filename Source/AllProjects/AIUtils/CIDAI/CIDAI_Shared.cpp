// ----------------------------------------------------------------------------
//  FILE: CIDAI_Shared.cpp
//  DATE: Sat, Dec 07 22:19:59 2019 -0500
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------

#include "CIDAI_.hpp"

const TString kCIDAI::strFact_Default(L"CIDAI");
const TString kCIDAI::strFact_DefPrefix(L"/CIDAI/");
const TString kCIDAI::strDefFact_Inverter(L"/CADAI/Inverter");
const TString kCIDAI::strDefFact_Link(L"/CADAI/Link");
const TString kCIDAI::strDefFact_Root(L"/CIDAI/Root");
const TString kCIDAI::strDefFact_RandChoice(L"/CIDAI/RandChoice");
const TString kCIDAI::strDefFact_Selector(L"/CIDAI/Selector");
const TString kCIDAI::strDefFact_Sequence(L"/CIDAI/Sequence");
const TString kCIDAI::strDefFact_Success(L"/CIDAI/Success");
const TString kCIDAI::strDefFact_VarTest(L"/CIDAI/VarTest");
const TString kCIDAI::strNParam_LinkTarget(L"LinkTarget");
const TString kCIDAI::strNParam_VarTestComp(L"VarTestComp");
const TString kCIDAI::strNParam_VarTestVal(L"VarTestVal");
const TString kCIDAI::strNParam_VarTestVar(L"VarTestVar");
const TString kCIDAI::strVal_False(L"False");
const TString kCIDAI::strVal_True(L"True");


static TEnumMap::TEnumValItem aeitemValues_ENodeStates[4] = 
{
    {  tCIDLib::TInt4(tCIDAI::ENodeStates::Running), 0, 0,  { L"", L"", L"", L"Running", L"ENodeStates::Running", L"" } }
  , {  tCIDLib::TInt4(tCIDAI::ENodeStates::Success), 0, 0,  { L"", L"", L"", L"Success", L"ENodeStates::Success", L"" } }
  , {  tCIDLib::TInt4(tCIDAI::ENodeStates::Cancel), 0, 0,  { L"", L"", L"", L"Cancel", L"ENodeStates::Cancel", L"" } }
  , {  tCIDLib::TInt4(tCIDAI::ENodeStates::Failure), 0, 0,  { L"", L"", L"", L"Failure", L"ENodeStates::Failure", L"" } }

};

static TEnumMap emapENodeStates
(
     L"ENodeStates"
     , 4
     , kCIDLib::False
     , aeitemValues_ENodeStates
     , nullptr
     , tCIDLib::TCard4(tCIDAI::ENodeStates::Count)
);

const TString& tCIDAI::strXlatENodeStates(const tCIDAI::ENodeStates eVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return emapENodeStates.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, bThrowIfNot);
}

tCIDAI::ENodeStates tCIDAI::eXlatENodeStates(const TString& strVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return tCIDAI::ENodeStates(emapENodeStates.i4MapEnumText(strVal, TEnumMap::ETextVals::BaseName, bThrowIfNot));
}

TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDAI::ENodeStates eVal)
{
    strmTar << emapENodeStates.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, kCIDLib::False);
    return strmTar;
}
TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDAI::ENodeStates eVal)
{
    strmTar.WriteEnum(tCIDLib::TCard4(eVal));
    return strmTar;
}
TBinInStream& operator>>(TBinInStream& strmSrc, tCIDAI::ENodeStates& eVal)
{
    eVal = tCIDAI::ENodeStates(strmSrc.c4ReadEnum());
    return strmSrc;
}
tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDAI::ENodeStates* const aeList, const tCIDLib::TCard4 c4Count)
{
    tCIDLib::TCard4 c4Cur;
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
    {
        strmSrc >> c4Cur;
        aeList[c4Index] = tCIDAI::ENodeStates(c4Cur);
    }
}
tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDAI::ENodeStates* const aeList, const tCIDLib::TCard4 c4Count)
{
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
        strmTar << tCIDLib::TCard4(aeList[c4Index]);
}
tCIDLib::TBoolean tCIDAI::bIsValidEnum(const tCIDAI::ENodeStates eVal)
{
    return emapENodeStates.bIsValidEnum(tCIDLib::TCard4(eVal));

}

