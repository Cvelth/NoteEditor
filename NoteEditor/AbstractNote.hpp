#pragma once
#include "Exceptions.h"

class AbstractNote {
protected:
	size_t m_duration;
	bool m_octave;
public:
	void setDuration(size_t duration);
	void setOctave(bool octave);
};