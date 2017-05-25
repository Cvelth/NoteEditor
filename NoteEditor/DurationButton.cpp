#include "durationButton.hpp"

void DurationButton::clickSlot(bool) {
	emit clickedSignal(m_duration);
}

DurationButton::DurationButton(size_t duration) {
	m_duration = duration;
	setText(QString::number(duration));
	setCheckable(true);
	connect(this, &QPushButton::clicked, this, &DurationButton::clickSlot);
}

size_t DurationButton::get() {
	return m_duration;
}
