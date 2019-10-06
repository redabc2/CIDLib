//
// FILE NAME: CIDIDL_ParmaInfo.cpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 08/10/2004
//
// COPYRIGHT: Charmed Quark Systems, Ltd @ 2019
//
//  This software is copyrighted by 'Charmed Quark Systems, Ltd' and
//  the author (Dean Roddey.) It is licensed under the MIT Open Source
//  license:
//
//  https://opensource.org/licenses/MIT
//
// DESCRIPTION:
//
//  This file implements the method parameter info class.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include    "CIDIDL.hpp"


// ---------------------------------------------------------------------------
//  Magic macros
// ---------------------------------------------------------------------------
RTTIDecls(TCGenTypeInfo,TObject)
RTTIDecls(TCGenMethodParm,TObject)



// ---------------------------------------------------------------------------
//   CLASS: TCGenTypeInfo
//  PREFIX: tInfo
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  TCGenTypeInfo: Constructors and Destructor
// ---------------------------------------------------------------------------
TCGenTypeInfo::TCGenTypeInfo() :

    m_bMoveableType(kCIDLib::False)
{
}

TCGenTypeInfo::TCGenTypeInfo(const TXMLTreeElement& xtnodeType) :

    m_bMoveableType(kCIDLib::False)
{
    Set(xtnodeType);
}

TCGenTypeInfo::~TCGenTypeInfo()
{
}


// ---------------------------------------------------------------------------
//  TCGenTypeInfo: Public, non-virtual methods
// ---------------------------------------------------------------------------
const TString& TCGenTypeInfo::strAuxType() const
{
    return m_strAuxType;
}


const TString& TCGenTypeInfo::strKeyExtract() const
{
    return m_strKeyExtract;
}


const TString& TCGenTypeInfo::strKeyOps() const
{
    return m_strKeyOps;
}


const TString& TCGenTypeInfo::strKeyType() const
{
    return m_strKeyType;
}


const TString& TCGenTypeInfo::strModulus() const
{
    return m_strModulus;
}


const TString& TCGenTypeInfo::strType() const
{
    return m_strType;
}


tCIDLib::TVoid TCGenTypeInfo::Set(const TXMLTreeElement& xtnodeType)
{
    m_strType = xtnodeType.strQName();
    m_bMoveableType = kCIDLib::False;
    m_strAuxType.Clear();
    m_strKeyExtract.Clear();
    m_strKeyOps.Clear();
    m_strKeyType.Clear();
    m_strModulus.Clear();

    if (m_strType == s_strElem_Object)
    {
        // We can't know if it's moveable, so assume so until proven otherwise
        m_bMoveableType = kCIDLib::True;
        m_strAuxType = xtnodeType.xtattrNamed(s_strElem_Type).strValue();
    }
     else if (m_strType == s_strElem_Enumerated)
    {
        // Get the type attribute out, which is the actual type
        m_strAuxType = xtnodeType.xtattrNamed(s_strElem_Type).strValue();
    }
     else if (m_strType == s_strElem_Bag)
    {
        m_bMoveableType = kCIDLib::True;
        m_strAuxType = xtnodeType.xtattrNamed(s_strElem_ElemType).strValue();
    }
     else if (m_strType == s_strElem_HashSet)
    {
        m_bMoveableType = kCIDLib::True;
        m_strAuxType = xtnodeType.xtattrNamed(s_strElem_ElemType).strValue();
        m_strKeyOps = xtnodeType.xtattrNamed(s_strElem_KeyOps).strValue();
        m_strModulus = xtnodeType.xtattrNamed(s_strElem_Modulus).strValue();
    }
     else if ((m_strType == s_strElem_HeapBuf)
          ||  (m_strType == s_strElem_MemBuf)
          ||  (m_strType == s_strElem_String))
    {
        //
        //  TMemBuf itself is not movenable, but on the server side base class, we
        //  create a THeapBuf object for processing on the server side, which is.
        //
        m_bMoveableType = kCIDLib::True;
    }
     else if (m_strType == s_strElem_KeyedHashSet)
    {
        m_bMoveableType = kCIDLib::True;
        m_strAuxType = xtnodeType.xtattrNamed(s_strElem_ElemType).strValue();
        m_strKeyType = xtnodeType.xtattrNamed(s_strElem_KeyType).strValue();
        m_strKeyOps = xtnodeType.xtattrNamed(s_strElem_KeyOps).strValue();
        m_strModulus = xtnodeType.xtattrNamed(s_strElem_Modulus).strValue();
        m_strKeyExtract = xtnodeType.xtattrNamed(s_strElem_KeyExtract).strValue();
    }
     else if (m_strType == s_strElem_Vector)
    {
        m_bMoveableType = kCIDLib::True;
        m_strAuxType = xtnodeType.xtattrNamed(s_strElem_ElemType).strValue();
    }
     else if (m_strType == s_strElem_FundArray)
    {
        m_strAuxType = xtnodeType.xtattrNamed(s_strElem_ElemType).strValue();
    }
     else if (m_strType == s_strElem_FundVector)
    {
        m_strAuxType = xtnodeType.xtattrNamed(s_strElem_ElemType).strValue();
    }
}


