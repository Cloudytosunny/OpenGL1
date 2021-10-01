#ifndef SHADER_H
#define SHADER_H


#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>
#include <QDebug>
#include <QString>

//class HelloOpenGL : public QOpenGLWidget
//{
//    Q_OBJECT

//public:
//    explicit HelloOpenGL(QWidget *parent = nullptr);

class Shader
{

public:

    QOpenGLShaderProgram shaderProgram;
    // ------------------------------------------------------------------------
    Shader(const QString& vertexPath, const QString& fragmentPath)
    {

            QOpenGLShader vertexShader(QOpenGLShader::Vertex);
            bool success = vertexShader.compileSourceFile(vertexPath);
            if (!success)
            {
                qDebug() << "ERROR::SHADER::VERTEX::COMPILATION_FAILED"<<endl;
                qDebug() << vertexShader.log() << endl;
            }

            QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
            success = fragmentShader.compileSourceFile(fragmentPath);
            if (!success)
            {
                qDebug() << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED"<<endl;
                qDebug() << fragmentShader.log() << endl;
            }

            shaderProgram.addShader(&vertexShader);
            shaderProgram.addShader(&fragmentShader);
            success = shaderProgram.link();
            if(!success)
            {
                qDebug() << "ERROR::SHADER::PROGRAM::LINKING_FAILED" << endl;
                qDebug() << shaderProgram.log() << endl;
            }
    }
    // ------------------------------------------------------------------------
    void use()
    {
       shaderProgram.bind();
    }

    // ------------------------------------------------------------------------
    void setMat4(const QString &name, const QMatrix4x4& value)
    {
        GLint loc = shaderProgram.uniformLocation(name);
        shaderProgram.setUniformValue(loc, value);
    }
    // ------------------------------------------------------------------------
    void setInt(const QString &name, const GLint& value)
    {
        GLint loc = shaderProgram.uniformLocation(name);
        shaderProgram.setUniformValue(loc, value);
    }
    // ------------------------------------------------------------------------
    void setFloat(const QString &name, const float& value)
    {
        GLint loc = shaderProgram.uniformLocation(name);
        shaderProgram.setUniformValue(loc, value);
    }

    void setVec4(const QString &name, QVector4D& value)
    {
        GLint loc = shaderProgram.uniformLocation(name);
        shaderProgram.setUniformValue(loc, value);
    }

    void setVec3(const QString &name, QVector3D& value)
    {
        GLint loc = shaderProgram.uniformLocation(name);
        shaderProgram.setUniformValue(loc, value);
    }

private:

};
#endif
