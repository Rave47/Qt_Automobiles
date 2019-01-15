#pragma once
#include <iostream>

using namespace std;

class Automobile {
protected:
    string mark;
    string model;
    string type;
	int year;
	float engine_capacity;
	int power;

public:
    virtual ~Automobile() {};
    virtual void addToFile(string) = 0;

    string getMark();
    string getModel();
    string getType();
    int getYear();
    float getEC();
    int getPower();
    virtual int getExt() = 0;

    void editMark(string);
    void editModel(string);
    void editYear(int);
    void editEC(float);
    void editPower(int);
    virtual void editExtra(int) = 0;
};
