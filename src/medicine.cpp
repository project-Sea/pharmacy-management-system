#include <iostream>
#include <sstream>
#include "medicine.h"



int main() {
    MYSQL* conn = createConnection();
    if (!conn) {
        std::cerr << "Could not connect to DB.\n";
        return 1;
    }
    std::cout << "Connected to DB.\n";

    while (true) {
        std::cout << "\n1) Add  2) List  3) Update  4) Delete  5) Exit\n";
        int choice = Medicine().getInt("Choose an option: ");
        if (choice == 1) {
            Medicine m;
            m.inputDetails();
            m.insertDB(conn);
        } else if (choice == 2) {
            Medicine::listAll(conn);
        } else if (choice == 3) {
            int uid = Medicine().getInt("ID to update: ");
            Medicine m(uid);
            m.inputUpdate();
            m.updateDB(conn);
        } else if (choice == 4) {
            long long did = Medicine().getLongLong("ID to delete: ");
            Medicine::deleteDB(conn, did);
        } else if (choice == 5) {
            std::cout << "Bye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }

        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
        system("clear");  // or "cls" on Windows
    }

    closeConnection(conn);
    return 0;
}
