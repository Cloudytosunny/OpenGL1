#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
#include <QMatrix4x4>
#include <QKeyEvent>
#include <QOpenGLShader>//为了glfloat 这些变量，所以引进这个头文件
#include <QDebug>


enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};


class Camera {
public:
	Camera(QVector3D position = QVector3D(0.0f, 0.0f, 0.0f), int width = 300,int height=300)
		 {

		this->cameraPos = position;
		this->lastX = width / 2;
		this->lastY = height / 2;
        this->DealMouseMovement(0, 0);
        //this->UpdateCameraLookatMatVectors();

	}

	






public:
	QMatrix4x4 getViewMat(); //返回view矩阵函数

	void DealMouseMovement(GLfloat Xoffset, GLfloat Yoffset); //理鼠标操作带来的矩阵变化函数,offset偏离量
	void DealMouseScroll(GLfloat Yoffset);//鼠标滚轮事件
	void DealKeyboardInputs();//***每次渲染主动调用，处理存储的所有键盘事件！
	void DealKeyInput(CameraMovement direction);//键盘处理事件函数，单个
    void DealMouseRightPress();

	void UpdateCameraLookatMatVectors();//更新有关lookat的三个变量
	



public://成员变量

	//相机有关
	QVector3D cameraPos = QVector3D(0.0f, 0.0f, 0.0f);//相机位置
    QVector3D lastcameraPos = QVector3D(0.0f, 0.0f, 0.0f);//相机位置

    QVector3D cameraTarget = QVector3D(0.0, 0.0f, 0.0f);//相机对的方向上任意一个向量
	QVector3D cameraDirection = QVector3D(cameraPos - cameraTarget);//相机朝向，正常都是正对z的负半轴方向
	QVector3D cameraUp = QVector3D(0.0f, 1.0f, 0.0f);//正常指向y的正半轴
	QVector3D cameraRight = QVector3D::crossProduct(cameraDirection, cameraUp);//这里原本也可以是x轴正方向，但我们为了普适性更好一些，将其进行叉乘

																			   
	//鼠标有关
    GLfloat sensitivity = 0.01f;     //鼠标灵敏度
    GLfloat movementSpeed = 0.1f;     //键盘移动速度
    GLfloat zoom = 9.0f;//投影矩阵的那个角度
		//欧拉角,水平的移动影响偏航角，竖直的移动影响俯仰角
    GLfloat yaw = -86.39f;             //偏航角
	GLfloat pitch = 0.0f;           //俯视角
			//cameraDirection.setX(cos(yaw)*cos(pitch));
			//cameraDirection.setY(sin(pitch));
			//cameraDirection.setZ(sin(yaw)*cos(pitch));
			//鼠标是否按下
	GLboolean isFirstMouse = GL_TRUE;
	GLboolean isLeftMousePress = GL_FALSE;
    GLboolean isMouseRightPress = GL_FALSE;


	//屏幕坐标,上一次的位置
	GLint lastX;
	GLint lastY;
    GLfloat lastXoffset = 0;
    GLfloat lastYoffset = GLfloat(1.570796);



	//键盘多键触控所需
	GLboolean keys[1024] = {0};


};
#endif // CAMERA_H
