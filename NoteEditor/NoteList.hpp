#pragma once
#include <vector>

class Note;

class NoteList {
protected:
	std::vector<Note*> m_data;
public:
	NoteList();
	void addNote(Note* note);
	size_t size();
	Note* at(size_t i);
};