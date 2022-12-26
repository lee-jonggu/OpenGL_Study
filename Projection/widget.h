#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void drawPyramid();

    GLfloat xAngle, yAngle, zAngle;
    GLfloat left, right, bottom, top, bNear, bFar;
    GLfloat fov;
    int bProjection;
    int bObject;
    GLsizei lastWidth, lastHeight;

private:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
protected:
    void keyPressEvent(QKeyEvent* event) override;

};
#endif // WIDGET_H
