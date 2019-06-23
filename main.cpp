#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;


const GLfloat Pi = 3.1415926536f;
const GLint N = 60;
const GLint r = 10;
float  rr = 10;

GLuint listName;
int point_tmp;
int point ;
int level = 1;
int n = 3;
int speed=1;
int change;
int number = 11;
int isbtn=0;
int gameover=0;//1過關 -1失敗 0遊戲中
int df=0;
int lf=0;
int sizedf=0;
GLfloat pivPt;
int deadline = 10;
int times;
float tempx,tempy;
int time_point;

class wcPt2D
{
      public:
         GLfloat x, y;
};
static wcPt2D verts [20]= { {0.0, 200.0} , { 200*cos(Pi/6), -200*sin(Pi/6)}, { -200*cos(Pi/6), -200*sin(Pi/6)}};

void draw_wired_circle(float x, float y, float r, float g, float b,int R)
{
    int i;
    glLineWidth(5.0f);
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    for(i=0; i<N; ++i)
        glVertex2f(x+R*cos(2*i*Pi/N), y+R*sin(2*i*Pi/N));
    glEnd();
}
void init(void)
{
    glClearColor(0.2,0.5,0.8,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300.0,300.0,-700.0,300.0);
}

void value_reset()
{
    for (int i=0;i<n;i++)
    {
        verts[i].x=0;
        verts[i].y=0;
    }
    rr =10;
    n = 0;
    lf=0;
    sizedf=0;
    pivPt = 0.0;
}


void draw_position(int n)
{
    n=n-1;
    glColor3f(1.0,1.0,1.0);
    switch (n)
    {
        case 0:
            glBegin(GL_LINE_STRIP);
                glVertex2f(15,15);
                glVertex2f(15,-15);
                glVertex2f(-15,-15);
                glVertex2f(-15,15);
                glVertex2f(15,15);
            glEnd();
            break;
        case 1:
            glBegin(GL_LINES);
                glVertex2f(0,15);
                glVertex2f(0,-15);
            glEnd();
            break;
        case 2:
            glBegin(GL_LINE_STRIP);
                glVertex2f(-15,15);
                glVertex2f(15,15);
                glVertex2f(15,0);
                glVertex2f(-15,0);
                glVertex2f(-15,-15);
                glVertex2f(15,-15);
            glEnd();
            break;
        case 3:
            glBegin(GL_LINE_STRIP);
                glVertex2f(-15,15);
                glVertex2f(15,15);
                glVertex2f(15,-15);
                glVertex2f(-15,-15);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(-15,0);
                glVertex2f(15,0);
            glEnd();
            break;
        case 4:
            glBegin(GL_LINE_STRIP);
                glVertex2f(-15,15);
                glVertex2f(-15,0);
                glVertex2f(15,0);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(15,15);
                glVertex2f(15,-15);
            glEnd();
            break;
        case 5:
            glBegin(GL_LINE_STRIP);
                glVertex2f(15,15);
                glVertex2f(-15,15);
                glVertex2f(-15,0);
                glVertex2f(15,0);
                glVertex2f(15,-15);
                glVertex2f(-15,-15);
            glEnd();
            break;
        case 6:
            glBegin(GL_LINE_STRIP);
                glVertex2f(15,15);
                glVertex2f(-15,15);
                glVertex2f(-15,-15);
                glVertex2f(15,-15);
                glVertex2f(15,0);
                glVertex2f(-15,0);
            glEnd();
            break;
        case 7:
            glBegin(GL_LINE_STRIP);
                glVertex2f(-15,0);
                glVertex2f(-15,15);
                glVertex2f(15,15);
                glVertex2f(15,-15);
            glEnd();
            break;
        case 8:
            glBegin(GL_LINE_STRIP);
                glVertex2f(15,15);
                glVertex2f(15,-15);
                glVertex2f(-15,-15);
                glVertex2f(-15,15);
                glVertex2f(15,15);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(-15,0);
                glVertex2f(15,0);
            glEnd();
            break;
        case 9:
            glBegin(GL_LINE_STRIP);
                glVertex2f(15,0);
                glVertex2f(-15,0);
                glVertex2f(-15,15);
                glVertex2f(15,15);
                glVertex2f(15,-15);
                glVertex2f(-15,-15);
            glEnd();
            break;
        case 10:
            glBegin(GL_LINE_STRIP);
                glVertex2f(15,15);
                glVertex2f(15,-15);
                glVertex2f(0,-15);
                glVertex2f(0,15);
                glVertex2f(15,15);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(-10,15);
                glVertex2f(-10,-15);
            glEnd();
            break;
        case 11:
            glBegin(GL_LINES);
                glVertex2f(10,15);
                glVertex2f(10,-15);
                glVertex2f(-10,15);
                glVertex2f(-10,-15);
            glEnd();
            break;
    }
}

