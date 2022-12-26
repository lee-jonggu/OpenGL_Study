#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <GL/glut.h>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    GLfloat lx,ly,lz;
    GLfloat xAngle, yAngle, zAngle;
    GLfloat red, green, blue;

private:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

protected:
    void keyPressEvent(QKeyEvent* envet);
};
#endif // WIDGET_H
