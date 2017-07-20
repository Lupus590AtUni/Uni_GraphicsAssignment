// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once



#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <direct.h> // for getcwd

#include "GL/glew.h"
#include "GL/glut.h"
#include "textfile.h"
#include "globals.h"
#include "cShader.h"
#include "cRenderClass.h"

#include "NA_HeatLamp.h"
#include "NA_MathsLib.h"

#include "objloader.h"
#include "NA_Pig.h"

#include <string>
using std::string;

#define GLM_FORCE_RADIANS 
#include "glm/glm.hpp"

using glm::vec2;
using glm::vec3;
using glm::vec4;



