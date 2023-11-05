#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	int height;
	
	Node(int d = 0) {
		data = d;
		left = nullptr;
		right = nullptr;
		height = 1;
	}	
};

int getHeight(Node* node) {
	if(node == nullptr) {
		return 0;
	} else {
		return node->height;
	}
}

int max(int a, int b) {
	if(a > b) {
		return a;
	} else {
		return b;
	}
}

Node* rightRotate(Node* x) {
	Node* y = x->left;
	Node* T2 = y->right;
	y->right = x;
	x->left = T2;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	return x;
}

Node* leftRotate(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	return x;
}

int getBF(Node* node) {
	if(node == nullptr) {
		return 0;
	} else {
		return getHeight(node->left) - getHeight(node->right);
	}
}

Node* insert(Node* root, int data) {
	if(root == nullptr) {
		Node* temp = new Node(data);
		return temp;
	}
	
	if(data == root->data) {
		return root;
	}
	
	if(data < root->data) {
		root->left = insert(root->left, data);
	} else if(data > root->data) {
		root->right = insert(root->right, data);
	} else {
		return root;	
	}
	
	root->height = 1 + max(getHeight(root->left), getHeight(root->right)); // update balance factor
	
	int balance = getBF(root);
	
	if(balance > 1) {
		if(data < root->left->data) {
			return rightRotate(root);
		} else if(data > root->left->data) {
			root->left = leftRotate(root);
			return rightRotate(root);
		}
	}
	
	if(balance < -1) {
		if(data > root->right->data) {
			return leftRotate(root);
		} else if(data < root->right->data) {
			root->right = rightRotate(root);
			return leftRotate(root);
		}
	}
	return root;
}

void print(Node* root) {
	if(root == nullptr) {
		return;
	}
	print(root->left);
	cout << root->data << " ";
	print(root->right);
}

int main() {
	Node *root = NULL;
  	root = insert(root, 33);
  	root = insert(root, 13);
  	root = insert(root, 53);
  	root = insert(root, 9);
  	root = insert(root, 21);
  	root = insert(root, 61);
  	root = insert(root, 8);
  	root = insert(root, 11);
  	print(root);
}