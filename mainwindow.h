#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

class QTimer;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

	QRandomGenerator m_randomizer;

private:
    QTimer* m_timer = nullptr;
};
#endif // MAINWINDOW_H
