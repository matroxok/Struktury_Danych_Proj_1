#include <iostream>
#include "lista.hpp"
using namespace std;

// konstruktor węzła, ustwianie wartości, przekazanie wskażnika dalej
Node::Node(int value)
{
	data = value; 
	next = nullptr; 
}

// konstruktor listy
ListaWiazana::ListaWiazana() 
{
    head = nullptr;  
}

// destruktor listy, wskazanie aktualnego elementu / nastepnego, usunięcie, przejście
ListaWiazana::~ListaWiazana()
{
    Node* current = head;  
    Node* nextNode;     
    while (current != nullptr) 
    {
		nextNode = current->next; 
		delete current;  
		current = nextNode;  
    }

    // ustawienia wskaźników
	head = nullptr;      
	tail = nullptr;   
}

// sprawdzamy status listy - (pusta / nie pusta)
bool ListaWiazana::isEmpty() 
{
	return head == nullptr; 
    // wskaźnik = nullp tr
}

// dodawanie na początek
void ListaWiazana::addFirst(int value) 
{   
    
    if (isEmpty())
    {
		head = new Node(value); 
        tail = head;
    }
    else
    {
		Node* newNode = new Node(value); 
		newNode->next = head; 
		head = newNode; 
    }  
	count++;
}

// dodawanie na koniec
void ListaWiazana::addLast(int value) 
{
    if(isEmpty())
    {
        head = new Node(value);   
        tail = head; 
    }
    else
    {
		Node* newNode = new Node(value); 
        tail->next = newNode; 
        tail = newNode; 
    }
    count ++;
}

// dodawanie na wskazany indeks
void ListaWiazana::addAtIndex(int index, int value)
{
        if (index < 0 || index > count) 
        {
            cout << "(!) Error: index out of range!" << endl;
            return;
        }
		if (index == 0) 
        {
            addFirst(value);     
            return;
        }
		if (index == count) 
        {
            addLast(value);     
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head; 
		for (int i = 0; i < index - 1; i++) 
        {
            current = current->next;
        }
		newNode->next = current->next; 
		current->next = newNode; 
        count++; 
}

// usuwanie z wskazanego indeksu
void ListaWiazana::deleteAtIndex(int index) 
{
	if (index < 0 || index >= count) 
    {
        cout << "(!) Error: index out of range!" << endl;
        return;
    }
    if(index == 0) 
    {
        deleteFirst(); 
        return;
    }
	if (index == count - 1) 
    {
        deleteLast(); 
        return;
    }
    Node* current = head;
	for (int i = 0; i < index - 1; i++) 
    {
        current = current->next;
    }
    Node* Delete = current->next; 
    current->next = Delete->next; 
    delete Delete; 
}

// usuwanie z początku
void ListaWiazana::deleteFirst() 
{
	if (isEmpty())
    {
        cout << "(!) Error: index is 0." << endl;
        return;
    }
    Node* current = head; 
    head = head->next;
    delete current; 
    count--;
    if (head == nullptr)    
    { 
        tail = nullptr;
    }
}

// usuwanie z konca listy
void ListaWiazana::deleteLast() 
{
    if (isEmpty()) 
    {
        cout << "(!) Error: List is empty." << endl;
        return;
    }
    if (head == tail) 
     { 
        delete head;
        head = nullptr;
        tail = nullptr;
    } 
    else 
    {
        Node* current = head;
        while (current->next != tail) 
         { 
            current = current->next;
        }
        delete tail; 
        tail = current; 
        tail->next = nullptr; 
    }
    count--;
}

// pokazujemy listę oraz idziemy do końca listy
void ListaWiazana::show() 
{
    if (isEmpty()) 
    {
        cout << "(!) Error: List is empty." << endl;
        return;
    }
    Node* current = head; 
    int index = 0; 
	while (current != nullptr)  
    { 
        cout << "[" << index << "] " << current->data << " "; 
        current = current->next;
        index++;
    }
    cout << endl; 
}

// szukamy wartości
void ListaWiazana::search(int value) 
{
    if (isEmpty()) 
    {
        cout << "(!) Error: List is empty." << endl;
        return;
    }
    Node* current = head;
    int index = 0; 
    while (current != nullptr) 
     { 
        if (current->data == value)    
        {
            return;
        }
        current = current->next; 
        index++;
    }

}
