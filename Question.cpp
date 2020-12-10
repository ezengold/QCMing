#include "Question.h"
#include "Reponse.h"

using namespace std;

Question::Question(string question, Reponse r1, Reponse r2, Reponse r3, Reponse r4, Reponse bon)
{
    rep1=new Reponse(r1.getReponse());
    rep2=new Reponse(r2.getReponse());
    rep3=new Reponse(r3.getReponse());
    rep4=new Reponse(r4.getReponse());
    bonneReponse=new Reponse(bon.getReponse());

    this->question=question;
}

void Question::setQuestion(string nquestion)
{
    this->question=question;
}

string Question::getQuestion()
{
    return this->question;
}

string Question::getRep1()
{
    return this->rep1->getReponse();
}

string Question::getRep2()
{
    return this->rep2->getReponse();
}

string Question::getRep3()
{
    return this->rep3->getReponse();
}

string Question::getRep4()
{
    return this->rep4->getReponse();
}

string Question::getBonneReponse()
{
    return this->bonneReponse->getReponse();
}

Question::~Question()
{
    delete rep1;
    delete rep2;
    delete rep3;
    delete rep4;
    delete bonneReponse;
}
