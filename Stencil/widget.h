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

    GLfloat nx, ny;
    GLboolean bScissor;
    GLboolean bStencil;
    GLboolean bEqual;

private:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

protected:
    void keyPressEvent(QKeyEvent* envet);
};
#endif // WIDGET_H
