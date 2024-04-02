#include <QTimer>
#include <QPushButton>
#include <QWidget>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	resize(300, 600);

	m_timer = new QTimer(this);
	int lowerBound = 100;
	int upperBound = 1000;

	m_timer->setInterval(m_randomizer.bounded(lowerBound,upperBound));
	m_timer->start();

	connect(m_timer, &QTimer::timeout, [lowerBound, upperBound, this]
	{
		m_timer->setInterval(m_randomizer.bounded(lowerBound,upperBound));
		m_timer->start();

		auto pb = new QPushButton("*", this);
		pb->setMouseTracking(true);

		qint32 x = m_randomizer.bounded(30, this->width() - 30);
		qint32 y = 10;

		pb->setGeometry(x, y, 25, 25);
		pb->show();

		auto speed = m_randomizer.bounded(1,10);

		auto moveTimer = new QTimer(pb);
		moveTimer->setInterval(100);
		moveTimer->start();

		connect(moveTimer, &QTimer::timeout, [pb, speed, this]
		{
			pb->move(pb->pos() + QPoint(0, speed * (pb->underMouse() ? 2 : 1)));

			if (pb->pos().y() > height())
			{
				pb->deleteLater();
				setPalette(QPalette(QPalette::Background, Qt::red));
				setWindowTitle("You LOOSE!");
			}
		});

		connect(pb, &QPushButton::clicked,
				pb, &QPushButton::deleteLater);
	});

	m_timer->start();
}

MainWindow::~MainWindow()
{
}
