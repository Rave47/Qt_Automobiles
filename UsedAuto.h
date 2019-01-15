#pragma once
#include "Automobile.h"

class UsedAuto : public Automobile {
private:
    int mileage;
public:
    UsedAuto(string, string, int, float, int, int);
    ~UsedAuto() {};
    void addToFile(string);
    int getExt(){return mileage;}
    void editExtra(int);
};
