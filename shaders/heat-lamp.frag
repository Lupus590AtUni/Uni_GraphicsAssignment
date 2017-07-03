//uniform float	Intensity;

//uniform sampler2D	grabTexture;

//uniform vec3	pigPos; //TODO: can I interigate for this too, or do I have to pass it?

//varying vec2 	texCoord;

const float		PI = 3.14;


uniform float		Intensity;
uniform sampler2D	grabTexture;

varying vec2 		texCoord;

void main(void)
{	
	//vec3 pigPos = vec3 (0.0);



	vec3 lightPos = vec3(gl_LightSource[0].position.x, gl_LightSource[0].position.y, gl_LightSource[0].position.z);
	

	float effectiveIntesity;

	//TODO: find the normal

	//if(dot(gl_Normal, vec4(lightPos, 1.0)) > 0.0)//facing the light //uncommenting this breaks the shader
	{

		//float rSqrd = (pigPos.x-lightPos.x)+(pigPos.y-lightPos.y)+(pigPos.z-lightPos.z); //not sqrt-ing as it will be sqrd again anyways
		//effectiveIntesity = lightIntensity/(4.0*PI*rSqrd); //rSqrd == r*r
	}
	//else
	{
		effectiveIntesity = 0.0;
	}

	//TODO: change the colour of the pixel
	//gl_FragColor = vec4( lightPos.x, lightPos.y, lightPos.z, 1.0 );


	//simple check to make sure that shader compiles
	vec3 lP = vec3(gl_LightSource[0].position.x, gl_LightSource[0].position.y, gl_LightSource[0].position.z);
	gl_FragColor = vec4( lP.x, lP.y, lP.z, 1.0 );
}
