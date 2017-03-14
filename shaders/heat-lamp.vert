uniform vec3	lightPos; 	//TODO: use GL light as can interigate in here
uniform float	lightIntensity;

uniform vec3	pigPos; //TODO: can I interigate for this too, or do I have to pass it?

varying vec2 	texCoord;

const float		pi = 3.14;

void main(void)
{	
	float effectiveIntesity;
	//TODO: if facing away then effective intesity is 0;
	if(normal blarg blarg...)
	{
	}
	
	//TODO: calculate r properly
	float r = distance between lightPos and pigPos;

	effectiveIntesity = lightIntensity/(4*pi*r*r)
	

	//TODO: change the colour of the pixel
}