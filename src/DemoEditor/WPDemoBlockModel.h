/* ==========================================================================

    Copyright © 2026 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPDEMOBLOCKMODEL_H_
#define _WPDEMOBLOCKMODEL_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoBlockModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoLabel.h"

class AFX_EXT_CLASS CWPDemoBlockModel :
    public CProMoBlockModel
{
public:
    CWPDemoBlockModel();
    virtual ~CWPDemoBlockModel();

    //Overrides
    virtual CProMoModel* Clone();

    virtual BOOL CanBeSubBlockOf(CProMoBlockModel* block) const;
    virtual BOOL CanBeBoundaryOf(CProMoBlockModel* block, unsigned int alignment) const;
    static	CProMoModel* CreateFromString(const CString& str);

protected:
    virtual void CreateProperties();
    virtual void CustomizeLabel(CProMoLabel* label);

};

#endif //_WPDEMOBLOCKMODEL_H_

