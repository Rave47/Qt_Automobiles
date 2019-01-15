#include"DamagedAuto.h"
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>

DamagedAuto::DamagedAuto(string m, string mdl, int y, float ec, int pwr, int integr) {
	mark = m;
	model = mdl;
    type = { "Damaged" };
	year = y;
	engine_capacity = ec;
	power = pwr;
	integrity = integr;
}

void DamagedAuto::addToFile(string str) {
    ofstream fout(str, ios_base::app);
	fout << mark << endl;
	fout << model << endl;
	fout << type << endl;
	fout << year << endl;
	string ec = to_string(engine_capacity);
	fout << ec << endl;
	fout << power << endl;
	fout << integrity << endl << endl;

	fout.close();
}

void DamagedAuto::editExtra(int val) {integrity = val;}
