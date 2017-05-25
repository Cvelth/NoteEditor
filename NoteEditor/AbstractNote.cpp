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

void AbstractNote::setOctave(size_t octave) {
	if (octave - 1 < 3)
		m_octave = octave;
	else
		throw IncorrectInputException();
}
