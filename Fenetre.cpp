#include "Fenetre.h"

using namespace std;

int Fenetre::currentLine=0;

void Fenetre::fcolor(int x)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

Fenetre::Fenetre()
{
    this->width=100;
    this->height=40;
    this->margin_left=10;
    this->margin_top=3;
}

Fenetre::Fenetre(int margeGauche, int margeHaute, int Width, int Height)
{
    this->width=Width;
    this->height=Height;
    this->margin_left=margeGauche;
    this->margin_top=margeHaute;
}

int Fenetre::getWidth()
{
    return this->width;
}

int Fenetre::getHeight()
{
    return this->height;
}

int Fenetre::getMarginLeft()
{
    return this->margin_left;
}

int Fenetre::getMarginTop()
{
    return this->margin_top;
}


void Fenetre::setWidth(int nWidth)
{
    this->width=nWidth;
}

void Fenetre::setHeight(int nHeight)
{
    this->height=nHeight;
}

void Fenetre::setMarginLeft(int nMarginLeft)
{
    this->margin_left=nMarginLeft;
}

void Fenetre::setMarginTop(int nMarginTop)
{
    this->margin_top=nMarginTop;
}


void Fenetre::gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    fflush(stdout);
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void Fenetre::moove(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    fflush(stdout);
    dwCursorPosition.X += x;
    dwCursorPosition.Y += y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
// Fonction pour dessiner un rectangle
void Fenetre::rectangle(int x, int y, int largeur, int haut)
{
    int i;
    gotoxy(x,y);
    printf("%c",218);
    gotoxy(x+largeur,y);
    printf("%c",191);
    gotoxy(x, y+haut);
    printf("%c",192);
    gotoxy(x+largeur, y+haut);
    printf("%c",217);
    for (i=1; i<largeur; i++)
    {
        gotoxy(x+i,y);
        printf("%c",196);
        gotoxy(x+i,y+haut);
        printf("%c",196);
    }
    for (i=1; i<haut; i++)
    {
        gotoxy(x,y+i);
        printf("%c",179);
        gotoxy(x+largeur,y+i);
        printf("%c",179);
    }
}

void Fenetre::setVisible(bool state)
{
    if(state)
    {
        rectangle(this->margin_left,this->margin_top,this->width,this->height);
    }
}

void Fenetre::setContent(Fenetre &f)
{
    f.setMarginLeft(this->margin_left+f.getMarginLeft());
    f.setMarginTop(this->margin_top+f.getMarginTop());
    f.setVisible(true);
    this->setVisible(true);
    gotoxy(f.getMarginLeft()+1,f.getMarginTop()+1);
}

void Fenetre::setText(string text, int margeGauche, int margeHaut, int color)
{
    gotoxy(this->getMarginLeft()+margeGauche, this->getMarginTop()+margeHaut);
    fcolor(color);
    cout<<text;
    this->currentLine=margeHaut+this->getMarginTop()+1;
}

void Fenetre::addText(string text, int color, Fenetre &parent)
{
    gotoxy(this->getMarginLeft()+1,this->currentLine++);
    fcolor(color);
    cout<<text;
}

void Fenetre::putEndLine(int n, Fenetre &parent)
{
    for(int i(0) ; i<n ; i++)
    {
        this->addText("",15,parent);
    }
}

Fenetre::~Fenetre()
{

}
