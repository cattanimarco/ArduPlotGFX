#ifndef ARDU_DATAVIS_VISITOR_DRAW_H
#define ARDU_DATAVIS_VISITOR_DRAW_H

#include "Geometry.h"
#include "Driver.h"
#include "Data.h"

class VisitorDraw 
{
public:
	VisitorDraw();
	VisitorDraw(Driver *driver);

	void visit(Data *data, Line *const boundaries);
	void visit(Data *data, Rectangle *const boundaries);
	void visit(Data *data, Circle *const boundaries);

	Driver *driver;
};

#endif //ARDU_DATAVIS_VISITOR_DRAW_H