#pragma once
#include "qopenglwidget.h"
#include "qopenglfunctions.h"

class Staff : public QOpenGLWidget, protected QOpenGLFunctions {
private:
	const size_t height = 100;
protected:
	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;
public:
	Staff();
	void drawNotes();
	void drawStaff();
	void drawLine(float x);
};