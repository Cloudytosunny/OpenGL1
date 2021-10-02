#include "camera.h"

#include <QDebug>

QMatrix4x4 Camera::getViewMat()
{
	QMatrix4x4 view;
    if(!isMouseRightPress)
    {view.lookAt(cameraPos, cameraTarget, cameraUp); cameraDirection = cameraTarget - cameraPos;}
    else
    {
        view.lookAt(this->cameraPos, this->cameraPos + this->cameraDirection, this->cameraUp);
    }
	return view;
}

void Camera::DealKeyInput(CameraMovement direction)
{
	GLfloat velocity = this->movementSpeed;
	if (direction == FORWARD)
		this->cameraPos += this->cameraDirection * velocity;
	if (direction == BACKWARD)
		this->cameraPos -= this->cameraDirection * velocity;
	if (direction == LEFT)
		this->cameraPos -= this->cameraRight * velocity;
	if (direction == RIGHT)
		this->cameraPos += this->cameraRight * velocity;
	if (direction == UP)
		this->cameraPos += QVector3D(0.0f, 1.0f, 0.0f) * velocity;
	if (direction == DOWN)
		this->cameraPos -= QVector3D(0.0f, 1.0f, 0.0f) * velocity;

}

void Camera::DealMouseMovement(GLfloat Xoffset, GLfloat Yoffset)
{
	Xoffset *= this->sensitivity;
	Yoffset *= this->sensitivity;
    if(!isMouseRightPress)
    {
    lastXoffset += Xoffset;
    lastYoffset += Yoffset;
    if (lastYoffset < GLfloat(0.001))
    {lastYoffset -= Yoffset;}
    if (lastYoffset > GLfloat(3.141))
    {lastYoffset -= Yoffset;}


    float radius = 10.0f;
    cameraPos.setX(sin(-lastXoffset) * sin(-lastYoffset) * radius);
    cameraPos.setY(cos(-lastYoffset) * radius);
    cameraPos.setZ(cos(-lastXoffset) * sin(-lastYoffset) * radius);

    cameraTarget = QVector3D(0.0, 0.0f, 0.0f);//相机对的方向上任意一个向量
    cameraDirection = QVector3D(cameraPos - cameraTarget);//相机朝向，正常都是正对z的负半轴方向
    this->cameraRight = QVector3D::crossProduct(this->cameraDirection, QVector3D(0.0f, 1.0f, 0.0f)).normalized();
    this->cameraUp = QVector3D::crossProduct(this->cameraRight, this->cameraDirection).normalized();

    }
    else
    {

        this->yaw += Xoffset;
        this->pitch += Yoffset;

            if (this->pitch > 89.0f)
                this->pitch = 89.0f;
            if (this->pitch < -89.0f)
                this->pitch = -89.0f;


        this->UpdateCameraLookatMatVectors();
    }



}

void Camera::DealMouseScroll(GLfloat Yoffset)
{
	if (this->zoom >= 1.0f && this->zoom <= 45.0f)
		this->zoom -= Yoffset;
	if (this->zoom > 45.0f)
		this->zoom = 45.0f;
	if (this->zoom < 1.0f)
		this->zoom = 1.0f;
}

void Camera::DealKeyboardInputs()
{

	if (keys[Qt::Key_W])
		DealKeyInput(FORWARD);
	if (keys[Qt::Key_S])
		DealKeyInput(BACKWARD);
	if (keys[Qt::Key_A])
		DealKeyInput(LEFT);
	if (keys[Qt::Key_D])
		DealKeyInput(RIGHT);
	if (keys[Qt::Key_E])
		DealKeyInput(UP);
	if (keys[Qt::Key_Q])
		DealKeyInput(DOWN);
}

void Camera::UpdateCameraLookatMatVectors()
{
    QVector3D Direction(cos(this->yaw) * cos(this->pitch), sin(this->pitch), sin(this->yaw) * cos(this->pitch));
	this->cameraDirection = Direction.normalized();
	this->cameraRight = QVector3D::crossProduct(this->cameraDirection, QVector3D(0.0f, 1.0f, 0.0f)).normalized();
	this->cameraUp = QVector3D::crossProduct(this->cameraRight, this->cameraDirection).normalized();
}

void Camera::DealMouseRightPress()
{
    if(isMouseRightPress)
    {
        lastcameraPos = cameraPos;
        cameraPos = QVector3D(0.0f, 0.0f, 0.0f);//相机位置
        zoom = 45.0f;//投影矩阵的那个角度
        yaw = -86.39f;             //偏航角
        pitch = 0.0f;           //俯视角
    }
    else
    {
       cameraPos = lastcameraPos;
       zoom = 9.0f;
    }

}