void draw_position2(int n)
{
    n=n;
    glColor3f(1.0,1.0,1.0);
    switch (n)
    {
        case 1:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINE_STRIP);
                glVertex2f(-40,-260);
                glVertex2f(40,-260);
                glVertex2f(40,-340);
                glVertex2f(-40,-340);
                glVertex2f(-40,-260);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(-105,-260);
                glVertex2f(-105,-340);
            glEnd();
            break;
        case 2:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINE_STRIP);
                glVertex2f(40,-300);
                glVertex2f(-40,-300);
                glVertex2f(-40,-260);
                glVertex2f(40,-260);
                glVertex2f(40,-340);
                glVertex2f(-40,-340);
            glEnd();
            break;
        case 3:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINE_STRIP);
                glVertex2f(-40,-260);
                glVertex2f(40,-260);
                glVertex2f(40,-340);
                glVertex2f(-40,-340);
                glVertex2f(-40,-260);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(-40,-300);
                glVertex2f(40,-300);
            glEnd();
            break;
        case 4:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINE_STRIP);
                glVertex2f(-40,-300);
                glVertex2f(-40,-260);
                glVertex2f(40,-260);
                glVertex2f(40,-340);
            glEnd();
            break;
        case 5:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINE_STRIP);
                glVertex2f(40,-260);
                glVertex2f(-40,-260);
                glVertex2f(-40,-340);
                glVertex2f(40,-340);
                glVertex2f(40,-300);
                glVertex2f(-40,-300);
            glEnd();
            break;
        case 6:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINE_STRIP);
                glVertex2f(40,-260);
                glVertex2f(-40,-260);
                glVertex2f(-40,-300);
                glVertex2f(40,-300);
                glVertex2f(40,-340);
                glVertex2f(-40,-340);
            glEnd();
            break;
        case 7:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINE_STRIP);
                glVertex2f(-40,-260);
                glVertex2f(-40,-300);
                glVertex2f(40,-300);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(40,-260);
                glVertex2f(40,-340);
            glEnd();
            break;
        case 8:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINE_STRIP);
                glVertex2f(-40,-260);
                glVertex2f(40,-260);
                glVertex2f(40,-340);
                glVertex2f(-40,-340);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(40,-300);
                glVertex2f(-40,-300);
            glEnd();
            break;
        case 9:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINE_STRIP);
                glVertex2f(-40,-260);
                glVertex2f(40,-260);
                glVertex2f(40,-300);
                glVertex2f(-40,-300);
                glVertex2f(-40,-340);
                glVertex2f(40,-340);
            glEnd();
            break;
        case 10:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(0,-260);
                glVertex2f(0,-340);
            glEnd();
            break;
        case 11:
            glBegin(GL_LINE_STRIP);
                glVertex2f(60,-260);
                glVertex2f(140,-260);
                glVertex2f(140,-340);
                glVertex2f(60,-340);
                glVertex2f(60,-260);
            glEnd();
            break;
    }
}

void draw_times()
{
    glBegin(GL_LINES);
        glVertex2f(-200,-300);
        glVertex2f(-250,-300);
        glVertex2f(-225,-300);
        glVertex2f(-225,-350);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-140,-300);
        glVertex2f(-190,-300);
        glVertex2f(-165,-300);
        glVertex2f(-165,-350);
        glVertex2f(-140,-350);
        glVertex2f(-190,-350);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(-130,-350);
        glVertex2f(-117,-300);
        glVertex2f(-105,-350);
        glVertex2f(-92,-300);
        glVertex2f(-80,-350);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-70,-300);
        glVertex2f(-30,-300);
        glVertex2f(-70,-300);
        glVertex2f(-70,-350);
        glVertex2f(-70,-350);
        glVertex2f(-30,-350);
        glVertex2f(-70,-325);
        glVertex2f(-30,-325);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-5,-300);
        glVertex2f(-5,-320);
        glVertex2f(-5,-330);
        glVertex2f(-5,-350);
    glEnd();
}

