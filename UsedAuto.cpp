#include"UsedAuto.h"
#include <string>
#include <conio.h>
#include <fstream>
#include <iomanip>


UsedAuto::UsedAuto(string m, string mdl, int y, float ec, int pwr, int mil) {
	mark = m;
	model = mdl;
    type = { "Pre-Owned" };
	year = y;
	engine_capacity = ec;
	power = pwr;
	mileage = mil;
}

void UsedAuto::addToFile(string str) {
    ofstream fout(str, ios_base::app);
	fout << mark << endl;
	fout << model << endl;
	fout << type << endl;
	fout << year << endl;
	string ec = to_string(engine_capacity);
	fout << ec << endl;
	fout << power << endl;
    fout << mileage << endl << endl;

	fout.close();
}

void UsedAuto::editExtra(int val) {mileage = val;}
