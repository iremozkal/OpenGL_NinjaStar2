#version 430
out vec4  fColor;
in vec3 vColor;

void main() {
	// brighter tone of the color
	fColor = vec4(vColor*1.5, 1.0);
}
