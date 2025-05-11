#include <iostream>
#include <string>
#include "include/db_connection.h"


class Medicine {
    int               id;
    std::string       name;
    long long         price;
    std::string       expiryDate;
    std::string       category;
    long long         quantity;

    // --- Date validation helpers ---
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }

    bool isValidDate(const std::string& d) const {
        if (d.size() != 10 || d[4] != '-' || d[7] != '-') {
            return false;
        }
        int y, m, day;
        try {
            y   = std::stoi(d.substr(0,4));
            m   = std::stoi(d.substr(5,2));
            day = std::stoi(d.substr(8,2));
        } catch (...) {
            return false;
        }
        if (m < 1 || m > 12) return false;
        int dim[] = {31, isLeapYear(y) ? 29 : 28, 31,30,31,30,31,31,30,31,30,31};
        return (day >= 1 && day <= dim[m-1]);
    }

    std::string getDate(const std::string& prompt) {
        std::string d;
        do {
            std::cout << prompt;
            std::getline(std::cin, d);
            if (!isValidDate(d)) {
                std::cout << "Invalid date. Use YYYY-MM-DD format.\n";
            }
        } while (!isValidDate(d));
        return d;
    }

    // --- Numeric validation helpers ---
    long long getLongLong(const std::string& prompt) {
        long long v;
        std::string line;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            if (ss >> v) {
                return v;
            }
            std::cout << "Please enter a valid integer number.\n";
        }
    }

    int getInt(const std::string& prompt) {
        int v;
        std::string line;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            if (ss >> v) {
                return v;
            }
            std::cout << "Please enter a valid integer.\n";
        }
    }

public:
    Medicine() 
      : id(0), price(0), quantity(0) 
    {}

    Medicine(int i) 
      : id(i), price(0), quantity(0) 
    {}

    void inputDetails() {
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        price      = getLongLong("Enter Price (integer): ");
        expiryDate = getDate("Enter Expiry Date (YYYY-MM-DD): ");
        std::cout << "Enter Category: ";
        std::getline(std::cin, category);
        quantity   = getLongLong("Enter Quantity (integer): ");
    }

    void inputUpdate() {
        std::cout << "Enter new Name: ";
        std::getline(std::cin, name);
        price      = getLongLong("Enter new Price (integer): ");
        expiryDate = getDate("Enter new Expiry Date (YYYY-MM-DD): ");
        std::cout << "Enter new Category: ";
        std::getline(std::cin, category);
        quantity   = getLongLong("Enter new Quantity (integer): ");
    }

    void insertDB(MYSQL* conn) {
        std::stringstream ss;
        ss << "INSERT INTO medicines(name, price, expiry_date, category, quantity) VALUES ('"
           << name << "', " << price << ", '" << expiryDate << "', '"
           << category << "', " << quantity << ")";
        if (mysql_query(conn, ss.str().c_str()) != 0) {
            std::cerr << "Insert error: " << mysql_error(conn) << "\n";
        } else {
            std::cout << "Added!\n";
        }
    }

    void updateDB(MYSQL* conn) {
        std::stringstream ss;
        ss << "UPDATE medicines SET name='" << name
           << "', price=" << price
           << ", expiry_date='" << expiryDate
           << "', category='" << category
           << "', quantity=" << quantity
           << " WHERE id=" << id;
        if (mysql_query(conn, ss.str().c_str()) != 0) {
            std::cerr << "Update error: " << mysql_error(conn) << "\n";
        } else {
            std::cout << "Updated!\n";
        }
    }

    static void deleteDB(MYSQL* conn, long long delId) {
        std::stringstream ss;
        ss << "DELETE FROM medicines WHERE id=" << delId;
        if (mysql_query(conn, ss.str().c_str()) != 0) {
            std::cerr << "Delete error: " << mysql_error(conn) << "\n";
        } else {
            std::cout << "Deleted!\n";
        }
    }

    static void listAll(MYSQL* conn) {
        if (mysql_query(conn, "SELECT * FROM medicines") != 0) {
            std::cerr << "Select error: " << mysql_error(conn) << "\n";
            return;
        }
        MYSQL_RES* res = mysql_store_result(conn);
        if (!res) {
            std::cerr << "Result error: " << mysql_error(conn) << "\n";
            return;
        }
        std::cout << "\n-- All Medicines --\n";
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            std::cout << "ID: "       << row[0]
                      << " | Name: "   << row[1]
                      << " | Category: "<< row[4]
                      << " | Qty: "    << row[5]
                      << " | Price: "  << row[2]
                      << " | Expiry: " << row[3] << "\n";
        }
        mysql_free_result(res);
    }
};
