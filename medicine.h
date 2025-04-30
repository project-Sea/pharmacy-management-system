#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Medicine{
    int id,quantity;
    string name, expiryDate;
    double price;
};
vector <Medicine> inventory;
void loadingAnimationh(const string& message) {
    system("cls");
    cout << "\n\n\t\t\t\t" << message;
    for (int i = 0; i < 3; i++) {
        cout << ".";
        Sleep(500); // Delay for 500 milliseconds
    }
    cout << endl;
}
void addNewMedicine(){
    loadingAnimationh("Loading Add New Medicine Page");
    system("cls");
    cout << "\n\n\t\t\t\tAdd New Medicine: " << endl;
    Medicine m1;
    cout << "Enter the name of the Medicine: ";
    cin >> m1.name;
    cout << "Enter the ID of the Medicine: ";
    cin >> m1.id;
    cout << "Enter the quantity: ";
    cin >> m1.quantity;
    cout << "Enter the price: ";
    cin >> m1.price;
    cout << "Enter the expiry date of the medicine: ";
    cin >> m1.expiryDate;
    cout << "Medicine added successfully!"<< endl;
    cout << "ID: "<< m1.id << ", Name: " << m1.name << ", Quantity: " <<
          m1.quantity << ", Price: " << m1.price << ", Expiry Date: " <<
          m1.expiryDate << endl;
    inventory.push_back(m1);
    cout << endl;
}
void updateMedicineInfo(){
    cout << "Update Medicine Information: " << endl;
    int id, choice;
    string name;
    bool found = false;
    cout << "Find by: \n1. ID or \n2. Name?"<< endl;
    cin >> choice;
    if(choice == 1){
        cout << "Enter ID: ";
        cin >> id;
        for(int i=0; i<inventory.size(); ++i){
            Medicine& medicine = inventory[i];

            if(medicine.id == id){
                found = true;

                cout << "Medicine found!" << endl;

                while(true){
                    int num;
                    cout << "What do you want to change?" << endl;
                    cout << "1. Name\n2. Price\n3. Quantity\n4. Expiry Date\n5. Exit Editing" << endl;
                    cin >> num;
                    switch (num){
                        case 1:
                            cout << "Enter Name: ";
                            cin >> medicine.name;
                            break;
                        case 2:
                            cout << "Enter Price: ";
                            cin >> medicine.price;
                            break;
                        case 3:
                            cout << "Enter Quantity: ";
                            cin >> medicine.quantity;
                            break;
                        case 4:
                            cout << "Enter Expiry Date: ";
                            cin >> medicine.expiryDate;
                            break;
                        case 5:
                            return;
                        default:
                            cout << "Invalid choice!"<< endl;
                    }
                }
            }
            if(found){
                break;
            }
        }

    }else if (choice == 2){
        cout << "Enter Name: ";
        cin >>  name;
        for(int i=0; i<inventory.size(); ++i){
            Medicine& medicine = inventory[i];

            if(medicine.name == name){
                found = true;

                cout << "Medicine found!" << endl;

                while(true){
                    int num;
                    cout << "What do you want to change?" << endl;
                    cout << "1. ID\n2. Price\n3. Quantity\n4. Expiry Date\n5. Exit Editing" << endl;
                    cin >> num;
                    switch (num){
                        case 1:
                            cout << "Enter ID: ";
                            cin >> medicine.id;
                            break;
                        case 2:
                            cout << "Enter Price: ";
                            cin >> medicine.price;
                            break;
                        case 3:
                            cout << "Enter Quantity: ";
                            cin >> medicine.quantity;
                            break;
                        case 4:
                            cout << "Enter Expiry Date: ";
                            cin >> medicine.expiryDate;
                            break;
                        case 5:
                            return;
                        default:
                            cout << "Invalid choice!"<< endl;
                    }
                }
            }
            if(found){
                break;
            }
        }
    }else {
        cout << "You give invalid input!\n";
    }
    if(!found){
        cout << "Medicine not found in the inventory!" << endl;
    }

}
