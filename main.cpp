#include <iostream>
#include <iomanip>
using namespace std;
class BinarySearchTree
{
private:
    struct TreeNode
    {
        TreeNode* left;
        TreeNode* right;
        int data;
    };
    TreeNode* root;
public:
    BinarySearchTree()
    {
        root = nullptr;
    }
    bool isEmpty() const { return root == nullptr; }
    void printPostOrder();
    void postOrder(TreeNode*, int indent, bool last);
    void insert(int value);
    void remove(int value);
};

void BinarySearchTree::insert(int value)
{
    TreeNode* newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (isEmpty())
    {
        root = newNode;
    }
    else
    {
        TreeNode* current = root;
        TreeNode* parent = nullptr;

        while (current)
        {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }
}

void BinarySearchTree::remove(int value)
{
    if (isEmpty())
    {
        cout << "This Tree is empty!" << endl;
        return;
    }

    TreeNode* current = root;
    TreeNode* parent = nullptr;
    bool found = false;

    // Locate the node to be deleted and its parent
    while (current != nullptr)
    {
        if (current->data == value)
        {
            found = true;
            break;
        }
        else
        {
            parent = current;
            if (value > current->data)
                current = current->right;
            else
                current = current->left;
        }
    }

    if (!found)
    {
        cout << "Data not found!" << endl;
        return;
    }

    // Case 1: Node with only one child or no child
    if (current->left == nullptr || current->right == nullptr)
    {
        TreeNode* temp = (current->left != nullptr) ? current->left : current->right;

        // No child case
        if (temp == nullptr)
        {
            if (parent == nullptr)
                root = nullptr;
            else if (current == parent->left)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            delete current;
        }
        else // One child case
        {
            if (parent == nullptr)
                root = temp;
            else if (current == parent->left)
                parent->left = temp;
            else
                parent->right = temp;
            delete current;
        }
    }
    else // Case 2: Node with two children
    {
        TreeNode* successor = current->right;
        TreeNode* successorParent = nullptr;

        while (successor->left != nullptr)
        {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (successorParent != nullptr)
            successorParent->left = successor->right;
        else
            current->right = successor->right;

        delete successor;
    }
}

void BinarySearchTree::printPostOrder()
{
    postOrder(root, 0, true);
}

void BinarySearchTree::postOrder(TreeNode* node, int indent, bool last)
{
    if (node != nullptr)
    {
        if (indent > 0)
        {
            cout << setw(indent) << ' ';
        }

        if (last)
        {
            cout << "R----";
            indent += 6;
        }
        else
        {
            cout << "L----";
            indent += 6;
        }

        cout << node->data << endl;

        postOrder(node->left, indent, false);
        postOrder(node->right, indent, true);
    }
}

int main()
{
    BinarySearchTree bst;
    int choice;
    int value;

    while (true)
    {
        cout << endl << endl;
        cout << " Binary Search Tree Operations " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Insertion/Creation " << endl;
        cout << " 2. Printing " << endl;
        cout << " 3. Removal " << endl;
        cout << " 4. Exit " << endl;
        cout << " Enter your choice : ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case 1:
            cout << " Enter Number to be inserted : ";
            cin >> value;
            bst.insert(value);
            break;
        case 2:
            cout << endl;
            cout << " Printing " << endl;
            cout << " --------------------" << endl;
            bst.printPostOrder();
            break;
        case 3:
            cout << " Enter data to be deleted : ";
            cin >> value;
            bst.remove(value);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
}
