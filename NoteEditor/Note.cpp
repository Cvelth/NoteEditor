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

std::string getNoteType(NoteType t) {
	switch (t) {
		case NoteType::A: return "A";
		case NoteType::C: return "C";
		case NoteType::D: return "D";
		case NoteType::E: return "E";
		case NoteType::F: return "F";
		case NoteType::G: return "G";
		case NoteType::H: return "B#";
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
	std::string ret = getNoteType(m_noteType);
	if (m_sharp) ret += '#';
	if (m_flat) ret += 'b';
	ret += (m_octave ? '6' : '5');
	ret += getDurationString(m_duration);
	return ret;
}
