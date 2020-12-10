#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{
    this->score=0;
    this->nom="Joueur";
}

Joueur::Joueur(string nomJoueur)
{
    this->nom=nomJoueur;
    this->score=0;
}

string Joueur::getNom()
{
    return this->nom;
}

long Joueur::getScore()
{
    return this->score;
}

void Joueur::addPoint()
{
    this->score+=5;
}

void Joueur::addPoint(long point)
{
    this->score+=point;
}

Joueur::~Joueur(){}
