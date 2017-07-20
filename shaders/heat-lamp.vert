// I am surprisingly important
// the fragment shader is where the work is done

uniform float	Intensity;
varying vec3	Normal;
varying vec3	Vertex;
varying vec2 	texCoord;
varying vec2	heatCoord;

void main(void)
{	
	gl_Position 	= ftransform();
	texCoord	= gl_MultiTexCoord0.xy;
	heatCoord	= gl_MultiTexCoord1.xy;

	Normal = vec3(gl_Normal.xyz);
	Vertex = vec3(gl_Vertex.xyz);

}