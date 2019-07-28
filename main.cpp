#include "universcapharnaum.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UniversCapharnaum av(ModeAffichage::ema_Jeu);
    Hist* hist = av.ExecuterGenerateurHistoire();
    av.LancerHistoire(hist);
    av.show();

    return a.exec();
}
