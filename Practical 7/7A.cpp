#include <iostream>

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    TreeNode* Insert(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        }
        if (key < root->key) {
            root->left = Insert(root->left, key);
        } else if (key > root->key) {
            root->right = Insert(root->right, key);
        }

        return root;
    }

    void Display(TreeNode* root) {
        if (root != nullptr) {
            Display(root->left);
            std::cout << root->key << " ";
            Display(root->right);
        }
    }

    void FindMax(TreeNode* root) {
        if (root == nullptr) {
            std::cout << "BST is empty\n";
            return;
        }

        TreeNode* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }

        std::cout << "Max value in BST: " << current->key << "\n";
    }
};

int main() {
    BinarySearchTree bst;

    // Asking the user for input
    int n, value;
    std::cout << "Enter the number of elements in the BST: ";
    std::cin >> n;

    std::cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        bst.root = bst.Insert(bst.root, value);
    }

    std::cout << "BST Elements: ";
    bst.Display(bst.root);
    std::cout << "\n";

    bst.FindMax(bst.root);

    return 0;
}
