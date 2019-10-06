// ----------------------------------------------------------------------------
//  FILE: CIDAudStream_Shared.cpp
//  DATE: Sat, Oct 05 19:48:04 2019 -0400
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------

#include "CIDAudStream_.hpp"



static TEnumMap::TEnumValItem aeitemValues_EStrmStates[3] = 
{
    {  tCIDLib::TInt4(tCIDAudStream::EStrmStates::Ready), 0, 0,  { L"", L"", L"", L"Ready", L"EStrmStates::Ready", L"" } }
  , {  tCIDLib::TInt4(tCIDAudStream::EStrmStates::Error), 0, 0,  { L"", L"", L"", L"Error", L"EStrmStates::Error", L"" } }
  , {  tCIDLib::TInt4(tCIDAudStream::EStrmStates::WaitConnect), 0, 0,  { L"", L"", L"", L"WaitConnect", L"EStrmStates::WaitConnect", L"" } }

};

static TEnumMap emapEStrmStates
(
     L"EStrmStates"
     , 3
     , kCIDLib::False
     , aeitemValues_EStrmStates
     , nullptr
     , tCIDLib::TCard4(tCIDAudStream::EStrmStates::Count)
);

const TString& tCIDAudStream::strXlatEStrmStates(const tCIDAudStream::EStrmStates eVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return emapEStrmStates.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, bThrowIfNot);
}

tCIDAudStream::EStrmStates tCIDAudStream::eXlatEStrmStates(const TString& strVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return tCIDAudStream::EStrmStates(emapEStrmStates.i4MapEnumText(strVal, TEnumMap::ETextVals::BaseName, bThrowIfNot));
}

TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDAudStream::EStrmStates eVal)
{
    strmTar << emapEStrmStates.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, kCIDLib::False);
    return strmTar;
}
tCIDLib::TBoolean tCIDAudStream::bIsValidEnum(const tCIDAudStream::EStrmStates eVal)
{
    return emapEStrmStates.bIsValidEnum(tCIDLib::TCard4(eVal));

}

