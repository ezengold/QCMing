#include "Jeu.h"
#include "Fenetre.h"

using namespace std;

void Jeu::fcolor(int x)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

Jeu::Jeu()
{
    this->jouer=true;
}

int Jeu::nQuiz(string reper)
{
    this->fichier.open(reper.c_str());
    int n(0);

    if(fichier)
    {
        string ligne;
        while(getline(fichier,ligne))
        {
            n++;
        }
    }

    this->fichier.close();

    return n;
}

void Jeu::exec(bool state)
{
    while(state)
    {
        system("cls");
        system("color 0e");

        //PAGE D'ACCUEIL
        Fenetre Main;
        Fenetre SousMain(2,1,Main.getWidth()-4,Main.getHeight()-2);
        Main.setContent(SousMain);
        Sleep(500);

        ifstream Accueil("Design/Accueil.txt");
        if(Accueil)
        {
            string ligne;
            getline(Accueil,ligne);
            SousMain.setText(ligne,SousMain.getWidth()/10+3, (SousMain.getHeight()/3-1),7);
            Sleep(50);
            while(getline(Accueil,ligne))
            {
                SousMain.addText("\t\t"+ligne,7,Main);
                Sleep(50);
            }

            SousMain.putEndLine(3,Main);
            SousMain.addText("\t\t\t\t\tCHARGEMENT...",14,Main);
            Sleep(2000);

            //CHARGEMENT DU JEU
            vector<Question*> quiz;
            vector<int> ordre;
            string mot;

            ifstream qfich("Questions/questions.txt");
            int nombreDeQuestions=this->nQuiz("Questions/questions.txt");
            ifstream rfich;
            ifstream aide;
            ofstream record("Records/records.txt", ios::app);
            if(qfich)
            {
                string ligne, nrfich;
                int i(1);
                while(getline(qfich,ligne))
                {
                    string q;
                    q=ligne;
                    MType f(i);
                    nrfich="Reponses/"+f.str+".txt";

                    rfich.open(nrfich.c_str());
                    if(rfich)
                    {
                        getline(rfich,ligne);
                        Reponse re1(ligne);
                        getline(rfich,ligne);
                        Reponse re2(ligne);
                        getline(rfich,ligne);
                        Reponse re3(ligne);
                        getline(rfich,ligne);
                        Reponse re4(ligne);
                        getline(rfich,ligne);
                        MType bon(ligne);

                        ordre.push_back(bon.ent);

                        if(bon.ent==1)
                        {
                            quiz.push_back(new Question(q,re1,re2,re3,re4,re1));
                        }
                        else if(bon.ent==2)
                        {
                            quiz.push_back(new Question(q,re1,re2,re3,re4,re2));
                        }
                        else if(bon.ent==3)
                        {
                            quiz.push_back(new Question(q,re1,re2,re3,re4,re3));
                        }
                        else if(bon.ent==4)
                        {
                            quiz.push_back(new Question(q,re1,re2,re3,re4,re4));
                        }
                        else
                        {
                            system("color 47");
                            SousMain.addText("ERREUR DE CHOIX DE REPONSE !",14,Main);
                            Sleep(3000);
                            system("color 0e");
                        }

                        rfich.close();
                    }
                    else
                    {
                        system("color 47");
                        SousMain.addText("ERREUR D'OUVERTURE DES REPONSES !",14,Main);
                        state=false;
                        Sleep(3000);
                        system("color 0e");

                    }



                    i++;
                }

                cout<<" 100 %";
                Sleep(2000);


            }
            else
            {
                system("color 47");
                SousMain.addText("ERREUR D'OUVERTURE DES QUESTIONS !",14,Main);
                Sleep(3000);
                system("color 0e");
            }



            Accueil.close();


            while(this->jouer && state)
            {
                //MENU PRINCIPAL
                system("cls");
                system("color 0e");
                Fenetre Menu;

                Fenetre Welcome(2,1,Menu.getWidth()-4,Menu.getHeight()/10);
                Menu.setContent(Welcome);

                Fenetre MenuContainer(2, 2+Welcome.getMarginTop(), Menu.getWidth()-4, Menu.getHeight()-Welcome.getMarginTop()-3);
                Menu.setContent(MenuContainer);

                Fenetre MenuTitre(2+MenuContainer.getWidth()/5,1, 6*(MenuContainer.getWidth()/10),MenuContainer.getHeight()/10+1);
                MenuContainer.setContent(MenuTitre);

                Menu.setVisible(true);

                //ACCUEIL
                Welcome.setText("BIENVENUE SUR QCMING !",2*(Welcome.getWidth()/5),2,15);

                MenuTitre.setText("Menu Principal",2*(MenuTitre.getWidth()/5),2,14);
                MenuContainer.putEndLine(3,Menu);

                Sleep(300);

                MenuTitre.addText("",15,Menu);
                MenuTitre.addText("1- JOUER",15,Menu);
                MenuTitre.addText("",15,Menu);
                MenuTitre.addText("",15,Menu);
                MenuTitre.addText("2- AFFICHER LES SCORES",15,Menu);
                MenuTitre.addText("",15,Menu);
                MenuTitre.addText("",15,Menu);
                MenuTitre.addText("3- AIDE",15,Menu);
                MenuTitre.addText("",15,Menu);
                MenuTitre.addText("",15,Menu);
                MenuTitre.addText("4- QUITTER",15,Menu);
                MenuTitre.addText("",15,Menu);

                MenuTitre.addText("",15,Menu);

                MenuTitre.addText("Veuillez choisir un numero : ",14,MenuContainer);
                int choix(1);
                cin>>choix;

                if(choix==1)
                {
                    //LOGIN
                    string name;
                    cin.ignore();
                    MenuTitre.addText("",15,Menu);
                    Fenetre regist(MenuTitre.getMarginLeft()-10,30,MenuTitre.getWidth(),MenuTitre.getHeight());
                    Menu.setContent(regist);
                    regist.gotoxy(regist.getMarginLeft()+regist.getWidth()/4, regist.getMarginTop()+1);
                    Sleep(200);
                    regist.setText("Votre nom ?",1,0,15);
                    MenuTitre.addText("",15,Menu);
                    MenuTitre.addText("\t",15,Menu);

                    getline(cin,name);
                    Joueur jj(name);
                    Menu.setText("Bien ! C'est parti \t"+name+"...\t",Menu.getMarginLeft()+Menu.getWidth()/4,regist.getMarginTop()+3,15);
                    Sleep(3000);


                    //JEU
                    for(int i(0) ; i<nombreDeQuestions ; i++)
                    {
                        int choice;

                        system("cls");
                        system("color 0e");

                        Fenetre platform;
                        Fenetre Barre(2,1,platform.getWidth()-4, platform.getHeight()/10);
                        platform.setContent(Barre);

                        platform.setVisible(true);

                        Barre.setText("\t\tQCMing : Test d'intelligence !",Barre.getMarginLeft()+Barre.getWidth()/5,2,15);
                        MType exemple1(jj.getScore());
                        Barre.addText("\t"+jj.getNom()+" : "+exemple1.str+" points.",14,platform);

                        Fenetre jeuContenue(2,Barre.getHeight()+2,5*((platform.getWidth()-6)/7),platform.getHeight()-Barre.getHeight()-3);
                        platform.setContent(jeuContenue);

                        Fenetre Arbitre(4+jeuContenue.getWidth(),Barre.getHeight()+2, platform.getWidth()-6-jeuContenue.getWidth(), platform.getHeight()-Barre.getHeight()-3);
                        platform.setContent(Arbitre);


                        MType inc(i+1);
                        jeuContenue.setText("Question "+inc.str,10,2,14);
                        Sleep(200);

                        jeuContenue.putEndLine(2,jeuContenue);

                        jeuContenue.addText("\t"+quiz[i]->getQuestion(),15,jeuContenue);
                        jeuContenue.putEndLine(4,jeuContenue);
                        cout<<"\t\t1 - "<<quiz[i]->getRep1()<<"\n";
                        jeuContenue.putEndLine(3,jeuContenue);
                        cout<<"\t\t2 - "<<quiz[i]->getRep2()<<"\n";
                        jeuContenue.putEndLine(3,jeuContenue);
                        cout<<"\t\t3 - "<<quiz[i]->getRep3()<<"\n";
                        jeuContenue.putEndLine(3,jeuContenue);
                        cout<<"\t\t4 - "<<quiz[i]->getRep4()<<"\n";
                        jeuContenue.putEndLine(4,jeuContenue);

                        //VERIFICATION
                        cout<<"\t\t\tReponse : ";
                        cin>>choice;
                        if(choice==ordre[i])
                        {
                            system("color 02");
                            Arbitre.setText("Bonne reponse !",5,2*(Arbitre.getHeight()/5),15);
                            Arbitre.putEndLine(2,Arbitre);
                            Arbitre.addText("      +5 points !",15,Arbitre);
                            jj.addPoint();
                        }
                        else
                        {
                            system("color 04");
                            Arbitre.setText("Mauvaise reponse !",5,2*(Arbitre.getHeight()/5),15);
                            Arbitre.putEndLine(2,Arbitre);
                            Arbitre.addText("      +0 point !",15,Arbitre);
                        }

                        platform.~Fenetre();
                        Barre.~Fenetre();
                        Sleep(2000);
                    }

                    //FIN DU JEU
                    system("cls");
                    system("color 0e");

                    Fenetre MainEnd(30,10,60,20);
                    Fenetre SousMainEnd(2,1,MainEnd.getWidth()-4,MainEnd.getHeight()-2);
                    MainEnd.setContent(SousMainEnd);

                    SousMainEnd.setText("  FIN DU JEU",2*(SousMainEnd.getWidth()/5),2,15);
                    MType score(jj.getScore());
                    SousMainEnd.putEndLine(2,SousMainEnd);
                    SousMainEnd.putEndLine(2,SousMainEnd);
                    SousMainEnd.putEndLine(2,SousMainEnd);


                    SousMainEnd.addText("  "+jj.getNom()+", vous avez realise un total de "+score.str+" points !",14,SousMainEnd);
                    SousMainEnd.putEndLine(2,SousMainEnd);

                    if(jj.getScore()<=10)
                    {
                        SousMainEnd.addText("  Vous etes tres mediocre ! Prr...",4,SousMainEnd);
                        SousMainEnd.putEndLine(2,SousMainEnd);
                    }
                    else if(jj.getScore()<=25 && jj.getScore()>10)
                    {
                        SousMainEnd.addText("  Vous etes moyennement bons! Felicitations... LOL...",2,SousMainEnd);
                        SousMainEnd.putEndLine(2,SousMainEnd);
                    }
                    else if(jj.getScore()<=35 && jj.getScore()>25)
                    {
                        SousMainEnd.addText("\tVous etes tres bons ! LOL...",14,SousMainEnd);
                        SousMainEnd.putEndLine(2,SousMainEnd);
                    }
                    else if(jj.getScore()>35)
                    {
                        SousMainEnd.addText("  Vous etes EXCELLENT! Felicitations...",14,SousMainEnd);
                        SousMainEnd.putEndLine(2,SousMainEnd);
                    }

                    SousMainEnd.putEndLine(2,SousMainEnd);
                    SousMainEnd.addText("\t\t\t   FIN",15,SousMainEnd);


                    //ENREGISTREMENT DES RECORDS
                    MType scor(jj.getScore());
                    string ligne=jj.getNom()+"\t"+scor.getStr()+" points";
                    if(record)
                    {
                        record<<ligne<<endl;
                    }
                    else
                    {
                        SousMainEnd.putEndLine(2,SousMainEnd);
                        SousMainEnd.addText("Erreur d'ajout de score !",15,SousMainEnd);
                        system("color 47");
                        Sleep(2000);
                        system("color 0e");
                    }

                }
                else if(choix==2)
                {
                    system("cls");
                    system("color 0e");

                    Fenetre Scores(35,5,50,30);
                    Fenetre Entete(0,0,Scores.getWidth(),3);
                    Scores.setContent(Entete);
                    Scores.setVisible(true);

                    Entete.setText("Meilleures scores",2*(Scores.getWidth()/5),1,14);
                    Entete.putEndLine(3,Entete);
                    ifstream  listeRecords("Records/records.txt");
                    if(listeRecords)
                    {
                        string ligne;
                        int i(1);
                        while(getline(listeRecords,ligne) && i<=8)
                        {
                            MType inc(i);
                            Entete.addText(inc.str+" - "+ligne,14,Entete);
                            Entete.putEndLine(2,Entete);
                            i++;
                        }

                        Scores.gotoxy(Scores.getMarginLeft()+1,Scores.getMarginTop()+Scores.getHeight()+2);
                        listeRecords.close();
                    }
                    else
                    {
                        Entete.addText("Erreur d'acces !!!",4,Entete);
                        Entete.putEndLine(10,Entete);
                        system("color 47");
                        Sleep(2000);
                        system("color 0e");
                    }
                }
                else if(choix==3)
                {
                    system("cls");
                    system("color e0");
                    aide.open("helpme.txt");
                    if(aide)
                    {
                        string ligne;
                        while(getline(aide,ligne))
                        {
                            cout<<ligne+"\n";
                        }

                        aide.close();
                    }
                    else
                    {
                        cout<<"\n\n\tErreur de chargement de la page d'aide !\n\n\n\n\n\n\t";
                        system("color 47");
                        Sleep(2000);
                        system("color 0e");
                    }
                }
                else
                {
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t";
                    state=false;
                }

                cout<<"\n\n\n\n";
                system("pause");
            }


        }
        else
        {
            system("color 47");
            SousMain.setText("FICHIER D'ACCUEIL INTROUVABLE !!!",Main.getMarginLeft()+SousMain.getWidth()/3,SousMain.getHeight()/2,7);
            cout<<"\n\n\n\n\n\n\n\n\n\n\n";
            state=false;
        }


        state=false;

        cout<<"\n\n\t";
    }
}

Jeu::~Jeu()
{
    this->jouer=false;
}

