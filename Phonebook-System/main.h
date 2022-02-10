#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "addNewContact.h"
#include "displayContacts.h"
#include "searchContact.h"
#include "removeContact.h"
#include "modifyContact.h"
#include "BST.cpp"


int main();
void showMenu();
void showBanner(const char*);
void userChoice(BST*);
void returnToMain();
BST* readAllContacts();
