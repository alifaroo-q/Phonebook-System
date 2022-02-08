#include "modifyContact.h"
#include "main.h"
#include <sstream>
#include <vector>
#include <string>
#include "Contact.h"
#include <fstream>
#include "BST.cpp"

void modifyContact() {
	system("cls");
	showBanner("Modify Contact");

	int contactID;

	std::cout << "\n\n Enter ID : ";
	std::cin >> contactID;
	std::cin.ignore();

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

	std::vector<Contact*> allContacts = list.get();

	bool isFound = false; int index;
	for (int i = 0; i < allContacts.size(); i++) {
		if (allContacts[i]->getId() == contactID) {
			index = i;
			isFound = true;
		}
	}

	if (!isFound) {
		std::cout << "\n Contact with id " << contactID << " not found\n";
		return;
	}

	std::string name, phone, email;

	std::cout << "\n Enter New Phone : ";
	std::getline(std::cin, phone);
	std::cout << " Enter New Name : ";
	std::getline(std::cin, name);
	std::cout << " Enter New Email : ";
	std::getline(std::cin, email);


	allContacts[index]->setPhone(phone);
	allContacts[index]->setName(name);
	allContacts[index]->setEmail(email);

	std::ofstream file_out;
	file_out.open("contact_data.dat", std::ios::out);

	if (file_out.is_open()) {

		for (int i = 0; i < allContacts.size(); i++) {
			file_out << allContacts[i]->toString() << "\n";
		}

		file_out.close();
		std::cout << "\n Contact with id " << contactID << " modified\n";
	}
	else {
		std::cout << "\n Error opening the file\n";
	}

}
