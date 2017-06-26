#include "stdafx.h"
#include "NA_ObjLoader.h"
#include <fstream>
#include <iostream>
#include <string> // std::getLine
#include <vector>
using std::vector;

NA_ObjLoader na_objLoader; // access with extern NA_ObjLoader na_objLoader

NA_ObjLoader::NA_ObjLoader()
{
}


NA_ObjLoader::~NA_ObjLoader()
{
}

// https://stackoverflow.com/questions/143174/how-do-i-get-the-directory-that-a-program-is-running-from
#include <direct.h>
#define GetCurrentDir _getcwd

bool NA_ObjLoader::load(string fileName, NA_Obj* objOut)
{
	// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/

	// check for valid output
	if (objOut == NULL)
	{
		std::cout << "NA_ObjLoader::load - pointer to output is NULL\n";
		return false;
	}

	// open the file
	std::ifstream objFile;

	
	objFile.open(fileName);
	if (!objFile.is_open())
	{
		std::cout << "Failed to open file " << GetCurrentDir(NULL, 0) << "/" << fileName << "\n"; //BUG: no matter what I point this too it fails to open
		return false;
	}

	// load file via iostream into std::vector
	std::vector<string> temp;
	while (!objFile.eof())
	{
		string line;
		objFile >> line;
		std::cout << line;
		temp.push_back(line); //TODO: check that this copies line and doesn't just reference it
	}
	objFile.close();
	

	// seperate components based of first char of line into 3 seperate std::vectors

	// pack std::vectors into NA_Obj (convert to arrays first?)
	return true;
}

NA_Obj::NA_Obj()
{
}

NA_Obj::~NA_Obj()
{
	if (vertex != NULL)
	{
		delete vertex;
		vertex = NULL;
		vertexCount = 0;
	}
	if (normal != NULL)
	{
		delete normal;
		normal = NULL;
		normalCount = 0;
	}
	if (face != NULL)
	{
		delete face;
		face = NULL;
		faceCount = 0;
	}
}

NA_Tri NA_Obj::getFace(int faceID)
{
	//TODO: NA_Obj::getFace

	return NA_Tri();
}
