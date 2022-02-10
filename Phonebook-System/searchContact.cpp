#include <iostream>
#include "main.h"
#include "BST.cpp"
#include "searchContact.h"

void searchById(BST* allContacts) {
	system("cls");
	showBanner("SEARCH CONTACTS");

	int id;

	std::cout << "\n\n Enter ID : ";
	std::cin >> id;

	Contact* record = allContacts->search(id);

	std::cout << "\n\n ID : " << record->getId() << "\n";
	std::cout << " Phone : " << record->getPhone() << "\n";
	std::cout << " Name : " << record->getName() << "\n";
	std::cout << " Email : " << record->getEmail() << "\n";

	returnToMain();

}
