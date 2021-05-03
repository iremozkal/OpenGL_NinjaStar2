#version 430
out vec4  fColor;
in vec3 vColor;

void main(){
	fColor = vec4(vColor, 1.0);
}

