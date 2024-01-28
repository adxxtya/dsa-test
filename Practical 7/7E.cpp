
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

        void InorderTraversal(TreeNode* root) {
            if (root != nullptr) {
                InorderTraversal(root->left);
                std::cout << root->key << " ";
                InorderTraversal(root->right);
            }
        }

        int CountNodes(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }

            return 1 + CountNodes(root->left) + CountNodes(root->right);
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

        std::cout << "BST nodes (Inorder Traversal): ";
        bst.InorderTraversal(bst.root);
        std::cout << std::endl;

        int nodeCount = bst.CountNodes(bst.root);
        std::cout << "Number of Nodes in BST: " << nodeCount << std::endl;

        return 0;
    }
