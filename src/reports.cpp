#include "../include/reports.h"
#include "../include/db_connection.h" 

#include <iostream>
#include <mysql/jdbc.h>
#include <iomanip>

using namespace std;

void generateDailyReport() {
    try {
        sql::Connection* conn = getDBConnection();
        sql::Statement* stmt = conn->createStatement();

        string query = "SELECT sale_date, SUM(total_price) AS daily_total "
                       "FROM sales "
                       "GROUP BY sale_date";

        sql::ResultSet* res = stmt->executeQuery(query);

        cout << "=== Daily Sales Report ===\n";
        while (res->next()) {
            cout << "Date: " << res->getString("sale_date")
                 << " | Total: $" << res->getDouble("daily_total") << '\n';
        }

        delete res;
        delete stmt;
        delete conn;
    } catch (sql::SQLException& e) {
        cerr << "Error generating daily report: " << e.what() << '\n';
    }
}

void generateMonthlyReport() {
    try {
        sql::Connection* conn = getDBConnection();
        sql::Statement* stmt = conn->createStatement();

        string query = "SELECT DATE_FORMAT(sale_date, '%Y-%m') AS month, "
                       "SUM(total_price) AS monthly_total "
                       "FROM sales "
                       "GROUP BY month";

        sql::ResultSet* res = stmt->executeQuery(query);

        cout << "\n=== Monthly Sales Report ===\n";
        while (res->next()) {
            cout << "Month: " << res->getString("month")
                 << " | Total: $" << res->getDouble("monthly_total") << '\n';
        }

        delete res;
        delete stmt;
        delete conn;
    } catch (sql::SQLException& e) {
        cerr << "Error generating monthly report: " << e.what() << '\n';
    }
}

void generateNetRevenueReport() {
    try {
        sql::Connection* conn = getDBConnection();
        sql::Statement* stmt = conn->createStatement();

        string salesQuery = "SELECT SUM(total_price) AS total_sales FROM sales";
        string expensesQuery = "SELECT SUM(amount) AS total_expenses FROM expenses";

        sql::ResultSet* salesRes = stmt->executeQuery(salesQuery);
        double totalSales = 0;
        if (salesRes->next()) totalSales = salesRes->getDouble("total_sales");

        sql::ResultSet* expensesRes = stmt->executeQuery(expensesQuery);
        double totalExpenses = 0;
        if (expensesRes->next()) totalExpenses = expensesRes->getDouble("total_expenses");

        double netRevenue = totalSales - totalExpenses;

        cout << "\n=== Net Revenue Report ===\n";
        cout << "Total Sales:    $" << totalSales << '\n';
        cout << "Total Expenses: $" << totalExpenses << '\n';
        cout << "Net Revenue:    $" << netRevenue << '\n';

        delete salesRes;
        delete expensesRes;
        delete stmt;
        delete conn;
    } catch (sql::SQLException& e) {
        cerr << "Error generating net revenue report: " << e.what() << '\n';
    }
}
