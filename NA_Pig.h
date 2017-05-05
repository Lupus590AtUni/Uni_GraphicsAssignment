#pragma once
#include "stdafx.h"

class NA_Pig
{
private:
	object_type pigObj;
public:
	NA_Pig();
	~NA_Pig();

	void draw();

	//void loadShader();

	vec3 pos;

	int pigShader = 0;

	void init();

};

