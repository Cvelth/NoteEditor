#pragma once
#include <vector>

class Staff;
class QLayout;

class StaffHolder {
private:
	std::vector<Staff*> m_data;
	QLayout* m_layout;
public:
	StaffHolder(QLayout* layout);
	void updateLayout();
};