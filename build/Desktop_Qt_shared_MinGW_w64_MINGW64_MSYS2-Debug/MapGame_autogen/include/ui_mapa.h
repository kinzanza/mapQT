/********************************************************************************
** Form generated from reading UI file 'mapa.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPA_H
#define UI_MAPA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mapa
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mapa)
    {
        if (Mapa->objectName().isEmpty())
            Mapa->setObjectName("Mapa");
        Mapa->resize(800, 600);
        centralwidget = new QWidget(Mapa);
        centralwidget->setObjectName("centralwidget");
        Mapa->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mapa);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        Mapa->setMenuBar(menubar);
        statusbar = new QStatusBar(Mapa);
        statusbar->setObjectName("statusbar");
        Mapa->setStatusBar(statusbar);

        retranslateUi(Mapa);

        QMetaObject::connectSlotsByName(Mapa);
    } // setupUi

    void retranslateUi(QMainWindow *Mapa)
    {
        Mapa->setWindowTitle(QCoreApplication::translate("Mapa", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mapa: public Ui_Mapa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPA_H
