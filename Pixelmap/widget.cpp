#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Bitmap");
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
    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
}

void Widget::paintGL()
{
    // Pixel Map
    /*
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLubyte data[32*32*3];

    for(int y = 0; y<32; y++) {
        for(int x = 0; x<32; x++) {
            data[y*32*3 + x*3+0] = 0xff;
            data[y*32*3 + x*3+1] = 0xff;
            data[y*32*3 + x*3+2] = 0x00;
        }
    }

    glRasterPos2f(0,0);
    glDrawPixels(32,32,GL_RGB, GL_UNSIGNED_BYTE,data);

    glFlush();
    */

    // Read Image
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLubyte *data;

    QImage *image = new QImage("bmp_24.bmp");
    data = image->bits();
    if(data != NULL) {
        glRasterPos2f(-0.5,-0.5);
        glDrawPixels(image->width(), image->height(), GL_BGRA, GL_UNSIGNED_BYTE,data);
    }

    glRasterPos2f(-1,-1);
    glCopyPixels(100,100,80,50,GL_COLOR);

    glFlush();
}
