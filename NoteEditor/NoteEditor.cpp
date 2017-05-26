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
	connect(ui.normal, &QRadioButton::clicked, this, &NoteEditor::normal);
	connect(ui.flat, &QRadioButton::clicked, this, &NoteEditor::flat);
	connect(ui.sharp, &QRadioButton::clicked, this, &NoteEditor::sharp);
	connect(ui.exportButton, &QRadioButton::clicked, this, &NoteEditor::exportMid);
	connect(ui.clearButton, &QRadioButton::clicked, this, &NoteEditor::clear);
}
void NoteEditor::normal() {
	m_controller.setCurrentNoteType(0);
}
void NoteEditor::flat() {
	m_controller.setCurrentNoteType(1);
}
void NoteEditor::sharp() {
	m_controller.setCurrentNoteType(2);
}

void NoteEditor::exportMid() {
	m_controller.exportMid("exportedFile.mid");
}

void NoteEditor::clear() {
	m_controller.clear();
}
