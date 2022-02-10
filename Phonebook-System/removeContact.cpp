#include <vector>
#include <fstream>
#include <regex>
#include "main.h"
#include "BST.cpp"
#include "removeContact.h"

void removeContact(BST* allContacts) {
	system("cls");
	showBanner("REMOVE CONTACT");

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

	bool isRemoved = false;

	if (allContacts->search(contactID) == nullptr)
		std::cout << " Contact with id " << contactID << " not found\n";
	else {
		allContacts->remove(contactID);
		isRemoved = true;
	}

	std::vector<Contact*> allContact = allContacts->get();

	std::ofstream file_out;
	file_out.open("contact_data.dat", std::ios::out);

	if (file_out.is_open()) {

		for (int i = 0; i < allContact.size(); i++) {
			file_out << allContact[i]->toString() << "\n";
		}

		file_out.close();
	}
	else
		std::cout << "Error opening the file\n";

	if (isRemoved)
		std::cout << "\n Contact with id " << contactID << " removed\n";

	returnToMain();
}