void draw_time(int t)
{
    switch (deadline-t)
    {
        case 1:
            draw_times();
            glBegin(GL_LINES);
                glVertex2f(90,-300);
                glVertex2f(90,-350);
            glEnd();
            break;
        case 2:
            draw_times();
            glBegin(GL_LINE_STRIP);
                glVertex2f(65,-300);
                glVertex2f(115,-300);
                glVertex2f(115,-325);
                glVertex2f(65,-325);
                glVertex2f(65,-350);
                glVertex2f(115,-350);
            glEnd();
            break;
        case 3:
            draw_times();
            glBegin(GL_LINE_STRIP);
                glVertex2f(65,-300);
                glVertex2f(115,-300);
                glVertex2f(115,-350);
                glVertex2f(65,-350);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(65,-325);
                glVertex2f(115,-325);
            glEnd();
            break;
        case 4:
            draw_times();
            glBegin(GL_LINE_STRIP);
                glVertex2f(65,-300);
                glVertex2f(65,-325);
                glVertex2f(115,-325);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(115,-350);
                glVertex2f(115,-300);
            glEnd();
            break;
        case 5:
            draw_times();
            glBegin(GL_LINE_STRIP);
                glVertex2f(115,-300);
                glVertex2f(65,-300);
                glVertex2f(65,-325);
                glVertex2f(115,-325);
                glVertex2f(115,-350);
                glVertex2f(65,-350);
            glEnd();
            break;
        case 6:
            draw_times();
            glBegin(GL_LINE_STRIP);
                glVertex2f(115,-300);
                glVertex2f(65,-300);
                glVertex2f(65,-350);
                glVertex2f(115,-350);
                glVertex2f(115,-325);
                glVertex2f(65,-325);
            glEnd();
            break;
        case 7:
            draw_times();
            glBegin(GL_LINE_STRIP);
                glVertex2f(65,-325);
                glVertex2f(65,-300);
                glVertex2f(115,-300);
                glVertex2f(115,-350);
            glEnd();
            break;
        case 8:
            draw_times();
            glBegin(GL_LINE_STRIP);
                glVertex2f(65,-300);
                glVertex2f(115,-300);
                glVertex2f(115,-350);
                glVertex2f(65,-350);
                glVertex2f(65,-300);
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(65,-325);
                glVertex2f(115,-325);
            glEnd();
            break;
        case 9:
            draw_times();
            glBegin(GL_LINE_STRIP);
                glVertex2f(115,-325);
                glVertex2f(65,-325);
                glVertex2f(65,-300);
                glVertex2f(115,-300);
                glVertex2f(115,-350);
                glVertex2f(65,-350);
            glEnd();
            break;
        case 0:
            draw_times();
            glBegin(GL_LINE_STRIP);
                glVertex2f(65,-300);
                glVertex2f(115,-300);
                glVertex2f(115,-350);
                glVertex2f(65,-350);
                glVertex2f(65,-300);
            glEnd();
            break;
    }
}

