#pragma once
#include "Automobile.h"

class NewAuto : public Automobile {
private:
    int warranty;
public:
    NewAuto(string, string, int, float, int, int);
    ~NewAuto() {};
    void addToFile(string);
    int getExt(){return warranty;}
    void editExtra(int);
};
