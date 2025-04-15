#ifndef lista_wiazana
#define lista_wiazana
#include <iostream>

// tutaj wprowadzamy strukturę elementu, gdzie defininiujemy:
// - wartość
// wskaźnik
// wywołujemy konstruktor

struct Node { 
    int data; 
    Node* next; 
    Node(int value);  
};

// tutaj lista jednokierunkowa
class ListaWiazana 
{

private:
    Node* head; //wskaźnik - pierwszy element
    Node* tail; //wskaźnik - ostatni element
	int count; 

// Tutaj mamy idać od góry:
// wywoałnie konstruktora oraz destruktora
// sprawdzenie zawartości elementów w liście
// dodawanie na początku i na końcu
// dodawanie elementu na wskazane miejsce (indeks), usuwanie
// usuwanie elementu z początku oraz z końca
// pokazanie tablicy oraz funckaja szukajca
public:
   ListaWiazana(); 
    ~ListaWiazana(); 
    bool isEmpty(); 
    void addFirst(int value); 
    void addLast(int value); 
    void addAtIndex(int index, int value); 
    void deleteAtIndex(int index); 
    void deleteFirst(); 
    void deleteLast(); 
    void show(); 
    void search(int value); 
};

#endif
