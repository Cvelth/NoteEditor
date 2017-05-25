#pragma once

class DurationHolder;
class StaffHolder;
class NoteList;
class QLayout;

class Controller {
private:
	DurationHolder* m_duration;
	StaffHolder* m_staffs;
	NoteList* m_notes;

public:
	Controller();
	void initializeDurationSystem(QLayout* layout);
	void initializeStaffSystem(QLayout* layout);
};