#pragma once

// unused and incomplete code


#include "stdafx.h"
#define GLM_FORCE_RADIANS 
#include "glm/glm.hpp"

using glm::vec3;

struct NA_Tri
{
	vec3 x;
	vec3 y;
	vec3 z;
};

class NA_Obj
{
public:
	NA_Obj();
	~NA_Obj();
	NA_Tri getFace(int faceID);
	
	//TODO: change this
	int vertexCount;
	vec3* vertex = NULL;
	int normalCount;
	vec3* normal = NULL;
	int faceCount;
	int* face = NULL; //how will this work? use array of ints to form triangles, use it to index vertex?
};

class NA_ObjLoader
{
public:
	NA_ObjLoader();
	~NA_ObjLoader();
	bool load(string fileName, NA_Obj* objOut);
	
};

