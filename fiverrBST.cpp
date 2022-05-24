#include <iostream>
#include <stack>
#include <queue>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = 0;
        right = 0;
    }
    Node()
    {
        data = 0;
        left = 0;
        right = 0;
    }
};
class finger
{
    Node *ptr;

public:
    friend class BST;

    Node *removeRelinkLeft(Node *r, int v)
    {
        return this->delInBST(r, v);
    }

    Node *removeRelinkRight(Node *r, int v)
    {
        return this->delInBST(r, v);
    }
    Node *removeLeafNode(Node *r, int v)
    {
        return this->delInBST(r, v);
    }
    Node *moveToNextLevel(Node *r, int val)
    {
        if (r == NULL)
        {
            return r;
        }
        else
        {
            Node *temp = r;
            while (temp != NULL)
            {
                // cout<<temp->data<<endl;
                if (val == temp->data)
                {
                    return temp;
                }
                else if (val < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        // cout<<"------"<<endl;
                        return NULL;
                    }
                    temp = temp->left;
                }
                else
                {
                    if (temp->right == NULL)
                        return NULL;
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }
    Node *inordersucessor(Node *r)
    {
        Node *c = r;
        while (c && c->left != NULL)
        {
            c = c->left;
        }
        return c;
    }
    Node *delInBST(Node *r, int v)
    {
        // base case
        Node *temp;
        if (r == NULL)
        {
            return NULL;
        }
        else if (v < r->data)
        {
            r->left = delInBST(r->left, v);
        }

        else if (v > r->data)
        {
            r->right = delInBST(r->right, v);
        }

        else
        {
            if (r->left == NULL && r->right == NULL)
            {
                delete (r); // wipe out the memory, in C, use free function
                r = NULL;
            }

            else if (r->left == NULL)
            {
                temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                temp = r->left;
                delete r;
                return temp;
            }
            else
            {

                temp = inordersucessor(r->right);

                r->data = temp->data;

                r->right = delInBST(r->right, temp->data);
            }
        }
        return r;
    }
};
class BST
{
    Node *root;
    finger finger1, finger2;

    Node *recursiveSearch(Node *r, int val)
    {
        if (r == NULL)
        {
            return r;
        }
        else
        {
            Node *temp = r;
            while (temp != NULL)
            {
                // cout<<temp->data<<endl;
                if (val == temp->data)
                {
                    return temp;
                }
                else if (val < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        // cout<<"------"<<endl;
                        return NULL;
                    }
                    temp = temp->left;
                }
                else
                {
                    if (temp->right == NULL)
                        return NULL;
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }
    void _deleteTree(Node *node)
    {
        if (node == NULL)
            return;

        /* first delete both subtrees */
        _deleteTree(node->left);
        _deleteTree(node->right);

        /* then delete the node */
        cout << "Deleting node: " << node->data << endl;
        delete node;
    }
    void _print(Node *r)
    {
        if (r != NULL)
        {
            cout << r->data << " ";
            _print(r->left);
            _print(r->right);
        }
    }

public:
    friend class finger;
    BST()
    {
        root = 0;
    }
    BST(Node *n)
    {
        root = n;
    }
    void AddNode(int data)
    {
        Node *temp = root;
        Node *ptr = new Node(data); // 5
                                    //   3     6
        if (root == 0)
        {
            root = ptr;
            finger1.ptr = root;
            finger2.ptr = root;
            cout << "added as Root" << endl;
            return;
        }
        while (temp != 0)
        {
            if (data == temp->data)
            {
                cout << "Duplicate value" << endl; // c++
                return;
            }
            else if (temp->data > data && temp->left == 0)
            {
                temp->left = ptr;
                cout << "Inserted at left of : " << temp->data << endl;
                return;
            }
            else if (temp->data < data && temp->right == 0)
            {
                temp->right = ptr;
                cout << "Inserted at right of : " << temp->data << endl;
                return;
            }
            else if (temp->data > data && temp->left != 0)
            {
                temp = temp->left;
            }
            else if (temp->data < data && temp->right != 0)
            {
                temp = temp->right;
            }
        }
    }

    Node *search(int val)
    {
        Node *temp = root;
        return recursiveSearch(temp, val);
    }

    void deleteNode(int val)
    {
        Node *temp = root;
        Node *find = recursiveSearch(temp, val);
        if (find != 0)
        {
            finger1.removeLeafNode(temp, val);
            finger1.removeRelinkLeft(temp, val);
            finger1.removeRelinkRight(temp, val);
        }
        else
            cout << "Data not found " << endl;
        // if (find->left == NULL && find->right == NULL)
        // {
        //     temp = root;
        //     root = finger1.removeLeafNode(temp, val);
        // }
        // else if (find->left == NULL && find->right != NULL)
        // {
        //     temp = root;
        //     finger1.removeRelinkRight(temp, val);
        // }
        // else if (find->left != NULL && find->right == NULL)
        // {
        //     temp = root;
        //     finger1.removeRelinkLeft(temp, val);
        // }
        // else
        // {
        //     temp = root;
        //     finger1.removeRelinkRight(temp, val);
        // }
    }
    void print()
    {
        Node *temp = root;
        cout << "Tree :    ";
        this->_print(temp);
        cout << endl;
    }
    void run()
    {
        int choice = -1, n;
        while (choice != 0)
        {
            cout << "Press 0 to quit " << endl
                 << "Press 1 to insert " << endl
                 << "Press 2 to Find " << endl
                 << "Press 3 to remove Node " << endl
                 << "Press 4 to print " << endl
                 << "Press 5 to replace Node " << endl
                 << "Press 6 to delete Tree " << endl
                 << "Press 7 to clear screen " << endl;
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter data to insert : ";
                cin >> n;
                this->AddNode(n);
            }
            else if (choice == 2)
            {
                cout << "Enter data to find : ";
                cin >> n;
                this->find(n);
            }
            else if (choice == 3)
            {
                cout << "Enter data to delete  : ";
                cin >> n;
                this->deleteNode(n);
            }
            else if (choice == 4)
            {
                this->print();
            }
            else if (choice == 5)
            {
                int n, o;
                cout << "Enter old node data : ";
                cin >> o;
                cout << "Enter new node data : ";
                cin >> n;
                this->replace(o, n);
            }
            else if (choice == 6)
            {
                this->deleteTree();
            }
            else if (choice == 7)
                system("CLS");
            else
            {
                if (choice != 0)
                    cout << "Enter valid input" << endl;
            }
        }
        this->print();
        cout << endl
             << "QUITING" << endl;
    }
    void find(int val)
    {
        Node *temp = root;
        Node *find = finger1.moveToNextLevel(temp, val);
        if (find != NULL)
        {
            cout << "Success" << endl;
        }
        else
            cout << "Failure" << endl;
    }
    void deleteTree()
    {
        Node *temp = root;
        this->_deleteTree(temp);
        this->finger1.ptr = NULL;
        this->finger2.ptr = NULL;
        this->root = NULL;
    }
    void replace(int old, int New)
    {
        if (search(old) == NULL)
        {
            cout << "Data not found " << endl;
            return;
        }
        this->deleteNode(old);
        this->AddNode(New);
    }
    ~BST()
    {
        this->deleteTree();
    }
};

int main()
{
    BST tree;
    tree.run();
    return 0;
}
