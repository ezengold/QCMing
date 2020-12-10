#ifndef DEF_JEU
#define DEF_JEU

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "Reponse.h"
#include "Question.h"
#include "MType.h"
#include "Joueur.h"

class Jeu
{
private:
    bool jouer;

public:
    std::ifstream fichier;

    Jeu();
    void exec(bool);
    void fcolor(int);
    int nQuiz(std::string);
    ~Jeu();
};

#endif // DEF_JEU
