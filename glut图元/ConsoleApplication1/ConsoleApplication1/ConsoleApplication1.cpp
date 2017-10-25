// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

//#include <GLTools.h>	// OpenGL toolkit
//#include <GLMatrixStack.h>
//#include <GLFrame.h>
//#include <GLFrustum.h>
//#include <GLBatch.h>
//#include <GLGeometryTransform.h>

//#include<GLTools.h>
#define FREEGLUT_STATIC
#include <glut.h>
#include<iostream>
using namespace std;
struct vector3 {
	float x;
	float y;
	float z;
};
GLUquadric* gluquadric1;
vector3 pos;
vector3 pos2;
GLuint list1;
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);


	glShadeModel(GL_SMOOTH);
	gluquadric1 = gluNewQuadric();
	pos.x = 0;
	pos.y = 0;
	pos.z =0;
	cout << "ccccccccccccccc" << endl;
	glViewport(0, 0, 800,600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1, 0.1f, 10000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -25.0);
	gluLookAt(0, 2,7,0, 0, -7, 0, 1, 0);
}
void Myreshape(int w,int h)
{
	//glViewport(0, 0, 800, 600);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(45.0, 800/600,1.0,10000.0);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glTranslatef(0, 0, -25);
	cout << "ccccccccccccccc" << endl;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1f, 10000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0,-25.0);
}
void buildlist(GLuint& a)
{
	a = glGenLists(1);
	glNewList(a, GL_COMPILE);
	glBegin(GL_QUADS);
	
	glVertex3f(-1, 0, -1);
	glVertex3f(-1, 0, 1);
	glVertex3f(1, 0, 1);
	glVertex3f(1, 0, -1);
	glEnd();
	glEndList();
}
void Render()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_STENCIL_TEST);
	float y = 35.0f;
	/*glPushMatrix();

	glColor3f(1, 0, 0);
	
	glTranslatef(pos.x, pos.y, pos.z);

	
	glutWireSphere(1.0f, 50, 50);
	glPopMatrix();*/
	for (int i = 0; i < 10; i++)
	{
	
		glPushMatrix();

		glColor3f(1, 0, 0);
		glTranslatef(pos.x, pos.y, pos.z);
		glRotatef(-y * 2.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(pos2.x, pos2.y, pos2.z);
		gluSphere(gluquadric1, 5, 20, 20);
		//glutWireSphere(1.0f, 50, 50);
		glPopMatrix();
		y += 0.75f;
		if (i == 0)
		{
			glAccum(GL_LOAD, 0.5f);
		}
		else
		{
			glAccum(GL_ACCUM, 0.05f);
		}
	}
	glAccum(GL_RETURN, 1.0f);
	/*glLoadIdentity();*/
	glClearStencil(0);
	glClear(GL_STENCIL_BUFFER_BIT);
	glStencilFunc(GL_ALWAYS, 1, 0xff);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glEnable(GL_STENCIL_TEST);
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);
	glColor3f(0, 1, 0);
	//glRectf(-2, -2, 2, 2);
	glPushMatrix();

	glColor3f(0, 1, 0);
	glTranslatef(0, -5.0f, 0);
	glScalef(8, 1, 8);

	glCallList(list1);
	glPopMatrix();
	glDepthMask(GL_TRUE);
	glStencilFunc(GL_EQUAL, 1, 0xff);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glPushMatrix();

	glColor3f(1, 0, 0);
	glScalef(1, -1, 1);
	glTranslatef(pos.x, pos.y, pos.z);
	
	gluSphere(gluquadric1, 5, 20, 20);
	glutWireSphere(1.0f, 50, 50);
	glPopMatrix();
	glutSwapBuffers();
	

}
void Keyprocess(unsigned char key,int x,int y)
{
	pos2 = pos;
	cout << key << endl;
	cout << pos.x <<"  "<<pos.y<<"  "<<pos.z<< endl;
	switch (key)
	{
	case'w':
		pos.z-=1;
		
		break;
	case's':
		pos.z+=1;
	
		break;
	case 'a':
		pos.x-=1;
		
		break;
	case'd':
		pos.x+=1;
		break;
	case 'q':
		pos.y -= 1;

		break;
	case'e':
		pos.y += 1;
		break;
	default:
		break;
	}
}
void Process(int value)
{
	Render();
	glutTimerFunc(18, Process, GetTickCount());
}
int main(int argc,char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA|GL_STENCIL );
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("tt");
	
	init();
	//reshape(800,600);
	buildlist(list1);
	glutReshapeFunc(Myreshape);
	glutKeyboardFunc(Keyprocess);
	glutTimerFunc(18, Process, GetTickCount());
	glutMainLoop();
    return 0;
}

