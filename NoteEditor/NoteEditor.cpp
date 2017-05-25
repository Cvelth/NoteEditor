#include "NoteEditor.h"
#include "durationHolder.hpp"

NoteEditor::NoteEditor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_duration = new DurationHolder(6, ui.durationLayout);
}
