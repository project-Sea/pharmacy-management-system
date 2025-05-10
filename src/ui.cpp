#include "../include/ui.h"

// You must declare these if they're defined elsewhere
void showInventoryMenu();
void showSalesMenu();

void showMainMenu()
{
    int choice;

    do
    {
        system("cls");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t" << std::setfill('=') << std::setw(43) << "=" << std::endl;
        std::cout << "\t\t\t\t|     PHARMACY MANAGEMENT SYSTEM      |\n";
        std::cout << "\t\t\t\t" << std::setfill('=') << std::setw(43) << "=" << std::endl;
        std::cout << "\t\t\t\t| 1. Medicine Inventory Management    |\n";
        std::cout << "\t\t\t\t| 2. Sales & Financial Management     |\n";
        std::cout << "\t\t\t\t| 3. Exit System                      |\n";
        std::cout << "\t\t\t\t" << std::setfill('=') << std::setw(43) << "=" << std::endl;
        std::cout << "\n\t\t\t\tEnter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            showInventoryMenu();
            break;
        case 2:
            showSalesMenu();
            break;
        case 3:
            system("cls");
            system("COLOR A");
            std::cout << "\n\n\n\t\t\t\tThank you for using the system!\n";
            std::cout << "\t\t\t\tGoodbye!\n";
            Sleep(1500);
            break;
        default:
            std::cout << "\n\t\t\t\tInvalid choice! Try again.\n";
            Sleep(1000);
        }
    } while (choice != 3);
}

void showWelcomeScreen()
{
    system("COLOR 7");

    std::cout << "\n\n\n";
    std::cout << "\t\t\t\t####################################\n";
    std::cout << "\t\t\t\t#                                  #\n";
    std::cout << "\t\t\t\t#         Welcome to the           #\n";
    std::cout << "\t\t\t\t#     Pharmacy Management System   #\n";
    std::cout << "\t\t\t\t#                                  #\n";
    std::cout << "\t\t\t\t####################################\n";
    std::cout << "\n\t\t\t\t### No Expired Drugs Detected ###\n";

    Sleep(2500);
    system("COLOR B");
}

void showStartupAnimation()
{
    int bar1 = 177, bar2 = 219;
    std::cout << "\n\n\n\t\t\t\tChecking Expiring Dates...";
    std::cout << "\n\n\n\t\t\t\tLoading...";
    std::cout << "\n\n\n\t\t\t\t";

    for (int i = 0; i < 30; i++)
        std::cout << (char)bar1;
    std::cout << "\r\t\t\t\t";

    for (int i = 0; i < 30; i++)
    {
        std::cout << (char)bar2;
        Sleep(30);
    }

    system("cls");
}
