

//uniform vec3	pigPos; //TODO: can I interigate for this too, or do I have to pass it?


const float		PI = 3.14;
const float		lightIntensity = 1.0;


uniform float		Intensity;
uniform sampler2D	grabTexture;

varying vec3		Normal;
varying vec3		Vertex;
varying vec2 		texCoord;

void main(void)
{	
	vec3 pigPos = Vertex;



	vec3 lightPos = vec3(gl_LightSource[0].position.xyz);

	normalize(lightPos);

	
	

	float effectiveIntesity;

	//TODO: find the normal

	vec3 normal = vec3(Normal.xyz);

	float d = dot(normal.xyz, lightPos.xyz);
	if(d > 0.0)//facing the light
	{

		float rSqrd = (pigPos.x-lightPos.x)+(pigPos.y-lightPos.y)+(pigPos.z-lightPos.z); //not sqrt-ing as it will be sqrd again anyways
		effectiveIntesity = lightIntensity/(4.0*PI*rSqrd); //rSqrd == r*r

		//effectiveIntesity = 0.0;
	}
	else
	{
		effectiveIntesity = 0.0;
	}

	//TODO: change the colour of the pixel
	gl_FragColor = vec4(vec4( abs(lightPos.x), abs(lightPos.y), abs(lightPos.z), 1.0 ) * effectiveIntesity); //TODO: improve


	//simple check to make sure that shader compiles
	vec3 lP = vec3(abs(gl_LightSource[0].position.x/100), abs(gl_LightSource[0].position.y/100), abs(gl_LightSource[0].position.z/100));
	//gl_FragColor = vec4( lP.x, lP.y, lP.z, 1.0 );
}
