#include <string>
#pragma once

class Contact {
private:
	int id;
	std::string phone;
	std::string name;
	std::string email;

public:
	Contact(int, std::string, std::string, std::string);
	~Contact();

	int getId();
	void setId(int);
	std::string getPhone();
	void setPhone(std::string);
	std::string getName();
	void setName(std::string);
	std::string getEmail();
	void setEmail(std::string);

	std::string toString();

};

