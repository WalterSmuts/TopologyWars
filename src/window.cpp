#include "window.h"

Window::Window(QWidget *parent) :
	QWidget(parent)
{
	//Window Constructor
}

void Window::paintEvent(QPaintEvent *event)
{
	//Setup Painter
	QPainter painter;
	painter.begin(this);

	//Paint black background
	painter.fillRect(event->rect(), Qt::black);
	//Paint 10x10 red square in middle of screen
	painter.fillRect(event->rect().width()/2-5, event->rect().height()/2-5, 10, 10, Qt::red);

	//Finalize Paint event
	QWidget::paintEvent(event);
	painter.end();
}
