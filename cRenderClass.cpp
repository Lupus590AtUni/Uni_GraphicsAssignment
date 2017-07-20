// cRenderClass.cpp
// 
//////////////////////////////////////////////////////////////////////////////////////////
// includes 
//////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <iostream>
using std::cout;

//////////////////////////////////////////////////////////////////////////////////////////
// Declarations 
//////////////////////////////////////////////////////////////////////////////////////////
cRenderClass graphics( SCREEN_WIDTH, SCREEN_HEIGHT );

unsigned int	m_tex[256];

//////////////////////////////////////////////////////////////////////////////////////////
// cRenderClass() - constructor 
//////////////////////////////////////////////////////////////////////////////////////////
cRenderClass::cRenderClass(const int w, const int h)
{
	m_sw = w;
	m_sh = h;

	int total_count = w*h*4;

	m_buffer = new float[total_count];

	for( int i=0; i<total_count; i++ )
	{
		m_buffer[i] = 1;
	}

	m_point_size = 1;

	m_OPENGL_2_0_SUPPORTED = true;

	// generate a number of textures...
	glGenTextures(1, m_tex);
}

//////////////////////////////////////////////////////////////////////////////////////////
// cRenderClass() - destructor 
//////////////////////////////////////////////////////////////////////////////////////////
cRenderClass::~cRenderClass()
{
}

//////////////////////////////////////////////////////////////////////////////////////////
// loop() - enters game loop
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::loop()
{
	glutMainLoop();
}

extern cShaderInfo	ShaderInfo;

