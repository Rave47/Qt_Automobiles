#pragma once
#include "Automobile.h"

class DamagedAuto : public Automobile{
private:
    int integrity;
public:
    DamagedAuto(string, string, int, float, int, int);
    ~DamagedAuto() {};
    void addToFile(string);
    int getExt(){return integrity;}
    void editExtra(int);
};
