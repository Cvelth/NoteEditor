#pragma once
#include "qopenglwidget.h"
#include "qopenglfunctions.h"

class Note;
class DurationHolder;

class Staff : public QOpenGLWidget, protected QOpenGLFunctions {
private:
	const size_t HEIGHT = 100;
	DurationHolder* m_duration;
protected:
	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

	Note* generateNote(size_t y);
public:
	Staff(DurationHolder* duration);
	void drawNotes();
	void drawStaff();
	void drawLine(float x);
};