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
    int choice;
    string fileName;

    Graph g;
    FileReader fileReader;
    MyTimer timer;

    // TEMP
    g = fileReader.readFile("data_in/data3.txt");

    while (true)
    {
        cout << "\n1. Wczytaj dane z pliku" << endl;
        cout << "2. Wygeneruj graf losowo" << endl;
        cout << "3. Wyświetl graf listowo i macierzowo" << endl;
        cout << "4. Algorytm Prima" << endl;
        cout << "5. Algorytm Kruskala" << endl << endl;
        cout << "6. Wyjdz" << endl;
        cout << "Wybierz opcje: ";
        // cin >> choice, cout << endl;
        choice = 4;
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

            exit(0);

            break;
        case 5:

            break;
        case 6:

            
            break;

        default:
            break;
        }


    }
}


