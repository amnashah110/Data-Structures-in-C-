#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	
	Node(int d = 0) {
		data = d;
		left = nullptr;
		right = nullptr;
	}	
};

Node* insertNode(Node* root, int data) {
	if(root == nullptr) { // if no data in binary tree
		Node* temp = new Node(data);
		return temp;
	}
	
	if(data == root->data) {
		return root; // if data already present
	}
	
	if(data < root->data) {
		root->left = insertNode(root->left, data);
	} else {
		root->right = insertNode(root->right, data);
	}
	return root;
}

void inOrder(Node* root) {
	if(root == nullptr) {
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

bool isFullBT(Node* root) {
	if(root == nullptr) {
		return true;
	} 
	
	if(root->left == nullptr && root->right == nullptr) {
		return true;
	}
	
	if(root->left && root->right) {
		return (isFullBT(root->left) && isFullBT(root->right));
	}
	return false;
}

int countNodes(Node *root) {
	if(root == nullptr) {
		return 0;
	}
	return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isCompleteBT(Node* root, int index, int numNodes) {
	if(root == nullptr) {
		return true;
	}
	
	if(index >= numNodes) {
		return false;
	}
	
	return (isCompleteBT(root->left, 2 * index + 1, numNodes) && isCompleteBT(root->right, 2 * index + 2, numNodes));
}

int main() {
	Node *root = nullptr;
	root = insertNode(root, 4);
	root = insertNode(root, 3);
	root = insertNode(root, 2);
	root = insertNode(root, 5);
	//root = insertNode(root, 5);
	inOrder(root);
	if(isFullBT(root)) {
		cout << endl << "It is a Full Binary Tree";
	} else {
		cout << endl << "It is not a Full Binary Tree";
	}
	if(isCompleteBT(root, 0, countNodes(root))) {
		cout << endl << "It is a Complete Binary Tree";
	} else {
		cout << endl << "It is not a Complete Binary Tree";
	}
}