#ifndef ARDU_DATAVIS_DRIVER_H
#define ARDU_DATAVIS_DRIVER_H

#include "Style.h"

class Driver
{
  public:
	void drawPixel(float x, float y, Color color);
	void drawLine(float x0, float y0, float x1, float y1, Color color);
	void drawCircle(float x0, float y0, float r, Color color);
	void drawRect(float x, float y, float w, float h, Color color);
	void fillRect(float x, float y, float w, float h, Color color);
	void fillCircle(float x0, float y0, float r, Color color);
};

#endif //ARDU_DATAVIS_DRIVER_H
