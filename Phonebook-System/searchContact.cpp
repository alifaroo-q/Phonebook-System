#include "searchContact.h"
#include <iostream>
#include "main.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "BST.cpp"

void searchById() {
	system("cls");
	showBanner("SEARCH CONTACTS");

	int id;

	std::cout << "\n\n Enter ID : ";
	std::cin >> id;
	std::ifstream file;
	file.open("contact_data.dat");
	
	BST list = BST();

	if (file.is_open()) {
		std::string line;

		while (std::getline(file, line)) {
			std::stringstream ssin(line);
			std::vector<std::string> dataSet;

			while (ssin.good()) {
				std::string temp;
				ssin >> temp;
				dataSet.push_back(temp);
			}

			list.insert(new Contact(std::stoi(dataSet[0]), dataSet[1], dataSet[2], dataSet[3]));
		}
	
		file.close();
	}

	Contact* record = list.search(id);

	std::cout << "\n\n ID : " << record->getId() << "\n";
	std::cout << " Phone : " << record->getPhone() << "\n";
	std::cout << " Name : " << record->getName() << "\n";
	std::cout << " Email : " << record->getEmail() << "\n";

}
