#include <string>
#pragma once

class Contact
{
private:
	int id;
	int phone;
	std::string name;
	std::string email;

public:
	Contact(int, int, std::string, std::string);
	~Contact();

	int getId();
	void setId(int);
	int getPhone();
	void setPhone(int);
	std::string getName();
	void setName(std::string);
	std::string getEmail();
	void setEmail(std::string);

};

