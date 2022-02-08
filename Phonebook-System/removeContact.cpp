#include "removeContact.h"
#include "main.h"
#include <fstream>
#include "BST.cpp"
#include <vector>
#include <sstream>
#include <string>

void removeContact() {
	system("cls");
	showBanner("REMOVE CONTACT");

	int contactID;

	std::cout << "\n\n Enter ID : ";
	std::cin >> contactID;

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

	list.remove(contactID);

	std::vector<Contact*> allContacts = list.get();

	std::ofstream file_out;
	file_out.open("contact_data.dat", std::ios::out);

	if (file_out.is_open()) {

		for (int i = 0; i < allContacts.size(); i++) {
			file_out << allContacts[i]->toString() << "\n";
		}

		file_out.close();
		std::cout << "\n Contact with id " << contactID << " removed\n";
	}
	else {
		std::cout << "Error opening the file\n";
	}
}
