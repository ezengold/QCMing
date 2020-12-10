#include "MType.h"
#include <cmath>
#include <sstream>

using namespace std;

MType::MType()
{

}

MType::MType(int n)
{
    this->ent=n;
    this->str=this->getStr();
}

MType::MType(string n)
{
    this->str=n;
    this->ent=this->getInt();
}

string MType::getStr()
{
    int n=this->ent;
    string nbre;

    stringstream g;
    g<<n;
    nbre=g.str();

    return nbre;
}

int MType::getInt()
{
    string nbre = this->str;
    int n;
    stringstream(nbre)>>n;

    return n;
}

MType::~MType() {}
