#include <fstream>
#include <regex>
#include "main.h"
#include "addNewContact.h"

void addNewContact(BST* allContacts) {
	system("cls");
	showBanner(" ADD NEW CONTACT");
	std::cout << "\n\n\n";

	Contact* newContact = createContact(allContacts);
	std::ofstream file("contact_data.dat", std::ios::app);
	bool isAdded = false;

	if (file.is_open()) {
		file << newContact->toString() << "\n";
		file.close();
		isAdded = true;
	}
	else
		std::cout << " Error opening the file\n";

	if (isAdded) {
		std::cout << "\n Contact added to phonebook\n";
		returnToMain();
	}
	else
		std::cout << " Failed to create new contact\n";
}

Contact* createContact(BST* allContacts) {

	// regex for data validation
	std::string idPattern = "[0-9]{4}";
	std::string phonePattern = "[0-9]{11}";
	std::string namePattern = "[a-zA-Z\\s+]{3,15}";
	std::string emailPattern = "\\w+@[a-z]+\\.[a-z]+";

	int id;
	std::string phone;
	std::string name;
	std::string email;

id:
	std::cout << " Enter ID : ";
	std::cin >> id;

	if (!std::regex_match(std::to_string(id), std::regex(idPattern))) {
		std::cout << "\n Enter Valid ID (4 digits)\n\n";
		goto id;
	}
	std::cin.ignore();

	if (!isUniqueID(id, allContacts)) {
		std::cout << "\n Contact with id " << id << " already exist, enter unique id\n\n";
		goto id;
	}

phone:
	std::cout << " Enter Phone : ";
	std::getline(std::cin, phone);

	if (!std::regex_match(phone, std::regex(phonePattern))) {
		std::cout << "\n Enter Valid Phone No (11 digits)\n\n";
		goto phone;
	}

name:
	std::cout << " Enter Name : ";
	std::getline(std::cin, name);

	if (!std::regex_match(name, std::regex(namePattern))) {
		std::cout << "\n Enter Valid Name (no numeric digits)\n\n";
		goto name;
	}

email:
	std::cout << " Enter Email : ";
	std::getline(std::cin, email);

	if (!std::regex_match(email, std::regex(emailPattern))) {
		std::cout << "\n Enter Valid Email (someone@something.com)\n\n";
		goto email;
	}

	return new Contact(id, phone, name, email);
}

bool isUniqueID(int id, BST* allContacts) {

	std::ifstream file("contact_data.dat", std::ios::in);
	if (file.is_open()) {
		if (file.peek() == std::ifstream::traits_type::eof()) return true; // checking if file is empty
		if (!(allContacts->search(id) == nullptr)) return false;
	}

	return true;
}