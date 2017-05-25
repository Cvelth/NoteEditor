#include "Staff.hpp"
#include "qevent.h"
#include "Note.hpp"
#include "DurationHolder.hpp"

void Staff::initializeGL() {
	initializeOpenGLFunctions();
	glClearColor(1, 1, 1, 1);
}

void Staff::resizeGL(int w, int h) {
	float margin = 1.f;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(0, w, 0, h, 0, 1);
}

void Staff::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT);// | GL_DEPTH_BUFFER_BIT);

	drawNotes();
	drawStaff();
}

void Staff::mousePressEvent(QMouseEvent * e) {
	if (e->button() == Qt::MouseButton::LeftButton) {
		Note* note = generateNote(e->y());
	}
}

Note * Staff::generateNote(size_t y) {
	if (y >= 22 && y <= 82)
		for (int i = 22, j = 0; i < 82; i += 10, j+=2) {
			if (y < i + 6)
				return new Note(j, m_duration->getCurrentDuration());
			else if (y < i + 10) 
				return new Note(j + 1, m_duration->getCurrentDuration());
		}
	return nullptr;
}

Staff::Staff(DurationHolder* duration) {
	m_duration = duration;
	setFixedHeight(HEIGHT);
	setMinimumHeight(HEIGHT);
}

void Staff::drawNotes() {

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