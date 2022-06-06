#include <GL/glut.h>
#include <stdio.h>
float angle[20], oldX=0;
int angleID=0; ///0:第0個關節，1:第一個關節，2:第二個關節
FILE*fout=NULL, *fin=NULL;
void myWrite()
{
    if(fin != NULL){
        fclose(fin);
        fin = NULL;
    }
    if(fout==NULL) fout=fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        printf(      "%.2f" , angle[i]);
        fprintf(fout, "%.2f", angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
float NewAngle[20],OldAngle[20];
void myRead()
{
    if(fout!=NULL)
    {
	fclose(fout);
	fout=NULL;
    }
    if(fin==NULL) fin=fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        OldAngle[i] = NewAngle [i];
        fscanf(fin,"%f",&NewAngle[i]);
        ///fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay(); ///重畫畫面
}
void myInterpolate(float alpha)
{
    for(int i=0 ;i<20 ;i++){
        angle[i] =alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        printf("%.2f",angle[i]);
    }
    printf("\n");
    glutPostRedisplay();
}
///float alpha = 0;
void timer(int t)
{
    float alpha =(t%30)/30.0;
    if(t%30==0) myRead(); ///遇到30整除時,做新舊交接
    myInterpolate(alpha);
    glutTimerFunc(33,timer,t+1);
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='p'){///play
        myRead(); ///先讀一行
        glutTimerFunc(0,timer,0); ///馬上開始播動畫
        ///myInterpolate(alpha);
        ///alpha =(alpha+0.1);
        ///if(alpha>1) alpha = alpha-1;
    }
    if(key=='r')myRead();
    if(key=='s')myWrite(); ///save
    if(key=='0')angleID=0; ///預設這是第一個
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}
void mouse(int button, int state , int x, int y) ///mouse按下去
{
    oldX = x;
}
void motion(int x,int y)
{
    angle[angleID] += (x-oldX);
    ///myWrite();///沒有必要一直寫檔
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1); ///白色
    glRectf(0.3,0.5,-0.3,-0.2);
    glPushMatrix();
        glTranslatef(0.3,0.5,0); ///掛在0.5,0.5
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0); ///紅色
        glRectf(0.3,0.5,0.8,0.3); ///右上手臂
        glPushMatrix();
        glTranslatef(0.8,0.4,0);
        glRotatef(angle[1],0,0,1);
        glTranslatef(-0.8,-0.4,0);
        glColor3f(0,1,0); ///綠色
        glRectf(0.8,0.5,1.1,0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左半邊
        glTranslatef(-0.3,0.5,0); ///掛在0.5,0.5
        glRotatef(angle[2],0,0,1);
        glTranslatef(+0.3,-0.4,0);
        glColor3f(1,0,0); ///紅色
        glRectf(-0.3,0.5,-0.8,0.3); ///左上手臂
        glPushMatrix();
        glTranslatef(-0.8,0.4,0);
        glRotatef(angle[3],0,0,1);
        glTranslatef(+0.8,-0.4,0);
        glColor3f(0,1,0); ///綠色
        glRectf(-0.8,0.5,-1.1,0.3); ///左下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week15 TRT angles again");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);
    glutMainLoop();
}
