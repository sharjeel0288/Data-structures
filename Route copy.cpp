#include "Port.h"
#include "Route.h"
#include "Navigator.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Default Constructor
Route::Route(){
    m_head = nullptr; 
	m_tail = nullptr; 
	m_size = 0; 
}

// Name: SetName(string)
// Desc: Sets the name of the route (usually first port to last port)
// Preconditions: None
// Postconditions: Sets name of route
void Route::SetName(string name){
    m_name = name;
}
// Name: ~Route() - Destructor
// Desc: Used to destruct a strand of Route
// Preconditions: There is an existing Route strand with at least one port
// Postconditions: Route is deallocated (including all dynamically allocated ports)
//                 to have no memory leaks!
Route::~Route(){}
// Name: InsertEnd (string, string, double, double)
// Desc: Creates a new port using the data passed to it.
//       Inserts the new port at the end of the route
// Preconditions: Takes in a Port
//                Requires a Route
// Postconditions: Adds the new port to the end of a route
void Route::InsertEnd(string name, string location, double north, double west){
    Port *temp = new Port(); 

    temp->GetName() = name;
    temp->GetLocation() = location;
    north = temp->GetNorth();
    west = temp->GetWest();
    if(m_head == nullptr){
        m_head = temp;
        m_tail = temp;
    }
    else{
        Port *curr = m_head;
        while(curr -> GetNext() != m_tail){
            curr = curr -> GetNext();
        }
        temp->SetNext(curr);

    }
}
// Name: RemovePort(int index)
// Desc: Removes a port from the route at the index provided
//       Hint: Special cases (first port, last port, middle port)
// Preconditions: Index must be less than the size of the route
//       Cannot make route less than two ports. If the route has
//       two or fewer ports, fails.
// Postconditions: Name may be updated. Size is reduced. Route has one less port.
void Route::RemovePort(int index){
    Port *curr = m_head;

    if(m_size == 0){
        return;
    }
    else if (m_size == 1){
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_size --;
        
    }
    else{
        while(curr -> GetNext() != m_tail){
            curr = curr->GetNext();
        }
        delete curr -> GetNext();
        m_tail = curr;
        m_tail -> SetNext(nullptr);
        m_size --;
    }

}
// Name: GetSize()
// Desc: Returns the number of ports in a route
// Preconditions: Requires a Route
// Postconditions: Returns m_size;
int Route::GetSize(){
    return m_size;
}
// Name: ReverseRoute
// Desc: Reverses a route
// Preconditions: Reverses the Route
// Postconditions: Route is reversed in place; nothing returned
void Route::ReverseRoute(){
    Port *ptr1, *ptr2, *ptr3 = new Port();

    if (m_head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (m_head->GetNext() == NULL)
    {
        return;
    }  
    ptr1 = m_head;
    ptr2 = ptr1->GetNext();
    ptr3 = ptr2->GetNext();
    ptr1->SetNext(nullptr);
    ptr2->SetNext(ptr1);
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->GetNext();
        ptr2->SetNext(ptr1);         
    }
    m_head = ptr2;

}
// Name: GetData (int)
// Desc: Returns a port at a specific index
// Preconditions: Requires a Route
// Postconditions: Returns the port from specific item
Port* Route::GetData(int index){

    // ostream &operator<< (ostream &output, Port &myPort) 
    // {
    //     output << myPort.m_name << ", " << myPort.m_location;
    // return output;
    // }
    
    // Port *current = m_head;
    // // the index of the
    // // node we're currently
    // // looking at
    // int count = 0;
    // while (current != NULL) {
    //     if (count == index)
    //         return current->GetName();
    //     count++;
    //     current = current->GetNext();
    // }


    // //Used to keep track of the Node Index
	// Port *temp = m_head;
	// //LinkedList traversal for finding the node
	// while(temp!=NULL){
	// 	if(temp->data == data){         
	// 		//If element found return index
	// 		return index;               
	// 	}
	// 	temp = temp->next;
	// 	index++;
	// }   
	// //If element not found
	// return -1; 
    
}
// Name: DisplayRoute
// Desc: Displays all of the ports in a route
// Preconditions: Requires a Route
// Postconditions: Displays all of the ports in a route
// Formatted: Baltimore, Maryland (N39.209 W76.517)
void Route::DisplayRoute(){

    // Port *tPtr;

    // for (int i = 0; i < 36; i++ )
    // if ( m_tracks[i] == tPtr && tPtr->isValid() ) {
    //   cout << "Train #" << tPtr->getNumber() << " is departing." << endl;
    //   removeTrain( tPtr );
    //   return true;
    // }
    // // If train tPtr not on a track, return false
    // return false;
    
    // int choice, count = 0;
    // cout << "Which route would you like to use?" << endl;

    // cin >> choice;

    // Port *curr = m_head;

    // for(curr = m_head; curr != nullptr; curr->GetNext()){
    //     count++;
    //     cout << count << ". " << GetData(choice) << endl;
    // }

}