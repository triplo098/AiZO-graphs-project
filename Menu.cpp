#include <chrono>
#include <stdio.h>
#include <iostream>

#include "Menu.h"
#include "FileReader.h"
#include "Algo.h"

using namespace std;

void Menu::callMenu()
{
    int choice;
    string fileName;

    Graph g;

    while (true)
    {
        cout << "\n1. Wczytaj dane z pliku" << endl;
        cout << "2. Wygeneruj graf losowo" << endl;
        cout << "3. Wyświetl graf listowo i macierzowo" << endl;
        cout << "4. Algorytm Prima" << endl;
        cout << "5. Algorytm Kruskala" << endl << endl;
        
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Podaj nazwe pliku: ";
            cin >> fileName;
            
            if(fileName.length() < 2) {
                fileName = "data_in/data1.txt";
            }

            FileReader fileReader;
            g = fileReader.readFile(fileName);

            break;
        case 2:
            break;
        case 3:

            g.print();
            break;

        case 4:

            Algo::Prim_MST(g.matrix , 0);


            break;
        }
    

    }
}


