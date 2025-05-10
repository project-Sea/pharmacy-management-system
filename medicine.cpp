#include <iostream>
#include "medicine.h"
std::vector<Medicine> inventory;
int main()
{
    int choice;

    do
    {
        std::cout << "\n=== Pharmacy Management System ===" << endl;
        std::cout << "1. Add New Medicine" << endl;
        std::cout << "2. Update Medicine Info" << endl;
        std::cout << "3. Display All Medicines" << endl;
        std::cout << "4. Exit" << endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

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
            std::cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
