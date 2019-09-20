#ifndef GRAFICI_GFX_DATA_FLOAT_H
#define GRAFICI_GFX_DATA_FLOAT_H

#include "../Data.h"

#ifndef NULL
#define NULL (0)
#endif

#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif


class DataSetFloat : public DataSet
{
public:

	void begin(float *yDataPoint, float zDataPoint, int len);
	void begin(float *yDataPoint, float *zDataPoint, int len);
	void begin(float *xDataPoint, float *yDataPoint, float zDataPoint, int len);
	void begin(float *xDataPoint, float *yDataPoint, float *zDataPoint, int len);
	
	DataPoint getDataPoint(int index);
	void refresh();
	int size(void);

private:
	float *xDataPoint;
	float *yDataPoint;
	float *zDataPoint;
	float zValue;
	float xMin;
	float yMin;
	float zMin;
	float xMax;
	float yMax;
	float zMax;
	
	int numElem;
};

void DataSetFloat::begin(float *yDataPoint, float zValue, int len)
{
	this->xDataPoint = NULL;
	this->yDataPoint = yDataPoint;
	this->zDataPoint = NULL;
	this->zValue = zValue;
	this->numElem = len;
	refresh();
};

void DataSetFloat::begin(float *yDataPoint, float *zDataPoint, int len)
{
	this->xDataPoint = NULL;
	this->yDataPoint = yDataPoint;
	this->zDataPoint = zDataPoint;
	this->zValue = 0;
	this->numElem = len;
	refresh();
};

void DataSetFloat::begin(float *xDataPoint, float *yDataPoint, float zValue, int len)
{
	this->xDataPoint = xDataPoint;
	this->yDataPoint = yDataPoint;
	this->zDataPoint = NULL;
	this->zValue = zValue;
	this->numElem = len;
	refresh();
};

void DataSetFloat::begin(float *xDataPoint, float *yDataPoint, float *zDataPoint, int len)
{
	this->xDataPoint = xDataPoint;
	this->yDataPoint = yDataPoint;
	this->zDataPoint = zDataPoint;
	this->zValue = 0;
	this->numElem = len;
	refresh();
};

DataPoint DataSetFloat::getDataPoint(int index)
{
	DataPoint p;
	if (index < numElem)
	{
		// normalize dataset to a 0.0 .. 1.0 value
		p.y = (yDataPoint[index] - yMin) / (yMax - yMin);

		if (xDataPoint != NULL)
		{
			p.x = (xDataPoint[index] - xMin) / (xMax - xMin);
		}
		else
		{
			p.x = (1.0 * index) / (numElem - 1);
		}

		//rewrite ho zdata is defined
		if (zDataPoint != NULL)
		{
			p.z = (zDataPoint[index] - zMin) / (zMax - zMin);
		}
		else
		{
			p.z = zValue;
		}
	}
	return p;
}

int DataSetFloat::size(void)
{
	return numElem;
}

void DataSetFloat::refresh(void)
{
	if (numElem > 0)
	{
		if (yDataPoint != NULL)
		{
			yMin = yMax = yDataPoint[0];
			for (int i = 1; i < numElem; ++i)
			{
				yMin = min(yMin, yDataPoint[i]);
				yMax = max(yMax, yDataPoint[i]);
			}
		}

		if (xDataPoint != NULL)
		{
			xMin = xMax = xDataPoint[0];
			for (int i = 1; i < numElem; ++i)
			{
				xMin = min(xMin, xDataPoint[i]);
				xMax = max(xMax, xDataPoint[i]);
			}
		}

		if (zDataPoint != NULL)
		{
			zMin = zMax = zDataPoint[0];
			for (int i = 1; i < numElem; ++i)
			{
				zMin = min(zMin, zDataPoint[i]);
				zMax = max(zMax, zDataPoint[i]);
			}
		}
	}
}


#endif //GRAFICI_GFX_DATA_FLOAT_H