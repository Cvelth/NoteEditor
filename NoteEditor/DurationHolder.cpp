#include "DurationHolder.hpp"

DurationHolder::DurationHolder(size_t number, QLayout* layout) {
	for (size_t i = 0; i <= number; i++) {
		auto b = new DurationButton(1 << i);
		QObject::connect(b, &DurationButton::clickedSignal, this, &DurationHolder::setDuration);
		layout->addWidget(b);
		m_buttons.insert(b);
	}	
}

DurationHolder::~DurationHolder() {
	for (auto it : m_buttons)
		delete it;
}

size_t DurationHolder::getCurrentDuration() {
	return m_current;
}

void DurationHolder::activateFirst() {
	(*m_buttons.begin())->click();
}

void DurationHolder::setDuration(size_t duration) {
	m_current = duration;
	for (auto it : m_buttons)
		if (it->get() != duration)
			it->setChecked(false);
}