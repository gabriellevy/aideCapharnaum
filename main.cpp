#include "universcapharnaum.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UniversCapharnaum av(ModeAffichage::ema_Jeu);
    //av.showMaximized();
    av.LancerHistoire(UniversCapharnaum::GEN_PNJ);
    av.show();

    return a.exec();
}
