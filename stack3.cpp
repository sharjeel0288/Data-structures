

#include <iostream>

using namespace std;
// using namespace main_savitch_7A;

template <class Item>
class Node
{
public:
    Node *next;
    Item data;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(Item n)
    {
        data = n;
        next = NULL;
    }
};
template <class Item>
class LinkedList
{
    Node<Item> *head;

public:
    LinkedList()
    {
        head = NULL;
        head->next = NULL;
    }
    LinkedList(Item n)
    {
        head = new Node<Item>(n);
    }
    void addNode(Item n)
    {
        if (head == NULL)
        {
            head = new Node<Item>(n);
            return;
        }
        Node<Item> *ptr = new Node<Item>(n);
        Node<Item> *temp = new Node<Item>();
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    void insertFront(Item n)
    {
        Node<Item> *ptr;
        ptr = new Node<Item>(n);
        ptr->next = head;
        // ptr->data = data;
        head = ptr;
    }
    Node<Item> *searchNode(Item n)
    {
        if (head != 0)
        {
            Node<Item> *temp = head;
            while (temp != NULL)
            {
                if (temp->data == n)
                    return temp;
                temp = temp->next;
            }
            cout << "No Node " << n << " in list.\n";
        }
    }
    bool deleteNode(Item n)
    {
        Node<Item> *cur = head->next;
        Node<Item> *pre = head;

        if (head->data == n)
        {
            head = head->next;
            delete (pre);
            return true;
        }
        while (cur != NULL)
        {
            if (cur->data == n)
            {
                pre->next = cur->next;
                delete (cur);
                return true;
            }
            cur = cur->next;
            pre = pre->next;
        }
        return false;
    }
    void reverse()
    {
        Node<Item> *prev = NULL, *next = NULL, *current = head;
        while (current != NULL) // 1 2 3 4
        {
            next = current->next; // temp has 2
            current->next = prev; // current>next (1)->Null
            prev = current;
            current = next;
        }
        head = prev;
    }
    void copyLinkedList(LinkedList l2)
    {
        if (head == NULL)
            return;
        Node<Item> *h1, *h2;
        h1 = head;
        h2 = l2.head;
        while (h1 != NULL)
        {
            l2.addNode(h1->data);
            h1 = h1->next;
        }
    }
    int compareLinkedList(LinkedList l2)
    {
        if (head == NULL && l2.head == NULL)
            return 1;
        if (head == NULL || l2.head == NULL)
            return 0;
        Node<Item> *h1, *h2;
        h1 = head;
        h2 = l2.head;
        while (h1 != NULL || h2 != NULL)
        {
            if (h1->data != h2->data)
                return 0;
            h1 = h1->next;
            h2 = h2->next;
        }
        if (h1 == NULL && h2 == NULL)
            return 1;
        if (h1 == NULL || h2 == NULL)
            return 0;
    }
    void deleteLinkedList()
    {
        Node<Item> *cur = head;
        Node<Item> *Nex = NULL;
        while (cur != NULL)
        {
            Nex = cur->next;
            delete (cur);
            cur = Nex;
        }
        head= NULL;
    }
    void display()
    {
        Node<Item> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl
             << endl;
    }
};

// template <class Item>
// void LinkedList<Item>::addNode(struct Node *head, int n)
// {
//     Node *newNode = new Node;
//     newNode->data = n;
//     newNode->next = NULL;

//     Node *cur = head;
//     while (cur)
//     {
//         if (cur->next == NULL)
//         {
//             cur->next = newNode;
//             return;
//         }
//         cur = cur->next;
//     }
// }

// template <class Item>
// void LinkedList<Item>::insertFront(struct Node **head, int n)
// {
//     Node *newNode = new Node;
//     newNode->data = n;
//     newNode->next = *head;
//     *head = newNode;
// }

// template <class Item>
// struct Node *searchNode(struct Node *head, int n)
// {
//     Node *cur = head;
//     while (cur)
//     {
//         if (cur->data == n)
//             return cur;
//         cur = cur->next;
//     }

// }

// template <class Item>
// bool LinkedList<Item>::deleteNode(struct Node **head, Node *ptrDel)
// {
//     Node *cur = *head;
//     if (ptrDel == *head)
//     {
//         *head = cur->next;
//         delete ptrDel;
//         return true;
//     }

//     while (cur)
//     {
//         if (cur->next == ptrDel)
//         {
//             cur->next = ptrDel->next;
//             delete ptrDel;
//             return true;
//         }
//         cur = cur->next;
//     }
//     return false;
// }

// template <class Item>
// struct Node *reverse(struct Node **head)
// {
//     Node *parent = *head;
//     Node *me = parent->next;
//     Node *child = me->next;

//     parent->next = NULL;
//     while (child)
//     {
//         me->next = parent;
//         parent = me;
//         me = child;
//         child = child->next;
//     }
//     me->next = parent;
//     *head = me;
//     return *head;
// }

// template <class Item>
// void LinkedList<Item>::copyLinkedList(struct Node *node, struct Node **pNew)
// {
//     if (node != NULL)
//     {
//         *pNew = new Node;
//         (*pNew)->data = node->data;
//         (*pNew)->next = NULL;
//         copyLinkedList(node->next, &((*pNew)->next));
//     }
// }

// template <class Item>
// int LinkedList<Item>::compareLinkedList(struct Node *node1, struct Node *node2)
// {
//     static int flag;

//     if (node1 == NULL && node2 == NULL)
//     {
//         flag = 1;
//     }
//     else
//     {
//         if (node1 == NULL || node2 == NULL)
//             flag = 0;
//         else if (node1->data != node2->data)
//             flag = 0;
//         else
//             compareLinkedList(node1->next, node2->next);
//     }

//     return flag;
// }

// template <class Item>
// void LinkedList<Item>::deleteLinkedList(struct Node **node)
// {
//     struct Node *tmpNode;
//     while (*node)
//     {
//         tmpNode = *node;
//         *node = tmpNode->next;
//         delete tmpNode;
//     }
// }

// template <class Item>
// void LinkedList<Item>::display(struct Node *head)
// {
//     Node *list = head;
//     while (list)
//     {
//         cout << list->data << " ";
//         list = list->next;
//     }
//     cout << endl;
//     cout << endl;
// }

int main()
{
    // struct Node *newHead;
    // struct Node *head = new Node;
    LinkedList<int> l1;
    int size;
    cout << "Create a linked list with size:";
    cin >> size;
    int temp;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value for the" << (i + 1) << "th node";
        cin >> temp;
        l1.addNode(temp);
    }

    l1.display();

    int numDel = size;
    Node<int> *ptrDelete = l1.searchNode(numDel);
    if (l1.deleteNode(numDel))
        cout << "Node " << numDel << " deleted!\n";
    l1.display();

    cout << "enter the value you want to remove";
    cin >> temp;
    numDel = temp;
     ptrDelete = l1.searchNode(numDel);
   if (l1.deleteNode(numDel))
        cout << "Node " << numDel << " deleted!\n";
    l1.display();
    return 0;
}
