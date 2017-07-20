#pragma once

#include "stdafx.h"

using glm::vec2;
using glm::vec3;
using glm::vec4;
class NA_HeatLamp
{
public:
	NA_HeatLamp();
	~NA_HeatLamp();

	void draw();

	vec3 pos;
	float heat;
	float radius; // size of circle - no effect on heat output

};

