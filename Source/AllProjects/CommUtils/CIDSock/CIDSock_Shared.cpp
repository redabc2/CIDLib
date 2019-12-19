// ----------------------------------------------------------------------------
//  FILE: CIDSock_Shared.cpp
//  DATE: Sat, Dec 07 22:19:59 2019 -0500
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------

#include "CIDSock_.hpp"



static TEnumMap::TEnumValItem aeitemValues_EProtos[12] = 
{
    {  tCIDLib::TInt4(tCIDSock::EProtos::None), 0, 0,  { L"", L"", L"", L"None", L"EProtos::None", L"None" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::File), 0, 0,  { L"", L"file", L"", L"File", L"EProtos::File", L"File" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::HTTP), 0, 0,  { L"", L"http", L"", L"HTTP", L"EProtos::HTTP", L"HTTP" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::FTP), 0, 0,  { L"", L"ftp", L"", L"FTP", L"EProtos::FTP", L"FTP" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::MailTo), 0, 0,  { L"", L"mailto", L"", L"MailTo", L"EProtos::MailTo", L"MailTo" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::News), 0, 0,  { L"", L"news", L"", L"News", L"EProtos::News", L"News" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::HTTPS), 0, 0,  { L"", L"https", L"", L"HTTPS", L"EProtos::HTTPS", L"HTTPS" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::RTSP), 0, 0,  { L"", L"rtsp", L"", L"RTSP", L"EProtos::RTSP", L"RTSP" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::RTSPS), 0, 0,  { L"", L"rtsps", L"", L"RTSPS", L"EProtos::RTSPS", L"RTSPS" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::SIP), 0, 0,  { L"", L"sip", L"", L"SIP", L"EProtos::SIP", L"SIP" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::WS), 0, 0,  { L"", L"ws", L"", L"WS", L"EProtos::WS", L"WS" } }
  , {  tCIDLib::TInt4(tCIDSock::EProtos::WSS), 0, 0,  { L"", L"wss", L"", L"WSS", L"EProtos::WSS", L"WSS" } }

};

static TEnumMap emapEProtos
(
     L"EProtos"
     , 12
     , kCIDLib::False
     , aeitemValues_EProtos
     , nullptr
     , tCIDLib::TCard4(tCIDSock::EProtos::Count)
);

const TString& tCIDSock::strAltXlatEProtos(const tCIDSock::EProtos eVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return emapEProtos.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::AltText, bThrowIfNot);
}

tCIDSock::EProtos tCIDSock::eAltXlatEProtos(const TString& strVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return tCIDSock::EProtos(emapEProtos.i4MapEnumText(strVal, TEnumMap::ETextVals::AltText, bThrowIfNot));
}

const TString& tCIDSock::strXlatEProtos(const tCIDSock::EProtos eVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return emapEProtos.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::Text, bThrowIfNot);
}

tCIDSock::EProtos tCIDSock::eXlatEProtos(const TString& strVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return tCIDSock::EProtos(emapEProtos.i4MapEnumText(strVal, TEnumMap::ETextVals::Text, bThrowIfNot));
}

TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDSock::EProtos eVal)
{
    strmTar << emapEProtos.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::Text, kCIDLib::False);
    return strmTar;
}
TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDSock::EProtos eVal)
{
    strmTar.WriteEnum(tCIDLib::TCard4(eVal));
    return strmTar;
}
TBinInStream& operator>>(TBinInStream& strmSrc, tCIDSock::EProtos& eVal)
{
    eVal = tCIDSock::EProtos(strmSrc.c4ReadEnum());
    return strmSrc;
}
tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDSock::EProtos* const aeList, const tCIDLib::TCard4 c4Count)
{
    tCIDLib::TCard4 c4Cur;
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
    {
        strmSrc >> c4Cur;
        aeList[c4Index] = tCIDSock::EProtos(c4Cur);
    }
}
tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDSock::EProtos* const aeList, const tCIDLib::TCard4 c4Count)
{
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
        strmTar << tCIDLib::TCard4(aeList[c4Index]);
}
tCIDLib::TBoolean tCIDSock::bIsValidEnum(const tCIDSock::EProtos eVal)
{
    return emapEProtos.bIsValidEnum(tCIDLib::TCard4(eVal));

}



static TEnumMap::TEnumValItem aeitemValues_EQualified[3] = 
{
    {  tCIDLib::TInt4(tCIDSock::EQualified::Partial), 0, 0,  { L"", L"", L"", L"Partial", L"EQualified::Partial", L"" } }
  , {  tCIDLib::TInt4(tCIDSock::EQualified::Full), 0, 0,  { L"", L"", L"", L"Full", L"EQualified::Full", L"" } }
  , {  tCIDLib::TInt4(tCIDSock::EQualified::DontCare), 0, 0,  { L"", L"", L"", L"DontCare", L"EQualified::DontCare", L"" } }

};

