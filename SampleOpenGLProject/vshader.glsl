#version 430

in vec2 vPosition;
in vec3 color;
out vec3 vColor;

void main()
{
	gl_Position = vec4(vPosition.x, vPosition.y, 0.0, 1.0);
	vColor = vec3(color);
}
