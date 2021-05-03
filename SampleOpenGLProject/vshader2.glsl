#version 430

in vec2 vPosition;
in vec3 color;
out vec3 vColor;
uniform int theta;

void main()
{
	// rotate with theta + half of the edge length
	gl_Position = vec4((vPosition.x * cos(theta) - vPosition.y * sin(theta))*0.5, (vPosition.x * sin(theta) + vPosition.y * cos(theta))*0.5, 0.0, 1.0); 
	vColor = vec3(color);
}