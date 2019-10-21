#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

using namespace std;

template<typename O>
struct Node{
    O data;
    Node *next;
    Node( O data ) : data(data), next(0) {}
};

template <typename O>
class Container
{
private:

    Node<O>* head;      //PROCESSING - tracks beginning of linked list
    Node<O>* tail;      //PROCESSING - tracks end of linked list
    //helper function for sum()
    O addUp(Node<O> *node) const; // pointer to an O object
    //helper function for length()
    int count(Node<O> *node) const;  // pointer to an O object

public:
    /******************
     ** Nested Class **
     ******************/
    class Iterator   
    {
	private:
		Node<O> *current;
	public:
        /********************************
     	*** Constructor & Destructor ***
     	********************************/
    	Iterator();
    	Iterator(Node<O> *ptr);  // pointer to an O object

		/********************************
     	***** Overloaded Operators *****
     	********************************/
        O& operator*();
        Iterator operator++(int n);
        bool operator!=(const Iterator &right) const;
        bool operator==(const Iterator &right) const;
    };

    /********************************
     *** Constructor & Destructor ***
     ********************************/
    Container();
    ~Container();

    /*****************
     *** Accessors ***
     *****************/
    int length() const; // pointer to an O object
    O sum() const;      //Should make overloaded + operators for other classes
    void display() const;
    Iterator begin();
    Iterator end();
    O front() const;
    O back() const;

    /****************
     *** Mutators ***
     ****************/
    void push_front(O value);	//IN - value to add to front of list
    void push_back(O value);	//IN - value to add to back of list
    void pop_front();
    void select_sort();

    /********************************
     ***** Overloaded Operators *****
     ********************************/
    Container & operator=( const Container<O> &list ); // pointer to an Container object
    template<typename U>
    friend ostream& operator<<(ostream& os, const Container<U>& paramCont);
};
/*********************************************************
 * class Container
 * This class represents a list of O objects. It is
 * a linked list and therefore all members of the Container
 * are dynamically allocated variables. This class manages
 * 2 attributes head and tail.
 * head - the memory address of the O struct at the
 * beginning of the linked list
 * tail - the memory address of the O struct at the
 * end of the linked list.
 *********************************************************/

/********************************
 *** Constructor & Destructor ***
 ********************************/

/**************************************************************************
* Container() :
* default constructor:
*__________________________________________________________________________
* Constructs a Container object with attributes:
* head = NULL
* tail = NULL
*__________________________________________________________________________
* PRO-CONDITIONS:
*   NONE
* POST-CONDITIONS:
*   Attributes of the Container object are initialized accordingly.
**************************************************************************/
template<typename O>
Container<O>::Container()
{
    head = NULL;
    tail = NULL;
}

/**************************************************************************
* Destructor ~Container
*__________________________________________________________________________
* Deallocates all memory in the Container object by deallocating each O
* object in the Container.
*__________________________________________________________________________
* PRO-CONDITIONS:
*   The Container object must have values intialized for the linked list
* attributes head and tail, O objects.
* POST-CONDITIONS:
*   All O objects are deallocated from the Container object.
**************************************************************************/
template <typename O>
Container<O>::~Container()
{
    cout << "\n======CONTAINER DESTRUCTOR CALL=======" << endl;
    Node<O>* current = head;
    Node<O>* upComing;
    while(current != NULL){
        upComing = current->next;
        delete current;
        current = upComing;
    }
    head = NULL;
    tail = NULL;
    cout << "======CONTAINER DESTROYED SUCCESSFULLY=======" << endl;
}

/*****************
 *** Accessors ***
 *****************/
/**************************************************************************
* Accessor: Display
*__________________________________________________________________________
* Prints all the data within the container
*__________________________________________________________________________
* PRO-CONDITIONS:
*   The Container object must have values intialized for the linked list
* attributes head and tail, O objects.
* POST-CONDITIONS:
*   All O objects are printed to the screen
**************************************************************************/
template <typename O>
void Container<O>::display() const
{
    Node<O>* current;
    current = head;

    while(current)
    {
        cout << current->data;
        if(head != tail && current->next)
            cout << " ";
        current = current->next;
    }
}

/**************************************************************************
* Accessor: begin()
*__________________________________________________________________________
* Returns a head pointer
*__________________________________________________________________________
* PRO-CONDITIONS:
*   The Container object must have values intialized for the linked list
* attributes head and tail, O objects.
* POST-CONDITIONS:
*   Returns a pointer that points to head
**************************************************************************/
template <typename O>
typename Container<O>::Iterator Container<O>::begin()
{
    return Iterator(head);
}


template <typename O>
typename Container<O>::Iterator Container<O>::end()
{
    return Iterator(tail);
}

template <typename O>
O Container<O>::front() const
{
    if(head)
        return head -> data;
    return NULL;
}

template <typename O>
O Container<O>::back() const
{
    if(tail)
        return tail -> data;
    return NULL;
}

template <typename O>
int Container<O>::count(Node<O> *node) const  // pointer to an O object
{
    if(node != NULL)
        return 1 + count(node->next);
    else
        return 0;
}

template <typename O>
int Container<O>::length() const
{
    return count(this->head);
}

/************************************************************
 * ACCESSOR: sum(Node<O>* node)
 ************************************************************
 * This function will recursively add and return the sum of
 * all objects that are in the Container class. What that return
 * number is will depend upon the programmer to overload the
 * + operator for each class being stored within this
 * Container object. This function has an 'O' object  return type as of
 * right now but should later be modified to return a double.
 ************************************************************
 * PRE-CONDITIONS:
 *  NONE
 * POST-CONDITIONS:
 *  Every object in this Container class is summed and the
 *  total is returned.
 ***********************************************************/
