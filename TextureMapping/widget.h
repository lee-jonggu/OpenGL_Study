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

    GLfloat xAngle, yAngle, zAngle;
    GLint EnvMode;
    GLint TexFilter;

private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

protected:
    void keyPressEvent(QKeyEvent* event) override;
};
#endif // WIDGET_H
