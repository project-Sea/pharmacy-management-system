#include "../include/expenses.h"
#include "../include/ui.h"
#include "../include/db_connection.h"

void addExpenses()
{

    system("cls");
    std::cout << "\n\n";
    std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
    std::cout << "\t\t\t\t|          Add Expenses              |\n";
    std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
    double amount;
    std::string description;
    std::cout << "\t\t\t\t| Enter Amount(in dollars): ";
    std::cin >> amount;
    std::cout << "\t\t\t\t| Enter Description: ";
    std::cin.ignore(); // Clear the newline character from the input buffer
    std::getline(std::cin, description);
    std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
    std::cout << "\t\t\t\t| Amount: " << amount << "\n";
    std::cout << "\t\t\t\t| Description: " << description << "\n";
    std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
    std::cout << "\t\t\t\t| Are you sure you want to add this? |\n";
    std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
    std::cout << "\t\t\t\t| 1. Yes                             |\n";
    std::cout << "\t\t\t\t| 2. No                              |\n";
    std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
    int choice;
    std::cout << "\t\t\t\tEnter your choice: ";
    std::cin >> choice;
    if (choice == 1)
    {
        // Assuming you have a function to add expenses to the database
        // addExpenseToDatabase(amount, description);
        MYSQL *conn = MySQLConnection::getInstance()->getConn();
        std::string query = "INSERT INTO TRANSACTION_LOG (amount, description,type) VALUES (" +
                            std::to_string(amount) + ", '" +
                            description + "', 'Expense')";

        if (mysql_query(conn, query.c_str()))
        {
            std::cerr << "\t\t\t\t| Error: " << mysql_error(conn) << "\n";
            std::cout << "\t\t\t\t| Expense not added.                 |\n";
        }
        else
        {
            std::cout << "\t\t\t\t| Expense added successfully!        |\n";
        }
    }
    else
    {
        std::cout << "\t\t\t\t| Expense not added.                 |\n";
    }
    std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
    std::cout << "\t\t\t\t| Press any key to return to menu.   |\n";
    std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
    std::cout << "\t\t\t\t" << std::setfill('=') << std::setw(43) << "=" << std::endl;
    std::cout << "\t\t\t\t|          Thank you!               |\n";
    std::cout << "\t\t\t\t" << std::setfill('=') << std::setw(43) << "=" << std::endl;
    std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;

    std::cout << "\n\n";
    system("pause");
}