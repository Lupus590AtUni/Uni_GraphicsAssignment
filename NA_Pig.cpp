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






	//glutSolidSphere(12, 120, 2);
	glScaled(20, 20, 20);

	//TODO: apply texture
	pigObj.render();
	

	glUseProgram(0); //disable pig heatlamp shader
	glPopMatrix();
	
}

void NA_Pig::init()
{
	//TODO: load texture

	int x, y, comp;
	
	unsigned char* data =  stbi_load("Pig/pig.tga", &x, &y, &comp, 0);
	if (data == NULL)
		std::cout << "NA_Pig::init - stbi_load returned null\n";

	//https://open.gl/textures
	//https://open.gl/content/code/c3_multitexture.txt
	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glGenerateMipmap(GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	pigObj.objloader("Pig/pig.obj");
	pigObj.id_texture = tex;
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