void RotateV2_level1(int value)
{
    if (level==1){pivPt=-1;}
    if (level==2)
        {
            int m=n%2;
                if (m==0){pivPt=1.5;}
                else pivPt = -1.5;

        }
    if (level==3)
    {
        speed++;
        if ( speed > 10 )
        {
            pivPt = -1;
            if(speed == 20)
            {speed = 0;}
        }
        else
        {pivPt = -6;}
    }
    if (level==4)
    {
        srand(time(NULL));
        change= rand()%10;
        if( change > 7 )
        {pivPt = -1.5;}
        else
        {pivPt = 1.5;}

    }
    if (level==5 && gameover==0)
    {
        int t = time(NULL);
        t = t - times ;
        if(t<=deadline){pivPt = -1.5;}
        else {gameover=-1;}
        draw_time(t);
        //cout<<t<<endl;
    }
    /*-----------------------------------------------------*/
    pivPt=pivPt*Pi/180;



    if(gameover==0)
    {
        for (int i = 0; i < n;i++)
        {
            if(isbtn==1)
            {

                isbtn=0;
                if (level==3)
                {
                    for (int i = 0; i < n-1;i++)
                    {
                        int jump=abs(verts[i].x-verts[n-2].x);
                        int jump2=abs(verts[i].x-verts[n-1].x);
                        if(n!=1&&i!=n-2&&verts[i].y<0&&jump<20)
                        {
                            if(jump<10)
                            {verts[n-2].y=-215;}
                            gameover=-1;
                            break;
                        }
                        else if(n!=1&&i!=n-2&&verts[i].y>0&&jump2<20)
                        {
                            if(jump2<10)
                            {verts[n-1].y=215;}
                            gameover=-1;
                            break;
                        }
                        else if (number==1)
                        {gameover=1;}
                    }


                }
                else if (level==4)
                {
                    for (int i = 0; i < n-1;i++)
                    {
                        int jump=abs(verts[i].x-verts[n-2].x);
                        int jump2=abs(verts[i].y-verts[n-1].y);
                        if(n!=1&&i!=n-2&&verts[i].y<0&&jump<20)
                        {
                            if(jump<10)
                            {verts[n-2].y=-215;}
                            gameover=-1;
                            break;
                        }
                        else if(n!=1&&i!=n-2&&verts[i].x>0&&jump2<20)
                        {
                            if(jump2<10)
                            {verts[n-1].x=215;}
                            gameover=-1;
                            break;
                        }
                        else if (number==1)
                        {gameover=1;}
                    }


                }

                else if (level==5)
                {
                    for (int i = 0; i < n-1;i++)
                    {
                        int jump=abs(verts[i].y-verts[n-1].y);
                        if(n!=1&&i!=n-1&&verts[i].x>0&&jump<20)
                        {
                            if(jump<10)
                            {verts[n-1].x=215;}
                            gameover=-1;
                        }
                        else if (number==1)
                        {gameover=1;}

                    }


                }

                else
                {
                    for (int i = 0; i < n;i++)
                    {
                        int jump=abs(verts[i].x-verts[n-1].x);
                        if(n!=1&&i!=n-1&&verts[i].y<0&&jump<20)
                        {
                            if(jump<10)
                            {verts[n-1].y=-215;}
                            gameover=-1;
                        }
                        else if (number==1)
                        {gameover=1;}
                    }

                }

            }

            if(level==5)
            {
                sizedf++;
                if(sizedf<=100)
                {

                    verts[i].x=verts[i].x*0.95;
                    verts[i].y=verts[i].y*0.95;
                }
                else if(sizedf>100)
                {

                    int test=pow(abs(verts[i].x),2)+pow(abs(verts[i].y),2);
                    if(test>=40000){}
                    else
                    {
                    verts[i].x=verts[i].x/0.95;
                    verts[i].y=verts[i].y/0.95;
                    }

                    if(sizedf==200){sizedf=0;}
                }

            }

            tempx=verts[i].x*cos(pivPt)-verts[i].y*sin(pivPt);
            tempy=verts[i].x*sin(pivPt)+verts[i].y*cos(pivPt);
            verts[i].x=tempx;
            verts[i].y=tempy;
            int positionNum=number;
            if(level==3||level==4)
            {
                positionNum=(number+1)/2;
            }
            draw_position(positionNum);

            draw_wired_circle(verts[i].x,verts[i].y,0,0,0,r);
            glLineWidth(1.0f);

            glBegin(GL_LINE_STRIP);
                glVertex2f(verts[i].x,verts[i].y);
                glVertex2f(0,0);
            glEnd();
        }
    }

    if(gameover==-1)
    {
       df++;
       if(df<25)
       {
            for (int i = 0; i < n;i++)
            {
                glClearColor(1.0,0.25,0.25,0.0);
                if(df<10)
                {
                    draw_wired_circle(verts[i].x,verts[i].y,0,0,0,rr);
                    glLineWidth(1.0f);
                    if(i==n-1){}
                    else
                    {
                        glBegin(GL_LINE_STRIP);
                            glVertex2f(verts[i].x,verts[i].y);
                            glVertex2f(0,0);
                        glEnd();
                    }

                }
                else if(df<20)
                {
                    verts[i].x=verts[i].x*0.65;
                    verts[i].y=verts[i].y*0.75;
                    //r=rr*0.95;
                    draw_wired_circle(verts[i].x,verts[i].y,0,0,0,rr);
                    glLineWidth(1.0f);
                    if(i==n-1){}
                    else
                    {
                        glBegin(GL_LINE_STRIP);
                            glVertex2f(verts[i].x,verts[i].y);
                            glVertex2f(0,0);
                        glEnd();
                    }
                }
            }



       }
       else
       {
            glClearColor(0.0,0.0,0.0,0.0);
             //F
            glColor3f(1,0,0);
            glBegin(GL_POLYGON);
                 glVertex2f(-220,200);
                 glVertex2f(-220,220);
                 glVertex2f(-100,220);
                 glVertex2f(-100,200);
            glEnd();
            glBegin(GL_POLYGON);
                 glVertex2f(-220,0);
                 glVertex2f(-220,220);
                 glVertex2f(-200,220);
                 glVertex2f(-200,0);
            glEnd();
            glBegin(GL_POLYGON);
                 glVertex2f(-220,100);
                 glVertex2f(-220,120);
                 glVertex2f(-120,120);
                 glVertex2f(-120,100);
            glEnd();
            //A
            glBegin(GL_POLYGON);
                  glVertex2f(-100,0);
                 glVertex2f(-40,220);
                 glVertex2f(-20,220);
                 glVertex2f(-80,0);
            glEnd();

            glBegin(GL_POLYGON);
                  glVertex2f(40,0);
                 glVertex2f(-20,220);
                 glVertex2f(-40,220);
                 glVertex2f(20,0);
            glEnd();

            glBegin(GL_POLYGON);
                 glVertex2f(-60,100);
                 glVertex2f(-60,120);
                 glVertex2f(0,120);
                 glVertex2f(0,100);
            glEnd();
            //I
             glBegin(GL_POLYGON);
                 glVertex2f(60,0);
                 glVertex2f(60,220);
                 glVertex2f(80,220);
                 glVertex2f(80,0);
            glEnd();
            //L
            glBegin(GL_POLYGON);
                 glVertex2f(100,0);
                 glVertex2f(100,220);
                 glVertex2f(120,220);
                 glVertex2f(120,0);
            glEnd();

            glBegin(GL_POLYGON);
                 glVertex2f(100,0);
                 glVertex2f(100,20);
                 glVertex2f(220,20);
                 glVertex2f(220,0);
            glEnd();

            //箭頭
            draw_wired_circle(0, -300, 1,0,0,120);
            draw_wired_circle(0, -300, 0,0,0,80);

            glColor3f(0,0,0);
            glBegin(GL_POLYGON);
                 glVertex2f(120,-350);
                 glVertex2f(120,-260);
                 glVertex2f(0,-260);
                 glVertex2f(0,-350);
            glEnd();

            glColor3f(1,0,0);
            glBegin(GL_POLYGON);
                 glVertex2f(100,-320);
                 glVertex2f(150,-260);
                 glVertex2f(30,-260);
            glEnd();



       }
    }
    if(gameover==1)
    {
       df++;
       if(df<25)
       {
         for (int i = 0; i < n;i++)
            {
                glClearColor(0.9,1,0.25,0.0);

                if(df<10)
                {
                    draw_wired_circle(verts[i].x,verts[i].y,0,0,0,rr);
                    glLineWidth(1.0f);

                        glBegin(GL_LINE_STRIP);
                            glVertex2f(verts[i].x,verts[i].y);
                            glVertex2f(0,0);
                        glEnd();


                }
                else if(df<20)
                {
                    verts[i].x=verts[i].x*1.3;
                    verts[i].y=verts[i].y*1.3;
                    //rr=rr*0.99;
                    draw_wired_circle(verts[i].x,verts[i].y,0,0,0,rr);
                    glLineWidth(1.0f);

                        glBegin(GL_LINE_STRIP);
                            glVertex2f(verts[i].x,verts[i].y);
                            glVertex2f(0,0);
                        glEnd();
                }
            }
       }
        else
        {
            if(level==5)
            {
                lf++;

                glClearColor(0.0,0.0,0.5,0.0);
                //glCallList (SUCCESS);
                glColor3f(0,1,0);
                //S
                glBegin(GL_POLYGON);
                         glVertex2f(-240,200);
                         glVertex2f(-240,220);
                         glVertex2f(-180,220);
                         glVertex2f(-180,200);
                glEnd();
                glBegin(GL_POLYGON);
                         glVertex2f(-240,140);
                         glVertex2f(-240,220);
                         glVertex2f(-220,220);
                         glVertex2f(-220,140);
                glEnd();
                glBegin(GL_POLYGON);
                         glVertex2f(-240,140);
                         glVertex2f(-240,120);
                         glVertex2f(-180,120);
                         glVertex2f(-180,140);
                glEnd();
                glBegin(GL_POLYGON);
                         glVertex2f(-180,60);
                         glVertex2f(-180,120);
                         glVertex2f(-200,120);
                         glVertex2f(-200,60);
                glEnd();

                glBegin(GL_POLYGON);
                         glVertex2f(-240,60);
                         glVertex2f(-240,80);
                         glVertex2f(-180,80);
                         glVertex2f(-180,60);
                glEnd();
                //U
                glBegin(GL_POLYGON);
                         glVertex2f(-140,60);
                         glVertex2f(-140,220);
                         glVertex2f(-160,220);
                         glVertex2f(-160,60);
                 glEnd();
                 glBegin(GL_POLYGON);
                         glVertex2f(-160,60);
                         glVertex2f(-160,80);
                         glVertex2f(-110,80);
                         glVertex2f(-110,60);
                 glEnd();
                 glBegin(GL_POLYGON);
                         glVertex2f(-100,60);
                         glVertex2f(-100,220);
                         glVertex2f(-120,220);
                         glVertex2f(-120,60);
                 glEnd();
                 //C
                  glBegin(GL_POLYGON);
                         glVertex2f(-30,60);
                         glVertex2f(-30,80);
                         glVertex2f(-80,80);
                         glVertex2f(-80,60);
                 glEnd();
                glBegin(GL_POLYGON);
                         glVertex2f(-30,200);
                         glVertex2f(-30,220);
                         glVertex2f(-80,220);
                         glVertex2f(-80,200);
                 glEnd();
                 glBegin(GL_POLYGON);
                         glVertex2f(-60,60);
                         glVertex2f(-60,220);
                         glVertex2f(-80,220);
                         glVertex2f(-80,60);
                 glEnd();
                 //C
                  glBegin(GL_POLYGON);
                         glVertex2f(40,60);
                         glVertex2f(40,80);
                         glVertex2f(-10,80);
                         glVertex2f(-10,60);
                 glEnd();
                glBegin(GL_POLYGON);
                         glVertex2f(40,200);
                         glVertex2f(40,220);
                         glVertex2f(-10,220);
                         glVertex2f(-10,200);
                 glEnd();
                 glBegin(GL_POLYGON);
                         glVertex2f(10,60);
                         glVertex2f(10,220);
                         glVertex2f(-10,220);
                         glVertex2f(-10,60);
                 glEnd();
                 //E
                 glBegin(GL_POLYGON);
                         glVertex2f(60,200);
                         glVertex2f(60,220);
                         glVertex2f(120,220);
                         glVertex2f(120,200);
                    glEnd();
                    glBegin(GL_POLYGON);
                         glVertex2f(60,140);
                         glVertex2f(60,220);
                         glVertex2f(80,220);
                         glVertex2f(80,140);
                    glEnd();
                    glBegin(GL_POLYGON);
                         glVertex2f(60,140);
                         glVertex2f(60,120);
                         glVertex2f(120,120);
                         glVertex2f(120,140);
                    glEnd();

                    glBegin(GL_POLYGON);
                         glVertex2f(60,60);
                         glVertex2f(60,120);
                         glVertex2f(80,120);
                         glVertex2f(80,60);
                    glEnd();

                    glBegin(GL_POLYGON);
                         glVertex2f(60,60);
                         glVertex2f(60,80);
                         glVertex2f(120,80);
                         glVertex2f(120,60);
                    glEnd();
                    //S
                    glBegin(GL_POLYGON);
                             glVertex2f(140,200);
                             glVertex2f(140,220);
                             glVertex2f(200,220);
                             glVertex2f(200,200);
                    glEnd();
                    glBegin(GL_POLYGON);
                             glVertex2f(140,140);
                             glVertex2f(140,220);
                             glVertex2f(160,220);
                             glVertex2f(160,140);
                    glEnd();
                    glBegin(GL_POLYGON);
                             glVertex2f(140,140);
                             glVertex2f(140,120);
                             glVertex2f(200,120);
                             glVertex2f(200,140);
                    glEnd();
                    glBegin(GL_POLYGON);
                             glVertex2f(200,60);
                             glVertex2f(200,120);
                             glVertex2f(180,120);
                             glVertex2f(180,60);
                    glEnd();

                    glBegin(GL_POLYGON);
                             glVertex2f(140,60);
                             glVertex2f(140,80);
                             glVertex2f(200,80);
                             glVertex2f(200,60);
                    glEnd();

                    //S
                    glBegin(GL_POLYGON);
                             glVertex2f(210,200);
                             glVertex2f(210,220);
                             glVertex2f(270,220);
                             glVertex2f(270,200);
                    glEnd();
                    glBegin(GL_POLYGON);
                             glVertex2f(210,140);
                             glVertex2f(210,220);
                             glVertex2f(230,220);
                             glVertex2f(230,140);
                    glEnd();
                    glBegin(GL_POLYGON);
                             glVertex2f(210,140);
                             glVertex2f(210,120);
                             glVertex2f(270,120);
                             glVertex2f(270,140);
                    glEnd();
                    glBegin(GL_POLYGON);
                             glVertex2f(270,60);
                             glVertex2f(270,120);
                             glVertex2f(250,120);
                             glVertex2f(250,60);
                    glEnd();

                    glBegin(GL_POLYGON);
                             glVertex2f(210,60);
                             glVertex2f(210,80);
                             glVertex2f(270,80);
                             glVertex2f(270,60);
                    glEnd();


                    glBegin(GL_POLYGON);
                             glVertex2f(-240,40);
                             glVertex2f(270,20);
                             glVertex2f(-240,20);
                             glVertex2f(270,40);
                    glEnd();

                    if(lf<3)
                    {
                     point_tmp=time(NULL);
                     point = point_tmp - time_point;

                    }
                    int points;
                    if (point<=30){points=1;}
                    else if (point<=60 && point>30) {points=2;}
                    else if (point<=90 && point>60) {points=3;}
                    else if (point<=120 && point>90) {points=4;}
                    else if (point<=150 && point>120) {points=5;}
                    else if (point<=180 && point>150) {points=6;}
                    else if (point<=210 && point>180) {points=7;}
                    else if (point<=240 && point>210) {points=8;}
                    else if (point<=270 && point>240) {points=9;}
                    else if (point<=300 && point>270) {points=10;}
                    else {points=11;}

                    draw_position2(points);

                }
             else
             {
                glClearColor(0.0,0.0,0.0,0.0);
                //NEXT
                glColor3f(1,1,0);
                //N
                glBegin(GL_POLYGON);
                     glVertex2f(-260,0);
                     glVertex2f(-260,220);
                     glVertex2f(-240,220);
                     glVertex2f(-240,0);
                glEnd();

                glBegin(GL_POLYGON);
                     glVertex2f(-160,0);
                     glVertex2f(-160,220);
                     glVertex2f(-140,220);
                     glVertex2f(-140,0);
                glEnd();

                glBegin(GL_POLYGON);
                     glVertex2f(-260,220);
                     glVertex2f(-240,220);
                     glVertex2f(-140,0);
                     glVertex2f(-160,0);
                glEnd();
                //E
                glBegin(GL_POLYGON);
                     glVertex2f(-120,0);
                     glVertex2f(-120,220);
                     glVertex2f(-100,220);
                     glVertex2f(-100,0);
                glEnd();
                glBegin(GL_POLYGON);
                     glVertex2f(-120,200);
                     glVertex2f(-120,220);
                     glVertex2f(0,220);
                     glVertex2f(0,200);
                glEnd();
                glBegin(GL_POLYGON);
                     glVertex2f(-120,20);
                     glVertex2f(-120,0);
                     glVertex2f(0,0);
                     glVertex2f(0,20);
                glEnd();
                glBegin(GL_POLYGON);
                     glVertex2f(-120,120);
                     glVertex2f(-120,100);
                     glVertex2f(0,100);
                     glVertex2f(0,120);
                glEnd();
                //X

                glBegin(GL_POLYGON);
                     glVertex2f(20,220);
                     glVertex2f(40,220);
                     glVertex2f(140,0);
                     glVertex2f(120,0);
                glEnd();


                glBegin(GL_POLYGON);
                     glVertex2f(120,220);
                     glVertex2f(140,220);
                     glVertex2f(40,0);
                     glVertex2f(20,0);
                glEnd();
                //T
                glBegin(GL_POLYGON);
                     glVertex2f(210,0);
                     glVertex2f(210,220);
                     glVertex2f(230,220);
                     glVertex2f(230,0);
                glEnd();
                 glBegin(GL_POLYGON);
                     glVertex2f(160,200);
                     glVertex2f(160,220);
                     glVertex2f(280,220);
                     glVertex2f(280,200);
                glEnd();
                 //箭頭
                glColor3f(1.0,1.0,0.0);
                glBegin(GL_POLYGON);
                     glVertex2f(-120,-320);
                     glVertex2f(30,-320);
                     glVertex2f(30,-200);
                     glVertex2f(-120,-200);
                glEnd();
                glBegin(GL_POLYGON);
                     glVertex2f(30,-380);
                     glVertex2f(30,-140);
                      glVertex2f(120,-260);
                glEnd();
             }

        }
    }

    glutPostRedisplay();
    glutTimerFunc(50,RotateV2_level1,value);
    glutSwapBuffers();

}

