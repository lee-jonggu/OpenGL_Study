#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <GL/glu.h>
#include <GL/glut.h>

struct bullet {
    float ypos;
    float xpos;
    float speed;
    bullet *next;
};

struct enemy {
    float ypos;
    float xpos;
    float speed;
    enemy *next;
};

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    GLuint fliter;
    GLuint texture[4];
    GLuint base;

    bullet *headB;
    bullet *tailB;
    bullet *currentB;

    bool firstShot;
    bool enemyAround;
    float tankPosHoriz;
    float lastShot;
    float newShot;
    float lastMove, newMove;

    enemy normalEnemy;

    GLUquadricObj* quadratic;

    QTimer timer;

    void updateBullet();
    void updateEnemy();
    int loadGLTextures();

private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mousePressEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent*);

private slots:
    void updateTimer();
};
#endif // WIDGET_H
