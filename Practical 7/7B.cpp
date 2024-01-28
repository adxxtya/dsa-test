
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

        TreeNode* LargestNode(TreeNode* root) {
            if (root == nullptr || root->right == nullptr) {
                return root;
            }

            return LargestNode(root->right);
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

        TreeNode* largestNode = bst.LargestNode(bst.root);

        if (largestNode != nullptr) {
            std::cout << "Largest Node in BST: " << largestNode->key << "\n";
        } else {
            std::cout << "BST is empty.\n";
        }

        return 0;
    }
