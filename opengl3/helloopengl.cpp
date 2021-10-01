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
    core->glEnable(GL_DEPTH_TEST);
    GLfloat vertices[] = {
                -0.5f, -0.5f, -0.5f,
                 0.5f, -0.5f, -0.5f,
                 0.5f,  0.5f, -0.5f,
                 0.5f,  0.5f, -0.5f,
                -0.5f,  0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,

                -0.5f, -0.5f,  0.5f,
                 0.5f, -0.5f,  0.5f,
                 0.5f,  0.5f,  0.5f,
                 0.5f,  0.5f,  0.5f,
                -0.5f,  0.5f,  0.5f,
                -0.5f, -0.5f,  0.5f,

                -0.5f,  0.5f,  0.5f,
                -0.5f,  0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f,  0.5f,
                -0.5f,  0.5f,  0.5f,

                 0.5f,  0.5f,  0.5f,
                 0.5f,  0.5f, -0.5f,
                 0.5f, -0.5f, -0.5f,
                 0.5f, -0.5f, -0.5f,
                 0.5f, -0.5f,  0.5f,
                 0.5f,  0.5f,  0.5f,

                -0.5f, -0.5f, -0.5f,
                 0.5f, -0.5f, -0.5f,
                 0.5f, -0.5f,  0.5f,
                 0.5f, -0.5f,  0.5f,
                -0.5f, -0.5f,  0.5f,
                -0.5f, -0.5f, -0.5f,

                -0.5f,  0.5f, -0.5f,
                 0.5f,  0.5f, -0.5f,
                 0.5f,  0.5f,  0.5f,
                 0.5f,  0.5f,  0.5f,
                -0.5f,  0.5f,  0.5f,
                -0.5f,  0.5f, -0.5f
    };

    GLfloat verticesTexturePostion[] = {
            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,

            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,

            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,

            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,

            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f,

            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f
        };



    core->glGenVertexArrays(1, &VAO);
    core->glBindVertexArray(VAO);

    core->glGenBuffers(1,&VBO);
    core->glGenBuffers(1,&VBOTexturePostion);

    core->glBindBuffer(GL_ARRAY_BUFFER, VBO);
    core->glBufferData(GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);
    core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof (GLfloat), (void*)0);
    core->glEnableVertexAttribArray(0);

    core->glBindBuffer(GL_ARRAY_BUFFER, VBOTexturePostion);
    core->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTexturePostion), verticesTexturePostion, GL_STATIC_DRAW);
    core->glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    core->glEnableVertexAttribArray(1);

    core->glBindVertexArray(0);

    core->glBindBuffer(GL_ARRAY_BUFFER,0);



    texture1 = new QOpenGLTexture(QImage("../opengl3/image/wall.jpg").mirrored(),QOpenGLTexture::GenerateMipMaps);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    texture1->setWrapMode(QOpenGLTexture::DirectionS,QOpenGLTexture::Repeat);
    texture1->setWrapMode(QOpenGLTexture::DirectionT,QOpenGLTexture::Repeat);
    texture1->setMinificationFilter(QOpenGLTexture::Nearest);
    texture1->setMagnificationFilter(QOpenGLTexture::Linear);

    texture2 = new QOpenGLTexture(QImage("../opengl3/image/face.bmp").mirrored(),QOpenGLTexture::GenerateMipMaps);
    texture2->setWrapMode(QOpenGLTexture::Repeat);
    texture2->setWrapMode(QOpenGLTexture::DirectionS,QOpenGLTexture::Repeat);
    texture2->setWrapMode(QOpenGLTexture::DirectionT,QOpenGLTexture::Repeat);
    texture2->setMinificationFilter(QOpenGLTexture::Nearest);
    texture2->setMagnificationFilter(QOpenGLTexture::Linear);


    ourShader = new Shader(QString("../opengl3/shader/rect.vert"),QString("../opengl3/shader/rect.frag"));
    ourShader->use();
    ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("ourTexture"),0);
    ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("ourTexture2"),1);


}
void HelloOpenGL::paintGL()
{
    if(key == "Key_P"){core->glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}
    if(key == "Key_O"){core->glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);}

    core->glClearColor(0.2f,0.3f,0.3f,1.0f);
    core->glClear(GL_COLOR_BUFFER_BIT);

    core->glActiveTexture(GL_TEXTURE0);
    texture1->bind();
    core->glActiveTexture(GL_TEXTURE1);
    texture2->bind();

    //shaderProgram.bind();
    ourShader->use();
    core->glBindVertexArray(VAO);
    //core->glDrawArrays(GL_TRIANGLES, 0, 3);

    QMatrix4x4 modelmat ;//model矩阵,负责物体坐标->世界坐标
    modelmat.rotate(QTime::currentTime().msecsSinceStartOfDay() / 500.0, QVector3D(0.4f, 0.3f, 0.7f));
    ourShader->setMat4("model", modelmat);

    QMatrix4x4 viewmat;//用于给摄像机的观察矩阵，可以看作是给全部绘制物体的统一model2矩阵
    ourShader->setMat4("view", viewmat);

    QMatrix4x4 projectionmat;//三维转二维的透视投影矩阵，近大远小
    projectionmat.perspective(0.0f, (GLfloat)width() / (GLfloat)height(), 0.1f, 100.f);
    ourShader->setMat4("projection", projectionmat);


    core->glDrawArrays(GL_TRIANGLES, 0, 36);
    update();
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
