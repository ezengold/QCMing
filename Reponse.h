#ifndef DEF_REPONSE
#define DEF_REPONSE

#include <string>

class Reponse
{
private:
    std::string reponse;

public:
    Reponse(std::string);
    void setReponse(std::string);
    std::string getReponse();
    ~Reponse();
};


#endif // DEF_REPONSE