void controll()
{
    if (level == 1)
    {
        glClearColor(0.2,0.5,0.8,0.0);
        number = 11 ;
        verts[0] = {0.0, 200.0};
        verts[1] = { 200*cos(Pi/6), -200*sin(Pi/6)};
        verts[2] = { -200*cos(Pi/6), -200*sin(Pi/6)};
        n=n+3;
        RotateV2_level1;
        glutPostRedisplay();

    }
    else if (level == 2)
    {
        glClearColor(0.8,0.5,0.9,0.0);
        number = 6 ;
        verts[0] = {0,200};
        verts[1] = {0,-200};
        verts[2] = {-200,0};
        verts[3] = {200,0};
        n=n+4;
        pivPt = -1.5;
        RotateV2_level1;
        glutPostRedisplay();
    }

    else if (level == 3)
    {
        glClearColor(1,0.8,0.25,0.0);
        number = 7 ;
        verts[0] = {0.0, 200.0};
        verts[1] = { 200*cos(Pi/6), -200*sin(Pi/6)};
        verts[2] = { -200*cos(Pi/6), -200*sin(Pi/6)};
        n=n+3;
        RotateV2_level1;
        glutPostRedisplay();
    }

    else if (level == 4)
    {
        glClearColor(0.4,0.9,0.3,0.0);
        number = 7 ;
        verts[0] = {0.0, 200.0};
        n=n+1;
        RotateV2_level1;
        glutPostRedisplay();
    }

    else if (level == 5)
    {
        glClearColor(0.8,0.8,0.8,0.0);
        times = time(NULL);
        number = 7 ;
        verts[0] = {0.0, 200.0};
        verts[1] = { 200*cos(Pi/6), -200*sin(Pi/6)};
        n=n+2;
        RotateV2_level1;
        glutPostRedisplay();
    }


    else
    {
        value_reset();
        RotateV2_level1;
        glutPostRedisplay();
        level = 6;
    }
}

