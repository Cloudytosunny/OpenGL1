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
#include <QKeyEvent>

#include "shader.h"

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

    void keyPressEvent(QKeyEvent *);


private:
    Ui::HelloOpenGL *ui;
    QOpenGLFunctions_3_3_Core *core;

    GLuint VBO;
    GLuint VAO;
    GLuint EBO;
    QOpenGLTexture *texture1;
    QOpenGLShaderProgram shaderProgram;
    Shader *ourShader;
    QString key;
};

#endif // HELLOOPENGL_H
