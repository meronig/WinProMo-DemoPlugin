/* ==========================================================================

	Copyright © 2026 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPDEMOCONTROLFACTORY_H_
#define _WPDEMOCONTROLFACTORY_H_

#include "../../../WinProMo/src/DiagramEditor/DiagramEntity.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoControlFactory.h"

class AFX_EXT_CLASS CWPDemoControlFactory :
	public CProMoControlFactory {

public:
	// Implementation
	virtual CDiagramEntity* CreateViewFromString(const CString& str);
	virtual CDiagramEntity* CreateViewFromString(const CString& str, CProMoModel* model);
	virtual CProMoModel* CreateModelFromString(const CString& str);
	virtual CDiagramEntity* CreateNewEntity(const CString& str);
	virtual void GetEntityTypes(CStringArray& typeList);

};

#endif // _WPDEMOCONTROLFACTORY_H_
