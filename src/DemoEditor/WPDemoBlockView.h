/* ==========================================================================

    Copyright © 2026 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPDEMOBLOCKVIEW_H_
#define _WPDEMOBLOCKVIEW_H_

#include "../../../WinProMo/src/ProMoEditor\ProMoBlockView.h"
class AFX_EXT_CLASS CWPDemoBlockView :
    public CProMoBlockView
{
public:
    CWPDemoBlockView();
    virtual ~CWPDemoBlockView();

    // Overrides
    virtual CDiagramEntity* Clone();
    virtual void DrawShape(CDC* dc, CRect& rect);

public:

    static CDiagramEntity* CreateFromString(const CString& str);
    static CDiagramEntity* CreateFromString(const CString& str, CProMoModel* model);
    static CDiagramEntity* Create(const CString& str);


};

#endif //_WPDEMOBLOCKVIEW_H_