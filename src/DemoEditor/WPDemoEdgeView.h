/* ==========================================================================

    Copyright © 2026 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPDEMOEDGEVIEW_H_
#define _WPDEMOEDGEVIEW_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoEdgeView.h"

class AFX_EXT_CLASS CWPDemoEdgeView :
    public CProMoEdgeView
{
public:
    CWPDemoEdgeView();
    virtual ~CWPDemoEdgeView();

    // Overrides
    virtual CDiagramEntity* Clone();
    static CDiagramEntity* CreateFromString(const CString& str);
    static	CDiagramEntity* CreateFromString(const CString& str, CProMoModel* model);
    static CDiagramEntity* Create(const CString& str);


protected:
    virtual void DrawHead(CDC* dc, CRect rect, double size);
    virtual void DrawTail(CDC* dc, CRect rect, double size);
    virtual void DrawLine(CDC* dc, CRect rect);

};

#endif //_WPDEMOEDGEVIEW_H_

