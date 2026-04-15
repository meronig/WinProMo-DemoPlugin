/* ==========================================================================

    Copyright © 2026 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPDEMOEDGEMODEL_H_
#define _WPDEMOEDGEMODEL_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoEdgeModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoLabel.h"

class AFX_EXT_CLASS CWPDemoEdgeModel :
    public CProMoEdgeModel
{
public:
    CWPDemoEdgeModel();
    virtual ~CWPDemoEdgeModel();

    //Overrides
    virtual CProMoModel* Clone();

    virtual BOOL CanConnectSource(CProMoBlockModel* source) const;
    virtual BOOL CanConnectDestination(CProMoBlockModel* destination) const;
    static	CProMoModel* CreateFromString(const CString& str);

    virtual void OnPropertyChanged(CProMoProperty* prop);

protected:
    virtual void CreateProperties();
    virtual void CustomizeLabel(CProMoLabel* label);

};

#endif //_WPDEMOEDGEMODEL_H_

