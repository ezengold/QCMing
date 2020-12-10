#ifndef DEF_JOUEUR
#define DEF_JOUEUR

#include <string>

class Joueur
{
private:
    std::string nom;
    long score;

public:
    Joueur();
    Joueur(std::string);
    std::string getNom();
    long getScore();
    void addPoint();
    void addPoint(long);
    ~Joueur();
};

#endif // DEF_JOUEUR
