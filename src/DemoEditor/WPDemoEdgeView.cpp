/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPDemoEdgeView

	Author :		Giovanni Meroni

	Purpose :		CWPDemoEdgeView implements CProMoEdgeView
					for the WinProMo Demo Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPDemoEdgeView.h"
#include "WPDemoEdgeModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"

CWPDemoEdgeView::CWPDemoEdgeView()
/* ============================================================
	Function :		CWPDemoEdgeView::CWPDemoEdgeView
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Override to set the type of the view element to a
					unique string, (e.g., "my_edge_view") and call
					SetModel to associate a model (derived from
					CProMoEdgeModel) to the view. Implement here
					the logic to customize the default visual 
					appearance of the edge view.

============================================================*/
{
	SetType(_T("promo_edge_view"));
	SetModel(new CWPDemoEdgeModel());

	// Set the default line color to blue, and line width to 2 pixels.
	SetLineColor(RGB(0, 0, 255));
	SetLineWidth(2);
}

CWPDemoEdgeView::~CWPDemoEdgeView()
/* ============================================================
	Function :		CWPDemoEdgeView::~CWPDemoEdgeView
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

============================================================*/
{
}

CDiagramEntity* CWPDemoEdgeView::Clone()
/* ============================================================
	Function :		CWPDemoEdgeView::Clone
	Description :	Clones this object and returns a new one.
	Access :		Public

	Return :		CProMoModel*	-	The resulting clone
	Parameters :	none

	Usage :			Call to clone the current object.

============================================================*/
{
	CWPDemoEdgeView* obj = new CWPDemoEdgeView;
	obj->Copy(this);
	obj->SetName(CProMoNameFactory::GetID());
	return obj;
}

void CWPDemoEdgeView::DrawLine(CDC* dc, CRect rect)
/* ============================================================
	Function :		CWPDemoEdgeView::DrawLine
	Description :	Draws the line of the edge.

	Return :		void
	Parameters :	CDC* dc		-	The CDC to draw to.
					CRect rect	-	The real rectangle of the
									object.
	Usage :			The default implementation draws a line with the
					current line color, width, and style.
					Override this function to change the way the
					line of the edge is drawn (e.g., to overlay an 
					icon on top of the line).
					In most cases, there is no need to override this 
					function.

   ============================================================*/
{
	CProMoEdgeView::DrawLine(dc, rect);
}

void CWPDemoEdgeView::DrawHead(CDC* dc, CRect rect, double size)
/* ============================================================
	Function :		CWPDemoEdgeView::DrawHead
	Description :	Draws the head of the edge.
	Access :		Protected

	Return :		void
	Parameters :	CDC* dc		-	The CDC to draw to.
					CRect rect	-	The real rectangle of the
									object.
					double size	-	The size of the head

	Usage :			The default implementation draws a solid
					triangle for the head of the edge.
					Override this function to change the shape
					being drawn for the head of the edge.

   ============================================================*/
{
	CProMoEdgeView::DrawHead(dc, rect, size);
}

void CWPDemoEdgeView::DrawTail(CDC* dc, CRect rect, double size)
/* ============================================================
	Function :		CWPDemoEdgeView::DrawTail
	Description :	Draws the tail of the edge.
	Access :		Protected

	Return :		void
	Parameters :	CDC* dc		-	The CDC to draw to.
					CRect rect	-	The real rectangle of the
									object.
					double size	-	The size of the tail

	Usage :			The default implementation draws a solid
					circle for the tail of the edge.
					Override this function to change the shape
					being drawn for the tail of the edge.

   ============================================================*/
{
	CProMoEdgeView::DrawTail(dc, rect, size);
}

CDiagramEntity* CWPDemoEdgeView::CreateFromString(const CString& str)
/* ============================================================
	Function :		CWPDemoEdgeView::CreateFromString
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

	CWPDemoEdgeView* obj = new CWPDemoEdgeView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

CDiagramEntity* CWPDemoEdgeView::CreateFromString(const CString& str, CProMoModel* model)
/* ============================================================
	Function :		CWPDemoEdgeView::CreateFromString
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

	CWPDemoEdgeView* obj = new CWPDemoEdgeView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}
	else {
		CWPDemoEdgeModel* blockModel = dynamic_cast<CWPDemoEdgeModel*>(model);

		if (blockModel) {
			obj->SetModel(blockModel);
		}
	}

	return obj;

}

CDiagramEntity* CWPDemoEdgeView::Create(const CString& str)
/* ============================================================
	Function :		CWPDemoEdgeView::Create
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
	CWPDemoEdgeView* obj = new CWPDemoEdgeView;
	if (!obj->HasType(str))
	{
		delete obj;
		obj = NULL;
	}
	return obj;
}