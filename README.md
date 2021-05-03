# OpenGL_NinjaStar2

OpenGL shape drawing and basic rotation and shading with Visual C++.  

## Tasks

+ Try to complete as many of the following steps as you can.
+ To switch between the steps use the following keyboard keys:
  - Use ‘1’ key to switch to Step 1.
  - Use ‘2’ key to switch to Step 2.
  - Use ‘3’ key to switch to Step 3.  

**STEP 1**: 
+ Scaling the ninja star from the previous experiment, create the scene given in the following picture.

  ![ninja star drawing](https://github.com/iremozkal/OpenGL_NinjaStar2/blob/main/Images/img1.PNG?raw=true)

+ Width and height of the star should be as half of the edge length of the drawing area.

**STEP 2**: 
+ Change the vertex shader code to create swinging animation given below:

  ![ninja star drawing](https://github.com/iremozkal/OpenGL_NinjaStar2/blob/main/Images/img2.PNG?raw=true)

+ The star should not spin around its origin but should rotate [-45, 45]° to perform the swing animation.  

**STEP 3**: 
+ Change the fragment shader code to degrade the color of the star according to itsrotation as given below:

  ![ninja star drawing](https://github.com/iremozkal/OpenGL_NinjaStar2/blob/main/Images/img3.PNG?raw=true)
+ The star should have its brightest color when its rotation is -45° and 45° and it should have its darkest color
when its rotation is 0°.
+ The brightest and darkest colors of your star should be as similar as possible to the ones given in the figure
above.  

**Hints**:
+ Use the variable “vPosition” to pass the vertex information to the vertex shader.
+ The shapes should be drawn as GL_TRIANGLES or GL_TRIANGLE_FAN or GL_TRIANGLE_STRIP s.  

**The Rotation Effect**:
+ You can use sine or cosine function to determine the rotation amount of each vertex around “z” axis (in vertex shader code).
+ You can use sine or cosine function to determine the brightness of each pixel (in fragment shader code).

**NOTE**: Implement your homework using OpenGL 3.1 version or higher. All programming assignments must use the shader-based functionality of OpenGL: 1) no immediate mode 2) at least one vertex shader and one fragment shader. Therefore, you should not use any of the deprecated features of the API, e.g. glBegin, glEnd, glVertex3f, glTranslate etc.  


## Solution
+ For all steps, I used switch cases and if else statements to choose the right step in keyboard() function and initialize the program with the right shaders.
+ In the beginning the program starts with the previous shape, its width and height are the length of the window. Program uses the default shaders to initialize.  

**STEP 1**: 
+ I used a scale value in vertex shader as 0.5 to set the width and height as half of the length of the window. 

**STEP 2**: 
+ I declerad a theta for the rotation. I To send the theta information to the vertex shader, loaded uniform variables with glUniform1i ( theta, a );
+ Then send the theta to the program. I want the rotation to continue from the angle that it stoped, so I increase 45 degree the ‘a’ integer angle value after every rotation.
+ In vertex shader, for the rotation I calculated the new positions according to these two equations with uniform theta and scale values.  

  ![ninja star drawing](https://github.com/iremozkal/OpenGL_NinjaStar2/blob/main/Images/equation.PNG?raw=true)  

**STEP 3**: 
+ In addition to second step, there’s a color change here. At 0,90,270, and 360 degrees of a full rotation, shape will be dark gray, otherwise it will be light gray. In keyboard() function, I check these two conditions and be sure that the program initializes with the right fragment shaders. In fragment shader, I change the color’s tone from darkest to brighter.  
 
After checking all steps, also check the angle for starting as 0 degree again after 360 degree.
And also, I came across with such a problem that, I needed to click to the windows screen to see the result of the next move even I did took a value from keyboard. To fix that problem, in keyboard() funciton I used glutPostRedisplay(); to call display right after keyboad operations done. It fixed the click problem.