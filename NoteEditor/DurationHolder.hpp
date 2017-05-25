#pragma once
#include "DurationButton.hpp"
#include <set>
#include "QLayout"

class DurationHolder : public QObject {
	Q_OBJECT
private:
	std::set<DurationButton*> m_buttons;
	size_t m_current;
public:
	DurationHolder(size_t number, QLayout* layout);
	~DurationHolder();
	size_t getCurrentDuration();
private slots:
	void setDuration(size_t duration);
};