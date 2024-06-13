#include <iostream>
#include <string>

#include "ScriptRunner.h"
#include "MyTimer.h"
#include "Graph.h"
#include "Algo.h"

#define PRIM 0
#define DJISKTRA 1
#define KRUSKAL 2
#define BELLMAN_FORD 3

#define MATRIX 0
#define LIST 1

using namespace std;

ScriptRunner::ScriptRunner(int argc, char *argv[])
{

    this->par = new int[argc - 1];

    for (int i = 0; i < argc - 1; i++)
    {
        this->par[i] = atoi(argv[i + 1]);

        // cout << "par[" << i << "] = " << par[i] << endl;
    }


}

void ScriptRunner::runScript()
{

    MyTimer timer;
    // cout << "b1" << endl;

    Graph g = Graph(par[2], par[3]);
    // cout << "b2" << endl;

    // g.print();


    for (int i = 0; i < par[4]; i++)
    {   

        if (par[0] == PRIM)
        {
            if (par[1] == MATRIX)
            {
                
                     timer.startTimer();
                Algo::Prim_MST(g.matrix, 0, false);
                timer.stopTimer();
            }
            else if (par[1] == LIST)
            {
                timer.startTimer();
                Algo::Prim_MST(g.list, 0, false);
                timer.stopTimer();
            }

            timer.sum += timer.duration;
        }
        else if (par[0] == DJISKTRA)
        {


            if (par[1] == MATRIX)
            {
                timer.startTimer();
                Algo::Dijkstra(g.matrix, 0, 1, false);
                timer.stopTimer();
            }
            else if (par[1] == LIST)
            {
                timer.startTimer();
                Algo::Dijkstra(g.list, 0, 1, false);
                timer.stopTimer();
            }

            timer.sum += timer.duration;
        }
        else if (par[0] == KRUSKAL)
        {
            if (par[1] == MATRIX)
            {
                timer.startTimer();
                Algo::Kruskal_MST(g.matrix, 0, false);
                timer.stopTimer();
            }
            else if (par[1] == LIST)
            {
                timer.startTimer();
                Algo::Kruskal_MST(g.list, 0, false);
                timer.stopTimer();
            }

            timer.sum += timer.duration;
        }
        
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << "par[" << i << "] = " << par[i] << endl;
    // }
    
    printf("czas: %.10g \n", (timer.sum / par[4]));
    return;
}
