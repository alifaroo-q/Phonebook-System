#include "displayContacts.h"
#include "main.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void displayContacts() {
	system("cls");
	showBanner("PHONEBOOK CONTACTS");

	std::ifstream file;
	file.open("contact_data.dat", std::ios::in);
	std::string data[4];
	int i = 0;

	if (file.is_open()) {
		std::string line;

		while (std::getline(file, line)) {
			std::stringstream ssin(line);
			
			while (ssin.good() && i < 4) {
				ssin >> data[i];
				i++;
			}
			
			std::cout << "\n\n";
			std::cout << " ID : " << data[0] << "\n";
			std::cout << " Phone : " << data[1] << "\n";
			std::cout << " Name : " << data[2] << "\n";
			std::cout << " Email : " << data[3] << "\n";
		
			i = 0;
		}
	
		file.close();
	}
}
