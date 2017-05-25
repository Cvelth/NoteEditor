#include "Staff.hpp"
#include "qevent.h"
#include "Note.hpp"
#include "DurationHolder.hpp"
#include "NoteList.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

void Staff::initializeGL() {
	initializeOpenGLFunctions();
	glClearColor(1, 1, 1, 1);

	glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
	glEnable(GL_BLEND);
	
	//glEnable(GL_LINE_SMOOTH);
	//glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
}

void Staff::resizeGL(int w, int h) {
	float margin = 1.f;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(0, w, 5, h + 5, 0, 1);
}

void Staff::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT);

	drawNotes();
	drawStaff();
}

void Staff::mousePressEvent(QMouseEvent * e) {
	if (e->button() == Qt::MouseButton::LeftButton) {
		if (auto note = generateNote(e->y()))
			m_notes->addNote(note);
	}
	emit updateStaffs();
	//update();
}

Note * Staff::generateNote(size_t y) {
	if (y >= 12 && y <= 82)
		for (int i = 12, j = 0; i < 82; i += 10, j += 2) {
			if (y < i + 6)
				return new Note(j, m_duration->getCurrentDuration());
			else if (y < i + 10) 
				return new Note(j + 1, m_duration->getCurrentDuration());
		}
	return nullptr;
}

void Staff::newBegin(size_t begin) {
	m_begin = begin;
}

void Staff::drawNotes() {
	size_t offset = 0;
	auto i = m_begin;
	for (; i < m_notes->size(); i++)
		if (width() - offset > 30)
			drawNote(m_notes->at(i), offset);
		else {
			emit OverflowSignal(i, m_id);
			break;
		}
}

void Staff::drawNote(Note * note, size_t& offset) {
	switch (note->getDuration()) {
		case 1:
			drawWholeNote(offset + 15, 85 - note->getPosition() * 5);
			break;
		case 2:
			drawHalfNote(offset + 15, 85 - note->getPosition() * 5, note->getOctave());
			break;
		case 4:
			drawQuarterNote(offset + 15, 85 - note->getPosition() * 5, note->getOctave());
			break;
		case 8:
			drawEighthNote(offset + 15, 85 - note->getPosition() * 5, note->getOctave());
			break;
		case 16:
			drawSixteenthNote(offset + 15, 85 - note->getPosition() * 5, note->getOctave());
			break;
	}
	if (note->getPosition() <= 1 || note->getPosition() == 13) 
		drawBar(offset + 15, 85 - note->getPosition() * 5);

	offset += 30;
}

void Staff::drawWholeNote(float x, float y) {
	drawEllipse(x, y, 9, 5, 0.f);
	drawEllipse(x, y, 4.5, 3.5, 1.f, M_PI * 5 / 12);
}

void Staff::drawHalfNote(float x, float y, bool up) {
	drawEllipse(x, y, 6.875, 4.79, 0, -M_PI * 10 / 36);
	drawEllipse(x, y, 5.3, 2.24, 1, -M_PI * 10/ 36);
	drawStick(x, y, up);
}

void Staff::drawQuarterNote(float x, float y, bool up) {
	drawEllipse(x, y, 6.875, 4.79, 0, -M_PI * 10 / 36);
	drawStick(x, y, up);
}

void Staff::drawEighthNote(float x, float y, bool up) {
	drawEllipse(x, y, 6.875, 4.79, 0, -M_PI * 10 / 36);
	drawStick(x, y, up);
	drawHook(x, y, up, 30);
}

void Staff::drawSixteenthNote(float x, float y, bool up) {
	drawEllipse(x, y, 6.875, 4.79, 0, -M_PI * 10 / 36);
	drawStick(x, y, up);
	drawHook(x, y, up, 30);
	drawSubHook(x, y, up, 40);
}
void Staff::drawEllipse(float ox, float oy, float cx, float cy, float color, float angle) {
	glBegin(GL_POLYGON);
	glColor3f(color, color, color);
	for (float f = 0; f < 2 * M_PI; f += M_PI / 10) {
		float cf = cosf(angle);
		float sf = -sinf(angle);
		float fx = cx * cosf(f);
		float fy = cy * sinf(f);
		glVertex2f(fx * cf - fy * sf + ox, fx * sf + fy * cf + oy);
	}
	glEnd();
}

