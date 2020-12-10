#include "Reponse.h"

using namespace  std;

Reponse::Reponse(string rep)
{
    reponse=rep;
}

void Reponse::setReponse(string nrep)
{
    reponse=nrep;
}

string Reponse::getReponse()
{
    return reponse;
}

Reponse::~Reponse() {}
