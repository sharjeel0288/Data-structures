// Name: Route.h
// Project: CMSC 202 Project 3, Spring 2022
// Author:  Jeremy Dixon
// Date:    2/22/2022
// Desc: This file contains the header details for the Route class
//       A route is a linked list that uses ports as nodes

#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "Port.h"
using namespace std;

class Route
{
public:
  // Name: Route() - Default Constructor
  // Desc: Used to build a new Route (linked list) make up of ports
  // Preconditions: None
  // Postconditions: Creates a new Route where m_head and m_tail point to nullptr and size = 0
  Route()
  {
    m_head = 0;
    m_tail = 0;
    m_size = 0;
  }
  // Name: SetName(string)
  // Desc: Sets the name of the route (usually first port to last port)
  // Preconditions: None
  // Postconditions: Sets name of route
  void SetName(string name)
  {
    m_name = name;
  }
  // Name: ~Route() - Destructor
  // Desc: Used to destruct a strand of Route
  // Preconditions: There is an existing Route strand with at least one port
  // Postconditions: Route is deallocated (including all dynamically allocated ports)
  //                 to have no memory leaks!
  ~Route()
  {
    Port *current = m_head;
    Port *next = NULL;

    while (current != NULL)
    {
      next = current->GetNext();
      free(current);
      current = next;
    }
    m_head = NULL;
  }
  // Name: InsertEnd (string, string, double double)
  // Desc: Creates a new port using the data passed to it.
  //       Inserts the new port at the end of the route
  // Preconditions: Takes in a Port
  //                Requires a Route
  // Postconditions: Adds the new port to the end of a route
  void InsertEnd(string name, string location, double north, double west)
  {
    // Port *temp = new Port(name, location, north, west);
    Port *ptr = new Port(name, location, west, north);
    cout << "Created" << endl;

    // temp->GetName() = name;
    // temp->GetLocation() = location;
    // north = temp->GetNorth();
    // west = temp->GetWest();
    if (m_head == 0)
    {
      cout << "in if" << endl;
      // m_head=ptr;
      // m_tail=ptr;
      cout << "fine" << endl;
    }
    else
    {
      Port *temp;
      temp = m_head;
      while (temp->GetNext() != NULL)
      {
        temp = temp->GetNext();
      }
      temp->SetNext(ptr);
      m_tail = ptr;
    }
  }
  // Name: RemovePort(int index)
  // Desc: Removes a port from the route at the index provided
  //       Hint: Special cases (first port, last port, middle port)
  // Preconditions: Index must be less than the size of the route
  //       Cannot make route less than two ports. If the route has
  //       two or fewer ports, fails.
  // Postconditions: Name may be updated. Size is reduced. Route has one less port.
  void RemovePort(int index)
  {
    Port *curr = m_head;

    if (m_size == 0)
    {
      return;
    }
    else if (m_size == 1)
    {
      delete m_head;
      m_head = nullptr;
      m_tail = nullptr;
      m_size--;
    }
    else
    {
      while (curr->GetNext() != m_tail)
      {
        curr = curr->GetNext();
      }
      delete curr->GetNext();
      m_tail = curr;
      m_tail->SetNext(nullptr);
      m_size--;
    }
  }
  // Name: GetName()
  // Desc: Returns the name of the route (Usually starting port to last port)
  //       For example: Baltimore to Brunswick
  // Preconditions: Requires a Route
  // Postconditions: Returns m_name;
  string GetName()
  {
    return m_name;
  }
  // Name: UpdateName()
  // Desc: Updates m_name based on the name of the first port in the route
  //       and the last port in the route
  //       For example: Baltimore to Brunswick
  // Preconditions: Requires a Route with at least two ports
  // Postconditions: Returns m_name;
  string UpdateName();
  // Name: GetSize()
  // Desc: Returns the number of ports in a route
  // Preconditions: Requires a Route
  // Postconditions: Returns m_size;
  int GetSize() { return m_size; }
  // Name: ReverseRoute
  // Desc: Reverses a route
  // Preconditions: Reverses the Route
  // Postconditions: Route is reversed in place; nothing returned
  void ReverseRoute()
  {
    Port *prev = NULL, *next = NULL, *current = m_head;
    while (current != NULL) // 1 2 3 4
    {
      next = current->GetNext(); // temp has 2
      current->SetNext(prev);    // current>next (1)->Null
      prev = current;
      current = next;
    }
    m_head = prev;
  }
  // Name: GetData (int)
  // Desc: Returns a port at a specific index
  // Preconditions: Requires a Route
  // Postconditions: Returns the port from specific item
  Port *GetData(int index)
  {
    Port *ptr;
    Port *Temp;
    Temp = m_head;

    int i = 0;
    while (i != index && Temp != 0)
    {
      Temp = Temp->GetNext();
      i++;
    }
    if (Temp != 0)
    {
      return Temp;
    }
    return 0;
  }
  // Name: DisplayRoute
  // Desc: Displays all of the ports in a route
  // Preconditions: Requires a Route
  // Postconditions: Displays all of the ports in a route
  // Formatted: Baltimore, Maryland (N39.209 W76.517)
  void DisplayRoute()
  {
    Port *temp = m_head;
    while (temp != 0)
    {
      cout << temp;
      temp = temp->GetNext();
    }
    cout << endl;
  }

private:
  string m_name; // Name of the Route
  Port *m_head;  // Front of the Route (Starting Point)
  Port *m_tail;  // End of the Route (Ending Point)
  int m_size;    // Total size of the Route
};

#endif
