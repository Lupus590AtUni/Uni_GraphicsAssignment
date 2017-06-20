#pragma once
struct NA_Vec
{
	float x;
	float y;
	float z;
};

struct NA_Tri
{
	NA_Vec x;
	NA_Vec y;
	NA_Vec z;
};

class NA_Obj
{
	NA_Obj();
	~NA_Obj();
	NA_Tri getFace(int faceID);
	
	int vertexCount;
	NA_Vec* vertex;
	int normalCount;
	NA_Vec* normal;
	int faceCount;
	int* face; //how does this work?  //use array of ints to form triangles, use its to index vertex
};

class NA_ObjLoader
{
public:
	NA_ObjLoader();
	~NA_ObjLoader();
	NA_Obj load(string fileName);
	
};

