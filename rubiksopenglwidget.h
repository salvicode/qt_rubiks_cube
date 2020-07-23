#ifndef RUBIKSOPENGLWIDGET_H
#define RUBIKSOPENGLWIDGET_H

#include <QColor>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#define RGB_MIN 1
#define RGB_MAX 255

class RubiksOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit RubiksOpenGLWidget(QWidget *parent = nullptr);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
};

#endif // RUBIKSOPENGLWIDGET_H
