#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <string>
#include <windows.h>
#include <iostream>
#include <cstdio>

class Fenetre
{
private:
    int width;
    int height;
    int margin_left;
    int margin_top;
    static int currentLine;

    void fcolor(int);

public:
    Fenetre();
    Fenetre(int,int,int,int);

    int getWidth();
    int getHeight();
    int getMarginLeft();
    int getMarginTop();

    void setWidth(int nWidth);
    void setHeight(int nHeight);
    void setMarginLeft(int nMarginLeft);
    void setMarginTop(int nMarginTop);

    void gotoxy(int,int);
    void moove(int,int);
    void rectangle(int,int,int,int);
    void setVisible(bool);
    void setContent(Fenetre &);
    void setText(std::string,int,int,int);
    void addText(std::string,int,Fenetre &);
    void putEndLine(int,Fenetre &);
    ~Fenetre();
};

#endif // DEF_FENETRE
