#pragma once
#include <QtWidgets/QWidget>
#include "ui_NoteEditor.h"
#include "Controller.hpp"


class NoteEditor : public QWidget
{
	Q_OBJECT

public:
	NoteEditor(QWidget *parent = Q_NULLPTR);

protected:

private:
	Controller m_controller;
	Ui::NoteEditorClass ui;
};
