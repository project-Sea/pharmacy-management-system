#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int main()
{
    system("COLOR 6");
    system("cls");
    // SetConsoleCP(437);
    // SetConsoleOutputCP(437);

    int bar1 = 177, bar2 = 219;
    cout << "\n\n\n\t\t\t\tChecking Expiring Dates";
    cout << "\n\n\n\t\t\t\tLoading...";
    cout << "\n\n\n\t\t\t\t";
    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar1;
    }
    cout << "\r";
    cout << "\t\t\t\t";
    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar2;
        Sleep(120);
    }
    system("cls");
    system("COLOR A");
    cout << '\t' << endl;
    cout << '\t' << endl;
    cout << "\t\t\t\t" << "######## Welcome ########" << endl;
    cout << '\t' << endl;
    cout << "\t\t\t\t" << "### No Expired Drugs ####" << endl;

    return 0;
}
