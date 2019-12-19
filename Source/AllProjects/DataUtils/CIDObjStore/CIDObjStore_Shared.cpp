// ----------------------------------------------------------------------------
//  FILE: CIDObjStore_Shared.cpp
//  DATE: Sat, Dec 07 22:19:59 2019 -0500
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------

#include "CIDObjStore_.hpp"



static TEnumMap::TEnumValItem aeitemValues_EFlags[2] = 
{
    {  tCIDLib::TInt4(tCIDObjStore::EFlags::CaseSensitive), 0, 0,  { L"", L"", L"", L"CaseSensitive", L"EFlags::CaseSensitive", L"" } }
  , {  tCIDLib::TInt4(tCIDObjStore::EFlags::RecoveryMode), 0, 0,  { L"", L"", L"", L"RecoveryMode", L"EFlags::RecoveryMode", L"" } }

};

static TEnumMap emapEFlags
(
     L"EFlags"
     , 2
     , kCIDLib::True
     , aeitemValues_EFlags
     , nullptr
     , tCIDLib::TCard4(tCIDObjStore::EFlags::None)
);

tCIDLib::TVoid tCIDObjStore::FormatEFlags(TString& strToFill, const TString& strPrefix, const tCIDLib::TCh chSepChar, const TEnumMap::ETextVals eVal)
{
    emapEFlags.FormatValues(strToFill, strPrefix, chSepChar, eVal);
}
const TString& tCIDObjStore::strXlatEFlags(const tCIDObjStore::EFlags eVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return emapEFlags.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, bThrowIfNot);
}

tCIDObjStore::EFlags tCIDObjStore::eXlatEFlags(const TString& strVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return tCIDObjStore::EFlags(emapEFlags.i4MapEnumText(strVal, TEnumMap::ETextVals::BaseName, bThrowIfNot));
}

TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDObjStore::EFlags eVal)
{
    strmTar << emapEFlags.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, kCIDLib::False);
    return strmTar;
}
tCIDLib::TBoolean tCIDObjStore::bIsValidEnum(const tCIDObjStore::EFlags eVal)
{
    return emapEFlags.bIsValidEnum(tCIDLib::TCard4(eVal));

}

