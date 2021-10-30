#include <stdio.h> 
#include <GL\glut.h>  
double xmin = 50, ymin = 50, xmax = 100, ymax = 100;
double xvmin = 200, yvmin = 200, xvmax = 300, yvmax = 300;
const int RIGHT = 8; const int LEFT = 2;
const int TOP = 4; const int BOTTOM = 1;
int ComputeOutCode(double x, double y)
{
	int code = 0;   if (y > ymax)
		code |= TOP;   
	else if (y < ymin)
		code |= BOTTOM;  
	if (x > xmax)
		code |= RIGHT;
	else if (x < xmin)
		code |= LEFT;    
	return code;
}
void CohenSutherland(double x0, double y0, double x1, double y1)
{
	int outcode0, outcode1, outcodeOut;
	int accept = 0, done = 0;
	outcode0 = ComputeOutCode(x0, y0);
	outcode1 = ComputeOutCode(x1, y1);
	do {
		if (!(outcode0 | outcode1))
		{
			accept = 1;      
			done = 1;
		}
		else if (outcode0 & outcode1)         
			done = 1;
		else {
			double x, y;
			outcodeOut = outcode0 ? outcode0 : outcode1;
			if (outcodeOut & TOP)
			{
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
			}
			else if (outcodeOut & BOTTOM)
			{
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			}
			else if (outcodeOut & RIGHT)
			{
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			}
			else
			{
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}
			if (outcodeOut == outcode0)
			{
				x0 = x;     
				y0 = y;
				outcode0 = ComputeOutCode(x0, y0);
			}
			else {
				x1 = x;     
				y1 = y;
				outcode1 = ComputeOutCode(x1, y1);
			}
		}
	} while (!done);
	if (accept)
	{
		double sx = (xvmax - xvmin) / (xmax - xmin);
		double sy = (yvmax - yvmin) / (ymax - ymin);
		double vx0 = xvmin + (x0 - xmin) * sx;
		double vy0 = yvmin + (y0 - ymin) * sy;
		double vx1 = xvmin + (x1 - xmin) * sx;
		double vy1 = yvmin + (y1 - ymin) * sy;
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(xvmin, yvmin);
		glVertex2f(xvmax, yvmin);
		glVertex2f(xvmax, yvmax);
		glVertex2f(xvmin, yvmax);
		glEnd();  
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2d(vx0, vy0);
		glVertex2d(vx1, vy1);
		glEnd();
	}
}
void display()
{
	double x0 = 60, y0 = 20, x1 = 80, y1 = 120;
	//double x2 = 120, y2 = 40, x3 = 40, y3 = 80;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);    
	glVertex2d(x0, y0);
	glVertex2d(x1, y1);  
	glEnd();
	//glBegin(GL_LINES);
	//glVertex2d(x2, y2);
	//glVertex2d(x3, y3);
	//glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymax);
	glVertex2f(xmin, ymax);
	glEnd();
	CohenSutherland(x0, y0, x1, y1);
	//CohenSutherland(x2, y2, x3, y3);
	glFlush();
}
void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cohen Suderland Line Clipping Algorithm");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}