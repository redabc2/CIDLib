// ----------------------------------------------------------------------------
//  FILE: TestORB_LoopbackClientProxy.hpp
//  DATE: Sat, Oct 05 19:48:04 2019 -0400
//    ID: 1799C1BE4E47BA7E-19344A2250A462D2
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------
#pragma once

#pragma CIDLIB_PACK(CIDLIBPACK)

class  TTestOrbIntfClientProxy : public TOrbClientBase
{
    public :
        // --------------------------------------------------------------------
        // Public, static data
        // --------------------------------------------------------------------
        static const TString strInterfaceId;

        // --------------------------------------------------------------------
        // Public Constructors and Destructor
        // --------------------------------------------------------------------
        TTestOrbIntfClientProxy();
        TTestOrbIntfClientProxy(const TOrbObjId& ooidSrc, const TString& strNSBinding);
        TTestOrbIntfClientProxy(const TTestOrbIntfClientProxy&) = delete;
        ~TTestOrbIntfClientProxy();

        // --------------------------------------------------------------------
        // Public operators
        // --------------------------------------------------------------------
        TTestOrbIntfClientProxy& operator=(const TTestOrbIntfClientProxy&) = delete;

        // --------------------------------------------------------------------
        // Public, inherited methods
        // --------------------------------------------------------------------
        tCIDLib::TVoid SetObjId
        (
            const   TOrbObjId& ooidToSet
            , const TString& strNSBinding
            , const tCIDLib::TBoolean bCheck = kCIDLib::True
        )   override;

        // --------------------------------------------------------------------
        // Public, non-virtual methods
        // --------------------------------------------------------------------
        tCIDLib::TBoolean bBagParamTest
        (
            const TBag<TArea>& colIn
            , TBag<TPoint>& colOut
            , TString& strFailReason
        );

        tCIDLib::TBoolean bParamTest
        (
            const tCIDLib::TCard4 c4In
            , tCIDLib::TCard4& c4Out
            , const tCIDLib::TFloat8 f8In
            , tCIDLib::TFloat8& f8Out
            , const TString& strIn
            , TString& strOut
            , TString& strInOut
            , const tCIDLib::TBoolean bIn
            , tCIDLib::TBoolean& bOut
            , TString& strFailReason
        );

        tCIDLib::TBoolean bPollData
        (
            tCIDLib::TCard4& c4SerialNum
            , TArea& areaRet
        );

        tCIDLib::TBoolean bVectorParamTest
        (
            TVector<TString>& colInOut
            , TString& strFailReason
        );

        tCIDLib::TCard4 c4BumpIt
        (
            const tCIDLib::TCard4 c4Input
        );

        tCIDLib::TVoid BulkTest
        (
            tCIDLib::TCard4& c4BufSz_mbufOut
            , THeapBuf& mbufOut
        );

        tCIDLib::TVoid ExceptTest();

        tCIDLib::TVoid ExceptTest
        (
            const tCIDLib::TCard4 c4Dummy
        );

        tCIDLib::TVoid SetData
        (
            const TArea& areaToSet
        );

    protected :
        // --------------------------------------------------------------------
        // Declare our friends
        // --------------------------------------------------------------------
        friend class TFacCIDOrb;

    private :
        // --------------------------------------------------------------------
        // Magic macros
        // --------------------------------------------------------------------
        RTTIDefs(TTestOrbIntfClientProxy,TOrbClientBase)
};

#pragma CIDLIB_POPPACK

inline tCIDLib::TVoid
TTestOrbIntfClientProxy::SetObjId(const  TOrbObjId& ooidToSet
              , const TString& strNSBinding
              , const tCIDLib::TBoolean bCheck)
{
    TParent::SetObjId(ooidToSet, strNSBinding, bCheck);
}

