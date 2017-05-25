#include "StaffHolder.hpp"
#include "Staff.hpp"
#include "qlayout.h"

StaffHolder::StaffHolder(QLayout * layout, DurationHolder * duration) {
	m_duration = duration;
	m_layout = layout;
	auto t = new Staff(m_duration);
	m_data.push_back(t);
	updateLayout();
}

void clearLayout(QLayout* layout) {
	while (QLayoutItem* item = layout->takeAt(0)) {
		if (QLayout* childLayout = item->layout())
			clearLayout(childLayout);
		delete item;
	}
}

void StaffHolder::updateLayout() {
	clearLayout(m_layout);
	for (auto t : m_data)
		m_layout->addWidget(t);
	m_layout->addItem(new QSpacerItem(1, 1, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
}