#include <iostream>
#include <chrono>
#include <fstream> 
#include "tablica.hpp"
#include "lista.hpp"

using namespace std;
using namespace std::chrono;

int main()
{
    ofstream outputFile("score.txt");
    if (!outputFile.is_open())
    {
        cerr << "(!) Error open file." << endl;
        return 1;
    }

    long long time = 0;
    int size = 1000000;  // elementy w liście
    TablicaDynamiczna Dynamic(size);  
    ListaWiazana Linked;            
    int rep = 100;  

    // zapełniamy listę
    for (int i = 0; i < size; i++) 
    { 
        Dynamic.addLast(i); 
        Linked.addLast(i);
    }
   

    // addFirst - ListaDynamiczna
    time = 0;
    cout << "(Healthy) Starting addFirst (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.addFirst(400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: addFirst " << time / rep << " n/s" << endl;
    cout << "[:)] Ended addFirst (Dynamiczna)" << endl;



    // addFirst - ListaWiazana
    time = 0;
    cout << "(Healthy) Starting addFirst (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.addFirst(400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Wiazana addFirst: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended addFirst (Wiazana)" << endl;



    // addLast - ListaDynamiczna
    time = 0;
    cout << "(Healthy) Starting addLast (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.addLast(400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Dynamiczna addLast: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended addLast (Dynamiczna)" << endl;



    // addLast - ListaWiazana
    time = 0;
    cout << "(Healthy) Starting: addLast (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.addLast(400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Wiazana addLast: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended addLast (Wiazana)" << endl;



    // addAtIndex - ListaDynamiczna
    time = 0;
    cout << "(Healthy) Starting: addAtIndex (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.addAtIndex(size / 2, 400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Dynamiczna addAtIndex: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended addAtIndex (Dynamiczna)" << endl;



    // addAtIndex - ListaWiazana
    time = 0;
    cout << "(Healthy) Starting: addAtIndex (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.addAtIndex(size / 2, 400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: addAtIndex: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended addAtIndex (Wiazana)" << endl;



    // deleteFirst - ListaDynamiczna
    time = 0;
    cout << "(Healthy) Starting: deleteFirst (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.deleteFirst();
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Dynamiczna deleteFirst: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended deleteFirst (Dynamiczna)" << endl;



    // deleteFirst - ListaWiazana
    time = 0;
    cout << "(Healthy) Starting: deleteFirst (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.deleteFirst();
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Wiazana deleteFirst: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended deleteFirst (Wiazana)" << endl;



    // deleteLast - ListaDynamiczna
    time = 0;
    cout << "(Healthy) Starting: deleteLast (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.deleteLast();
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Dynamiczna deleteLast: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended deleteLast (Dynamiczna)" << endl;



    // deleteLast - ListaWiazana
    time = 0;
    cout << "(Healthy) Starting: deleteLast (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.deleteLast();
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Wiazana deleteLast: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended deleteLast (Wiazana)" << endl;
    


    // deleteAtIndex - ListaDynamiczna
    time = 0;
    cout << "(Healthy) Starting: deleteAtIndex (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.deleteAtIndex(size / 2);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Dynamiczna deleteAtIndex: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended deleteAtIndex (Dynamiczna)" << endl;
    


    // deleteAtIndex - ListaWiazana
    time = 0;
    cout << "(Healthy) Starting: deleteAtIndex (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.deleteAtIndex(size / 2);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Wiazana deleteAtIndex: " << time / rep << " n/s" << endl;
    cout << "[:)] Ended deleteAtIndex (Wiazana)" << endl;



    // search - ListaDynamiczna
    time = 0;
    cout << "(Healthy) Starting: search dla liczby 90 (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.search(90);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Dynamiczna search (90): " << time / rep << " n/s" << endl;
    cout << "[:)] Ended search dla liczby 90 (Dynamiczna)" << endl;



    // search - ListaWiazana
    time = 0;
    cout << "(Healthy) Starting: search dla liczby 90 (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.search(90); // Poszukiwana wartość
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "(FINISH) Time: Wiazana search (90): " << time / rep << " n/s" << endl;
    cout << "[:)] Ended search dla liczby 90 (Wiazana)" << endl;


    return 0;
    outputFile.close(); // Zamknięcie pliku
}