// ---------------------------------------------------------------------------
//  TCGenTypeInfo: Private, static members
// ---------------------------------------------------------------------------
const TString    TCGenTypeInfo::s_strElem_Bag(L"CIDIDL:TBag");
const TString    TCGenTypeInfo::s_strElem_ElemType(L"CIDIDL:ElemType");
const TString    TCGenTypeInfo::s_strElem_Enumerated(L"CIDIDL:Enumerated");
const TString    TCGenTypeInfo::s_strElem_FundArray(L"CIDIDL:TFundArray");
const TString    TCGenTypeInfo::s_strElem_FundVector(L"CIDIDL:TFundVector");
const TString    TCGenTypeInfo::s_strElem_HashSet(L"CIDIDL:THashSet");
const TString    TCGenTypeInfo::s_strElem_HeapBuf(L"CIDIDL:THeapBuf");
const TString    TCGenTypeInfo::s_strElem_KeyExtract(L"CIDIDL:KeyExtract");
const TString    TCGenTypeInfo::s_strElem_KeyedHashSet(L"CIDIDL:TKeyedHashSet");
const TString    TCGenTypeInfo::s_strElem_KeyOps(L"CIDIDL:KeyOps");
const TString    TCGenTypeInfo::s_strElem_KeyType(L"CIDIDL:KeyType");
const TString    TCGenTypeInfo::s_strElem_MemBuf(L"CIDIDL:TMemBuf");
const TString    TCGenTypeInfo::s_strElem_Modulus(L"CIDIDL:Modulus");
const TString    TCGenTypeInfo::s_strElem_Object(L"CIDIDL:Object");
const TString    TCGenTypeInfo::s_strElem_String(L"CIDIDL:TString");
const TString    TCGenTypeInfo::s_strElem_Type(L"CIDIDL:Type");
const TString    TCGenTypeInfo::s_strElem_Vector(L"CIDIDL:TVector");




// ---------------------------------------------------------------------------
//   CLASS: TCGenMethodParm
//  PREFIX: mparm
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  TCGenMethodParm: Constructors and Destructor
// ---------------------------------------------------------------------------
TCGenMethodParm::TCGenMethodParm(const  TString&            strMethodName
                                , const TXMLTreeElement&    xtnodeParm) :

    m_bMoveable(kCIDLib::False)
    , m_eDir(tCIDLib::EParmDirs::Count)
{
    m_strName = xtnodeParm.xtattrNamed(s_strAttr_Name).strValue();

    // There may be default value
    tCIDLib::TCard4 c4Index;
    if (xtnodeParm.bAttrExists(s_strAttr_DefVal, c4Index))
        m_strDefVal = xtnodeParm.xtattrAt(c4Index).strValue();

    m_bMoveable = xtnodeParm.xtattrNamed(s_strAttr_Moveable).bValueAs();

    // Get the direction value attribute, and map to the enum type
    const TString& strDir = xtnodeParm.xtattrNamed(s_strAttr_Dir).strValue();
    tCIDLib::EParmDirs eDir;
    if (strDir == TFacCIDIDL::strVal_In)
    {
        m_eDir = tCIDLib::EParmDirs::In;
    }
     else if (strDir == TFacCIDIDL::strVal_Out)
    {
        m_eDir = tCIDLib::EParmDirs::Out;
    }
     else if (strDir == TFacCIDIDL::strVal_InOut)
    {
        m_eDir = tCIDLib::EParmDirs::InOut;
    }
     else
    {
        // Make the compiler happy
        eDir = tCIDLib::EParmDirs::In;

        facCIDIDL.ThrowErr
        (
            CID_FILE
            , CID_LINE
            , kIDLErrs::errcGen_InvalidParmDir
            , tCIDLib::ESeverities::Failed
            , tCIDLib::EErrClasses::Format
            , strMethodName
        );
    }

    // Get the 0th child which is a our type, and set it
    m_tinfoThis.Set(xtnodeParm.xtnodeChildAtAsElement(0));

    //
    //  Move is only useful if it's a moveable type and not an output
    //  only parameter.
    //
    if (m_bMoveable)
    {
        if ((m_eDir == tCIDLib::EParmDirs::Out) || !m_tinfoThis.bIsMoveableType())
        {
            facCIDIDL.ThrowErr
            (
                CID_FILE
                , CID_LINE
                , kIDLErrs::errcGen_ParmMove
                , tCIDLib::ESeverities::Failed
                , tCIDLib::EErrClasses::Format
                , strMethodName
            );
        }
    }
}

TCGenMethodParm::~TCGenMethodParm()
{
}


// ---------------------------------------------------------------------------
//  TCGenMethodParm: Public, non-virtual methods
// ---------------------------------------------------------------------------
const TString& TCGenMethodParm::strDefVal() const
{
    return m_strDefVal;
}


const TString& TCGenMethodParm::strName() const
{
    return m_strName;
}


const TCGenTypeInfo& TCGenMethodParm::tinfoThis() const
{
    return m_tinfoThis;
}


// ---------------------------------------------------------------------------
//  TCGenMethodParm: Private, static members
// ---------------------------------------------------------------------------
const TString    TCGenMethodParm::s_strAttr_DefVal(L"CIDIDL:DefVal");
const TString    TCGenMethodParm::s_strAttr_Dir(L"CIDIDL:Dir");
const TString    TCGenMethodParm::s_strAttr_Moveable(L"CIDIDL:Moveable");
const TString    TCGenMethodParm::s_strAttr_Name(L"CIDIDL:Name");
