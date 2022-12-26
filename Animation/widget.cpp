#include "widget.h"

Widget::Widget(QWidget *parent)
    : QGLWidget(parent)
{
    rectPosX = 0.0f;
    rectPosY = 0.0f;
    rectsize = 250;

    xStep = 5.0f;
    yStep = 5.0f;

    setWindowTitle("Hello OpenGL");
    resize(600,600);

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),SLOT(timerFunction()));
    timer->start(1000/60);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    glClearColor(0.0,0.0,0.0,0.0);
}

void Widget::resizeGL(int w, int h)
{
    windowWidth = w;
    windowHeight = h;

    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1*w, w, -1*h, h, -1.0, 1.0);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_POLYGON);
    glVertex3f(rectPosX, rectPosY, 0.0);
    glVertex3f(rectPosX, rectPosY - rectsize, 0.0);
    glVertex3f(rectPosX + rectsize, rectPosY - rectsize, 0.0);
    glVertex3f(rectPosX + rectsize , rectPosY, 0.0);
    glEnd();

    glFlush();
}

void Widget::timerFunction()
{
    if(rectPosX > windowWidth - rectsize || rectPosX < -windowWidth)
        xStep = -xStep;

    if(rectPosY > windowHeight || rectPosY < -windowHeight + rectsize)
        yStep = -yStep;

    rectPosX += xStep;
    rectPosY += yStep;

    if(rectPosX > (windowWidth-rectsize + xStep))
        rectPosX = windowWidth - rectsize-1;
    else if(rectPosX < -(windowWidth + xStep))
        rectPosX = -windowWidth - 1;

    if(rectPosY > (windowHeight + yStep))
        rectPosY = windowHeight - 1;
    else if(rectPosY < -(windowHeight - rectsize + yStep))
        rectPosY = -windowHeight + rectsize - 1;

    repaint();
}

