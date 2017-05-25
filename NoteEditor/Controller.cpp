#include "Controller.hpp"
#include "DurationHolder.hpp"
#include "StaffHolder.hpp"

Controller::Controller() {
}

void Controller::initializeDurationSystem(QLayout * layout) {
	m_duration = new DurationHolder(6, layout);
}

void Controller::initializeStaffSystem(QLayout * layout) {
	m_staffs = new StaffHolder(layout, m_duration);
}
