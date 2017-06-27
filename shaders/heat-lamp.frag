//uniform float	Intensity;

//uniform sampler2D	grabTexture;

//uniform vec3	pigPos; //TODO: can I interigate for this too, or do I have to pass it?

//varying vec2 	texCoord;

//const float		pi = 3.14;

void main(void)
{	
	gl_FragColor = vec4( vec3(1.0, 0.0, 0.0), 1.0 );


	//vec3 lightpos = gl_ LightSource[0].position;

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

