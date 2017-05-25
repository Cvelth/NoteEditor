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
	
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
}

void Staff::resizeGL(int w, int h) {
	float margin = 1.f;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(0, w, 0, h, 0, 1);
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
	update();
}

Note * Staff::generateNote(size_t y) {
	if (y >= 12 && y <= 82)
		for (int i = 12, j = 0; i < 82; i += 10, j+=2) {
			if (y < i + 6)
				return new Note(j, m_duration->getCurrentDuration());
			else if (y < i + 10) 
				return new Note(j + 1, m_duration->getCurrentDuration());
		}
	return nullptr;
}

Staff::Staff(DurationHolder * duration, NoteList * notes) {
	m_duration = duration;
	m_notes = notes;
	setFixedHeight(HEIGHT);
	setMinimumHeight(HEIGHT);
}

void Staff::drawNotes() {
	size_t offset = 0;
	for (auto it = m_notes->begin(); it != m_notes->end(); it++)
		drawNote(*it, offset);
}

void Staff::drawNote(Note * note, size_t& offset) {
	if (note->getDuration() == 1) {
		drawOuterOval(offset + 15, 85 - note->getPosition() * 5);
		drawInnerOval(offset + 15, 85 - note->getPosition() * 5);
		offset += 30;
	}
}

void Staff::drawOuterOval(size_t x, size_t y) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (float f = 0; f < 2 * M_PI; f += M_PI / 10)
		glVertex2f(9 * cosf(f) + x, 5 * sinf(f) + y);
	glEnd();
}

void Staff::drawInnerOval(size_t x, size_t y) {
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (float f = 0; f < 2 * M_PI; f += M_PI / 10) {
		float cx =  cosf(M_PI / 3);
		float cy = -sinf(M_PI / 3);
		float fx = 4.5 * cosf(f);
		float fy = 3.5 * sinf(f);
		glVertex2f(fx * cx - fy * cy + x, fx * cy + fy * cx + y);
	}
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