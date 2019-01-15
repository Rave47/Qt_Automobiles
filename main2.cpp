#include "NewAuto.h"
#include "UsedAuto.h"
#include "DamagedAuto.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <fstream>
#include <iterator>

using namespace std;


list<Automobile*> load();
void print(list<Automobile*>);
list<Automobile*> input(list<Automobile*>);
void save(list<Automobile*>);
list<Automobile*>::iterator search(list<Automobile*>*, int);
list<Automobile*> remove(list<Automobile*>, int);
void edit(list<Automobile*>, int);

int main() {

	setlocale(LC_ALL, "Rus");
	list<Automobile*> data;

	// �������� ������
	data = load();
	// ������ � �������
	data = input(data);
	print(data);

	system("pause");
	return 0;
}


list<Automobile*> load() {

	list<Automobile*> l;
	ifstream file("base.txt");
	
	while (file) {
		string str;

		getline(file, str);
		if (str.empty()) break;
		string mark = str;

		getline(file, str);
		string model = str;

		getline(file, str);
		string type = str;

		getline(file, str);
		int year = atoi(str.c_str());

		getline(file, str);
		float engine_capacity = stof(str);

		getline(file, str);
		int power = atoi(str.c_str());
		
		if (type == "�����") {
			getline(file, str);
			int warranty = atoi(str.c_str());

			NewAuto *obj = new NewAuto(mark, model, year, engine_capacity, power, warranty);
			l.push_back(obj);
		}
		else {
			if (type == "����������") {
				getline(file, str);
				int mileage = atoi(str.c_str());

				getline(file, str);
				int owner_number = atoi(str.c_str());

				UsedAuto *obj = new UsedAuto(mark, model, year, engine_capacity, power, mileage, owner_number);
				l.push_back(obj);
			}
			else {
				if (type == "�����") {
					getline(file, str);
					int mileage = atoi(str.c_str());

					getline(file, str);
					int owner_number = atoi(str.c_str());

					getline(file, str);
					int integrity = atoi(str.c_str());

					DamagedAuto *obj = new DamagedAuto(mark, model, year, engine_capacity, power, mileage, owner_number, integrity);
					l.push_back(obj);
				}
				else cout << "������!!!!\n\n";
			}
		}
		getline(file, str);
			
	}
	file.close();

	return l;
}

void print(list<Automobile*> data) {
	system("cls");
	for (auto it = data.begin(); it != data.end(); ++it) {
		(*it)->show();
	}
}

list<Automobile*> input(list<Automobile*> data) {
	system("cls");
	cout << "������� ������ �� ����������:\n\n";
	cout << "����� ����������: ";
	string mark;
	cin >> mark;
	cout << "������: ";
	string model;
	cin >> model;
	cout << "��� ����������: 1. �����\n                ";
	cout<< "2. ����������\n                3. �����\n";
	int status;
	do {
		status = getch();
		if (status < '1' || status > '3') {
			cout << "\n�� ����� �������������� �����\n\n";
		}
	} while (status < '1' || status > '3');

	cout << "��� �������: ";
	int year;
	cin >> year;
	cout << "����� ���������, �: ";
	float engine_capacity;
	cin >> engine_capacity;
	cout << "��������, �/�: ";
	int power;
	cin >> power;
	switch (status)
	{
		case '1': {
			cout << "����������� ����: ";
			int warranty;
			cin >> warranty;
			NewAuto *obj= new NewAuto(mark, model, year, engine_capacity, power, warranty);
			data.push_back(obj);
			break;
		}
		case '2': {
			cout << "���������� ���������� �� ���: ";
			int owner_number;
			cin >> owner_number;
			cout << "������: ";
			int mileage;
			cin >> mileage;
			UsedAuto *obj = new UsedAuto(mark, model, year, engine_capacity, power, mileage, owner_number);
			data.push_back(obj);
			break;

		}
		case '3':
			cout << "���������� ���������� �� ���: ";
			int owner_number;
			cin >> owner_number;
			cout << "������: ";
			int mileage;
			cin >> mileage;
			cout << "�����������, %: ";
			int integr;
			cin >> integr;
			DamagedAuto *obj = new DamagedAuto(mark, model, year, engine_capacity, power, mileage, owner_number, integr);
			data.push_back(obj);
			break;
	}

	save(data);
	return data;
}

void save(list<Automobile*> data) {
	ofstream fout("base.txt", ios_base::trunc);
	fout.close();
	for (auto it = data.begin(); it != data.end(); ++it) {
		(*it)->addToFile();
	}
}

void edit(list<Automobile*> data, int n) {
	auto it = search(&data, n);
	(*it)->menuEdit();
}

list<Automobile*>::iterator search(list<Automobile*> *data, int n) {
	auto it = (*data).begin();
	for (int k = 0; k < n-1; ++k) {
		++it;
	}

	return it;
}

list<Automobile*> remove(list<Automobile*> data, int n) {
	auto it = search(&data, n);
	delete (*it);
	data.erase(it);
	return data;
}
