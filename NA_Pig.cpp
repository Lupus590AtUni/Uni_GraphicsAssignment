#include "stdafx.h"
#include "NA_Pig.h"


NA_Pig::NA_Pig()
{
	pos.x = 250;
	pos.y = 250;
	pos.z = 0;
}

NA_Pig pig;

NA_Pig::~NA_Pig()
{
}

void NA_Pig::draw()
{
	
	glTranslatef(pos.x, pos.y, pos.z);
	glutSolidSphere(12, 120, 2);
	glTranslatef(-pos.x, -pos.y, -pos.z);
	
}
