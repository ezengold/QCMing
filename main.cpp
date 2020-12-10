#include "Jeu.h"

using namespace std;

int system(const char*_command);

int main()
{
    Jeu jeu;
    jeu.exec(true);
    jeu.~Jeu();

    return 0;
}

