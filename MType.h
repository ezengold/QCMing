#ifndef DEF_MTYPE
#define DEF_MTYPE

#include <string>

class MType
{
public:
    int ent;
    std::string str;

public:
    MType();
    MType(int);
    MType(std::string);
    std::string getStr();
    int getInt();
    ~MType();
};

#endif // DEF_MTYPE
