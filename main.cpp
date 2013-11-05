#include "sim_application.h"
#include "main_window.h"

#ifdef __cplusplus
extern "C" {
#endif
int simqt_main(int argc, char *argv[])
//int main(int argc, char *argv[])
{
    SimApplication sim_app(argc, argv);
    MainWindow *main_w;

    main_w = new(MainWindow);
    main_w->show();

    return sim_app.exec();
}

#ifdef __cplusplus
}
#endif
