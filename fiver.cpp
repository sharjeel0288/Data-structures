

#include <iostream>
#include <cassert>

using namespace std;
// using namespace main_savitch_7A;


template <class Item>
class Node
{
public:
Node<Item> *next;
Item data;
// Node()
// {
//     data = 0;
//     next = 0;
// }
// Node(Item n)
// {
//     data = n;
//     next = 0;
// }
Node()
{
    data = 0;
    next = 0;
}

Node(Item n)
{
    data = n;
    next = 0;
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
    // head->next = NULL;
}
LinkedList(Item n)
{
    head = new Node<Item>(n);
}

void addNode(Item n)
{
    cout << "in add node" << endl;
    if (head == NULL)
    {
        cout << "head" << endl;
        head = new Node<Item>(n);
        // head->data=n;
        // this->display();
        // head->next=NULL;

        return;
    }
    Node<Item> *ptr = new Node<Item>();
    Node<Item> *temp = new Node<Item>();
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
    ptr->data = n;

    // this->display();
}

void insertFront(Item n)
{
    if (head == NULL)
    {
        cout << "head" << endl;
        head = new Node<Item>(n);
        // head->data=n;
        this->display();
        // head->next=NULL;

        return;
    }
    Node<Item> *ptr;
    ptr = new Node<Item>(n);
    ptr->next = head;
    // ptr->data = data;
    head = ptr;
}
// 
// Node<Item> *searchNode(Item n)
// {

//     {
//         if (head == NULL)
//         {
//             cout << "No Node " << n << " in list.\n";
//             return NULL;
//         }
//         Node<Item> *temp ;
//         temp = head;
//         while (temp != NULL)
//         {
//             if (temp->data == n)
//                 return temp;
//             temp = temp->next;
//         }
//         cout << "No Node " << n << " in list.\n";
//     }
// }

int size()
{
    if(head==NULL)
    return 0;
    Node<Item> *temp = head;
    int i = 0;
    while (temp != NULL) // 1 2 3 4
    {
        temp = temp->next;
        i++;
    }
    return i;
}

Item top()
{

    Node<Item> *cur = head->next;
    Node<Item> *pre = head;

    if(head==NULL)
    return 0;
    if(head->next==NULL)
    return head->data;
    while(cur->next!=NULL)
    cur=cur->next;
    // cout<<"cur->data : "<<cur->data<<endl;
    return cur->data;

}

Item peek(int index)
{
    

    Node<Item> *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (i == this->size()-index)
            break;
        temp = temp->next;
        i++;
    }
    return temp->data;
    ;
}

Item pop()
{

    if (head == NULL)
            return NULL;
    if(head->next==NULL)
    {
        Node<Item> *p=head;
        head=NULL;
        int t=p->data;
        delete(p);
        return t;
    }
        Node<Item> *ptr = head;
        Node<Item> *temp = head->next;
        while (temp->next != NULL)
        {
            ptr = ptr->next;
            temp = temp->next;
        }
        ptr->next = NULL;
        int t=temp->data;
        free(temp);
        return t;
        
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
    head = NULL;
}

void display()
{
    cout << "List : ";
    Node<Item> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

int empty()
{
    if (head == 0)
        return 0;
    return 1;
}
};

// 
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

// 
// void LinkedList<Item>::insertFront(struct Node **head, int n)
// {
//     Node *newNode = new Node;
//     newNode->data = n;
//     newNode->next = *head;
//     *head = newNode;
// }

// 
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

// 
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

// 
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

// 
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

// 
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

// 
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

// 
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
    LinkedList<int> testStack;
    
    for (int  i = 0; i < 10; i++)
    {
        // testStack.addNode(i);
        cout<<i<<" "<<testStack.size()<<endl;
			testStack.display();	   // Size should match
			assert(i == (testStack.size()));
			testStack.addNode(i);				   // Add item to Stack
			testStack.display();	   // Size should match
			assert(i + 1 == testStack.size()); // Size should match
			assert(testStack.empty()==1);		   // The stack should not be empty
            cout<<i<<"   check     "<<testStack.top()<<endl;
            
			assert(i == testStack.top());	   // The top() should match what was just pushed
			for (size_t j = 1; j <= testStack.size(); ++j) // Check the Whole Stack
				assert(testStack.size() - j == testStack.peek(j));
    }
    cout<<"Asf";
     for (int i = 9; i >= 0; --i)
		{

            cout<<"ASfa";
            // cout<<"Size : "<<testStack.size();
            // cout<<"    top : "<<testStack.top();
            // cout<<"     pop : "<<testStack.pop();
            cout<<"   i : "<<i<<endl;
			assert(i  == testStack.size()-1); // Size should match
			assert(i == testStack.top());	
            cout<<"    topped   ";   // The top() should match
			assert(i == testStack.pop());
            cout<<"popped"<<endl;	   // And so should the pop()
		}

		assert(0 == testStack.size()); // And now it should be Empty
		assert(testStack.empty() == 0);
        cout<<"suc";
    return 0;
}
