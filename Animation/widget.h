#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>

class Widget : public QGLWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //사각형의 위치와 크기
    GLfloat rectPosX;
    GLfloat rectPosY;
    GLfloat rectsize;

    //사각형의 이동 변위(속도) / 한번에 이동하는 픽셀 값
    GLfloat xStep;
    GLfloat yStep;

    // 화면의 크기
    GLfloat windowWidth;
    GLfloat windowHeight;

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public slots:
    void timerFunction();
};
#endif // WIDGET_H
