#include <iostream>

void showMenu();
void showBanner();

int main() {

	showBanner();
	showMenu();
	system("pause>0");
}

void showBanner() {
	std::cout << "\n\n\n";
	std::cout << "\t\t\t\t\t=========================\n";
	std::cout << "\t\t\t\t\t    CONTACT PHONEBOOK\n";
	std::cout << "\t\t\t\t\t=========================\n";
}

void showMenu() {
	std::cout << "\n\n";
	std::cout << " 1 - Add New Contact\n";
	std::cout << " 2 - Remove Contact\n";
	std::cout << " 3 - Modify Contact\n";
	std::cout << " 4 - Search Contact (by id)\n";
	std::cout << " 5 - Search Contact (by name)\n";
	std::cout << " 6 - Display Contacts\n";
	std::cout << "\n 0 - Exit";
}