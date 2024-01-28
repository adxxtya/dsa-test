
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

        TreeNode* DeleteNode(TreeNode* root, int key) {
            if (root == nullptr) {
                return root;
            }

            if (key < root->key) {
                root->left = DeleteNode(root->left, key);
            } else if (key > root->key) {
                root->right = DeleteNode(root->right, key);
            } else {
                if (root->left == nullptr) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }

                TreeNode* temp = root->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }

                root->key = temp->key;
                root->right = DeleteNode(root->right, temp->key);
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

        // Asking the user for the node to delete
        int keyToDelete;
        std::cout << "Enter the key to delete: ";
        std::cin >> keyToDelete;

        bst.root = bst.DeleteNode(bst.root, keyToDelete);

        std::cout << "BST after deletion (Inorder Traversal): ";
        // Displaying the BST (inorder traversal) after deletion
        bst.InorderTraversal(bst.root);
        std::cout << std::endl;

        return 0;
    }
