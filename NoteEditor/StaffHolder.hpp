#pragma once
#include <vector>

class Staff;
class QLayout;
class DurationHolder;

class StaffHolder {
private:
	std::vector<Staff*> m_data;
	QLayout* m_layout;
	DurationHolder* m_duration;
public:
	StaffHolder(QLayout* layout, DurationHolder* duration);
	void updateLayout();
};