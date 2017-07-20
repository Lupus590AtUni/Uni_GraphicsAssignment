

const float		lightWeighting = 0.25;
const float		textureWeighting = 0.25;
const float		heatWeighting = 0.25;

const float		lightIntensity = 1.0;
const float		constFudge = 0.025;
const float		linearFudge = 0.025;
const float		quadraticFudge = 0.05;

uniform float		Intensity;
uniform sampler2D	grabTexture;
uniform	sampler2D	HeatValues;

varying vec3		Normal;
varying vec3		Vertex;
varying vec2 		texCoord;
varying vec2		heatCoord;

void main(void)
{	
	vec3 pigPos = Vertex;
	vec3 normPigPos = normalize(pigPos);


	vec3 lightPos = vec3(gl_LightSource[0].position.xyz);

	vec3 normLightPos = normalize(lightPos);

	
	

	float effectiveIntesity;


	vec3 normNormal = normalize(vec3(Normal.xyz));

	vec3 t = vec3(pigPos - lightPos);

	float distToLight = length(t)/100;

	float d = dot(normNormal.xyz, normLightPos.xyz);
	if(d > 0.0)//facing the light
	{
		effectiveIntesity = d*lightIntensity * (1.0/(constFudge + (linearFudge*distToLight) +(quadraticFudge*distToLight*distToLight)));
	}
	else
	{
		effectiveIntesity = 0.0;
	}

	vec4 lightingColour = vec4(vec4( 1.0 ) * effectiveIntesity); //TODO: improve
	
	//gl_FragColor = lightingColour;

	//texturing stuff
	//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/
	vec4 textureColour = vec4(texture2D(grabTexture, texCoord.xy)); 

	
	
	//gl_FragColor = (textureColour);


	vec4 heatColour = vec4(texture2D(HeatValues, heatCoord.xy)); // Options for calculating this:
																	// openGL frame buffer
																	// c++ calculated, bake into texture for shader to use
																	// c++ calculated, assign as vertex attributes (requires modification of object loader/renderer)

	//gl_FragColor = heatColour;

	gl_FragColor = (lightingColour * lightWeighting) + (textureColour * textureWeighting) + (heatColour * heatWeighting);

	//simple check to make sure that shader compiles
	vec3 lP = vec3(abs(gl_LightSource[0].position.x/100), abs(gl_LightSource[0].position.y/100), abs(gl_LightSource[0].position.z/100));
	vec4 r = vec4( lP.x, lP.y, lP.z, 1.0 );
	//gl_FragColor = r;
}
