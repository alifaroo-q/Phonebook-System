#include "main.h"

int main() {

	BST* allContacts = readAllContacts();

	showBanner("CONTACT PHONEBOOK");
	showMenu();
	userChoice(allContacts);
	system("pause>0");
}

BST* readAllContacts() {

	std::ifstream file("contact_data.dat");
	BST* tree = new BST();

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

			tree->insert(new Contact(std::stoi(dataSet[0]), dataSet[1], dataSet[2], dataSet[3]));
		}
	
		file.close();
	}

	return tree;
}

void showBanner(const char* heading) {
	std::cout << "\n\n\n";
	std::cout << "\t\t\t\t\t=========================\n";
	std::cout << "\t\t\t\t\t    " << heading << "\n";
	std::cout << "\t\t\t\t\t=========================\n";
}

void showMenu() {
	std::cout << "\n\n";
	std::cout << " 1 - Add New Contact\n";
	std::cout << " 2 - Remove Contact\n";
	std::cout << " 3 - Modify Contact\n";
	std::cout << " 4 - Search Contact (by id)\n";
	std::cout << " 5 - Display Contacts\n";
	std::cout << "\n 0 - Exit";
}

void returnToMain() {

	char mainPage;
	std::cout << "\n\n Return to main menu (Yes = y) : ";
	std::cin >> mainPage;

	if (mainPage == 'y' || mainPage == 'Y') {
		system("cls");
		main();
	}
	else {
		exit(EXIT_SUCCESS);
	}
}

void userChoice(BST* allContacts) {
	int choice;
	std::cout << "\n\n Select Option : ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		addNewContact(allContacts);
		break;
	case 2:
		removeContact(allContacts);
		break;
	case 3:
		modifyContact(allContacts);
		break;
	case 4:
		searchById(allContacts);
		break;
	case 5:
		displayContacts();
		break;
	case 0:
		exit(EXIT_SUCCESS);
		break;
	default:
		std::cout << "\n Select the correct option\n";
		returnToMain();
	}
}
