#include <chrono>
#include <stdio.h>
#include <iostream>

#include "Menu.h"
#include "FileReader.h"
#include "Algo.h"
#include "MyTimer.h"

using namespace std;

void Menu::callMenu()
{   
    int choice = 0;;
    string fileName;
    int v_num;
    int density;

    Graph g;
    Graph g1;
    FileReader fileReader;
    MyTimer timer;

    while (true)
    {
        cout << "\n1. Wczytaj dane z pliku" << endl;
        cout << "2. Wygeneruj graf losowo" << endl;
        cout << "3. Wyświetl graf listowo i macierzowo" << endl;
        cout << "4. Algorytm Prima" << endl;
        cout << "5. Algorytm Dijkstry" << endl;
        cout << "6. Wyjdz" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice, cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Podaj nazwe pliku: ";
            cin >> fileName;
            
            if(fileName.length() < 2) {
                fileName = "data_in/data2.txt";
            }

            g = fileReader.readFile(fileName);

            break;
        case 2:

            cout << "Podaj ilosc wierzcholkow: ";
            cin >> v_num;

            cout << "Podaj gestosc grafu (w %): ";
            cin >> density;

            g = Graph(v_num, density);

            // g.print();

            break;
        case 3:
            g.print();
            break;

        case 4:

            timer.startTimer();
            cout << "Macierz: " << endl;
            Algo::Prim_MST(g.matrix , 0);
            timer.stopTimer();
            timer.printTime();

            timer.startTimer();
            cout << "Lista: " << endl;
            Algo::Prim_MST(g.list, 0);
            timer.stopTimer();
            timer.printTime();


            break;

        case 5:
            timer.startTimer();
            cout << "Macierz: " << endl;
            Algo::Dijkstra(g.matrix , 0);
            timer.stopTimer();
            timer.printTime();

            timer.startTimer();
            cout << "Lista: " << endl;
            Algo::Dijkstra(g.list, 0);
            timer.stopTimer();
            timer.printTime();
            break; // Add break statement here

        case 6:
            exit(0);
            break;

        default:
            break;
        }


    }
}


