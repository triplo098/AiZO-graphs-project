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
    int choice = 0;
    int choice2 = 0;
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
        cout << "4. Algorytm Prima lub Kruskala" << endl;
        cout << "5. Algorytm Dijkstry lub Bellmana-Forda" << endl;
        cout << "6. Wyjdz" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice, cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Podaj nazwe pliku: ";
            cin >> fileName;

            if (fileName.length() < 2)
            {
                fileName = "data2.txt";
                // fileName = "data5.txt";
            }

            g = fileReader.readFile(fileName);

            break;
        case 2:

            cout << "Podaj ilosc wierzcholkow: ";
            cin >> v_num;

            cout << "Podaj gestosc grafu (w %): ";
            cin >> density;

            g.matrix.arrange_with_zeros();

            g1 = Graph(v_num, density);
            g1.print();

            g = g1;

            // g.print();

            break;
        case 3:
            g.print();
            break;

        case 4:
            cout << "Wybierz algorytm: " << endl;
            cout << "1. Algorytm Prima" << endl;
            cout << "2. Algorytm Kruskala" << endl;

            cin >> choice2;

            if (choice2 == 1)
            {

                cout << "Algorytm Prima" << endl;

                timer.startTimer();
                cout << "Macierz: " << endl;
                Algo::Prim_MST(g.matrix, 0);
                timer.stopTimer();
                timer.printTime();

                timer.startTimer();
                cout << "Lista: " << endl;
                Algo::Prim_MST(g.list, 0);
                timer.stopTimer();
                timer.printTime();
            }
            else if (choice2 == 2)
            {
                cout << "Algorytm Kruskala" << endl;
                
                timer.startTimer();
                cout << "Macierz: " << endl;
                Algo::Kruskal_MST(g.matrix, 0);
                timer.stopTimer();
                timer.printTime();

                timer.startTimer();
                cout << "Lista: " << endl;
                Algo::Kruskal_MST(g.list, 0);
                timer.stopTimer();
                timer.printTime();
            }

            break;
        case 5:



            cout << "Podaj wierzcholek startowy: ";
            int start;
            cin >> start;
            cout << "Podaj wierzcholek koncowy: ";
            int end;
            cin >> end;

            cout << "Wybierz algorytm: " << endl;
            cout << "1. Algorytm Dijkstry" << endl;
            cout << "2. Algorytm Bellmana-Forda" << endl;

            cin >> choice2;

            if (choice2 == 1)
            {
                cout << "Algorytm Dijkstry" << endl;

                timer.startTimer();
                cout << "Macierz: " << endl;
                Algo::Dijkstra(g.matrix, start, end);
                timer.stopTimer();
                timer.printTime();

                timer.startTimer();
                cout << "Lista: " << endl;
                Algo::Dijkstra(g.list, start, end);
                timer.stopTimer();
                timer.printTime();
            }
            else if (choice2 == 2)
            {
                cout << "Algorytm Bellmana-Forda" << endl;

                timer.startTimer();
                cout << "Macierz: " << endl;
                Algo::Bellman_Ford(g.matrix, start, end);
                timer.stopTimer();
                timer.printTime();

                timer.startTimer();
                cout << "Lista: " << endl;
                Algo::Bellman_Ford(g.list, start, end);
                timer.stopTimer();
                timer.printTime();

            }
            break;
        case 6:
            exit(0);
            break;

        default:
            break;
        }
    }
}
