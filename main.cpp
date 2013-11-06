#include "sim_application.h"
#include "main_window.h"
#include "qconsole.h"
#define _QT_GUI_LIB

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _QT_GUI_LIB
int simqt_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    SimApplication sim_app(argc, argv);
    MainWindow *main_w;

    main_w = new(MainWindow);
    main_w->show();

    return simApp->exec();
}

#ifdef __cplusplus
}
#endif
