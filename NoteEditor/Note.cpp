#include "Note.hpp"
#include "qstring.h"

Note::Note(size_t note, size_t duration) : m_flat(false), m_sharp(false), m_position(note) {
	m_duration = duration;
	if (note > 13)
		throw IncorrectInputException();
	if (note < 7) {
		m_noteType = NoteType(6 - note);
		m_octave = false;
	} else {
		m_noteType = NoteType(13 - note);
		m_octave = true;
	}
}

size_t Note::getPosition() {
	return m_position;
}

size_t getNoteType(size_t t) {
	switch (t) {
		case 0:  return 83;//60;
		case 1:  return 81;//62;
		case 2:  return 79;//64;
		case 3:  return 77;//65;
		case 4:  return 76;//67;
		case 5:  return 74;//69;
		case 6:  return 72;//71;
		case 7:  return 71;//72;
		case 8:  return 69;//74;
		case 9:  return 67;//76;
		case 10: return 65;//77;
		case 11: return 64;//79;
		case 12: return 62;//81;
		case 13: return 60;//83;
	}
}

char getDurationString(size_t duration) {
	switch (duration) {
		case 1: return 'w';
		case 2: return 'h';
		case 4: return 'q';
		case 8: return 'i';
		case 16: return 's';
		case 32: return 't';
		case 64: return 'x';
		case 128: return 'o';
	}
}

std::string Note::getMidi() {
	std::string ret;
	ret += "[" + QString::number(getNoteType(m_position) + (m_sharp ? 1 : 0) - (m_flat ? 1 : 0)).toStdString() + "]";
	ret += getDurationString(m_duration);
	return ret;
}
