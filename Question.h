#ifndef DEF_QUESTION
#define DEF_QUESTION

#include "Reponse.h"
#include <string>

class Question
{
    std::string question;
    Reponse *rep1, *rep2, *rep3, *rep4, *bonneReponse;

public:
    Question(std::string,Reponse,Reponse,Reponse,Reponse,Reponse);
    void setQuestion(std::string);
    std::string getQuestion();
    std::string getRep1();
    std::string getRep2();
    std::string getRep3();
    std::string getRep4();
    std::string getBonneReponse();
    ~Question();
};

#endif // DEF_QUESTION
