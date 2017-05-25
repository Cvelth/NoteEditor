#pragma once
#include "Exceptions.h"

class AbstractNote {
protected:
	size_t m_duration;
	size_t m_octave;
public:
	void setDuration(size_t duration);

	void setOctave(size_t octave);
	

};