#include "AbstractNote.hpp"
#include <cmath>
using namespace std;

void AbstractNote::setDuration(size_t duration) {
	double temp = log2(duration);
	if (abs(temp - round(temp)) < 0.01)
		m_duration = duration;
	else
		throw IncorrectInputException();
}

void AbstractNote::setOctave(bool octave) {
	m_octave = octave;
}

size_t AbstractNote::getDuration() {
	return m_duration;
}
