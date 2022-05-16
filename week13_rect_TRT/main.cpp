#include <GL/glut.h>
float angle=45,oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX = x ;
}
void motion(int x,int y)
{
    angle  += (x-oldX);
    oldX = x;
    glutPostRedisplay();///���e�e��
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ⪺
    glRectf(0.5,0.5,-0.5,-0.5);
    glPushMatrix();
        glTranslatef(0.5,0.5,0);///���@�U�n���b0.5,0.5
        glRotatef(angle,0,0,1);///����
        glTranslatef(-0.5,-0.4,0);
        glColor3f(1,0,0);///���⪺
        glRectf(0.5,0.5,1.0,0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit( &argc , argv );
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Homework13_TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
