#include "widget.h"
#include <math.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("Hello OpenGL");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();    // 상속받은 QOpenGLFunctions 초기화
    glClearColor(0.0,0.0,0.0,0.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,(GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(0, w/this->size().width(), 0, h/this->size().height(), -1, 1);
    glOrtho(-1.0,1.0, -1.0,1.0, -1.0,1.0);
}

void Widget::paintGL()
{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0,1.0,1.0);
//    glPointSize(10.0);
//    glLineWidth(5.0);

//    glEnable(GL_POINT_SMOOTH);
//    glBegin(GL_LINE_LOOP);
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.5,-0.5);
//    glVertex2d(0.5,-0.5);
//    double rad = 0.5;

//    for (int i = 0; i < 360; i++) { // i += 10
//        double angle, x, y;
//        angle = i * M_PI / 180;     // 360도를 돌면서 각 각도에 대한 theta 값
//        x = rad * cos(angle);       // x = 반지름 * cos(theta)
//        y = rad * sin(angle);       // y = 반지름 * sic(theta)
//        glVertex2f(x,y);
//    };

//    GLfloat w = 1, y;
//    for (y = 0.8; y > -0.8; y -= 0.2) {
//        glLineWidth(w++);
//        glBegin(GL_LINES);
//        glVertex2f(-0.8,y);
//        glVertex2f(0.8,y);
//        glEnd();
//    }
//    glEnd();

    // STIPPLE (점선)
    /*
     * GLushort arPat[] = {0xaaaa,0xaaaa,0xaaaa,0xaaaa,0x33ff,0x33ff,0x33ff,0x57ff,0x57ff};
    GLint arFac[] = {1,2,3,4,1,2,3,1,2};        // 비트 하나가 몇개의 점과 대응되는지
    glEnable(GL_LINE_STIPPLE);
    GLfloat y;
    GLint idx = 0;
    for (y = 0.8; y > -0.8; y -= 0.2) {
        glLineStipple(arFac[idx], arPat[idx]);
        glBegin(GL_LINES);
        glVertex2f(-0.8,y);
        glVertex2f(0.8,y);
        glEnd();
        idx++;
    }
    glEnd();
    glFlush();
    */

    // Triangles (삼각형)
    /*
     * glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);         // 배경 흰색

    glBegin(GL_TRIANGLES);          // triangles 그리기
    GLfloat x = -0.8;
    GLfloat y = 0.4;
    for (int i = 0; i < 6; i++) {
        glVertex2f(x,y);
        x += 0.3;
        y *= -1;
    };
    glEnd();
    glFlush();
    */

    // Triangles Strip
    /*
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);         // 배경 흰색

    glShadeModel(GL_FLAT);

    glBegin(GL_TRIANGLE_STRIP);          // triangles 그리기
    GLfloat x = -0.8;
    GLfloat y = 0.4;
    for (int i = 0; i < 6; i++) {
        if ( i % 2 == 0) {
            glColor3f(1.0,0.0,0.0);
        } else {
            glColor3f(0.0,1.0,0.0);
        }
        glVertex2f(x,y);
        x += 0.3;
        y *= -1;
    };
    glEnd();
    glFlush();
    */

    // Triangle Fan
    /*
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);         // 배경 흰색

    glShadeModel(GL_FLAT);          // 대표적인 정점의 색깔로 채워진다

    glBegin(GL_TRIANGLE_FAN);          // triangles 그리기
    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,0.5);
    glVertex2f(-0.35,0.35);

    glColor3f(0.0,1.0,0.0);
    glVertex2f(-0.5,0.0);

    glColor3f(1.0,0.0,0.0);
    glVertex2f(-0.35,-0.35);

    glColor3f(0.0,1.0,0.0);
    glVertex2f(0.0,-0.5);

    glEnd();
    glFlush();
    */

    // Rectangle (사각형)
    /*
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);

    glRectf(-0.8,0.8,0.8,-0.8);
    glFlush();
    */

    // Polygon ( 다각형)
    /*
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.0,0.5);
    glVertex2f(-0.5,0.0);
    glVertex2f(0.5,0.0);
    glVertex2f(0.0,-0.5);

    glEnd();
    glFlush();
    */

    // Polygon_Triangle ( 다각형)

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_TRIANGLES);
    glVertex2f(0.0,0.5);
    glVertex2f(-0.5,0.0);
    glVertex2f(0.0,0.0);

    glVertex2f(0.0,0.0);
    glVertex2f(0.5,0.0);
    glVertex2f(0.0,-0.5);

    glEnd();
    glFlush();

}
