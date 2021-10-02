#ifndef HELLOOPENGL_H
#define HELLOOPENGL_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLFunctions_3_3_Core>
#include <QDebug>
#include <QImage>
#include <QEvent>
#include <QTime>
#include <QKeyEvent>

#include "shader.h"
#include "camera.h"

namespace Ui {
class HelloOpenGL;
}

class HelloOpenGL : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit HelloOpenGL(QWidget *parent = nullptr);
    ~HelloOpenGL();

protected:

    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int w, int h);

    void keyPressEvent(QKeyEvent *event);   //键盘按下事件
    void keyReleaseEvent(QKeyEvent *event);  //键盘释放事件
    void mouseMoveEvent(QMouseEvent *event);//鼠标事件
    void wheelEvent(QWheelEvent *event);    //滚轮事件
    void mousePressEvent(QMouseEvent *event);  //鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *event); //鼠标释放事件


private:
    Ui::HelloOpenGL *ui;
    QOpenGLFunctions_3_3_Core *core;

    GLuint VBO;
    GLuint VBOTexturePostion;
    GLuint VAO;
    GLuint EBO;
    QOpenGLTexture *texture1;
    QOpenGLTexture *texture2;
    QOpenGLShaderProgram shaderProgram;
    Shader *ourShader;
    Camera *camera;
    QString key;
};

#endif // HELLOOPENGL_H
