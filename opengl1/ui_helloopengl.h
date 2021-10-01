/********************************************************************************
** Form generated from reading UI file 'helloopengl.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOOPENGL_H
#define UI_HELLOOPENGL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloOpenGL
{
public:

    void setupUi(QWidget *HelloOpenGL)
    {
        if (HelloOpenGL->objectName().isEmpty())
            HelloOpenGL->setObjectName(QStringLiteral("HelloOpenGL"));
        HelloOpenGL->resize(400, 300);

        retranslateUi(HelloOpenGL);

        QMetaObject::connectSlotsByName(HelloOpenGL);
    } // setupUi

    void retranslateUi(QWidget *HelloOpenGL)
    {
        HelloOpenGL->setWindowTitle(QApplication::translate("HelloOpenGL", "HelloOpenGL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HelloOpenGL: public Ui_HelloOpenGL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOOPENGL_H
