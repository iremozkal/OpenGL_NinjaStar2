#version 430

in vec2 vPosition;
in vec3 color;
out vec3 vColor;

void main()
{
	//  half of the edge length
	gl_Position = vec4(vPosition.x *0.5, vPosition.y *0.5, 0.0, 1.0);
	vColor = vec3(color);
}
