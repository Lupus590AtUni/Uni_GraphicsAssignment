#include "stdafx.h"
#include "NA_Pig.h"
#include "cRenderClass.h"

NA_Pig::NA_Pig()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
}

NA_Pig pig;

NA_Pig::~NA_Pig()
{
}

void NA_Pig::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(pos.x, pos.y, pos.z);

	
	extern cRenderClass graphics;

	//Shader Stuff
	//cShader *pList = graphics.ShaderInfo.getList();
	//int shdr = 2;

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


	

	//float intensity = 0.25f;

	//glUniform1i(pList[shdr].get_grabLoc(), (int)m_tex[0]);
	//glUniform1f(pList[shdr].intensity(), intensity);
	//
	//glUseProgram(0);//disable the shader





	//TODO: somewhere I have to map a texture
	//TODO: and load a pig with texture
	//TODO: and render that pig - I hate graphics

	//glutSolidSphere(12, 120, 2);
	glScaled(0.5, 0.5, 0.5);
	pigObj.render();
	

	glUseProgram(0); //disable pig heatlamp shader
	glPopMatrix();
	
}

void NA_Pig::init()
{
	pigObj.objloader("Pig/pig.obj");
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
