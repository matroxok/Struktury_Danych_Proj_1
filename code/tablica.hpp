#ifndef tablica_dynamiczna
#define tablica_dynamiczna
#include <iostream>


//tablica dynamiczna
// - wskaźnik do tablicy, zdefiniowanie rozmairu tablicy, funkcja zmienienia rozmiaru tablicy
class TablicaDynamiczna {


private:
	int* data; //wskaźnik do tablicy
    int size;
	int capacity; //rozmiar tablicy
    void resize(); //zmiana rozmiaru tablicy

// - wywoałnie konstruktora, dekonstruktora
// - dodawanie na początek / koniec tablocy
// - dodawanie na wskazany indeks oraz usuwanie na wskazanym
// - usuwanie na poczatku / koncu
// - pokazanie tablicy i na wskazanym indeksie
// - szukanie wartości na tablicy 
public:
    TablicaDynamiczna(int n);
    ~TablicaDynamiczna(); 
    void addFirst(int value); 
    void addLast(int value); 
    void addAtIndex(int index, int value); 
    void deleteAtIndex(int index); 
    void deleteFirst(); 
    void deleteLast(); 
    void show(); 
    void search(int value); 
    void showAtIndex(int index); 

};
#endif
