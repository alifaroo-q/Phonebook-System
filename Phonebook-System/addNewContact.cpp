#include "addNewContact.h"
#include "main.h"
#include <fstream>

void addNewContact() {
	system("cls");
	showBanner(" ADD NEW CONTACT");
	std::cout << "\n\n\n";

	Contact* newContact = createContact();

	std::ofstream file;
	file.open("contact_data.dat", std::ios::app);

	if (file.is_open()) {
		file << newContact->toString() << "\n";
		file.close();
	}
	else {
		std::cout << "Error opening the file\n";
	}

}

Contact* createContact() {
	
	int id;
	std::string phone;
	std::string name;
	std::string email;

	std::cout << " Enter ID : ";
	std::cin >> id;
	std::cin.ignore();
	std::cout << " Enter Phone : ";
	std::getline(std::cin, phone);
	std::cout << " Enter Name : ";
	std::getline(std::cin, name);
	std::cout << " Enter Email : ";
	std::getline(std::cin, email);
	
	return new Contact(id, phone, name, email);
}