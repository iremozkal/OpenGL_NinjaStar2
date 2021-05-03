#version 430

in vec2 vPosition;
in vec3 color;
out vec3 vColor;
uniform int theta;

void main()
{
	gl_Position = vec4((vPosition.x * cos(theta) - vPosition.y * sin(theta))/2, (vPosition.x * sin(theta) + vPosition.y * cos(theta))/2, 0.0, 1.0);
	vColor = vec3(color);
}