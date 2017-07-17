#include "stdafx.h"
#include "NA_Pig.h"
#include "cRenderClass.h"

#define STB_IMAGE_IMPLEMENTATION
#include "tgaLoader.h"

NA_Pig::NA_Pig()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
}

NA_Pig pig;

NA_Pig::~NA_Pig()
{
	if (rawLoadedTexture != NULL)
	{
		STBI_FREE(rawLoadedTexture);
		rawLoadedTexture = NULL;
	}
	if (heatValuesPsudoTexture != NULL)
	{
		delete(heatValuesPsudoTexture);
		heatValuesPsudoTexture = NULL;
	}
}

void NA_Pig::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(pos.x, pos.y, pos.z);
	glShadeModel(GL_SMOOTH);
	
	extern cRenderClass graphics;

	//Shader Stuff
	//cShader *pList = graphics.ShaderInfo.getList();
	//int shdr = 1;

	//if (shdr >= graphics.ShaderInfo.shaderCount())
	//{
	//	printf("Error: Can't access requested shader\n");
	//	shdr = 0;
	//}

	//// enable shader program..
	//glUseProgram(pList[shdr].program());

	//glUniform1fv(glGetAttribLocation(shaderID, variableNameAsString), sizeOfArray, valueAsArray)
	//glUniform1f(glGetAttribLocation(shaderID, variableNameAsString), value);

	//glUseProgram(shaderID);


	

	
	
	


	



	//glutSolidSphere(12, 120, 2);
	int size = 50;
	glScaled(size, size, size);

	

	

	// MATERIAL PROPERTISE
	GLfloat ambient[4] = { 1.0,1.0,1.0,1.0 };
	GLfloat diffuse[4] = { 1.0,1.0,1.0,1.0 };
	GLfloat specular[4] = { 1.0,1.0,1.0,1.0 };

	//glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

	// activate texture for application is shader
	//https://www.opengl.org/archives/resources/code/samples/glut_examples/examples/examples.html
	glEnable(GL_TEXTURE_2D);

	//apparently the shader needs this
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 4, 4, 0, GL_RGBA, GL_UNSIGNED_BYTE, rawLoadedTexture);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCREEN_WIDTH*SCREEN_HEIGHT, 0, 0, GL_RGB, GL_UNSIGNED_BYTE, &heatValuesPsudoTexture);

	glActiveTexture(pigObj.id_texture); //the shader can use this texture
	glActiveTexture(heatValuesTexID);

	cShader *pList = graphics.ShaderInfo.getList();
	glUseProgram( pList[1].program()); //shader on: no pig // fixed, was vertex shader being empty, replaced it with intensity.vert
										//shader off: ambient light only (tiny amount of diffuse or an illusion?)
	extern NA_MathsLib na_maths;
	float intensity = (float) na_maths.dice(100);

	glUniform1i(pList[1].get_grabLoc(), pigObj.id_texture);
	glUniform1f(pList[1].intensity(), intensity);
	glUniform1f(pList[1].get_heatValueGrabLoc(), heatValuesTexID);

	//glutSolidSphere(2, 15, 2);
	pigObj.render();
	
	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE_2D);
	glUseProgram(0); //disable pig heatlamp shader
	glPopMatrix();
	
}

void NA_Pig::init()
{

	int x, y, comp;
	
	rawLoadedTexture =  stbi_load("Pig/pig.bmp", &x, &y, &comp, 4);
	if (rawLoadedTexture == NULL)
		std::cout << "NA_Pig::init - stbi_load returned null\n";

	//https://open.gl/textures
	//https://open.gl/content/code/c3_multitexture.txt

	//texturing stuff
	glActiveTexture(GL_TEXTURE1);
	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D_ARRAY_EXT, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	float color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, rawLoadedTexture);

	//heat lamp psudo texture
	glActiveTexture(GL_TEXTURE2);
	GLuint heat;
	glGenTextures(1, &heat);
	glBindTexture(GL_TEXTURE_2D_ARRAY_EXT, heat);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	float heatColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, heatColor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	heatValuesPsudoTexture = new unsigned char[SCREEN_HEIGHT*SCREEN_WIDTH];
	memset(heatValuesPsudoTexture, 255, sizeof(unsigned char)*SCREEN_HEIGHT*SCREEN_WIDTH);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCREEN_WIDTH*SCREEN_HEIGHT, 0, 0, GL_RGB, GL_UNSIGNED_BYTE, &heatValuesPsudoTexture);
	heatValuesTexID = GL_TEXTURE2;

	pigObj.objloader("Pig/pig.obj");
	pigObj.id_texture = GL_TEXTURE1; //https://gamedev.stackexchange.com/questions/144828/why-is-my-texture-not-applied-correctly-in-opengl-2-0-with-glsl

	extern NA_MathsLib na_maths;
	na_maths.seedDice();
}

//void NA_Pig::loadShader()
//{
//	//https://www.opengl.org/sdk/docs/tutorials/ClockworkCoders/loading.php
//
//	const string shaderPath = "\\Shader Files\\heat-lamp";
//	const string vertexShaderExtention = ".vert";
//	const string fragmentShaderExtention = ".frag";
//
//	// Create containers for shaders
//	//OLD_TODO: these may need to be in the class
//	GLuint vertexShaderObject = glCreateShader(GL_VERTEX_SHADER);
//	GLuint fragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);
//
//	//OLD_TODO: read in shader from file
//
//	// Attach source files
//	glShaderSourceARB(vertexShaderObject, 1, &VertexShaderSource, &vlength);
//	glShaderSourceARB(fragmentShaderObject, 1, &FragmentShaderSource, &flength);
//
//	//Compile the shaders
//	glCompileShaderARB(vertexShaderObject);
//	glCompileShaderARB(fragmentShaderObject);
//
//	//Check that compile was ok
//	GLint vertexCompiled;
//
//	glGetShaderiv(vertexShaderObject, GL_COMPILE_STATUS, &vertexCompiled); //https://www.khronos.org/opengl/wiki/Shader_Compilation
//	if (vertexCompiled == GL_FALSE)
//	{
//		// yes it compiled!
//	}
//
//	GLint fragmentCompiled;
//
//	glGetShaderiv(fragmentShaderObject, GL_COMPILE_STATUS, &fragmentCompiled); //https://www.khronos.org/opengl/wiki/Shader_Compilation
//	if (fragmentCompiled == GL_FALSE)
//	{
//		// yes it compiled!
//	}
//}
