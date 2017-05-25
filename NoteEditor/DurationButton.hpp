#pragma once
#include <QPushButton>

class DurationButton : public QPushButton {
	Q_OBJECT

private:
	size_t m_duration;
public:
	DurationButton(size_t duration);	
	size_t get();

signals:
	void clickedSignal(int);
private slots:
	void clickSlot(bool);
};