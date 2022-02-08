#pragma once
#include "Contact.h"
#include <vector>

class Node {
public:
	Contact* data;
	Node* left;
	Node* right;

	Node(Contact* data) {
		this->data = data;
		this->right = nullptr;
		this->left = nullptr;
	}
};

class BST {
private:
	Node* root;
	std::vector<Contact*> bucket;

	void insert(Contact* data, Node* root) {
		Node* newNode = new Node(data);

		if (root == nullptr) {
			this->root = newNode;
			return;
		}

		else if (root->data->getId() == data->getId()) return;

		else if (root->data->getId() < data->getId()) {
			if (root->right == nullptr) {
				this->root->right = newNode;
			}
			else {
				insert(data, root->right);
			}
			return;
		}

		else if (root->data->getId() > data->getId()) {
			if (root->left == nullptr) {
				this->root->left = newNode;
			}
			else {
				insert(data, root->left);
			}
			return;
		}

	}

	Contact* search(int id, Node* root) {
		if (root == nullptr) return nullptr;

		if (root->data->getId() == id) {
			return root->data;
		}
		
		if (root->data->getId() > id) {
			if (root->right->data->getId() == id) {
				return root->right->data;
			}
			else {
				search(id, root->right);
			}
		}

		if (root->data->getId() < id) {
			if (root->left->data->getId() == id) {
				return root->left->data;
			}
			else {
				search(id, root->left);
			}
		}

		return nullptr;
	}

	Node* remove(int id, Node* root) {
		if (root == nullptr) return root;
		else if (id < root->data->getId())
			root->left = remove(id, root->left);
		else if (id > root->data->getId())
			root->right = remove(id, root->right);
		else {
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				root = nullptr;
			}
			else if (root->left == nullptr) {
				Node* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == nullptr) {
				Node* temp = root;
				root = root->left;
				delete temp;
			}
			else {
				Node* largest = root->left;
				while (largest->right != nullptr) {
					largest = largest->right;
				}
				root->data = largest->data;
				remove(largest->data->getId(), root->left);
			}
		}
		return root;
	}

	void putContacts(Node* root) {
		if (root == nullptr) return;
		bucket.push_back(root->data);
		if (root->left != nullptr) putContacts(root->left);
		if (root->right != nullptr) putContacts(root->right);
	}

public:
	void insert(Contact* data) {
		insert(data, root);
	}

	Contact* search(int id) {
		return search(id, root);
	}

	void remove(int id) {
		this->root = remove(id, root);
	}

	std::vector<Contact*> get() {
		putContacts(root);
		return bucket;
	}
};
