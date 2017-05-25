#pragma once
#include <vector>
#include "qobject.h"

class Note;
class Staff;
class QLayout;
class DurationHolder;
class NoteList;

class StaffHolder : public QObject {
	Q_OBJECT
private:
	std::vector<Staff*> m_data;
	QLayout* m_layout;
	DurationHolder* m_duration;
	NoteList* m_notes;
	size_t max_id;
public:
	StaffHolder(QLayout* layout, DurationHolder* duration, NoteList* notes);
	void clearLayout(QLayout * layout);
	void updateLayout();
	void addStaff(size_t id);

public slots:
	void updateStaffs();

protected slots:
	void addNewStaff(size_t i, size_t curr_id);
};