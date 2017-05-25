#include "NoteList.hpp"

NoteList::NoteList() {
}

void NoteList::addNote(Note* note) {
	m_data.push_back(note);
}

void NoteList::removeNote(Note * note) {
	m_data.remove(note);
}

std::list<Note*>::iterator NoteList::begin() {
	return m_data.begin();
}

std::list<Note*>::iterator NoteList::end() {
	return m_data.end();
}
