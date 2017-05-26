#pragma once
#include "AbstractNote.hpp"
#include <vector>
#include <string>
#include <cmath>
using namespace std;

enum class NoteType {
	C = 0, D = 1, E = 2, F = 3, G = 4, H = 5, A = 6
};

class Note : public AbstractNote {
protected:
	NoteType m_noteType;
	size_t m_position = 48;
	bool m_flat = false;
	bool m_sharp = false;

public:
	Note(size_t note, size_t duration);
	void setNote(NoteType noteType) {
		m_noteType = noteType;
	}
	void setFlat() {
		m_flat = true;
		m_sharp = false;
	}
	void setSharp() {
		m_flat = false;
		m_sharp = true;
	}
	void setNormalNote() {
		m_flat = false;
		m_sharp = false;
	}
	size_t getPosition();
	std::string getMidi();
};
