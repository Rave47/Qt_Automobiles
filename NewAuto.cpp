#include"NewAuto.h"
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>

NewAuto::NewAuto(string m, string mdl, int y, float ec, int pwr, int wr) {
	mark = m;
	model = mdl;
    type = { "New" };
	year = y;
	engine_capacity = ec;
	power = pwr;
	warranty = wr;
}

void NewAuto::addToFile(string str) {
    ofstream fout(str, ios_base::app);
	fout << mark << endl;
	fout << model << endl;
	fout << type << endl;
	fout << year << endl;
	string ec = to_string(engine_capacity);
	fout << ec << endl;
	fout << power << endl;
	fout << warranty << endl << endl;

	fout.close();
}

void NewAuto::editExtra(int val){warranty = val;}
