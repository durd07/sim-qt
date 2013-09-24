#include "open_command_line_window_dialog.h"
#include "ui_cli.h"

OpenCommandLineWindowDialog::OpenCommandLineWindowDialog(QWidget *parent) :
    QWidget(parent),
    open_command_line_window_dialog_ui_(new Ui::OpenCommandLineWindowDialog) {
    open_command_line_window_dialog_ui_->setupUi(this);
}

OpenCommandLineWindowDialog::~OpenCommandLineWindowDialog() {
    delete open_command_line_window_dialog_ui_;
}

