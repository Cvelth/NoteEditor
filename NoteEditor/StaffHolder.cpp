#include "StaffHolder.hpp"
#include "Staff.hpp"
#include "qlayout.h"
#include "NoteList.hpp"

StaffHolder::StaffHolder(QLayout * layout, DurationHolder * duration, NoteList * notes, size_t * type)
	: m_duration(duration), m_layout(layout), m_notes(notes), m_currentType(type) {
	addStaff(0);
}

void StaffHolder::clearLayout(QLayout* layout) {
	while (QLayoutItem* item = layout->takeAt(0)) {
		disconnect(item->widget(), 0, 0, 0);
		layout->removeItem(item);
	}
}

void StaffHolder::updateLayout() {
	clearLayout(m_layout);
	for (auto t : m_data)
		m_layout->addWidget(t);
	m_layout->addItem(new QSpacerItem(1, 1, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
}

void StaffHolder::addStaff(size_t i) {
	auto t = new Staff(m_duration, m_notes, i, max_id++, m_currentType);
	connect(t, &Staff::OverflowSignal, this, &StaffHolder::addNewStaff);
	connect(t, &Staff::updateStaffs, this, &StaffHolder::updateStaffs);
	m_data.push_back(t);
	updateLayout();
}

void StaffHolder::updateStaffs() {
	m_data.clear();
	max_id = 0;
	addStaff(0);
}

void StaffHolder::addNewStaff(size_t i, size_t curr_id) {
	if (curr_id >= max_id - 1)
		addStaff(i);
	else {
		m_data.at(curr_id + 1)->newBegin(i);
		m_data.at(curr_id + 1)->update();
	}
}