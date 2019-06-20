/*
When creating your project, uncheck OWL,
uncheck Class Library, select Static
instead of Dynamic and change the target
model to Console from GUI.
Also link glut.lib to your project once its done.
*/

#include <windows.h>   // Standard Header For Most Programs
#include <gl/gl.h>     // The GL Header File
#include <gl/glut.h>   // The GL Utility Toolkit (Glut) Header
#include <vector>

const int W = 500;
const int H = 500;

void trace_ray(std::vector<GLint> O, D, t_min, t_max) {
	closest_t = inf
		closest_sphere = NULL
		for sphere in scene.Spheres{
			t1, t2 = IntersectRaySphere(O, D, sphere)
			if t1 in[t_min, t_max] and t1 < closest_t
				closest_t = t1
				closest_sphere = sphere
				if t2 in[t_min, t_max] and t2 < closest_t
					closest_t = t2
					closest_sphere = sphere
		}
			if closest_sphere == NULL
				return BACKGROUND_COLOR
				return closest_sphere.color
}

void display(void)   // Create The Display Function
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);  // Select The Projection Matrix
	glLoadIdentity();									// Reset The Current Modelview Matrix
	gluOrtho2D(0.0, (GLdouble)W, (GLdouble)H, 0.0);
	glBegin(GL_POINTS);
		glColor3f(1, 1, 1);
		glVertex2i(100, 100);
	glEnd();
	glutSwapBuffers();
	// Swap The Buffers To Not Be Left With A Clear Screen
}

void reshape(int w, int h)   // Create The Reshape Function (the viewport)
{
	glutReshapeWindow(W, H);
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 27:        // When Escape Is Pressed...
		exit(0);   // Exit The Program
		break;        // Ready For Next Case
	default:        // Now Wrap It Up
		break;
	}
}

void main(int argc, char** argv)   // Create Main Function For Bringing It All Together
{
	glutInit(&argc, argv); // Erm Just Write It =)
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // Display Mode
	glutInitWindowSize(W, H); // If glutFullScreen wasn't called this is the window size
	glutCreateWindow("Rasterizer"); // Window Title (argv[0] for current directory as title)
	glutDisplayFunc(display);  // Matching Earlier Functions To Their Counterparts
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();          // Initialize The Main Loop
}

