#include "NoteEditor.h"
#include "durationHolder.hpp"
#include "Staff.hpp"
#include "Controller.hpp"

NoteEditor::NoteEditor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_controller.initializeDurationSystem(ui.durationLayout);
	m_controller.initializeStaffSystem(ui.StuffLayout);
	connect(ui.playButton, &QPushButton::clicked, &m_controller, &Controller::play);
}