//I am surprisingly important


uniform float	Intensity;
varying vec3	Normal;
varying vec3	Vertex;
varying vec2 	texCoord;

void main(void)
{	
	gl_Position 	= ftransform();
	texCoord	= gl_MultiTexCoord0.xy;

	Normal = vec3(gl_Normal.xyz);
	Vertex = vec3(gl_Vertex.xyz);

}