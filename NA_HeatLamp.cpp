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
	glPushMatrix();

	// fixes heat lamp tuning red
	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE_2D);
	glUseProgram(0);

	glLoadIdentity();
	glTranslatef(pos.x, pos.y, pos.z);
	glutSolidSphere(radius, 15, 2);

	extern cRenderClass graphics;

	glPopMatrix();

	//http://www.glprogramming.com/red/chapter05.html
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light0_position[] = { pos.x , pos.y, pos.z, 0.0 };
	GLfloat light1_position[] = { 10.0 , 0.0, 0.0, 0.0 };

//#include <iostream>
	//std::cout << "Light Pos: " << pos.x << ", "<<pos.y<<", "<<pos.z<<"\n";


	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	//glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);


	
	
}
