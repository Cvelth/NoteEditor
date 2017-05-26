#include "NoteList.hpp"
#include "Note.hpp"

NoteList::NoteList() {
}

void NoteList::addNote(Note* note) {
	m_data.push_back(note);
}

size_t NoteList::size() {
	return m_data.size();
}

Note * NoteList::at(size_t i) {
	return m_data.at(i);
}

std::string NoteList::getMidi() {
	std::string ret;
	for (auto note : m_data)
		ret += note->getMidi() + ' ';
	return ret;
}

void NoteList::clear() {
	m_data.clear();
}
