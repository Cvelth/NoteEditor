#pragma once
#include <list>

class Note;

class NoteList {
protected:
	std::list<Note*> m_data;
public:
	NoteList();
	void addNote(Note* note);
	void removeNote(Note* note);
	std::list<Note*>::iterator begin();
	std::list<Note*>::iterator end();
};