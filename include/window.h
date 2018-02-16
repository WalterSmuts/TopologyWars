#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

#define LEFT 16777234
#define RIGHT 16777236
#define UP 16777235
#define DOWN 16777237
#define EXIT 16777216
#define SPACE 32

class Window : public QWidget
{
	public:
	explicit Window(QWidget *parent = 0);
	void paintEvent(QPaintEvent *event);// Q_DECL_OVERRIDE; Not needed???

	protected:
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
	void timerEvent(QTimerEvent *event);

	private:
	//This is temp ship vars
	QColor colour;
	QRectF rect;

	bool left, right, up, down;
};

#endif // WINDOW_H
