#include "Controller.hpp"
#include "DurationHolder.hpp"
#include "StaffHolder.hpp"
#include "NoteList.hpp"
#include "Player.hpp"
#include "Exceptions.h"

Controller::Controller() {
	m_notes = new NoteList();
	m_player = new Player();
}

void Controller::initializeDurationSystem(QLayout * layout) {
	m_duration = new DurationHolder(4, layout);
	m_duration->activateFirst();
}

void Controller::initializeStaffSystem(QLayout * layout) {
	m_staffs = new StaffHolder(layout, m_duration, m_notes, &m_currentType);
}

void Controller::play() {
	m_player->play(m_notes);
}

void Controller::exportMid(std::string filename) {
	m_player->exportMid(m_notes, filename);
}

void Controller::setCurrentNoteType(size_t type) {
	if (type > 2)
		throw IncorrectInputException();
	m_currentType = type;
}