#include "stdafx.h"
#define GLM_FORCE_RADIANS 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp" 
#include "glm/gtc/type_ptr.hpp"

using glm::vec2;
using glm::vec3;
using glm::vec4;
class cRenderClass
{
public:

	cRenderClass(const int, const int);
	~cRenderClass();

	vec2 mousePos;

	void setViewport2D();

	void create(int argc, _TCHAR* argv[]);
	void initShaders();
	void loop();

	void render();
	void drawPixel(int, int);	

	inline void clear(){memset( m_buffer, 0, sizeof(float)*m_sw*m_sh*4 );}
	inline void pointSize(int size){m_point_size = size;}
	inline void colour(float r, float g, float b)
	{
		m_colour.r = r;
		m_colour.g = g;
		m_colour.b = b;
	}

	inline void OpenGL2_0(bool value){m_OPENGL_2_0_SUPPORTED = value;}
	inline bool OpenGL2_0(){return m_OPENGL_2_0_SUPPORTED;}
	
	

private:

	int		 m_sw, m_sh;
	int		 m_point_size;
	float	*m_buffer;
	sRGB	 m_colour;
	bool	m_OPENGL_2_0_SUPPORTED;
};

extern void debugMouse();

extern void adjustMouse();

extern void mouse(int x, int y);

extern void key(unsigned char c, int x, int y);

extern void click(int button, int state, int x, int y);