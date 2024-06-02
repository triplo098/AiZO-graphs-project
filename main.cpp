#include "Menu.h"
#include "ScriptRunner.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // Zależnie od ilości argumentów wywołuje menu lub skrypt
    if (argc == 1)
    {
        Menu menu;
        menu.callMenu();
    }
    else if (argc == 2)
    {
        ScriptRunner scriptRunner;
        scriptRunner.runScript();
    }
    else
    {
        cout << "Wrong number of arguments" << endl;
        return 1;
    }

    return 0;
}