#include "main_window.h"
#include "ui_main_window.h"

#include <QAction>
#include <QTreeWidget>

static MainWindow *gbl_cur_main_window = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_ui_(new Ui::MainWindow) {
    gbl_cur_main_window = this;
    main_ui_->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete main_ui_;
}
