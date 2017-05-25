#pragma once

#include <QtWidgets/QWidget>
#include "ui_NoteEditor.h"

class NoteEditor : public QWidget
{
	Q_OBJECT

public:
	NoteEditor(QWidget *parent = Q_NULLPTR);

private:
	Ui::NoteEditorClass ui;
};
