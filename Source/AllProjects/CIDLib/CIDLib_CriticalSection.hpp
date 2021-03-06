//
// FILE NAME: CIDLib_CriticalSection.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 05/23/1993
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
//  This header defines and implements a critical section class. This class
//  is implmented in terms of the kernel class, TKrnlCritSec. This guy
//  throws no exceptions, so its safe to use in the most primal places.
//
//  Also implemented here is a simple critical section janitor that makes
//  it safe to use critical sections in an exception based world.
//
// CAVEATS/GOTCHAS:
//
//  1)  We don't have a Cpp file so our out of line stuff (basically just
//      our magic macros) is in CIDLib.Cpp
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


#pragma CIDLIB_PACK(CIDLIBPACK)

// ---------------------------------------------------------------------------
//   CLASS: TCriticalSection
//  PREFIX: crs
// ---------------------------------------------------------------------------
class CIDLIBEXP TCriticalSection : public TObject, public TKrnlCritSec
{
    public  :
        // -------------------------------------------------------------------
        //  Constuctors and Destructor
        // -------------------------------------------------------------------
        TCriticalSection() = default;

        TCriticalSection(const TCriticalSection&) = delete;
        TCriticalSection(TCriticalSection&&) = delete;

        ~TCriticalSection() = default;


        // -------------------------------------------------------------------
        //  Public operators
        // -------------------------------------------------------------------
        TCriticalSection& operator=(const TCriticalSection&) = delete;
        TCriticalSection& operator=(TCriticalSection&&) = delete;


    private :
        // -------------------------------------------------------------------
        //  Do any needed magic macros
        // -------------------------------------------------------------------
        RTTIDefs(TCriticalSection,TObject)
};


// ---------------------------------------------------------------------------
//   CLASS: TCritSecLocker
//  PREFIX: crsl
// ---------------------------------------------------------------------------
class CIDLIBEXP TCritSecLocker : public  TObject
{
    public  :
        // -------------------------------------------------------------------
        //  Constuctors and Destructor
        // -------------------------------------------------------------------
        TCritSecLocker() = delete;


        TCritSecLocker(const TCriticalSection* const pcrsToSanitize) :

            m_pcrsSanitize(nullptr)
        {
            // Enter it and store the pointer, if we got something
            if (pcrsToSanitize != nullptr)
            {
                pcrsToSanitize->Enter();
                m_pcrsSanitize = pcrsToSanitize;
            }
        }

        TCritSecLocker(const TCritSecLocker&) = delete;
        TCritSecLocker(TCritSecLocker&&) = delete;

        ~TCritSecLocker()
        {
            // If we still have it, then exit the lock
            if (m_pcrsSanitize != nullptr)
                m_pcrsSanitize->Exit();
        }


        // -------------------------------------------------------------------
        //  Public operators
        // -------------------------------------------------------------------
        TCritSecLocker& operator=(const TCritSecLocker&) = delete;
        TCritSecLocker& operator=(TCritSecLocker&&) = delete;
        tCIDLib::TVoid* operator new(size_t) = delete;


        // -------------------------------------------------------------------
        //  Public, non-virtual methods
        // -------------------------------------------------------------------
        tCIDLib::TVoid Orphan()
        {
            // If we still have it, then exit the lock and zero our pointer
            if (m_pcrsSanitize != nullptr)
            {
                m_pcrsSanitize->Exit();
                m_pcrsSanitize = nullptr;
            }
        }


    private :
        // -------------------------------------------------------------------
        //  Private data members
        //
        //  m_pcrsSanitize
        //      This is the critical section to sanitize.
        // -------------------------------------------------------------------
        const TCriticalSection* m_pcrsSanitize;


        // -------------------------------------------------------------------
        //  Do any needed magic macros
        // -------------------------------------------------------------------
        RTTIDefs(TCritSecLocker,TObject)
};

#pragma CIDLIB_POPPACK

