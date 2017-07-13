

//uniform vec3	pigPos; //TODO: can I interigate for this too, or do I have to pass it?

const float		lightWeighting = 0.5;
const float		textureWeighting = 0.5;


const float		PI = 3.14;
const float		lightIntensity = 1.0;
const float		constFudge = 1;
const float		linearFudge = 1;
const float		quadraticFudge = 1;

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

	float distToLight = length(t); 

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
		
		effectiveIntesity = d*lightIntensity * falloff;




		//effectiveIntesity = d*lightIntensity * (1.0/(constFudge + (linearFudge*distToLight) +(quadraticFudge*distToLight*distToLight)));

	}
	else
	{
		effectiveIntesity = 0.0;
	}

	//TODO: change the colour of the pixel
	vec4 lightingColour = vec4(vec4( 1.0 ) * effectiveIntesity); //TODO: improve
	

	//texturing stuff
	//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/
	vec4 textureColour = vec4(texture2D(grabTexture, texCoord.xy)); // TODO: why is this blank?

	gl_FragColor = textureColour.rgb; //don't do rgba

	//gl_FragColor = (lightingColour * lightWeighting) + (textureColour * textureWeighting);

	//simple check to make sure that shader compiles
	vec3 lP = vec3(abs(gl_LightSource[0].position.x/100), abs(gl_LightSource[0].position.y/100), abs(gl_LightSource[0].position.z/100));
	//gl_FragColor = vec4( lP.x, lP.y, lP.z, 1.0 );
}
