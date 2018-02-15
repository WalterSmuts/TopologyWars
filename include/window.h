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

	private:
	//This is temp ship vars
	QColor colour;
	QRectF rect;
};

#endif // WINDOW_H
