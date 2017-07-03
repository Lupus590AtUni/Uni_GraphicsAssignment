//I am surprisingly important


uniform float	Intensity;
varying vec3	Normal;

varying vec2 	texCoord;

void main(void)
{	
	gl_Position 	= ftransform();
	texCoord	= gl_MultiTexCoord0.xy;

	Normal = vec3(gl_Normal.xyz);

}