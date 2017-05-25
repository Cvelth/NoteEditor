#include "Staff.hpp"

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

Staff::Staff() {
	setFixedHeight(height);
	setMinimumHeight(height);
}

void Staff::drawNotes() {

}

void Staff::drawStaff() {
	glBegin(GL_LINES);
	glLineWidth(3);
	glColor3f(0, 0, 0);

	for (int i = -2; i <= 2; i++)
		drawLine(0.5 * height - 0.1 * i * height);

	glEnd();
}

void Staff::drawLine(float y) {
	glVertex2f(0, y);
	glVertex2f(width(), y);
}