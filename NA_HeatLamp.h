#pragma once

#include "stdafx.h"
#define GLM_FORCE_RADIANS 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp" 
#include "glm/gtc/type_ptr.hpp"

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

