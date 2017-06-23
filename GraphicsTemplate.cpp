// GraphicsTemplate.cpp
// 
//////////////////////////////////////////////////////////////////////////////////////////
// includes 
//////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////////////////////
// externals 
//////////////////////////////////////////////////////////////////////////////////////////
extern cRenderClass graphics;

//////////////////////////////////////////////////////////////////////////////////////////
// renderScene() - render the scene
//////////////////////////////////////////////////////////////////////////////////////////
void renderScene()
{
	
	graphics.render();

}

//////////////////////////////////////////////////////////////////////////////////////////
// update() - update function
//////////////////////////////////////////////////////////////////////////////////////////
NA_HeatLamp heatLamp;
void update()
{
	// add any update code here...

	heatLamp.pos.x = graphics.mousePos.x;
	heatLamp.pos.y = graphics.mousePos.y;
	heatLamp.pos.z = 0;


	// always re-render the scene..
	renderScene();
}


// https://stackoverflow.com/questions/143174/how-do-i-get-the-directory-that-a-program-is-running-from
#include <direct.h>
#define GetCurrentDir _getcwd

#include <string>
#include <windows.h>

std::string getexepath()
{
	char result[MAX_PATH];
	return std::string(result, GetModuleFileName(NULL, result, MAX_PATH));
}

//////////////////////////////////////////////////////////////////////////////////////////
// _tmain() - program entry point
//////////////////////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{	
	/*vector<glm::vec4>* vertices = new vector<glm::vec4>;
	vector<glm::vec3>* normals = new vector<glm::vec3>;
	vector<GLushort>* element = new vector<GLushort>;*/

	char r[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, r);
	std::cout << GetCurrentDir(NULL, 0) << "\n" << getexepath() << "\n" << r << "\n";

	extern NA_ObjLoader na_objLoader;

	NA_Obj temp;
	if (!na_objLoader.load("Pig/Cube.obj", &temp))
		return 1;

	return 0;

	// init glut stuff..
	graphics.create(argc, argv);

	// good place for one-off initialisations and objects creation..
	extern NA_Pig pig;
	pig.init();

	// enter game loop..
	graphics.loop();	

	return 0;
}




