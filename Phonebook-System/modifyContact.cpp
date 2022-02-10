#include <vector>
#include <fstream>
#include <string>
#include <regex>
#include "main.h"
#include "BST.cpp"
#include "Contact.h"
#include "modifyContact.h"

void modifyContact(BST* allContacts) {
	system("cls");
	showBanner("Modify Contact");

	int contactID;
	std::string idPattern = "[0-9]{4}";

id:
	std::cout << "\n Enter ID : ";
	std::cin >> contactID;

	if (!std::regex_match(std::to_string(contactID), std::regex(idPattern))) {
		std::cout << "\n Enter Valid ID (4 digits)\n";
		goto id;
	}
	std::cin.ignore();

	std::vector<Contact*> allContact = allContacts->get();

	bool isFound = false; int index;
	for (int i = 0; i < allContact.size(); i++) {
		if (allContact[i]->getId() == contactID) {
			index = i;
			isFound = true;
		}
	}

	if (!isFound) {
		std::cout << "\n Contact with id " << contactID << " not found\n";
		return;
	}

	std::string name, phone, email;

	std::string phonePattern = "[0-9]{11}";
	std::string namePattern = "[a-zA-Z\\s+]{3,15}";
	std::string emailPattern = "\\w+@[a-z]+\\.[a-z]+";

phone:
	std::cout << " Enter New Phone : ";
	std::getline(std::cin, phone);

	if (!std::regex_match(phone, std::regex(phonePattern))) {
		std::cout << "\n Enter Valid Phone No (11 digits)\n\n";
		goto phone;
	}

name:
	std::cout << " Enter New Name : ";
	std::getline(std::cin, name);

	if (!std::regex_match(name, std::regex(namePattern))) {
		std::cout << "\n Enter Valid Name (no numeric digits)\n\n";
		goto name;
	}

email:
	std::cout << " Enter New Email : ";
	std::getline(std::cin, email);

	if (!std::regex_match(email, std::regex(emailPattern))) {
		std::cout << "\n Enter Valid Email (someone@something.com)\n\n";
		goto email;
	}

	allContact[index]->setPhone(phone);
	allContact[index]->setName(name);
	allContact[index]->setEmail(email);

	std::ofstream file_out("contact_data.dat", std::ios::out);
	if (file_out.is_open()) {

		for (int i = 0; i < allContact.size(); i++) {
			file_out << allContact[i]->toString() << "\n";
		}

		file_out.close();
		std::cout << "\n Contact with id " << contactID << " modified\n";
	}
	else 
		std::cout << "\n Error opening the file\n";

	returnToMain();
}
