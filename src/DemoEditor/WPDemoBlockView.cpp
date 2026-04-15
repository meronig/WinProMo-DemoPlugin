/* ==========================================================================

    Copyright © 2025-26 Technical University of Denmark

    CWPDemoBlockView

    Author :		Giovanni Meroni

    Purpose :		CWPDemoBlockView implements CProMoBlockView
                    for the WinProMo Demo Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPDemoBlockView.h"
#include "WPDemoBlockModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"
#include <math.h>
#include "../../../WinProMo/src/GeometryUtils/DoublePoint.h"
#include "../../../WinProMo/src/GeometryUtils/IntersectionHelper.h"

CWPDemoBlockView::CWPDemoBlockView()
/* ============================================================
    Function :		CWPDemoBlockView::CWPDemoBlockView
    Description :	Constructor
    Access :		Public

    Return :		void
    Parameters :	none

    Usage :			Override to set the type of the view element to a
                    unique string, (e.g., "my_block_view") and call
					SetModel to associate a model (derived from 
					CProMoBlockModel) to the view. Implement here 
					the logic to customize the shape of the block view.

============================================================*/
{
	// set the minimum and maximum size of the block view. 
    // The default is (0, 0) for minimum and (-1, -1) for maximum, 
    // which means that there are no constraints.
    SetConstraints(CSize(128, 32), CSize(-1, -1));
    
    SetType(_T("promo_block_view"));
    SetModel(new CWPDemoBlockModel());

    // customize the shape of the block view as a rectangle.
    SetShape(SHAPE_RECTANGLE);
	
    // set the default fill color of the block view to light green.
	SetFillColor(RGB(200, 255, 200));
}

CWPDemoBlockView::~CWPDemoBlockView()
/* ============================================================
    Function :		CWPDemoBlockView::~CWPDemoBlockView
    Description :	Destructor
    Access :		Public

    Return :		void
    Parameters :	none

============================================================*/
{
}

CDiagramEntity* CWPDemoBlockView::Clone()
/* ============================================================
    Function :		CWPDemoBlockView::Clone
    Description :	Clones this object and returns a new one.
    Access :		Public

    Return :		CProMoModel*	-	The resulting clone
    Parameters :	none

    Usage :			Call to clone the current object.

============================================================*/
{
    CWPDemoBlockView* obj = new CWPDemoBlockView;
    obj->Copy(this);
    obj->SetName(CProMoNameFactory::GetID());
    return obj;
}

CDiagramEntity* CWPDemoBlockView::CreateFromString(const CString& str)
/* ============================================================
    Function :		CWPDemoBlockView::CreateFromString
    Description :	Static factory function that creates and
                    returns an instance of this class if "str"
                    is a valid representation.
    Access :		Public

    Return :		CProMoModel*		-	The object, or "NULL"
                                            if "str" is not a
                                            representation of
                                            this type.
    Parameters :	const CString& str	-	The string to create
                                            from.

    Usage :			Can be used as a factory for text file loads.
                    Each object type should have its own
                    version - the default one is a model
                    implementation.

   ============================================================*/
{

    CWPDemoBlockView* obj = new CWPDemoBlockView;
    if (!obj->FromString(str))
    {
        delete obj;
        obj = NULL;
    }

    return obj;

}

CDiagramEntity* CWPDemoBlockView::CreateFromString(const CString& str, CProMoModel* model)
/* ============================================================
    Function :		CWPDemoBlockView::CreateFromString
    Description :	Static factory function that creates and
                    returns an instance of this class if "str"
                    is a valid representation.

    Return :		CDiagramEntity*		-	The object, or NULL
                                            if "str" is not a
                                            representation of
                                            this type.
    Parameters :	const CString& str	-	The string to create
                                            from.
                    CProMoModel* model	-	A model to be
                                            associated to the
                                            object being created.

    Usage :			Can be used as a factory for text file loads.
                    Each object type should have its own
                    version - the default one is a model
                    implementation.

   ============================================================*/
{

    CWPDemoBlockView* obj = new CWPDemoBlockView;
    if (!obj->FromString(str))
    {
        delete obj;
        obj = NULL;
    }
    else {
        CWPDemoBlockModel* blockModel = dynamic_cast<CWPDemoBlockModel*>(model);

        if (blockModel) {
            obj->SetModel(blockModel);
        }
    }

    return obj;

}

CDiagramEntity* CWPDemoBlockView::Create(const CString& str)
/* ============================================================
    Function :		CWPDemoBlockView::Create
    Description :	Creates an object of this type if the type
                    matches.
    Return :		CDiagramEntity*	-	The created object, or
                                        NULL if the type did
                                        not match.
    Parameters :	const CString& str	-	The type to create.
    Usage :			Static function used by the
                    "CProMoControlFactory" to create objects
                    of this type.
   ============================================================*/
{
    CWPDemoBlockView* obj = new CWPDemoBlockView;
    if (!obj->HasType(str))
    {
        delete obj;
        obj = NULL;
    }
    return obj;
}

void CWPDemoBlockView::DrawShape(CDC* dc, CRect& rect)
/* ============================================================
    Function :		CWPDemoBlockView::DrawShape
    Description :	Draws the shape of the block.

    Return :		void
    Parameters :	CDC* dc		-	The CDC to draw to.
                    CRect rect	-	The real rectangle of the
                                    object.

	Usage :			Override to customize the shape	being drawn 
                    (e.g., to overlay an icon on top of the 
                    default shape).
					If the shape is a rectangle, a polygon, or an 
					ellipse, there is no need to override this 
					function, as the drawing logic is already 
                    implemented in the base class.

   ============================================================*/
{
	CProMoBlockView::DrawShape(dc, rect);
    
}