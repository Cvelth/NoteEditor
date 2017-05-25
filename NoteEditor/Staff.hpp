#pragma once
#include "qopenglwidget.h"
#include "qopenglfunctions.h"

class Note;
class DurationHolder;
class NoteList;

class Staff : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT
private:
	const size_t HEIGHT = 100;
	DurationHolder* m_duration;
	NoteList* m_notes;
	size_t m_begin;
	size_t m_id;
protected:
	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

	Note* generateNote(size_t y);

	void drawNotes();
	void drawNote(Note* note, size_t& offset);
	void drawWholeNote(float x, float y);
	void drawHalfNote(float x, float y, bool up);
	void drawQuarterNote(float x, float y, bool up);
	void drawEighthNote(float x, float y, bool up);
	void drawSixteenthNote(float x, float y, bool up);
	void drawEllipse(float ox, float oy, float cx, float cy, float color = 0.f, float angle = 0.f);
	void drawStick(float x, float y, bool up);
	void drawBar(float x, float y);
	void drawHook(float x, float y, bool up, float offset);
	void drawSubHook(float x, float y, bool up, float offset);
	void drawStaff();
	void drawLine(float x);
public:
	Staff(DurationHolder* duration, NoteList* notes, size_t begin, size_t id);
	
	void newBegin(size_t begin);
signals:
	void OverflowSignal(size_t index, size_t id);
	void updateStaffs();
};