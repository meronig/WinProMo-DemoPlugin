/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _DEMODOC_H_
#define _DEMODOC_H_

#include "..\WinProMo\WinProMoDoc.h"
class WPDEMOPLUGIN_API CWPDemoDoc :
    public CWinProMoDoc
{
protected: // create from serialization only
    DECLARE_DYNCREATE(CWPDemoDoc)

    // Operations
public:
    CWPDemoDoc();
    virtual ~CWPDemoDoc();
    virtual void CreateContainer();

};

#endif //_DEMODOC_H_

