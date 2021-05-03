#include "glew.h"
#include "freeglut.h"
#include "Angel.h"

const int numOfCir = 5;
GLint numberOfSlides = 360-2;
GLfloat radius = 0.1f;
GLuint program;
GLuint vao[6];
GLuint a = 45;
GLuint  theta; 

GLfloat vertices[]{
	// -----Quad----- //
	0.0f, -0.5f,	//A
	0.5f, 0.0f,		//B
	0.0f, 0.5f,		//C
	0.0f, 0.5f,		//C
	-0.5f, 0.0f,	//D
	0.0f, -0.5,		//A
	// ---Triangle1--- //
	0.0f, -0.5,		//A
	-0.5f, 0.0f,	//D
	-1.0f, -1.0f,	//1
	// ---Triangle2--- //
	0.0f, -0.5f,	//A
	0.5f, 0.0f,		//B
	1.0f, -1.0f,	//2
	// ---Triangle3--- //
	0.5f, 0.0f,		//B
	1.0f, 1.0f,		//3
	0.0f, 0.5f,		//C
	// ---Triangle4--- //
	0.0f, 0.5f,		//C
	-1.0f, 1.0f,	//4
	-0.5f, 0.0f		//D
};
GLfloat colors[] = {
	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	// Quad
	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,
	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	// Triangle1
	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	// Triangle2
	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	// Triangle3
	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f,	0.45f, 0.45f, 0.45f		// Triangle4
}; 
GLfloat circle1[360 * numOfCir], circle2[360 * numOfCir], circle3[360 * numOfCir], circle4[360 * numOfCir], circle5[360 * numOfCir];
GLfloat circle1Color[360 * 3], circle2Color[360 * 3], circle3Color[360 * 3], circle4Color[360 * 3], circle5Color[360 * 3];

void drawCircle() {
	GLfloat x, y;
	for (int i = 0; i<180; i++) {
		x = radius * cos(i * 4.0f * M_PI / numberOfSlides);
		y = radius * sin(i * 4.0f * M_PI / numberOfSlides);
		// Circle at (0,0)
		circle1[2 * i] = x;					circle1[(2 * i) + 1] = y;
		circle1Color[(3 * i)] = 1.0f;		circle1Color[(3 * i) + 1] = 1.0f;		circle1Color[(3 * i) + 2] = 0.0f;
		// Circle at (0, -0.5)
		circle2[2 * i] = x;					circle2[(2 * i) + 1] = y - 0.5f;
		circle2Color[(3 * i)] = 1.0f;		circle2Color[(3 * i) + 1] = 1.0f;		circle2Color[(3 * i) + 2] = 0.0f;
		// Circle at (0.5 , 0)
		circle3[2 * i] = x + 0.5f;			circle3[(2 * i) + 1] = y;
		circle3Color[(3 * i)] = 1.0f;		circle3Color[(3 * i) + 1] = 1.0f;		circle3Color[(3 * i) + 2] = 0.0f;
		// Circle at (0, 0.5)
		circle4[2 * i] = x;					circle4[(2 * i) + 1] = y + 0.5f;
		circle4Color[(3 * i)] = 1.0f;		circle4Color[(3 * i) + 1] = 1.0f;		circle4Color[(3 * i) + 2] = 0.0f;
		// Circle at (-5,0)
		circle5[2 * i] = x - 0.5f;			circle5[(2 * i) + 1] = y;
		circle5Color[(3 * i)] = 1.0f;		circle5Color[(3 * i) + 1] = 1.0f;		circle5Color[(3 * i) + 2] = 0.0f;
	}
}

void init(void) {
	GLuint buffer[2];	
	GLint vPosition,vColor;

	program = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(program);
	
	drawCircle();	// Draw circles

	glGenVertexArrays(6, vao);
	
	glBindVertexArray(vao[0]);
	glGenBuffers(2, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	vColor = glGetAttribLocation(program, "color");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindVertexArray(vao[1]);

	glGenBuffers(2, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle1), circle1, GL_STATIC_DRAW);
	vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle1Color), circle1Color, GL_STATIC_DRAW);
	vColor = glGetAttribLocation(program, "color");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindVertexArray(vao[2]);

	glGenBuffers(2, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle2), circle2, GL_STATIC_DRAW);
	vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle2Color), circle2Color, GL_STATIC_DRAW);
	vColor = glGetAttribLocation(program, "color");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindVertexArray(vao[3]);

	glGenBuffers(2, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle3), circle3, GL_STATIC_DRAW);
	vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle3Color), circle3Color, GL_STATIC_DRAW);
	vColor = glGetAttribLocation(program, "color");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	
	glBindVertexArray(vao[4]);

	glGenBuffers(2, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle4), circle4, GL_STATIC_DRAW);
	vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle4Color), circle4Color, GL_STATIC_DRAW);
	vColor = glGetAttribLocation(program, "color");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindVertexArray(vao[5]);

	glGenBuffers(2, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle5), circle5, GL_STATIC_DRAW);
	vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle5Color), circle5Color, GL_STATIC_DRAW);
	vColor = glGetAttribLocation(program, "color");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 0.0, 1.0);						// yellow background
}

void display( void )
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// clear the window
	
	// Draw
	glBindVertexArray(vao[5]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 360);
	glBindVertexArray(vao[4]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 360);
	glBindVertexArray(vao[3]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 360);
	glBindVertexArray(vao[2]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 360);
	glBindVertexArray(vao[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 360);
	glBindVertexArray(vao[0]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 18);

	glutSwapBuffers();
}

void keyboard( unsigned char key, int x, int y )
{
	switch (key){
		case '1':
			key = 1;
			break;
		case '2':
			key = 2;
			break;
		case '3':
			key = 3;
			break;
		case 27:
			exit(EXIT_SUCCESS);
			break;
	}
	
	if (key == 1){
		program = InitShader("vshader1.glsl", "fshader.glsl");
		glUseProgram(program);
	}	
	else if (key == 2) {
		program = InitShader("vshader2.glsl", "fshader.glsl");
		glUseProgram(program);
			glUniform1i(theta, a);
			theta = glGetUniformLocation(program, "theta");
			a += 45;
	}
	else if (key == 3) {
		if (a == 0 || a == 90 || a == 180 || a == 270) {
			program = InitShader("vshader2.glsl", "fshader1.glsl");
			glUseProgram(program);
			glUniform1i(theta, a);
			theta = glGetUniformLocation(program, "theta");
			a += 45;
		}
		else {
			program = InitShader("vshader2.glsl", "fshader.glsl");
			glUseProgram(program);
			glUniform1i(theta, a);
			theta = glGetUniformLocation(program, "theta");
			a += 45;
		}
	}
	if (a == 360) {
		a = 0;
	}

	glutPostRedisplay();
}


int main( int argc, char **argv )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA );
	glutInitWindowSize( 500, 500 );

	// If you are using freeglut, the next two lines will check if 
	// the code is truly 3.1. Otherwise, comment them out
	glutInitContextVersion( 3, 1 );
	glutInitContextFlags( GLUT_FORWARD_COMPATIBLE );
	glutInitContextProfile( GLUT_CORE_PROFILE );

	glutCreateWindow( "Ninja Star" );

	glewExperimental = GL_TRUE;
	glewInit();
	init();
	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	
	glutMainLoop();
	return 0;
}