#include "raytracing.h"

raytracing rt;
void r(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void d()
{
	glClear(GL_COLOR_BUFFER_BIT);
	rt.draw();
	glutSwapBuffers();
}
void start(int &argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Raytracing");
	glutReshapeFunc(r);
	glutDisplayFunc(d);
	glutIdleFunc(d);
	glutMainLoop();
}
int main(int argc, char * argv[])
{
	start(argc, argv);
	return 0;
}