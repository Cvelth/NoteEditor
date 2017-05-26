#include "Controller.hpp"
#include "DurationHolder.hpp"
#include "StaffHolder.hpp"
#include "NoteList.hpp"
#include "Player.hpp"

Controller::Controller() {
	m_notes = new NoteList();
	m_player = new Player();
}

void Controller::initializeDurationSystem(QLayout * layout) {
	m_duration = new DurationHolder(4, layout);
}

void Controller::initializeStaffSystem(QLayout * layout) {
	m_staffs = new StaffHolder(layout, m_duration, m_notes);
}

void Controller::play() {
	m_player->play(m_notes);
}