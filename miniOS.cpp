#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Node
{

public:
    int process, quota, runtime;
    char id[2];
    Node *next;
    Node()
    {
        next = NULL;
        quota = 0;
        process = 0;
        id[0] = '-';
        id[1] = '-';
    }
    Node(int p, int q, char id1, char id2)
    {
        next = NULL;
        this->quota = q;
        this->process = p;
        this->id[0] = id1;
        this->id[1] = id2;
        this->runtime = p / q;
    }
};
class list
{
    Node *head;

public:
    list(Node *n)
    {
        head = n;
        n->next = head;
    }
    list()
    {
        head = NULL;
    }

    void InsertAtBeg(int p, int q, char id1, char id2)
    {
        Node *ptr = new Node(p, q, id1, id2);
        Node *pt = head;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            return;
        }
        if (head == NULL)
        {
            head = ptr;
            return;
        }
        do
        {
            pt = pt->next;
        } while (pt->next != head);
        pt->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    void insertAtEnd(int p, int q, char id1, char id2)
    {
        Node *ptr = new Node(p, q, id1, id2);
        Node *pt = head;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            return;
        }
        if (head == NULL)
        {
            head = ptr;
            return;
        }
        do
        {
            pt = pt->next;
        } while (pt->next != head);
        pt->next = ptr;
        ptr->next = head;
    }
    void insertAtINdex(int p, int q, char id1, char id2, int index)
    {
        int i = 0;
        Node *temp = head;
        Node *ptr = new Node(p, q, id1, id2);
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            return;
        }
        if (head == NULL)
        {
            head = ptr;
            return;
        }
        if (index == 0)
        {
            this->InsertAtBeg(p, q, id1, id2);
            return;
        }
        do
        {
            if (index == (i + 1))
                break;
            i++;
            temp = temp->next;
        } while (temp->next != head);
        if (index != (i + 1))
            return;
        ptr->next = temp->next;
        temp->next = ptr;
    }
    void delhead()
    {
        Node *temp = head;
        Node *ptr = head->next;
        do
        {
            temp = temp->next;
            ptr = ptr->next;
        } while (temp->next != head);
        temp->next = ptr->next;
        head = ptr->next;
        delete ptr;
    }
    void delNode(int index)
    {
        int i = 0;
        Node *temp = head;
        Node *ptr = head->next;
        if (index == 0)
        {
            delhead();
            return;
        }
        do
        {
            if (index == (i + 1))
                break;
            i++;
            temp = temp->next;
            ptr = ptr->next;
        } while (temp->next != head);
        if (index != (i + 1))
            return;
        temp->next = ptr->next;
        delete (ptr);
    }
    int Totalrt()
    {
        int rt = 0;
        Node *temp = head;
        do
        {
            rt += temp->runtime;
            temp = temp->next;
        } while (temp != head);
        return rt;
    }
    void miniOS()
    {
        int rt = this->Totalrt();
        Node *temp = head;
        while (rt > 0)
        {
            
            if (temp->runtime > 0)
            {
                cout << temp->id[0] << temp->id[1] << endl;
                rt--;
            }
            temp->runtime--;
            temp = temp->next;
            
        }
    }
};
int main()
{
    int n;
    cin>>n;
    int p,q;
    char id1,id2;
    list l;
    for (int i = 0; i < n; i++)
    {
        cin>>id1>>id2>>p>>q;
        l.insertAtEnd(p,q,id1,id2);
    }
    l.miniOS();
    
}