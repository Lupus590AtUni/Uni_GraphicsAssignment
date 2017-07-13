

//uniform vec3	pigPos; //TODO: can I interigate for this too, or do I have to pass it?


const float		PI = 3.14;
const float		lightIntensity = 1.0;
const float		constFudge = 0.25;
const float		linearFudge = 0.005;
const float		quadraticFudge = 0.025;

float rend	= 250.0;
float rstart = 50.0;


uniform float		Intensity;
uniform sampler2D	grabTexture;

varying vec3		Normal;
varying vec3		Vertex;
varying vec2 		texCoord;

void main(void)
{	
	vec3 pigPos = Vertex;
	vec3 normPigPos = normalize(pigPos);


	vec3 lightPos = vec3(gl_LightSource[0].position.xyz);

	vec3 normLightPos = normalize(lightPos);

	
	

	float effectiveIntesity;


	vec3 normNormal = normalize(vec3(Normal.xyz));

	vec3 t = vec3(lightPos - pigPos);

	float distToLight = length(t); //this line errors on kim's laptop, possible reasson to why light distance thing don't work
//	float distToLight = Intensity; //confirmed, this is issue for light distance not affecting brightness on object

	float d = dot(normNormal.xyz, normLightPos.xyz);
	if(d > 0.0)//facing the light
	{
		float falloff;

		if( distToLight < rstart )
			falloff = 1.0;
		else
		if( distToLight > rend )
			falloff = 0.0;
			else
			{
			falloff = rend-distToLight / rend-rstart;
			}




		effectiveIntesity = d*lightIntensity * falloff;// (1.0/(constFudge+(quadraticFudge*distToLight*distToLight))); //+ (linearFudge*distToLight) );// +(quadraticFudge*distToLight*distToLight));

	}
	else
	{
		effectiveIntesity = 0.0;
	}

	//TODO: change the colour of the pixel
	gl_FragColor = vec4(vec4( 1.0 ) * effectiveIntesity); //TODO: improve
	

	//texturing stuff
	//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/
//	gl_FragColor = vec4(texture2D(grabTexture, texCoord.xy),1.0);

	//simple check to make sure that shader compiles
	vec3 lP = vec3(abs(gl_LightSource[0].position.x/100), abs(gl_LightSource[0].position.y/100), abs(gl_LightSource[0].position.z/100));
	//gl_FragColor = vec4( lP.x, lP.y, lP.z, 1.0 );
}
