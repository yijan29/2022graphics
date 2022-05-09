#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f( 1 , 1 , 1 );///白色
    glutSolidTeapot( 0.3 );///大茶壺
    glPushMatrix();
        glTranslatef(0.3 , 0 ,0);
        glRotatef( angle , 0 , 0 , 1);///旋轉
        glTranslatef( 0.2 , 0 , 0);
        glColor3f( 1 , 0 , 0 );///紅色
        glutSolidTeapot( 0.2 );///小茶壺
        glPushMatrix();
        glTranslatef(0.2 , 0 ,0);
            glRotatef( angle , 0 , 0 , 1);///旋轉
            glTranslatef( 0.2 , 0 , 0);
            glColor3f( 1 , 0 , 0 );///紅色
            glutSolidTeapot( 0.2 );///小茶壺
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle += 0.03;
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
