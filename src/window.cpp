#include "window.h"
#include <iostream>
using namespace std;

Window::Window(QWidget *parent) :
	QWidget(parent)
{
	//Window Constructor
	colour = Qt::red;
	rect = QRectF(0, 0, 10, 10);
	startTimer(20);
	left = false;
	right = false;
	up = false;
	down = false;
}

void Window::paintEvent(QPaintEvent *event)
{
	//Setup Painter
	QPainter painter;
	painter.begin(this);

	//Paint black background
	painter.fillRect(event->rect(), Qt::black);
	//Paint 10x10 red square in middle of screen
	painter.fillRect(this->rect, colour);

	//Finalize Paint event
	QWidget::paintEvent(event);
	painter.end();
}

void Window::keyPressEvent(QKeyEvent *event){
	if (event->isAutoRepeat()) return;
	cout << "KeyPress!!! " << event->key() << endl;
	if (event->key() == LEFT) 	left = true;
	if (event->key() == RIGHT)	right = true;
	if (event->key() == UP) 	up = true;
	if (event->key() == DOWN) 	down = true;

	if (event->key() == EXIT) this->close();
}

void Window::keyReleaseEvent(QKeyEvent *event){
	if (event->isAutoRepeat()) return;
	cout << "KeyRelease!!! " << event->key() << endl;
	if (event->key() == LEFT)	left = false;
	if (event->key() == RIGHT)	right = false;
	if (event->key() == UP)		up = false;
	if (event->key() == DOWN)	down = false;
}

void Window::timerEvent(QTimerEvent *event)
{
	//cout << "Update..."<< endl;
	if (left)	this->rect.moveLeft(this->rect.left()-1);
	if (right)	this->rect.moveLeft(this->rect.left()+1);
	if (up)		this->rect.moveTop(this->rect.top()-1);
	if (down)	this->rect.moveTop(this->rect.top()+1); 

	//Repaint
	QWidget::update();
}
