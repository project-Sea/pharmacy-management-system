#include "../include/src.h"
#include "../include/ui.h"

void startProgram(MYSQL *conn)
{

    system("COLOR 7");
    showStartupAnimation();
    showWelcomeScreen();
    showMainMenu();
    // system("cls");
}

void loadingAnimation(const string &message)
{
    system("cls");
    cout << "\n\n\t\t\t\t" << message;
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(500); // Delay for 500 milliseconds
    }
    cout << endl;
}

void showInventoryMenu()
{
    int inventoryChoice;
    do
    {
        system("cls");
        cout << "\n\n";
        cout << "\t\t\t\t" << setfill('-') << setw(43) << "-" << endl;
        cout << "\t\t\t\t|     Medicine Inventory Management   |\n";
        cout << "\t\t\t\t" << setfill('-') << setw(43) << "-" << endl;
        cout << "\t\t\t\t| 1. Add New Medicine                 |\n";
        cout << "\t\t\t\t| 2. Update Medicine Details          |\n";
        cout << "\t\t\t\t| 3. Check Expiry Dates               |\n";
        cout << "\t\t\t\t| 4. Search Medicines                 |\n";
        cout << "\t\t\t\t| 5. Return to Main Menu              |\n";
        cout << "\t\t\t\t" << setfill('-') << setw(43) << "-" << endl;
        cout << "\n\t\t\t\tEnter your choice: ";
        cin >> inventoryChoice;

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
            cout << "\n\t\t\t\tInvalid choice! Try again.\n";
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
        cout << "\n\n";
        cout << "\t\t\t\t" << setfill('-') << setw(43) << "-" << endl;
        cout << "\t\t\t\t|     Sales & Financial Management    |\n";
        cout << "\t\t\t\t" << setfill('-') << setw(43) << "-" << endl;
        cout << "\t\t\t\t| 1. Process Sales Transaction        |\n";
        cout << "\t\t\t\t| 2. View Sales Reports               |\n";
        cout << "\t\t\t\t| 3. Return to Main Menu              |\n";
        cout << "\t\t\t\t" << setfill('-') << setw(43) << "-" << endl;
        cout << "\n\t\t\t\tEnter your choice: ";
        cin >> salesChoice;
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
            cout << "\n\t\t\t\tInvalid choice! Try again.\n";
            Sleep(1000);
        }
    } while (salesChoice != 3);
}

void addMedicine()
{
    loadingAnimation("Loading Add New Medicine Page");
    system("cls");
    cout << "\n\n\t\t\t\tAdd New Medicine";
    system("pause");
}

// void updateMedicine()
// {
//     loadingAnimation("Loading Update Medicine Details Page");
//     system("cls");
//     cout << "\n\n\t\t\t\tUpdate Medicine Details";
//     system("pause");
// }

// void checkExpiry()
// {
//     loadingAnimation("Loading Check Expiry Dates Page");
//     system("cls");
//     cout << "\n\n\t\t\t\tCheck Expiry Dates";
//     system("pause");
// }

// void searchMedicine()
// {
//     loadingAnimation("Loading Search Medicines Page");
//     system("cls");
//     cout << "\n\n\t\t\t\tSearch Medicines";
//     system("pause");
// }

// void processSale()
// {
//     loadingAnimation("Loading Process Sales Transaction Page");
//     system("cls");
//     cout << "\n\n\t\t\t\tProcess Sales Transaction";
//     system("pause");
// }

// void viewSalesReport()
// {
//     loadingAnimation("Loading View Sales Reports Page");
//     system("cls");
//     cout << "\n\n\t\t\t\tView Sales Reports";
//     system("pause");
// }