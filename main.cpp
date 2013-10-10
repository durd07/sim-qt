#include "sim_application.h"
#include "main_window.h"

int main(int argc, char *argv[])
{
    SimApplication sim_app(argc, argv);
    MainWindow *main_w;

    main_w = new(MainWindow);
    main_w->show();

    return simApp->exec();
}