void Staff::drawStick(float x, float y, bool up) {
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x + 5.8, y + 3);
	glVertex2f(x + 5.8, y + 3 + (up ? +39 : -39));
	glVertex2f(x + 5.8 - 1, y + 3 + (up ? +39 : -39));
	glVertex2f(x + 5.8 - 1, y + 3);
	glEnd();
}

void Staff::drawBar(float x, float y) {
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x - 12, y);
	glVertex2f(x + 12, y);
	glEnd();
}

#define D(up) (up ? 1 : -1)

void Staff::drawHook(float x, float y, bool up, float offset) {
	glBegin(GL_QUAD_STRIP);
	glColor3f(0, 0, 0);
	x += 5.8;
	y += 3;
	glVertex2f(x - 1, y + D(up) * (offset + 10));
	glVertex2f(x + 3.5, y + D(up) * (offset - 1));
	glVertex2f(x - 1, y + D(up) * (offset + 0));
	glVertex2f(x + 2.7, y + D(up) * (offset + 6.25));
	glVertex2f(x + 5.5, y + D(up) * (offset - 2));
	glVertex2f(x + 3.75, y + D(up) * (offset + 3.5));
	glVertex2f(x + 6.75, y + D(up) * (offset - 3.5));
	glVertex2f(x + 6.4, y + D(up) * (offset - 0.1));
	glVertex2f(x + 8.3, y + D(up) * (offset - 5.5));
	glVertex2f(x + 9.2, y + D(up) * (offset - 3.5));
	glVertex2f(x + 11.2, y + D(up) * (offset - 6.1));
	glVertex2f(x + 10.8, y + D(up) * (offset - 6.5));
	glVertex2f(x + 10.6, y + D(up) * (offset - 8.9));
	glVertex2f(x + 11.4, y + D(up) * (offset - 8.4));
	glVertex2f(x + 10.9, y + D(up) * (offset - 12.5));
	glVertex2f(x + 12, y + D(up) * (offset - 12.9));
	glVertex2f(x + 10.5, y + D(up) * (offset - 16.4));
	glVertex2f(x + 11.4, y + D(up) * (offset - 16.9));
	glVertex2f(x + 9.5, y + D(up) * (offset - 18.75));
	glVertex2f(x + 10.4, y + D(up) * (offset - 20));
	glVertex2f(x + 9.4, y + D(up) * (offset - 21.5));
	
	glEnd();
}

void Staff::drawSubHook(float x, float y, bool up, float offset) {
	glBegin(GL_QUAD_STRIP);
	glColor3f(0, 0, 0);
	x += 5.8;
	y += 3;
	glVertex2f(x - 1, y + D(up) * (offset + 10));
	glVertex2f(x + 3.5, y + D(up) * (offset - 1));
	glVertex2f(x - 1, y + D(up) * (offset + 0));
	glVertex2f(x + 2.7, y + D(up) * (offset + 6.25));
	glVertex2f(x + 5.5, y + D(up) * (offset - 2));
	glVertex2f(x + 3.75, y + D(up) * (offset + 3.5));
	glVertex2f(x + 6.75, y + D(up) * (offset - 3.5));
	glVertex2f(x + 6.4, y + D(up) * (offset - 0.1));
	glVertex2f(x + 10.9, y + D(up) * (offset - 8.5));
	glVertex2f(x + 12, y + D(up) * (offset - 8.9));
	glVertex2f(x + 10.5, y + D(up) * (offset - 12.4));
	glVertex2f(x + 11.4, y + D(up) * (offset - 12.9));
	glVertex2f(x + 9.5, y + D(up) * (offset - 14.75));
	glVertex2f(x + 10.4, y + D(up) * (offset - 16));
	glVertex2f(x + 9.4, y + D(up) * (offset - 17.5));

	glEnd();
}
void Staff::drawStaff() {
	glBegin(GL_LINES);
	glLineWidth(3);
	glColor3f(0, 0, 0);
	for (int i = -2; i <= 2; i++)
		drawLine(0.5 * HEIGHT - 0.1 * i * HEIGHT);
	glEnd();
}

void Staff::drawLine(float y) {
	glVertex2f(0, y);
	glVertex2f(width(), y);
}

Staff::Staff(DurationHolder * duration, NoteList * notes, size_t begin, size_t id) 
		: m_duration(duration), m_notes(notes), m_begin(begin), m_id(id) {
	setFixedHeight(HEIGHT);
	setMinimumHeight(HEIGHT);
}
