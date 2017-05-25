#pragma once
#include "AbstractNote.hpp"
#include <vector>
#include <cmath>
using namespace std;

enum class NoteType {
	C, D, E, F, G, H, A
};

class Note {
protected:
	NoteType m_noteType;
	bool m_flat;
	bool m_sharp;

public:
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
};
