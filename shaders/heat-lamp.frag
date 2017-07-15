



const float		lightWeighting = 0.75;
const float		textureWeighting = 0.25;


const float		PI = 3.14;
const float		lightIntensity = 1.0;
const float		constFudge = 0.025;
const float		linearFudge = 0.025;
const float		quadraticFudge = 0.05;

float rend	= 250.0;
float rstart = 50.0;


uniform float		Intensity;
uniform sampler2D	grabTexture;
//varying	sampler2D	HeatValues

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

	vec3 t = vec3(pigPos - lightPos);

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




		effectiveIntesity = d*lightIntensity * (1.0/(constFudge + (linearFudge*distToLight) +(quadraticFudge*distToLight*distToLight)));

	}
	else
	{
		effectiveIntesity = 0.0;
	}

	//TODO: change the colour of the pixel
	vec4 lightingColour = vec4(vec4( 1.0 ) * effectiveIntesity); //TODO: improve
	
	//gl_FragColor = lightingColour;

	//texturing stuff
	//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/
	vec4 textureColour = vec4(texture2D(grabTexture, texCoord.xy)); // TODO: why is this blank?

	vec4 col = vec4(textureColour.rgb, 1.0);
	col.r *= 1.0;
	col.g *= 1.0;
	
	gl_FragColor = (col);

	//gl_FragColor = (lightingColour * lightWeighting) + (textureColour.rgb * textureWeighting);

	//simple check to make sure that shader compiles
	vec3 lP = vec3(abs(gl_LightSource[0].position.x/100), abs(gl_LightSource[0].position.y/100), abs(gl_LightSource[0].position.z/100));
	vec4 r = vec4( lP.x, lP.y, lP.z, 1.0 );
	gl_FragColor = r;

	gl_FragColor = (lightingColour * lightWeighting) + (r * textureWeighting);
}