void mainPicture(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if((gameover==0||df<22)&&level<6)
    {
        draw_wired_circle(0,0,0,0,0,40);
        if (number>0&&gameover==0&&level!=5)
        {
            draw_wired_circle(0,-260,0,0,0,r);
        }
        if (number>0&&gameover==0&&level==4)
        {
            draw_wired_circle(240,0,0,0,0,r);
        }
        if (number>0&&gameover==0&&level==5)
        {
            draw_wired_circle(240,0,0,0,0,r);
        }
    }

}

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
	    verts[n].x = 0;
        verts[n].y = -200;
        n = n+1;
        number--;
        isbtn=1;
        if(level==3)
        {
        verts[n].x = 0;
        verts[n].y = 200;
        n = n+1;
        number--;
        }
        if(level==4)
        {
        verts[n].x = 200;
        verts[n].y = 0;
        n = n+1;
        number--;
        }
        if (level==5)
        {
        verts[n-1].x = 200;
        verts[n-1].y = 0;
        }


        if (gameover !=0)
        {

            if(gameover==1)
            {
                if(level==5){level=1;}
                else {level++;}
            }
            df=0;
            gameover=0;
            value_reset();
            controll();
            glutPostRedisplay();
        }
	}
}


int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(50,20);
    glutInitWindowSize(600,1000);
    glutCreateWindow("aa");
    init();
    glutDisplayFunc(mainPicture);
    glutTimerFunc(50,RotateV2_level1,1);
    glutMouseFunc(mouse);
    time_point=time(NULL);
    glutMainLoop();
}
