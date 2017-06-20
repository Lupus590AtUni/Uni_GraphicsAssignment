#include "stdafx.h"
#include "NA_ObjLoader.h"

NA_ObjLoader na_objLoader; // access with extern NA_ObjLoader na_objLoader

NA_ObjLoader::NA_ObjLoader()
{
}


NA_ObjLoader::~NA_ObjLoader()
{
}

NA_Obj NA_ObjLoader::load(string fileName)
{
	// load file via iostream into std::vector

	// seperate components based of first char of line into 3 seperate std::vectors

	// pack std::vectors into NA_Obj (convert to arrays first?)
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
