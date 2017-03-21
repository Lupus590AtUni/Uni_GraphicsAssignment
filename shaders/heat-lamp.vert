uniform vec3	lightPos; 	//TODO: use GL light as can interigate in here
uniform float	Intensity;

uniform sampler2D	grabTexture;

uniform vec3	pigPos; //TODO: can I interigate for this too, or do I have to pass it?

varying vec2 	texCoord;

const float		pi = 3.14;

void main(void)
{	
	float effectiveIntesity;
	if(dot(normal, lightPos) > 0)//facing the light
	{
		float rSqrd = (pigPos.x-
		
		Pos.x)+(pigPos.y-lightPos.y)+(pigPos.z-lightPos.z); //not sqrt-ing as it will be sqrd again anyways
		effectiveIntesity = lightIntensity/(4*pi*rSqrd); //rSqrd == r*r
	}
	else
	{
		effectiveIntesity = 0;
	}

	//TODO: change the colour of the pixel
}