static TEnumMap emapEQualified
(
     L"EQualified"
     , 3
     , kCIDLib::False
     , aeitemValues_EQualified
     , nullptr
     , tCIDLib::TCard4(tCIDSock::EQualified::Count)
);

const TString& tCIDSock::strXlatEQualified(const tCIDSock::EQualified eVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return emapEQualified.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, bThrowIfNot);
}

tCIDSock::EQualified tCIDSock::eXlatEQualified(const TString& strVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return tCIDSock::EQualified(emapEQualified.i4MapEnumText(strVal, TEnumMap::ETextVals::BaseName, bThrowIfNot));
}

TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDSock::EQualified eVal)
{
    strmTar << emapEQualified.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, kCIDLib::False);
    return strmTar;
}
TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDSock::EQualified eVal)
{
    strmTar.WriteEnum(tCIDLib::TCard4(eVal));
    return strmTar;
}
TBinInStream& operator>>(TBinInStream& strmSrc, tCIDSock::EQualified& eVal)
{
    eVal = tCIDSock::EQualified(strmSrc.c4ReadEnum());
    return strmSrc;
}
tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDSock::EQualified* const aeList, const tCIDLib::TCard4 c4Count)
{
    tCIDLib::TCard4 c4Cur;
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
    {
        strmSrc >> c4Cur;
        aeList[c4Index] = tCIDSock::EQualified(c4Cur);
    }
}
tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDSock::EQualified* const aeList, const tCIDLib::TCard4 c4Count)
{
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
        strmTar << tCIDLib::TCard4(aeList[c4Index]);
}
tCIDLib::TBoolean tCIDSock::bIsValidEnum(const tCIDSock::EQualified eVal)
{
    return emapEQualified.bIsValidEnum(tCIDLib::TCard4(eVal));

}



static TEnumMap::TEnumValItem aeitemValues_EExpOpts[3] = 
{
    {  tCIDLib::TInt4(tCIDSock::EExpOpts::None), 0, 0,  { L"", L"", L"", L"None", L"EExpOpts::None", L"" } }
  , {  tCIDLib::TInt4(tCIDSock::EExpOpts::Encode), 0, 0,  { L"", L"", L"", L"Encode", L"EExpOpts::Encode", L"" } }
  , {  tCIDLib::TInt4(tCIDSock::EExpOpts::Expand), 0, 0,  { L"", L"", L"", L"Expand", L"EExpOpts::Expand", L"" } }

};

static TEnumMap emapEExpOpts
(
     L"EExpOpts"
     , 3
     , kCIDLib::False
     , aeitemValues_EExpOpts
     , nullptr
     , tCIDLib::TCard4(tCIDSock::EExpOpts::Count)
);

const TString& tCIDSock::strXlatEExpOpts(const tCIDSock::EExpOpts eVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return emapEExpOpts.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, bThrowIfNot);
}

tCIDSock::EExpOpts tCIDSock::eXlatEExpOpts(const TString& strVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return tCIDSock::EExpOpts(emapEExpOpts.i4MapEnumText(strVal, TEnumMap::ETextVals::BaseName, bThrowIfNot));
}

TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDSock::EExpOpts eVal)
{
    strmTar << emapEExpOpts.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, kCIDLib::False);
    return strmTar;
}
TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDSock::EExpOpts eVal)
{
    strmTar.WriteEnum(tCIDLib::TCard4(eVal));
    return strmTar;
}
TBinInStream& operator>>(TBinInStream& strmSrc, tCIDSock::EExpOpts& eVal)
{
    eVal = tCIDSock::EExpOpts(strmSrc.c4ReadEnum());
    return strmSrc;
}
tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDSock::EExpOpts* const aeList, const tCIDLib::TCard4 c4Count)
{
    tCIDLib::TCard4 c4Cur;
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
    {
        strmSrc >> c4Cur;
        aeList[c4Index] = tCIDSock::EExpOpts(c4Cur);
    }
}
tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDSock::EExpOpts* const aeList, const tCIDLib::TCard4 c4Count)
{
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
        strmTar << tCIDLib::TCard4(aeList[c4Index]);
}
tCIDLib::TBoolean tCIDSock::bIsValidEnum(const tCIDSock::EExpOpts eVal)
{
    return emapEExpOpts.bIsValidEnum(tCIDLib::TCard4(eVal));

}

