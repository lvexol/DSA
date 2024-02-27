#include <iostream>
#include <cmath>
using namespace std;
class BinaryTree {
private:
    int* treeArray;
    int capacity;
    int size;
public:
    BinaryTree(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->treeArray = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            treeArray[i] = -1;
        }
    }

    void insert(int value) {
        if (size >= capacity) {
           cout << "Binary tree is full. Cannot insert more elements.\n";
            return;
        }

        treeArray[size] = value;
        size++;
    }

    void inorderTraversal() {
        inorderTraversalHelper(0);
       cout <<endl;
    }

    void preorderTraversal() {
        preorderTraversalHelper(0);
       cout <<endl;
    }

    void postorderTraversal() {
        postorderTraversalHelper(0);
       cout <<endl;
    }

    void inorderTraversalHelper(int index) {
        if (index < size) {
            inorderTraversalHelper(2 * index + 1);
           cout << treeArray[index] << " ";
            inorderTraversalHelper(2 * index + 2);
        }
    }

    void preorderTraversalHelper(int index) {
        if (index < size) {
           cout << treeArray[index] << " ";
            preorderTraversalHelper(2 * index + 1);
            preorderTraversalHelper(2 * index + 2);
        }
    }

    void postorderTraversalHelper(int index) {
        if (index < size) {
            postorderTraversalHelper(2 * index + 1);
            postorderTraversalHelper(2 * index + 2);
           cout << treeArray[index] << " ";
        }
    }
};
int main() {
    BinaryTree tree(10);
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
   cout << "Inorder Traversal: ";
    tree.inorderTraversal();
   cout << "Preorder Traversal: ";
    tree.preorderTraversal();
   cout << "Postorder Traversal: ";
    tree.postorderTraversal();
    return 0;
}
