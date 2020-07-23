#include "rubiksopenglwidget.h"
#include "mathutils.h"
#include "colorutils.h"

RubiksOpenGLWidget::RubiksOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}

void RubiksOpenGLWidget::initializeGL()
{
    float r, g, b, a = MathUtils::normalize_0_1(255.0f, RGB_MIN, RGB_MAX);
    initializeOpenGLFunctions();
    ColorUtils::qColorToRGB_0_1(Qt::black, r, g, b);
    glClearColor(r, g, b, a);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}
void RubiksOpenGLWidget::paintGL()
{
    float r, g, b;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //X axis
    glBegin(GL_LINES);
    ColorUtils::qColorToRGB_0_1(Qt::red, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();

    //Y axis
    glBegin(GL_LINES);
    ColorUtils::qColorToRGB_0_1(Qt::blue, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();

    //Z axis
    glBegin(GL_LINES);
    ColorUtils::qColorToRGB_0_1(Qt::green, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glEnd();

    //Triangle
    glBegin(GL_TRIANGLES);
    ColorUtils::qColorToRGB_0_1(Qt::green, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glEnd();
}
void RubiksOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
