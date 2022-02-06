#pragma once
#include "Contact.h"

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

	void insert(Contact* data, Node* root) {
		Node* newNode = new Node(data);

		if (root == nullptr) {
			this->root = newNode;
			return;
		}

		if (root->data->getId() == data->getId()) return;

		if (root->data->getId() > data->getId()) {
			if (root->right == nullptr) {
				this->root->right = newNode;
			}
			else {
				insert(data, root->right);
			}
			return;
		}

		if (root->data->getId() < data->getId()) {
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

public:
	void insert(Contact* data) {
		insert(data, root);
	}

	Contact* search(int id) {
		return search(id, root);
	}
};
