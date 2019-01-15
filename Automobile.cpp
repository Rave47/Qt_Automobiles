#include "Automobile.h"
#include <string>
#include <cmath>

string Automobile::getMark(){return mark;}

string Automobile::getModel(){return model;}

string Automobile::getType(){return type;}

int Automobile::getYear(){return year;}

float Automobile::getEC(){return floor(engine_capacity*10)/10;}

int Automobile::getPower(){return power;}

void Automobile::editMark(string str) {mark = str;}

void Automobile::editModel(string str) {model = str;}

void Automobile::editYear(int val) {year = val;}

void Automobile::editEC(float val) {engine_capacity = val;}

void Automobile::editPower(int val) {power = val;}
