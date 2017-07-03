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
	glLoadIdentity();
	glTranslatef(pos.x, pos.y, pos.z);
	glutSolidSphere(radius, 120, 2);

	extern cRenderClass graphics;

	//http://www.glprogramming.com/red/chapter05.html
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light0_position[] = { graphics.mousePos.x , graphics.mousePos.y, 1.0, 0.0 };
	GLfloat light1_position[] = { 10.0 , 0.0, 0.0, 0.0 };

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	//glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);


	glPopMatrix();
	
}
