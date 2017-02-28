#include "stdafx.h"
#include "NA_Pig.h"
#include "cRenderClass.h"

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

	
	extern cRenderClass graphics;

	//TODO: load up and configure shader

	//glUniform1fv(glGetAttribLocation(shaderID, variableNameAsString), sizeOfArray, valueAsArray)
	//glUniform1f(glGetAttribLocation(shaderID, variableNameAsString), value);

	//glUseProgram(shaderID);

	//TODO: somewhere I have to map a texture
	//TODO: and load a pig with texture
	//TODO: and render that pig - I hate graphics

	glutSolidSphere(12, 120, 2);

	glUseProgram(0); //disable pig heatlamp shader
	glTranslatef(-pos.x, -pos.y, -pos.z);
	
}
