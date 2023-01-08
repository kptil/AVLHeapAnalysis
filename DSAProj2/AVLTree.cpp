#include "AVLTree.h"
#include <iostream>
#include <queue>

// Constructors for a AVLNode and an AVLTree.
AVLNode::AVLNode(int value, AVLNode* left, AVLNode* right, int height) {
    val = value;
    this->left = left;
    this->right = right;
    this->height = height;
}

AVLTree::AVLTree() {
    root = nullptr;
}

/*======= Rotations and Utility Functions =======*/

AVLNode* AVLTree::rotateLeft(AVLNode* node)
{
    AVLNode* newRoot = node->right;
    node->right = newRoot->left;
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->left = node;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

AVLNode* AVLTree::rotateRight(AVLNode* node)
{
    AVLNode* newRoot = node->left;
    node->left = newRoot->right;
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->right = node;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

AVLNode* AVLTree::rotateLeftRight(AVLNode* node)
{
    node->left = rotateLeft(node->left);
    node = rotateRight(node);
    return node;
}

AVLNode* AVLTree::rotateRightLeft(AVLNode* node)
{
    node->right = rotateRight(node->right);
    node = rotateLeft(node);
    return node;
}

// Returns 1-based height of node
int AVLTree::height(AVLNode* node) {
    return node == nullptr ? 0 : node->height;
}

// Gets the minimum value in a tree by searching to the left until the left child is nullptr.
AVLNode* AVLTree::getMin(AVLNode* root) {
    if (root->left == nullptr) { return root; }
    else {
        return getMin(root->left);
    }
}

int AVLTree::balanceFactor(AVLNode* node) {
    return node == nullptr ? 0 : height(node->left) - height(node->right);
}

AVLNode* AVLTree::balance(AVLNode* root) {
    if (root == nullptr) { return root; }

    if (height(root->left) - height(root->right) == 2) {
        if (height(root->left->left) >= height(root->left->right)) {
            root = rotateRight(root);
        }
        else {
            root = rotateLeftRight(root);
        }
    }
    else if (height(root->left) - height(root->right) == -2) {
        if (height(root->right->left) >= height(root->right->right)) {
            root = rotateRightLeft(root);
        }
        else {
            root = rotateLeft(root);
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;
}

/*===== Insertion =====*/

void AVLTree::insert(int value) {
    root = insertHelp(root, value);
    numElements++;
}

// Duplicate elements are allowed and placed to the left.
AVLNode* AVLTree::insertHelp(AVLNode* root, int value) {
    if (root == nullptr) {
        root = new AVLNode(value);
        return root;
    }
    else if (value > root->val) {
        root->right = insertHelp(root->right, value);
    }
    else {
        root->left = insertHelp(root->left, value);
    }

    // Balancing
    root->height = max(height(root->left), height(root->right)) + 1;
    int balFactor = balanceFactor(root);

    if (balFactor > 1) {
        if (height(root->left->left) > height(root->left->right)) {
            return rotateRight(root);
        }
        else if (height(root->left->left) < height(root->left->right)) {
            return rotateLeftRight(root);
        }
    }
    if (balFactor < -1) {
        if (height(root->right->right) > height(root->right->left)) {
            return rotateLeft(root);
        }
        else if (height(root->right->right) < height(root->right->left)) {
            return rotateRightLeft(root);
        }
        
    }
  

    return root;
}

/*===== Removal =====*/
void AVLTree::remove() {
    root = removeHelp(root, root->val);
    numElements--;
}

AVLNode* AVLTree::removeHelp(AVLNode* root, int value) {
    if (root == nullptr) { return root; }
    if (root->val == value) {
        if (root->left == nullptr && root->right == nullptr) { root = nullptr; }
        else if (root->right == nullptr) { root = root->left; }
        else if (root->left == nullptr) { root = root->right; }
        else {
            AVLNode* minTemp = getMin(root->right);
            root->val = minTemp->val;
            root->right = removeHelp(root->right, minTemp->val);
        }
    }
    else if (value > root->val) {
        root->right = removeHelp(root->right, value);
    }
    else {
        root->left = removeHelp(root->left, value);
    }

    // Balancing

    if (root == nullptr) { return root; }
    else {
        root->height = max(height(root->left), height(root->right)) + 1;
        int balFactor = balanceFactor(root);

        if (balFactor > 1) { // there must be a at least two nodes to the left
            if (height(root->left->left) > height(root->left->right)) {
                return rotateRight(root);
            }
            else if (height(root->left->left) < height(root->left->right)) {
                return rotateLeftRight(root);
            }
        }
        if (balFactor < -1) { // there must be at least two nodes to the right
            if (height(root->right->right) > height(root->right->left)) {
                return rotateLeft(root);
            }
            else if (height(root->right->right) < height(root->right->left)) {
                return rotateRightLeft(root);
            }
        }

        return root;
    }
}

/*==== Traversal =====*/

void AVLTree::traverseLevelOrder() {
    queue<AVLNode*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        count = q.size();
        for (int i = 0; i < count; i++) {
            cout << q.front()->val << " ";
            if (q.front()->left != NULL) { q.push(q.front()->left); }
            if (q.front()->right != NULL) { q.push(q.front()->right); }
            q.pop();
        }

    }
    cout << endl;
    return;
}

/*===== Test Print Function ======*/
void AVLTree::printInOrder() {
    printHelp(root);
}

void AVLTree::printHelp(AVLNode* root) {
    if (root == nullptr) { return; }
    printHelp(root->left);
    std::cout << root->val << " ";
    printHelp(root->right);
}

int AVLTree::GetSize() {
    return numElements;
}
