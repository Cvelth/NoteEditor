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
#include <QtWidgets/QRadioButton>
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
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *normal;
    QRadioButton *flat;
    QRadioButton *sharp;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *playButton;
    QPushButton *exportButton;

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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 686, 436));
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        normal = new QRadioButton(NoteEditorClass);
        normal->setObjectName(QStringLiteral("normal"));
        normal->setChecked(true);

        horizontalLayout_2->addWidget(normal);

        flat = new QRadioButton(NoteEditorClass);
        flat->setObjectName(QStringLiteral("flat"));

        horizontalLayout_2->addWidget(flat);

        sharp = new QRadioButton(NoteEditorClass);
        sharp->setObjectName(QStringLiteral("sharp"));

        horizontalLayout_2->addWidget(sharp);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        playButton = new QPushButton(NoteEditorClass);
        playButton->setObjectName(QStringLiteral("playButton"));

        horizontalLayout_4->addWidget(playButton);

        exportButton = new QPushButton(NoteEditorClass);
        exportButton->setObjectName(QStringLiteral("exportButton"));

        horizontalLayout_4->addWidget(exportButton);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(NoteEditorClass);

        QMetaObject::connectSlotsByName(NoteEditorClass);
    } // setupUi

    void retranslateUi(QWidget *NoteEditorClass)
    {
        NoteEditorClass->setWindowTitle(QApplication::translate("NoteEditorClass", "NoteEditor", Q_NULLPTR));
        normal->setText(QApplication::translate("NoteEditorClass", "Normal Note", Q_NULLPTR));
        flat->setText(QApplication::translate("NoteEditorClass", "Flat", Q_NULLPTR));
        sharp->setText(QApplication::translate("NoteEditorClass", "Sharp", Q_NULLPTR));
        playButton->setText(QApplication::translate("NoteEditorClass", "Play", Q_NULLPTR));
        exportButton->setText(QApplication::translate("NoteEditorClass", "Export", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NoteEditorClass: public Ui_NoteEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEEDITOR_H
