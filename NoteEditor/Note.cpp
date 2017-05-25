#include "Note.hpp"

Note::Note(size_t note, size_t duration) {
	m_duration = duration;
	if (note > 13)
		throw IncorrectInputException();
	if (note < 7) {
		m_noteType = NoteType(note);
		m_octave = false;
	} else {
		m_noteType = NoteType(note - 7);
		m_octave = true;
	}
}

size_t Note::getPosition() {
	return size_t(m_noteType) + (m_octave ? 7 : 0);
}
