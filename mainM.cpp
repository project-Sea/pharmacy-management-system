#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void showInventoryMenu();
void showSalesMenu();
void addMedicine();
void updateMedicine();
void checkExpiry();
void searchMedicine();
void processSale();
void viewSalesReport();
void loadingAnimation(const string& message);

int main()
{
    system("COLOR 7");
    system("cls");

    system("COLOR 6");
    system("cls");

    int bar1 = 177, bar2 = 219;
    cout << "\n\n\n\t\t\t\tChecking Expiring Dates...";
    cout << "\n\n\n\t\t\t\tLoading...";
    cout << "\n\n\n\t\t\t\t";
    for (int i = 0; i < 30; i++) {
        cout << (char)bar1;
    }
    cout << "\r";
    cout << "\t\t\t\t";
    for (int i = 0; i < 30; i++) {
        cout << (char)bar2;
        Sleep(30);
    }

    system("cls");
    system("COLOR 7");

    cout << "\n\n\n";
    cout << "\t\t\t\t####################################\n";
    cout << "\t\t\t\t#                                  #\n";
    cout << "\t\t\t\t#         Welcome to the           #\n";
    cout << "\t\t\t\t#     Pharmacy Management System   #\n";
    cout << "\t\t\t\t#                                  #\n";
    cout << "\t\t\t\t####################################\n";
    cout << "\n\t\t\t\t### No Expired Drugs Detected ###\n";

    Sleep(2500);

    system("COLOR B");

    int choice;

    do {
        system("cls");
        cout << "\n\n";
        cout << "\t\t\t\t" << setfill('=') << setw(43) << "=" << endl;
        cout << "\t\t\t\t|     PHARMACY MANAGEMENT SYSTEM      |\n";
        cout << "\t\t\t\t" << setfill('=') << setw(43) << "=" << endl;
        cout << "\t\t\t\t| 1. Medicine Inventory Management    |\n";
        cout << "\t\t\t\t| 2. Sales & Financial Management      |\n";
        cout << "\t\t\t\t| 3. Exit System                       |\n";
        cout << "\t\t\t\t" << setfill('=') << setw(43) << "=" << endl;
        cout << "\n\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                showInventoryMenu();
                break;
            case 2:
                showSalesMenu();
                break;
            case 3:
                system("cls");
                system("COLOR A");
                cout << "\n\n\n\t\t\t\tThank you for using the system!\n";
                cout << "\t\t\t\tGoodbye!\n";
                Sleep(1500);
                break;
            default:
                cout << "\n\t\t\t\tInvalid choice! Try again.\n";
                Sleep(1000);
        }
    } while(choice != 3);

    return 0;
}

void loadingAnimation(const string& message) {
    system("cls");
    cout << "\n\n\t\t\t\t" << message;
    for (int i = 0; i < 3; i++) {
        cout << ".";
        Sleep(500); // Delay for 500 milliseconds
    }
    cout << endl;
}

void showInventoryMenu() {
    int inventoryChoice;
    do {
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

        switch(inventoryChoice) {
            case 1: addMedicine(); break;
            case 2: updateMedicine(); break;
            case 3: checkExpiry(); break;
            case 4: searchMedicine(); break;
            case 5: break;
            default:
                cout << "\n\t\t\t\tInvalid choice! Try again.\n";
                Sleep(1000);
        }
    } while(inventoryChoice != 5);
}

void showSalesMenu() {
    int salesChoice;
    do {
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

        switch(salesChoice) {
            case 1: processSale(); break;
            case 2: viewSalesReport(); break;
            case 3: break;
            default:
                cout << "\n\t\t\t\tInvalid choice! Try again.\n";
                Sleep(1000);
        }
    } while(salesChoice != 3);
}

void addMedicine() {
    loadingAnimation("Loading Add New Medicine Page");
    system("cls");
    cout << "\n\n\t\t\t\tAdd New Medicine";
    system("pause");
}

void updateMedicine() {
    loadingAnimation("Loading Update Medicine Details Page");
    system("cls");
    cout << "\n\n\t\t\t\tUpdate Medicine Details";
    system("pause");
}

void checkExpiry() {
    loadingAnimation("Loading Check Expiry Dates Page");
    system("cls");
    cout << "\n\n\t\t\t\tCheck Expiry Dates";
    system("pause");
}

void searchMedicine() {
    loadingAnimation("Loading Search Medicines Page");
    system("cls");
    cout << "\n\n\t\t\t\tSearch Medicines";
    system("pause");
}

void processSale() {
    loadingAnimation("Loading Process Sales Transaction Page");
    system("cls");
    cout << "\n\n\t\t\t\tProcess Sales Transaction";
    system("pause");
}

void viewSalesReport() {
    loadingAnimation("Loading View Sales Reports Page");
    system("cls");
    cout << "\n\n\t\t\t\tView Sales Reports";
    system("pause");
}