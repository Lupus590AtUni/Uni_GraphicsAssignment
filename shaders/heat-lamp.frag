//uniform float	Intensity;

//uniform sampler2D	grabTexture;

//uniform vec3	pigPos; //TODO: can I interigate for this too, or do I have to pass it?

//varying vec2 	texCoord;

//const float		pi = 3.14;


uniform float		Intensity;
uniform sampler2D	grabTexture;

varying vec2 		texCoord;

void main(void)
{	
	


	vec3 lightpos = vec3(gl_LightSource[0].position.x, gl_LightSource[0].position.y, gl_LightSource[0].position.z);
	gl_FragColor = vec4( lightpos.x, lightpos.y, lightpos.z, 1.0 );

	//float effectiveIntesity;
	//if(dot(normal, lightPos) > 0.0)//facing the light
	//{
	//	float rSqrd = (pigPos.x-Pos.x)+(pigPos.y-lightPos.y)+(pigPos.z-lightPos.z); //not sqrt-ing as it will be sqrd again anyways
	//	effectiveIntesity = lightIntensity/(4.0*pi*rSqrd); //rSqrd == r*r
	//}
	//else
	//{
	//	effectiveIntesity = 0.0;
	//}

	//TODO: change the colour of the pixel
	//.frag is pixels, but the colour needs the vertex, HOW DO I SEND STUFF TO THE OTHER SHADER!!!!
}