template<typename O>
O Container<O>::addUp(Node<O> *node) const 
{
    if(node != tail)
        return node->data + addUp(node->next);
    else
        return node->data;
}

template<typename O>
O Container<O>::sum() const
{
    return addUp(this->head);
}

/****************
 *** Mutators ***
 ****************/

template <typename O>
void Container<O>::push_front(O value) //IN - value to add to front of list
{
    Node<O>* current;
    Node<O>* newNode;

    //Both set to the first node added
    newNode = new Node<O>(value);
    if(!head && !tail)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    current = head;
    head = newNode;
    head->next = current;
}

template <typename O>
void Container<O>::push_back(O value)      //IN - value to add to back of list
{
    Node<O>* current;
    Node<O>* newNode;

    //Both set to the first node added
    newNode = new Node<O>(value);
    newNode->next = NULL;
    if(!head && !tail)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    current = tail;
    tail = newNode;
    current->next = tail;
}

template <typename O>
void Container<O>::pop_front()
{
    if(!head && !tail)
        return;

    Node<O>* current;
    current = head->next;
    delete head;
    head = current;
}

/**************************************************************************
* Mutator method select_sort() : class Container
*__________________________________________________________________________
* Sorts the linked list into ascending order.
*__________________________________________________________________________
* PRO-CONDITIONS:
*   The Container object must have values intialized for the linked list
* attributes head and tail, O objects.
* POST-CONDITIONS:
*   The Container is arranged from least to greatest.
**************************************************************************/
template <typename O>
void Container<O>::select_sort()
{
    Node<O>* current;
    Node<O>* min;
    O old;
    bool restart;

    restart = false;
    current = head;
    min = current->next;

    while(current)
    {
        while(min)
        {
            if(min->data < current->data)
            {
                old = current->data;
                current->data = min->data;
                min->data = old;
                current = head;
                min = current->next;
                restart = true;
                break;
            }
            min = min->next;
            restart = false;
        }
        if(!restart)
        {
            current = current->next;
            if(current)
                min = current->next;
        }
    }
}

/**************************************************************************
* Overloaded assignment operator =(const Container &list) : class Container
*__________________________________________________________________________
* Deallocates memory from the calling Container object to assignd a deep
* copy of the Container object passed as a parameter.
*__________________________________________________________________________
* PRO-CONDITIONS:
*   The Container object parameter must have values intialized for the linked
* list attributes head and tail, O objects.
* POST-CONDITIONS:
*   The contents of the Container parameter are assigned to the calling
* Container object
**************************************************************************/
template <typename O>
Container<O>& Container<O>::operator=(const Container<O> &list)  // pointer to an Container object
{
    cout << "Overloaded Assignment Operator Called\n";
    Node<O> *current;
    Node<O> *nextNode;

    //Deallocate the memory for all elements of the current Container
    current = head;
    while(current)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = NULL;
    tail = NULL;

    //Copy all elements from Intlist parameter to current Intlist
    current = list.head;
    while(current)
    {
        push_back(current->data);
        current = current->next;
    }
    return *this;
}

/**********/
//ITERATOR//
/**********/

/**************************************************************************
* Default constructor Iterator(): Class Iterator
*__________________________________________________________________________
* Default constructor for the class, setting current to null.
*__________________________________________________________________________
* PRO-CONDITIONS
*   NONO
* POST-CONDITIONS
*   A new object.
**************************************************************************/
template <typename O>
Container<O>::Iterator::Iterator()
{
    current = nullptr;
}

/**************************************************************************
* Constructor Iterator(): Class Iterator
*__________________________________________________________________________
* Constructor for the class, setting current to ptr.
*__________________________________________________________________________
* PRO-CONDITIONS
*   NONO
* POST-CONDITIONS
*   A new object.
**************************************************************************/
template <typename O>
Container<O>::Iterator::Iterator(Node<O> *ptr) //pointer to an O object
{
    current = ptr;
}

/**************************************************************************
* Accessor operator*(): Class Iterator
*__________________________________________________________________________
* Dereferences the node data.
*__________________________________________________________________________
* PRO-CONDITIONS
*   NONO
* POST-CONDITIONS
*   Returns the data in node.
**************************************************************************/
template <typename O>
O& Container<O>::Iterator::operator*()
{
    return current->data;
}

/**************************************************************************
* Mutator operator++: Class Iterator
*__________________________________________________________________________
* Returns an Iterator object pointing to the node next to the
* current node that the calling IntlistIterator is pointing to.
*__________________________________________________________________________
* PRO-CONDITIONS
*   NONO
* POST-CONDITIONS
*   An Iterator object is returned pointing to the neighbouring node.
**************************************************************************/
template<typename O>
typename Container<O>::Iterator Container<O>::Iterator::operator++(int n)
{
    current = current->next;
    return Iterator(current);
}

template<typename O>
ostream& operator<<(ostream& os, const Container<O>& paramCont)
{
    Node<O>* current;
    current = paramCont.head;

    while(current)
    {
        os << current->data;
        if(paramCont.head != paramCont.tail && current->next)
            os << " ";
        current = current->next;
    }
    return os;
}
template<typename O>
bool Container<O>::Iterator::operator ==(const Iterator& right) const
{
    return(current==right.current);
}

template<typename O>
bool Container<O>::Iterator::operator !=(const Iterator& right) const
{
    return(current!=right.current);
}
#endif // CONTAINER_H

