#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

    glEnd();


    glutSwapBuffers();///�洫2����buffer
}
int main(int argc,char ** argv)///�i��main�禡
{
     glutInit(&argc, argv);///��l��
     glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///�⭿+3D
     glutCreateWindow("week03���m��T���ε���");///�ص���

     glutDisplayFunc(display);///���ѥΨӵe�Ϫ��禡

     glutMainLoop();///�D�n���j��
     return 0;
}
