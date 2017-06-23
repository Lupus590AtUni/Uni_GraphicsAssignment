#include "stdafx.h"
#include "NA_ObjLoader.h"
#include <fstream>
#include <iostream>
#include <string> // std::getLine

NA_ObjLoader na_objLoader; // access with extern NA_ObjLoader na_objLoader

NA_ObjLoader::NA_ObjLoader()
{
}


NA_ObjLoader::~NA_ObjLoader()
{
}

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
		std::cout << "Failed to open file " << fileName << "\n";
		return false;
	}

	// load file via iostream into std::vector
	while (!objFile.eof())
	{
		string line;
		objFile >> line;
		std::cout << line;
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
