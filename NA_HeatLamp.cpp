#include "stdafx.h"
#include "NA_HeatLamp.h"


NA_HeatLamp::NA_HeatLamp()
{
	radius = 12;
	heat = 12;
}



NA_HeatLamp::~NA_HeatLamp()
{
}

void NA_HeatLamp::draw()
{
	
	glutSolidSphere(radius, 120, 2);
}