//////////////////////////////////////////////////////////////////////////////////////////
// initShaders() - init GLSL shaders
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::initShaders()
{
	GLenum err = glewInit();

	if( GLEW_OK != err )
	{
		printf("Error: Glew is not supported\n\n");
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	if (glewIsSupported("GL_VERSION_2_0"))
	{
		printf("OpenGL 2.0 is supported\n\n");
	}
	else
	{
		printf("Error: OpenGL 2.0 is not supported\n\n");
		m_OPENGL_2_0_SUPPORTED = false;
	}

	ShaderInfo.create();
}

//////////////////////////////////////////////////////////////////////////////////////////
// initialize glut stuff
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::create(int argc, _TCHAR* argv[])
{
	// initialise the glut library
	glutInit(&argc, argv);

	// set up the initial display mode
	// need both double buffering and z-buffering
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// set the initial window position
	glutInitWindowPosition(100, 100);

	// set the initial window size
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	// create and name the window
	glutCreateWindow("Using GLSL Shaders for Post Processing (Multi-Pass)!");

	// reshape callback for current window
	glutReshapeFunc(winReshapeFunc);

	// set display callback for current window
	glutDisplayFunc(renderScene);	
	// set up the global idle callback
	glutIdleFunc(update);

	initShaders();	  

    // This block copied from HPC boids cpu
    glutMouseFunc(click);
	glutKeyboardFunc(key);
	glutMotionFunc(mouse);
	glutPassiveMotionFunc(mouse);

	//note: do texture loading here

}

//////////////////////////////////////////////////////////////////////////////////////////
// drawPixel() - draw a pixel into an off-screen buffer
//				 if m_point_size>1 then draw a block of pixels
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::drawPixel(int x, int y)
{
	int start, end;

	start = -(m_point_size/2);
	end	= (int)((m_point_size/2.0f) + 0.5);

	for( int i=start; i<end; i++ )
	{
		for( int j=start; j<end; j++ )
		{
			// reject values outside m_buffer range
			if( (x+j < 0) || (x+j >= m_sw) )
				continue;

			if( (y+i < 0) || (y+i >= m_sh) )
				continue;

			m_buffer[(((y+i)*m_sw+(x+j))*4) + 0] = m_colour.r;
			m_buffer[(((y+i)*m_sw+(x+j))*4) + 1] = m_colour.g;
			m_buffer[(((y+i)*m_sw+(x+j))*4) + 2] = m_colour.b;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// setViewport2D() - sets up the viewport ready for a screen grab
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::setViewport2D()
{
	glLoadIdentity();
		
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, m_sw, 0, m_sh);
	glMatrixMode(GL_MODELVIEW);

	// set up the viewport
	glViewport
	(
		0,							// lower left x position
		0,							// lower left y position
		m_sw,	// viewport width
		m_sh	// viewport height
	);
}




//////////////////////////////////////////////////////////////////////////////////////////
// render() - 
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::render( )
{
	
	// BEFORE SHADER

	// disable shader program

	// clear the back buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	// copy contents from my own buffer
	glDrawPixels( m_sw, m_sh, GL_RGBA, GL_FLOAT, m_buffer );


	

	extern NA_HeatLamp heatLamp;
	extern NA_Pig pig;

	glUseProgram(0);
	

	heatLamp.draw();
	pig.draw();


	glUseProgram(0);

	// finally swap the buffers of the current window
	glutSwapBuffers();
	
	// clear out the temp buffer
	clear();
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// winReshapeFunc() - gets called initially and whenever the window get resized
// resizing has been locked
//////////////////////////////////////////////////////////////////////////////////////////
void winReshapeFunc(GLint w, GLint h)
{
	// specify current matrix
	glMatrixMode(GL_PROJECTION);

	// load an identity matrix
	glLoadIdentity();	

	// create a projection matrix... i.e. 2D projection onto xy plane
	glOrtho( -SCREEN_WIDTH, SCREEN_WIDTH, -SCREEN_HEIGHT, SCREEN_HEIGHT, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// set up the viewport
	glViewport
	(
		0,				// lower left x position
		0,				// lower left y position
		(GLsizei) SCREEN_WIDTH,	// viewport width
		(GLsizei) SCREEN_HEIGHT	// viewport height
	);
}

// All of below copied from HPC boids cpu




void debugMouse()
{
	extern cRenderClass graphics;
	cout << "Mouse:\n";
	cout << " raw pos : " << graphics.mouseRaw.x << ", " << graphics.mouseRaw.y << "\n";
	cout << " adjusted pos : " << graphics.mousePos.x << ", " << graphics.mousePos.y << "\n";
	
	/*
	//draw a dot under the mouse for debugging
	graphics.setColour(0.0f, 0.0f, 1.0f);
	graphics.setPointSize(3);
	graphics.drawPixel(graphics.mousePos.x, graphics.mousePos.y);
	graphics.setColour(1.0f, 0.0f, 0.0f);
	graphics.setPointSize(1);
	graphics.drawPixel(graphics.mousePos.x, graphics.mousePos.y);
	*/
}



void mouse(int x, int y)
{
	

	graphics.mouseRaw.x = x;
	graphics.mouseRaw.y = y;

	//https://www.gamedev.net/topic/507797-moving-objects-with-the-mouse-in-3d/
	//https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluUnProject.xml
	// https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glGet.xml

	GLdouble modelMatix[16];
	GLdouble projMatix[16];
	GLint viewport[4];

	
	glGetDoublev(GL_MODELVIEW_MATRIX, modelMatix);
	glGetDoublev(GL_PROJECTION_MATRIX, projMatix);
	glGetIntegerv(GL_VIEWPORT, viewport);

	

	GLdouble fixedX;
	GLdouble fixedY;
	GLdouble fixedZ;

	

	if (gluUnProject(graphics.mouseRaw.x, graphics.mouseRaw.y, 0, modelMatix, projMatix, viewport, &fixedX, &fixedY, &fixedZ) == GL_FALSE)
	{
		cout << "cRenderClass - mouse func - gluUnProject returned false\n";
		return;
	}

	

	graphics.mousePos.x = (float)fixedX;
	graphics.mousePos.y = (float)fixedY*-1;
}

void key(unsigned char c, int x, int y)
{
	// allow rotation of pig, this was helpful for texture debugging
	extern NA_Pig pig;
	switch (c)
	{
		case 'w':
		case 'W':
			pig.rotation.y = pig.rotation.y - 10.0f;
			break;
		case 's':
		case 'S':
			pig.rotation.y = pig.rotation.y + 10.0f;
			break;
		case 'a':
		case 'A':
			pig.rotation.x = pig.rotation.x + 10.0f;
			break;
		case 'd':
		case 'D':
			pig.rotation.x = pig.rotation.x - 10.0f;
			break;
	}

}

void click(int button, int state, int x, int y)
{

}