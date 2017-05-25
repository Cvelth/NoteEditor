#pragma once
#include <vector>

class Staff;
class QLayout;
class DurationHolder;
class NoteList;

class StaffHolder {
private:
	std::vector<Staff*> m_data;
	QLayout* m_layout;
	DurationHolder* m_duration;
	NoteList* m_notes;
public:
	StaffHolder(QLayout* layout, DurationHolder* duration, NoteList* notes);
	void updateLayout();
};