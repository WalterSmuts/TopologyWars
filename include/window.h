#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Window : public QWidget
{
	public:
	explicit Window(QWidget *parent = 0);
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // WINDOW_H
