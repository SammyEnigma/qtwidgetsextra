#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Generator.h"

namespace Ui {
    class MainWindow;
}

class QTreeWidgetItem;
class QAbstractButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tbAdd_clicked();
    void on_tbRemove_clicked();
    void on_tbUp_clicked();
    void on_tbDown_clicked();
    void on_dbbButtons_clicked(QAbstractButton *button);

private:
    Ui::MainWindow *ui;
    Generator m_generator;

    bool saveFile(const QString &content, const QString &filePath) const;

    void apply();
    void save();
};

#endif // MAINWINDOW_H
