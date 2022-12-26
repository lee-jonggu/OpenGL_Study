#include "widget.h"
#include <GL/glut.h>
#include <cmath>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("Open GL Matrix");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0,0,0,0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,(GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    GLfloat angle = 45.0;
    GLfloat value = angle * M_PI / 180;

//    GLfloat rotate[16] = { cos(value), -sin(value), 0, 0,
//                          sin(value), cos(value), 0, 0,
//                          0, 0, 1, 0,
//                         0,0,0,1};

//    glMultMatrixf(rotate);               // GL_MODELVIEW 행렬에 곱한다

//    GLfloat trans[16] = { 1, 0, 0, 0,
//                          0, 1, 0, 0,
//                          0, 0, 1, 0,
//                         0.2,0.5,0,1};
//    glMultMatrixf(trans);

//    GLfloat scale[16] = { 1, 0, 0, 0,
//                          0, 1.5, 0, 0,
//                          0, 0, 1, 0,
//                         0,0,0,1};
//    glMultMatrixf(scale);

//    GLfloat transScale[16] = { 1.5, 0, 0, 0,
//                              0, 1.5, 0, 0,
//                              0, 0, 1, 0,
//                             0.5,0.5,0,1};
//    glMultMatrixf(transScale);

    // 기울기
    GLfloat sheer[16] = { 1  , 0  , 0  , 0  ,
                          0.5, 1  , 0  , 0  ,
                          0  , 0  , 1  , 0  ,
                          0  , 0  , 0  , 1  };
    glMultMatrixf(sheer);

    glutWireTeapot(0.2);

    glPopMatrix();
    glFlush();
}
