#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Price {
	string productName, shopName;
	double price;
};

void toLowerCase(string& str) {
	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Price> list;

	ifstream dataOut("Data.txt");

	Price oneElement;

	while (!dataOut.eof()) {
		dataOut >> oneElement.productName >>
			oneElement.shopName >> oneElement.price;
		toLowerCase(oneElement.shopName);
		list.push_back(oneElement);
	}

	string shop;
	while (true) {
		cout << "Введіть назву магазину для отримання інформації про товари: ";
		cin >> shop;
		toLowerCase(shop);

		bool error = true;
		for (int i = 0; i < list.size(); i++) {
			if (list[i].shopName == shop) {
				cout << "Назва товару: " << list[i].productName
					<< " Ціна: " << list[i].price << endl;

				error = false;
			}
		}

		if (error) {
			cout << "Такого магазину немає в списку" << endl;
		}

		system("pause");
		cout << endl;
	}

	return 0;
}