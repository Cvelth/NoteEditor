#pragma once
#include "qobject.h"

class DurationHolder;
class StaffHolder;
class NoteList;
class QLayout;
class Player;

class Controller : public QObject {
	Q_OBJECT
private:
	DurationHolder* m_duration;
	StaffHolder* m_staffs;
	NoteList* m_notes;
	Player* m_player;
	size_t m_currentType;

public:
	Controller();
	void initializeDurationSystem(QLayout* layout);
	void initializeStaffSystem(QLayout* layout);
	void play();
	void setCurrentNoteType(size_t type);
};