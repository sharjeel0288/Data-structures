#include <iostream>
#include <iomanip>
#include <cstring>
#include<stack>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stacks
{
    Node *Top = new Node();

public:
    Stacks()
    {
        Top = NULL;
    }
    Stacks *push(int data)
    {
        if (this->isFull())
            cout << "Stack overflow" << endl;

        else
        {
            Node *n = new Node();

            n->data = data;
            n->next = this->Top;
            this->Top = n;
            return this;
        }
    }
    int pop()
    {
        if (empty())
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            if(Top==NULL)
            return NULL;
            Node *n = this->Top;
            this->Top = this->Top->next;
            int data = n->data;
            free(n);
            return data;
        }
    }
    bool empty()
    {
        if (this->Top == NULL)
            return true;

        return false;
    }
    bool isFull()
    {
        Node *p = new Node();
        if (p == NULL)
            return true;

        free(p);
        return false;
    }
    int top()
    {
        if(Top!=NULL)
        return Top->data;
        return NULL;
    }
    void triversal()
    {
        Node *ptr = new Node();
        ptr = Top;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    int size()
    {
        Node *ptr = new Node();
        ptr = Top;
        int i=0;
        while (ptr != NULL)
        {
i++;            ptr = ptr->next;
        }
        return i;
    }
    int peak(int index)
    {
        Node *t = Top;
        for (int i = 0; (i < index - 1 && t != NULL); i++)
        {
            t = t->next;
        }
        if (t != NULL)
        {
            return t->data;
        }
        return -1;
    }
};


bool checkConflict(Stacks RowStacks, Stacks ColStacks, int row, int column);
void createQueens(int numberOfQueens);
int main()
{
	int numberOfQueens;
	Stacks s1;
	std::stack<int> s2;
	cout<<s1.empty();
	cout<<s2.empty();
	for (int i = 0; i < 10; i++)
	{
		s1.push(i);
		s1.triversal();
		s2.push(i);
	}
	
	cout<<"my toop : "<<s1.top();
	cout<<"s top : "<<s2.top();
	for (int i = 0; i < 10; i++)
	{
		cout<<"My top : "<<s1.top()<<"    S top : "<<s2.top()<<endl;
		cout<<"My sz : "<<s1.size()<<"    S sz : "<<s2.size()<<endl;
		s1.pop();
		s2.pop();
		// s1.display();
	}
	cout << endl;
	


	std::cout << "How many Queens/Row x Columns do you want to have? (Must be 4 or greater) ";
	std::cin >> numberOfQueens;
	createQueens(numberOfQueens);

	return 0;
}
bool checkConflict(Stacks RowStacks, Stacks ColStacks, int row, int column)
{
	bool conflict = false;
	while (!RowStacks.empty())
	{
		// Checks columns of the queen on Stackss
		if (column == ColStacks.top())
		{
			conflict = true;
			break;
		}
		// Check the diagonals by taking the slope and if the slope is 1 then its a diagonal
		else if (abs((row - RowStacks.top())) == abs((column - ColStacks.top())))
		{
			conflict = true;
			break;
		}
		// Pop it each time so we can check all values
		ColStacks.pop();
		RowStacks.pop();
	}
	return conflict;
}
void createQueens(int numberOfQueens)
{
	// Stackss to hold columns and rows
	Stacks ColStacks;

	Stacks RowStacks;

	int column = 1;
	int row = 1;
	int filled = 0;
	bool conflict = false;

	// Determine if the board is an impossible size
	bool specialCase = false;

	RowStacks.push(row);
	ColStacks.push(column);

	filled++;
	row++;

	while (RowStacks.size() < numberOfQueens)
	{
		// Conflict check
		conflict = checkConflict(RowStacks, ColStacks, row, column);

		if (conflict && column != numberOfQueens)
		{
			column++;
		}

		else if (conflict && column == numberOfQueens)
		{
			// If the one already set on board can be moved, move it over one column
			if (ColStacks.top() + 1 <= numberOfQueens)
			{
				column = ColStacks.top() + 1;
				row = RowStacks.top();
			}
			// If it cannot move, pop it off and make the one under it move over one
			else
			{
				RowStacks.pop();
				ColStacks.pop();
				filled--;
				if (!RowStacks.empty())
				{
					column = ColStacks.top() + 1;
					row = RowStacks.top();
				}
			}
			// Then pop it off so we can move it and check for conflicts, ran every time
			if (!RowStacks.empty())
			{
				RowStacks.pop();
				ColStacks.pop();
				filled--;
			}
			else
			{
				specialCase = true;
				break;
			}
		}
		// If there are no conflicts, then push it on the Stacks
		else
		{
			filled++;
			RowStacks.push(row);
			ColStacks.push(column);
			if (filled == numberOfQueens)
			{
				break;
			}
			else
			{
				column = 1;
				row++;
			}
		}
        cout<<"row : "<<RowStacks.size()<<"   col : "<<ColStacks.size()<<endl;
	}

	std::cout << "Filled Spots: " << filled << std::endl;

	if (!specialCase)
	{
		cout<<RowStacks.size()<<endl;
		for (int i = numberOfQueens; i > 0; i--)
		{
			std::cout << "Row: " << RowStacks.top() << " Col: " << ColStacks.top() << std::endl;
			RowStacks.pop();
			ColStacks.pop();
		}
	}

	else
	{
		std::cout << "The board size of " << numberOfQueens << " x " << numberOfQueens << " is not possible." << std::endl;
	}
}
