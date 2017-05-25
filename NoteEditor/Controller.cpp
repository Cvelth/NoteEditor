#include "Controller.hpp"
#include "DurationHolder.hpp"
#include "StaffHolder.hpp"
#include "NoteList.hpp"

Controller::Controller() {
	m_notes = new NoteList();
}

void Controller::initializeDurationSystem(QLayout * layout) {
	m_duration = new DurationHolder(4, layout);
}

void Controller::initializeStaffSystem(QLayout * layout) {
	m_staffs = new StaffHolder(layout, m_duration, m_notes);
}
