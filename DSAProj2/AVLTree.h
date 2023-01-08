#pragma once
#include <string>

using namespace std;

struct AVLNode
{
	int val;
	AVLNode* left;
	AVLNode* right;
	int height;
	AVLNode(int val = 0, AVLNode* left = nullptr, AVLNode* right = nullptr, int height = 1);
};

class AVLTree
{
	AVLNode* root;
	int numElements;

	AVLNode* rotateLeft(AVLNode* node);
	AVLNode* rotateRight(AVLNode* node);
	AVLNode* rotateLeftRight(AVLNode* node);
	AVLNode* rotateRightLeft(AVLNode* node);
	int height(AVLNode* node);
	AVLNode* balance(AVLNode* root);
	int balanceFactor(AVLNode* node);
	AVLNode* getMin(AVLNode* root);

	AVLNode* insertHelp(AVLNode* root, int value);
	AVLNode* removeHelp(AVLNode* root, int value);
	void printHelp(AVLNode* root);

public:
	AVLTree();
	void insert(int value);
	void remove();
	void traverseLevelOrder();
	void printInOrder();
	int GetSize();
};

