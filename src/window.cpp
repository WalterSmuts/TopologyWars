#include "window.h"
#include <math.h>
#include <iostream>
using namespace std;

Window::Window(QWidget *parent) :
	QWidget(parent)
{
	//Window Constructor
	colour = Qt::red;
	rect = QRectF(this->width()/2, this->height()/2, 10, 10);
	startTimer(1);
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
	//Paint 10x10 blue ellipse
	painter.setBrush(Qt::blue);
	painter.drawEllipse(rect);

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
	//Animate Elipse
	this->rect.setWidth(100 + 50*sin((float)tick/(float)80));
	this->rect.setHeight(100);

	this->rect.setX(round(-this->rect.width()/2 + this->width()/2.0 + 200*sin((float)tick/(float)50 + M_PI/2)));
	this->rect.setY(round(-this->rect.height()/2 + this->height()/2.0 + 200*sin((float)tick/(float)50)));

	//Repaint
	QWidget::update();
	tick++;
}
