#include "tablica.hpp"
#include <iostream>

using namespace std;

//konstruktor
TablicaDynamiczna::TablicaDynamiczna(int n)
{
    data = new int[n];
    size = 0;
    capacity = n;
}

//destruktor:
// - zwalniamny pamięć oraz zmiana rozmairu tablocy
// - alokacja oraz podwojenie pamięci wymaganej 
// - kopiowanie, zwolnienie, dodanie, zmiana pamięci
// 
// 
TablicaDynamiczna::~TablicaDynamiczna()
{
    delete[] data;  
}
void TablicaDynamiczna::resize() { 
	int new_capacity = capacity * 2; 
	int* new_data = new int[new_capacity]; 
    std::copy(data, data + size, new_data); 
	delete[] data; 
	data = new_data; 
	capacity = new_capacity; 
}

// dodanie pamięci gdy tablica osiągnęła swój limit oraz przemieszanie elementów w prawo, ustawianie elementu na pierwszy
void TablicaDynamiczna::addFirst(int value)
{
    if (size == capacity)  
    {
        resize();
    }
    for (int i = size; i > 0; i--) 
    {
        data[i] = data[i - 1];
    }
    data[0] = value;  
    size++;
}

// dodawanie noiwych wartości oraz na sam koniec tablicy
void TablicaDynamiczna::addLast(int value) 
{
    if (size == capacity)
    {
        resize();
    }
    data[size] = value;  
    size++;
}

// sprawdzamy czy indeks jest w zakresie tablicy
void TablicaDynamiczna::addAtIndex(int index, int value)
{
    if (index < 0 || index > size)  
    {
        cout << "(!) Error: index out of range!" << endl;
        return;
    }
    if (size == capacity)
    {
        resize();
    }
    for (int i = size; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

// usuwamy wskaźnik z tablicy indeksu, przesuniecie elementów w lewo
void TablicaDynamiczna::deleteAtIndex(int index) 
{
    if (index < 0 || index >= size)
    {
        cout << "(!) Error: index out of range!" << endl;
        return;
    }
    for (int i = index; i < size - 1; i++)     
    {
        data[i] = data[i + 1];
    }
    size--;
}

//usuwanie z początku, if czy tablica nie jest pusta, przemieszenie elementów w lewo
void TablicaDynamiczna::deleteFirst()
{
    if (size == 0)      
    {
        cout << "(!) Error: no elements to delete" << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        data[i] = data[i + 1];     
    }
    size--;
}

//usuwanie z końca 
void TablicaDynamiczna::deleteLast() 
{
    if (size == 0)
    {
        cout << "(!) Error: no elements to delete" << endl;
        return;
    }
    size--;
}

// pokazanie tablicy
void TablicaDynamiczna::show() 
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "]" << "." << data[i] << " ";
    }
    cout << endl;
}

//szukanie wartości
void TablicaDynamiczna::search(int value) 
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == value)
        {
            return;
        }
    }
}

//pokazywanie indeksu elemntu wskazanego
void TablicaDynamiczna::showAtIndex(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "(!) Error: index out of range!" << endl;
        return;
    }
    cout << "Element on index: " << index << ": " << data[index] << endl;
}
