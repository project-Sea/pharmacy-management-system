#include <iostream>
#include "medicine.h"
vector<Medicine> inventory;
int main()
{
    int choice;

    do
    {
        cout << "\n=== Pharmacy Management System ===" << endl;
        cout << "1. Add New Medicine" << endl;
        cout << "2. Update Medicine Info" << endl;
        cout << "3. Display All Medicines" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addNewMedicine();
            break;
        case 2:
            updateMedicineInfo();
            break;
        case 3:
            displayAllMedicines();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
