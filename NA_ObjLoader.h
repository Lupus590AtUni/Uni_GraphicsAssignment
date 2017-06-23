#pragma once

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
	NA_Obj();
	~NA_Obj();
	NA_Tri getFace(int faceID);
	
	//TODO: change this
	int vertexCount;
	vec3* vertex;
	int normalCount;
	vec3* normal;
	int faceCount;
	int* face; //how will this work? use array of ints to form triangles, use it to index vertex?
};

class NA_ObjLoader
{
public:
	NA_ObjLoader();
	~NA_ObjLoader();
	NA_Obj load(string fileName);
	
};

