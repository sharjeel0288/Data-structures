#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
    Node()
    {

        this->next = NULL;
        this->data = 0;
    }

    void triversal()
    {
        Node *ptr = this;
        while (ptr != NULL)
        {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
        cout << endl;
    }
    Node *insertAtBeginning(int data)
    {
        Node *ptr;
        ptr = new Node();
        ptr->next = this;
        ptr->data = data;
        return ptr;
    }
    Node *insertAtEnd(int data)
    {
        Node *ptr = new Node();
        Node *temp = new Node();
        temp = this;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        ptr->data = data;
        return this;
    }
    Node *insertAtAfter(Node *prevNode, int data)
    {
        Node *ptr = new Node();
        Node *temp = new Node();
        temp = this;
        ptr->data = data;
        ptr->next = prevNode->next;
        prevNode->next = ptr;
        return this;
    }
    Node *insertAtIndex(int data, int index)
    {
        Node *ptr;
        Node *Temp;
        ptr = new Node();
        Temp = this;
        if (index == 0)
        {
            return this->insertAtBeginning(data);
        }
        int i = 0;
        while (i != index - 1)
        {
            Temp = Temp->next;
            i++;
        }
        if (Temp->next == NULL)
        {
            return this->insertAtEnd(data);
        }
        ptr->next = Temp->next;
        Temp->next = ptr;
        ptr->data = data;

        return this;
    }
    Node *DeleteHead()
    {
        if (this != NULL)
        {
            Node *head = this;
            Node *ptr = this;
            head = head->next;
            free(ptr);
            return head;
        }
        return this;
    }
    Node *DeleteAtIndex(int index)
    {

        Node *ptr = this;
        Node *temp;
        bool flag = false;
        int counter = 0;
        Node *t = this;
        if (index == 0)
        {
            return this->DeleteHead();
        }
        while (t != NULL)
        {
            if (counter == index)
            {
                flag = true;
                break;
            }
            counter++;
        }
        if (flag != true)
        {
            cout << "Out of index" << endl;
            return this;
        }
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            return this->DeleteLastNode();
        }
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        return this;
    }
    Node *UpdateByKey(int key)
    {
        bool check = true;
        Node *temp = this;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                check = false;
                break;
            }
            temp = temp->next;
        }
        if (check != false)
        {
            cout << "Node not found" << endl;
            return this;
        }
        cout << "Enter new data value : ";
        int val;
        cin >> val;
        temp->data = val;
        return this;
    }
    Node *DeleteLastNode()
    {
        Node *ptr = this;
        Node *temp = this->next;
        while (temp->next != NULL)
        {
            ptr = ptr->next;
            temp = temp->next;
        }
        ptr->next = NULL;
        free(temp);
        return this;
    }

    Node *DeleteWithKey(int value)
    {
        Node *ptr = this;
        Node *temp = this->next;
        while (temp->data != value && temp->next != NULL)
        {
            ptr = ptr->next;
            temp = temp->next;
        }
        if (temp->data == value)
        {
            ptr->next = temp->next;
            free(temp);
        }
        return this;
    }
    bool IsEmpty()
    {
        if (this == NULL)
            return true;
        return false;
    }
    bool isFull()
    {
        Node *temp = new Node();
        if (temp == NULL)
            return true;
        return false;
    }
};

int main()
{
    int data, Index;
    Node *List;
    cout << "List created enter head node data : ";
    cin >> data;
    List = new Node(data);

    int choice;
    while (choice != 0)
    {
        cout << "Press 1 for inserting a node at Beginning"
             << endl
             << "Press 2 for inserting a node at end"
             << endl
             << "Press 3 for insert at index"
             << endl
             << "Press 4 for deleting head node"
             << endl
             << "Press 5 for delete at index"
             << endl
             << "Press 6 for delete last node"
             << endl
             << "Press 7 for delete with key"
             << endl
             << "Press 8 for printing list"
             << endl
             << "Press 9 for IsEmpty"
             << endl
             << "Press 10 for IsFull"
             << endl
             << "Press 11 for updating node value" << endl
             << "Press 0 for end " << endl
             << endl;
        cin >> choice;
        switch ((choice))
        {
        case 1:
            cout << "Enter Data : ";
            cin >> data;
            List = List->insertAtBeginning(data);
            break;
        case 2:
            cout << "Enter Data : ";
            cin >> data;
            List = List->insertAtEnd(data);
            break;
        case 3:
            cout << "Enter Data : ";
            cin >> data;
            cout << "Enter Index : ";
            cin >> Index;
            List = List->insertAtIndex(data, Index);
            break;
        case 4:
            List = List->DeleteHead();
            break;
        case 5:
            cout << "Enter Index : ";
            cin >> Index;
            List = List->DeleteAtIndex(Index);
            break;
        case 6:
            List = List->DeleteLastNode();
            break;
        case 7:
            cout << "Enter Data : ";
            cin >> data;
            List = List->DeleteWithKey(data);
            break;
        case 8:
            List->triversal();
            break;
        case 9:
            if (List->IsEmpty())
                cout << "List is empty";
            else
                cout << "List is not empty" << endl;
            break;
        case 10:
            if (List->isFull())
                cout << "List full" << endl;
            else
                cout << "List is not full" << endl;
            break;
        case 11:
            cout << "Enter data which is to be updated : ";
            cin >> data;
            List = List->UpdateByKey(data);
            break;
        case 0:
            break;
        default:
            cout << "Enter valid input" << endl;
            break;
        }
    }

    return 0;
}