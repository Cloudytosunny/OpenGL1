#include "helloopengl.h"
#include "ui_helloopengl.h"

//static Shader ourShader("../opengl1/shader/rect.vert","../opengl1/shader/rect.frag");


HelloOpenGL::HelloOpenGL(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::HelloOpenGL)
{
    //ui->setupUi(this);


}

HelloOpenGL::~HelloOpenGL()
{
    delete ui;
}

void HelloOpenGL::initializeGL()
{

    core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();

    GLfloat vertices[] = {
          0.5f,  0.5f, 0.0f, 1.0f, 1.0f,  //右上
          0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  //右下
         -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  //左下
         -0.5f,  0.5f, 0.0f, 0.0f, 1.0f   //左上
    };

    GLuint indices[] = {
        0,1,3,
        1,3,2
    };


    core->glGenVertexArrays(1, &VAO);
    core->glBindVertexArray(VAO);


    core->glGenBuffers(1,&VBO);
    core->glGenBuffers(1,&EBO);

    core->glBindBuffer(GL_ARRAY_BUFFER, VBO);
    core->glBufferData(GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);
    core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof (GLfloat), (void*)0);
    core->glEnableVertexAttribArray(0);
    core->glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof (GLfloat), (void*)(3 * sizeof(GLfloat)));
    core->glEnableVertexAttribArray(1);

    core->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    core->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices, GL_STATIC_DRAW);

    core->glBindVertexArray(0);

    core->glBindBuffer(GL_ARRAY_BUFFER,0);

    core->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    texture1 = new QOpenGLTexture(QImage("../opengl1/image/wall.jpg"));
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    texture1->setWrapMode(QOpenGLTexture::DirectionS,QOpenGLTexture::Repeat);
    texture1->setWrapMode(QOpenGLTexture::DirectionT,QOpenGLTexture::Repeat);
    texture1->setMinificationFilter(QOpenGLTexture::Nearest);
    texture1->setMagnificationFilter(QOpenGLTexture::Linear);


    ourShader = new Shader(QString("../opengl1/shader/rect.vert"),QString("../opengl1/shader/rect.frag"));
    ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("ourTexture"),0);


}
void HelloOpenGL::paintGL()
{
    if(key == "Key_P"){core->glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}
    if(key == "Key_O"){core->glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);}

    core->glClearColor(0.2f,0.3f,0.3f,1.0f);
    core->glClear(GL_COLOR_BUFFER_BIT);

    core->glActiveTexture(GL_TEXTURE0);
    texture1->bind();

    //shaderProgram.bind();
    ourShader->use();
    core->glBindVertexArray(VAO);
    //core->glDrawArrays(GL_TRIANGLES, 0, 3);
    core->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void HelloOpenGL::resizeGL(int w, int h)
{
    update();

}

void HelloOpenGL::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_P:
             key = "Key_P";
             break;
        case Qt::Key_O:
             key = "Key_O";
             break;
    }
    update();

}
