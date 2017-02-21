#include "stdafx.h"
#include "NA_Pig.h"
#include "cRenderClass.h"
#include "cShader.h"

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

	//TODO: activate shader here?
	extern cRenderClass graphics;

	cShader *pList = graphics.ShaderInfo.getList();
	glUseProgram(pList[pigShader].program());

	glutSolidSphere(12, 120, 2);

	glUseProgram(0); //disable pig heatlamp shader
	glTranslatef(-pos.x, -pos.y, -pos.z);
	
}
