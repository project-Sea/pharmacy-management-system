#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>


using namespace std;

class Medicine{
    private:
        int id,quantity;
        string name, expiryDate, category;
        double price;
    public:
        void inputDetails(){
            cout << "Enter the name of the Medicine: ";
            getline(cin >> ws, name);
            cout << "Enter the ID of the Medicine: ";
            cin >> id;
            cout << "Enter the category of the Medicine: ";
            getline(cin >> ws, category);
            cout << "Enter the quantity: ";
            cin >> quantity;
            cout << "Enter the price: ";
            cin >> price;
            cout << "Enter the expiry date of the medicine: ";
            getline(cin >> ws, expiryDate);
            
        }

        void display(){
            cout << "ID: "<< id << ", Name: " << name 
            << ", Category: " <<category << ", Quantity: " << quantity 
            << ", Price: " << price << ", Expiry Date: " << expiryDate << endl;
        }

        int getId() const {return id;}
        string getName() const {return name;}
        void setId(int i){ id = i;}
        void setName(string n) {name = n;}
        void setPrice(double p) { price = p;}
        void setQuantity(int q) { quantity =q;}
        void setExpiry(string e) { expiryDate = e;}
        void setCategory(string c) {category = c;}
        
};
extern vector <Medicine> inventory;
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
    m1.inputDetails();
    cout << "Medicine added successfully!"<< endl;
    m1.display();
    inventory.push_back(m1);
    cout << endl;
}
void editMedicine(Medicine& med){
    int num;
    do{
        cout << "\nWhat do you want to update?" << endl;
        cout << "1. Name\n2. ID\n3. Category\n4. Price\n5. Quantity\n6. Expiry Date\n7. Exit editing\nChoice: ";
        cin >> num;
        switch (num) {
            case 1: {
                string name;
                cout << "New Name: ";
                getline(cin >> ws, name);
                med.setName(name);
                break;}
            case 2: {
                int id;
                cout << "New ID: ";
                cin >> id;
                med.setId(id);
                break;}
            case 3:{
                string category;
                cout << "New Category: ";
                getline(cin >> ws, category);
                med.setCategory(category);
                break;}
            case 4:{
                double price;
                cout << "New Price: ";
                cin >> price;
                med.setPrice(price);
                break;}
            case 5:{
                int qt;
                cout << "New Quantity: ";
                cin >> qt;
                med.setQuantity(qt);
                break;}
            case 6:{
                string expiry;
                cout << "New Expiry Date: ";
                getline(cin >> ws, expiry);
                med.setExpiry(expiry);
                break;}
            case 7:
                cout << "Finished editing." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }while (num !=7);
}
void updateMedicineInfo(){
    cout << "Update Medicine Information: " << endl;
    int edit_choice;
    cout << "Edit By:\n1. Name or\n2. ID?\n3. Return\nChoice: ";
    cin >> edit_choice;

    bool found = false;

    if(edit_choice == 1){
        string name;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        for(int i=0;i<inventory.size();++i){
            Medicine& med= inventory[i];
            if(med.getName() == name){
                found = true;
                cout << "Medicine found!" << endl;
                editMedicine(med);
                if (found){ break;}
            }
        }
        if(!found) cout << "Medicine not found!" << endl;
    }else if (edit_choice == 2){
        int id;
        cout << "Enter the ID: ";
        cin >> id;

        for(int i=0;i<inventory.size();++i){
            Medicine& med= inventory[i];
            if(med.getId() == id){
                found = true;
                cout << "Medicine found!" << endl;
                editMedicine(med);
                if (found){ break;}
            }
        }
        if(!found) cout << "Medicine not found!" << endl;
    }else if (edit_choice == 3){ return;}
    else {
        cout << "Invalid input!" << endl;
    }
}
void displayAllMedicines() {
    system("cls");
    cout << "\n\n\t\t\t\tAll Medicines in Inventory:\n" << endl;
    if (inventory.empty()) {
        cout << "No medicines in the inventory yet." << endl;
        return;
    }
    for (int i=0;i< inventory.size();++i) {
        Medicine & med =inventory[i];
        med.display();
    }
}
