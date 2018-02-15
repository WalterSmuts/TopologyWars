#include "window.h"
#include <iostream>
using namespace std;

Window::Window(QWidget *parent) :
	QWidget(parent)
{
	//Window Constructor
	colour = Qt::red;
	rect = QRectF(0, 0, 10, 10);
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
	cout << "KeyPress!!! " << event->key() << endl;
	if (event->key() == LEFT) 	this->rect.moveLeft(this->rect.left()-10);
	if (event->key() == RIGHT) 	this->rect.moveLeft(this->rect.left()+10);
	if (event->key() == UP) 	this->rect.moveTop(this->rect.top()-10);
	if (event->key() == DOWN) 	this->rect.moveTop(this->rect.top()+10);

	if (event->key() == EXIT) this->close();

	QWidget::update();
}
