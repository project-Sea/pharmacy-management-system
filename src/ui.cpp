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
            Sleep(100);
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
    if (false){
        system("COLOR A");
        std::cout << "\n\t\t\t\t### No Expired Drugs Detected ###\n";
    } 
    else
        system("COLOR 4");
        std::cout << "\n\t\t\t\t### ALERT!!! ###\n";
        std::cout << "\n\t\t\t\t### Expired Drugs Detected!!! ###\n";
    
    system("Pause");
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
        Sleep(100);
    }

    system("cls");
}

void loadingAnimation(const std::string &message)
{
    system("cls");
    std::cout << "\n\n\t\t\t\t" << message;
    for (int i = 0; i < 3; i++)
    {
        std::cout << ".";
        Sleep(300); // Delay for 500 milliseconds
    }
    std::cout << std::endl;
}

void showInventoryMenu()
{
    int inventoryChoice;
    do
    {
        system("cls");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t|     Medicine Inventory Management   |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t| 1. Add New Medicine                 |\n";
        std::cout << "\t\t\t\t| 2. Update Medicine Details          |\n";
        std::cout << "\t\t\t\t| 3. Check Expiry Dates               |\n";
        std::cout << "\t\t\t\t| 4. Search Medicines                 |\n";
        std::cout << "\t\t\t\t| 5. Return to Main Menu              |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\n\t\t\t\tEnter your choice: ";
        std::cin >> inventoryChoice;

        switch (inventoryChoice)
        {
        case 1:
            // addNewMedicine();
            break;
        case 2:
            // updateMedicineInfo();
            break;
        case 3:
            // checkExpiry();
            break;
        case 4:
            // searchMedicine();
            break;
        case 5:
            break;
        default:
            std::cout << "\n\t\t\t\tInvalid choice! Try again.\n";
            Sleep(1000);
        }
    } while (inventoryChoice != 5);
}

void showSalesMenu()
{
    int salesChoice;
    do
    {
        system("cls");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t|     Sales & Financial Management    |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t| 1. Process Sales Transaction        |\n";
        std::cout << "\t\t\t\t| 2. View Sales Reports               |\n";
        std::cout << "\t\t\t\t| 3. Return to Main Menu              |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\n\t\t\t\tEnter your choice: ";
        std::cin >> salesChoice;
        // C:\Users\HP\Documents\GitHub\Cpp resources and projects\fop_project
        switch (salesChoice)
        {
        case 1:
            // processSale();
            break;
        case 2:
            // viewSalesReport();
            break;
        case 3:
            break;
        default:
            std::cout << "\n\t\t\t\tInvalid choice! Try again.\n";
            Sleep(1000);
        }
    } while (salesChoice != 3);
}

void addMedicine()
{
    loadingAnimation("Loading Add New Medicine Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tAdd New Medicine";
    system("pause");
}

void updateMedicine()
{
    loadingAnimation("Loading Update Medicine Details Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tUpdate Medicine Details";
    system("pause");
}

void checkExpiry()
{
    loadingAnimation("Loading Check Expiry Dates Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tCheck Expiry Dates";
    system("pause");
}

void searchMedicine()
{
    loadingAnimation("Loading Search Medicines Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tSearch Medicines";
    system("pause");
}

void processSale()
{
    loadingAnimation("Loading Process Sales Transaction Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tProcess Sales Transaction";
    system("pause");
}

void viewSalesReport()
{
    loadingAnimation("Loading View Sales Reports Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tView Sales Reports";
    system("pause");
}