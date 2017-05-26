/********************************************************************************
** Form generated from reading UI file 'NoteEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEEDITOR_H
#define UI_NOTEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoteEditorClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *StuffLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *durationLayout;
    QPushButton *playButton;

    void setupUi(QWidget *NoteEditorClass)
    {
        if (NoteEditorClass->objectName().isEmpty())
            NoteEditorClass->setObjectName(QStringLiteral("NoteEditorClass"));
        NoteEditorClass->resize(706, 522);
        verticalLayout_2 = new QVBoxLayout(NoteEditorClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(NoteEditorClass);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 686, 463));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        StuffLayout = new QVBoxLayout();
        StuffLayout->setSpacing(6);
        StuffLayout->setObjectName(QStringLiteral("StuffLayout"));

        horizontalLayout->addLayout(StuffLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        durationLayout = new QHBoxLayout();
        durationLayout->setSpacing(6);
        durationLayout->setObjectName(QStringLiteral("durationLayout"));

        horizontalLayout_3->addLayout(durationLayout);


        verticalLayout_2->addLayout(horizontalLayout_3);

        playButton = new QPushButton(NoteEditorClass);
        playButton->setObjectName(QStringLiteral("playButton"));

        verticalLayout_2->addWidget(playButton);


        retranslateUi(NoteEditorClass);

        QMetaObject::connectSlotsByName(NoteEditorClass);
    } // setupUi

    void retranslateUi(QWidget *NoteEditorClass)
    {
        NoteEditorClass->setWindowTitle(QApplication::translate("NoteEditorClass", "NoteEditor", Q_NULLPTR));
        playButton->setText(QApplication::translate("NoteEditorClass", "Play", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NoteEditorClass: public Ui_NoteEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEEDITOR_H
