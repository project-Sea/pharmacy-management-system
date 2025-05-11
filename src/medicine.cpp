#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

class Medicine {
private:
    long long quantity, price;
    std::string name, expiryDate, category;

    std::string getSimpleDate(const std::string& prompt) {
        std::string d;
        while (true) {
            std::cout << prompt;
            std::cin >> d;
            if (d.size() != 10 || d[4] != '-' || d[7] != '-') {
                std::cout << "\t\tBad format, try YYYY-MM-DD\n";
                continue;
            }

            int y = std::stoi(d.substr(0, 4));
            int m = std::stoi(d.substr(5, 2));
            int day = std::stoi(d.substr(8, 2));

            if (m < 1 || m > 12) {
                std::cout << "\t\tInvalid month. Try again.\n";
                continue;
            }

            int maxDay = 31;
            if (m == 4 || m == 6 || m == 9 || m == 11) maxDay = 30;
            else if (m == 2) {
                bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
                maxDay = leap ? 29 : 28;
            }

            if (day < 1 || day > maxDay) {
                std::cout << "\t\tInvalid day for that month. Try again.\n";
                continue;
            }

            return d;
        }
    }

    long long getValidLongLong(const std::string& prompt) {
        long long v;
        std::cout << prompt;
        while (!(std::cin >> v)) {
            std::cout << "\t\tPlease enter a valid number: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        return v;
    }

public:
    Medicine() : quantity(0), price(0) {}

    void inputDetails() {
        std::cout << "\t\tName: ";
        std::getline(std::cin >> std::ws, name);
        std::cout << "\t\tCategory: ";
        std::getline(std::cin >> std::ws, category);
        quantity = getValidLongLong("\t\tQuantity: ");
        price = getValidLongLong("\t\tPrice: ");
        expiryDate = getSimpleDate("\t\tExpiry (YYYY-MM-DD): ");
    }

    void inputUpdate() {
        std::cout << "\t\tNew Name: ";
        std::getline(std::cin >> std::ws, name);
        std::cout << "\t\tNew Category: ";
        std::getline(std::cin >> std::ws, category);
        quantity = getValidLongLong("\t\tNew Quantity: ");
        price = getValidLongLong("\t\tNew Price: ");
        expiryDate = getSimpleDate("\t\tNew Expiry (YYYY-MM-DD): ");
    }

    void insertDB(sql::Connection* con) {
        try {
            ensureConnection(con);

            auto pst = con->prepareStatement(
                "INSERT INTO medicines(name, price, expiry_date, category, quantity) VALUES (?, ?, ?, ?, ?)"
            );
            pst->setString(1, name);
            pst->setInt64(2, price);
            pst->setString(3, expiryDate);
            pst->setString(4, category);
            pst->setInt64(5, quantity);
            pst->executeUpdate();

            auto res = con->createStatement()->executeQuery("SELECT LAST_INSERT_ID() AS id");
            if (res->next()) {
                int insertedId = res->getInt("id");
                std::cout << "\t\tAdded! ID = " << insertedId << "\n";
                std::cout << "\t\tName: " << name
                     << ", Category: " << category
                     << ", Qty: " << quantity
                     << ", Price: " << price
                     << ", Expiry: " << expiryDate << "\n";
            }
        } catch (sql::SQLException& e) {
            std::cerr << "\t\tSQL error: " << e.what() << std::endl;
        }
    }

    static void listAll(sql::Connection* con) {
        try {
            ensureConnection(con);
            auto stmt = con->createStatement();
            auto res = stmt->executeQuery("SELECT * FROM medicines");
            while (res->next()) {
                std::cout << "\t\tID:" << res->getInt("id")
                     << " Name:" << res->getString("name")
                     << " Cat:" << res->getString("category")
                     << " Qty:" << res->getInt64("quantity")
                     << " Price:" << res->getInt64("price")
                     << " Exp:" << res->getString("expiry_date")
                     << "\n";
            }
        } catch (sql::SQLException& e) {
            std::cerr << "\t\tSQL error: " << e.what() << std::endl;
        }
    }

    void updateDB(sql::Connection* con, int id) {
        try {
            ensureConnection(con);

            auto pst = con->prepareStatement(
                "UPDATE medicines SET name=?, price=?, expiry_date=?, category=?, quantity=? WHERE id=?"
            );
            pst->setString(1, name);
            pst->setInt64(2, price);
            pst->setString(3, expiryDate);
            pst->setString(4, category);
            pst->setInt64(5, quantity);
            pst->setInt(6, id);
            int affected = pst->executeUpdate();
            if (affected == 0) {
                std::cout << "\t\tNo record found with that ID.\n";
            } else {
                std::cout << "\t\tUpdated!\n";
            }
        } catch (sql::SQLException& e) {
            std::cerr << "\t\tSQL error: " << e.what() << std::endl;
        }
    }

    static void deleteDB(sql::Connection* con, int delId) {
        try {
            ensureConnection(con);
            auto pst = con->prepareStatement("DELETE FROM medicines WHERE id=?");
            pst->setInt(1, delId);
            int affected = pst->executeUpdate();
            if (affected == 0) {
                std::cout << "\t\tNo record found with that ID.\n";
            } else {
                std::cout << "\t\tDeleted!\n";
            }
        } catch (sql::SQLException& e) {
            std::cerr << "\t\tSQL error: " << e.what() << std::endl;
        }
    }

    static void ensureConnection(sql::Connection* &con) {
        if (!con->isValid()) {
            std::cout << "\t\tConnection lost. Reconnecting...\n";
            sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "root", "pass");
            con->setSchema("pharmacy_db");
        }
    }
};

void clearScreen() {
  // To make it work in different OS
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    try {
        auto driver = sql::mysql::get_mysql_driver_instance();
        std::unique_ptr<sql::Connection> con(
            driver->connect("tcp://127.0.0.1:3306", "root", "pass")  // Change password as needed
        );
        con->setSchema("pharmacy_db");
        std::cout << "Connected.\n";

        while (true) {
            std::cout << "\n\t\t1) Add  \n\t\t2) List  \n\t\t3) Update  \n\t\t4) Delete  \n\t\t5) Exit\n";
            int ch; std::cin >> ch;
            if (ch == 1) {
                Medicine m;
                m.inputDetails();
                m.insertDB(con.get());
            } else if (ch == 2) {
                Medicine::listAll(con.get());
            } else if (ch == 3) {
                int uid;
                std::cout << "\t\tID to update: ";
                while (!(std::cin >> uid)) {
                    std::cout << "\t\tEnter a valid number: ";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                Medicine m;
                m.inputUpdate();
                m.updateDB(con.get(), uid);
            } else if (ch == 4) {
                int did;
                std::cout << "\t\tID to delete: ";
                while (!(std::cin >> did)) {
                    std::cout << "\t\tEnter a valid number: ";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                Medicine::deleteDB(con.get(), did);
            } else if (ch == 5) {
                std::cout << "\t\tBye!\n";
                break;
            } else {
                std::cout << "\t\tOops, try again.\n";
            }

            std::cout << "\t\tPress enter...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
            clearScreen();
        }
    } catch (std::exception& e) {
        std::cerr << "\t\tError: " << e.what() << std::endl;
    }
    return 0;
}
