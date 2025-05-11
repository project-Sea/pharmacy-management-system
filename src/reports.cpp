#include "../include/reports.h"
#include "../include/db_connection.h"
#include "../include/ui.h"

void generateDailyReport() {
    MYSQL *conn = MySQLConnection::getInstance()->getConn();
    MYSQL_RES *res = nullptr;
    MYSQL_ROW row;

    const char *query = "SELECT sale_date, SUM(total_price) AS daily_total "
                       "FROM sales "
                       "GROUP BY sale_date";

    if (mysql_query(conn, query)) {
        std::cerr << "Query error: " << mysql_error(conn) << std::endl;
        return;
    }

    res = mysql_store_result(conn);
    if (!res) {
        std::cerr << "No result set: " << mysql_error(conn) << std::endl;
        return;
    }

    int num_fields = mysql_num_fields(res);

    std::cout << "\n\t\t\t\t=== Daily Sales Report ===\n\t\t\t\t";
    while ((row = mysql_fetch_row(res))) {
        std::cout << "Date: " << (row[0] ? row[0] : "NULL")
             << " | Total: $" << (row[1] ? row[1] : "NULL") << "\n\t\t\t\t";
    }

    mysql_free_result(res);
}

void generateWeeklyReport() {
    MYSQL *conn = MySQLConnection::getInstance()->getConn();
    MYSQL_RES *res = nullptr;
    MYSQL_ROW row;

    std::string query = "SELECT YEAR(sale_date) AS year, WEEK(sale_date, 1) AS week, "
                   "SUM(total_price) AS weekly_total "
                   "FROM sales "
                   "GROUP BY year, week "
                   "ORDER BY year, week";

    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Query error: " << mysql_error(conn) << std::endl;
        return;
    }

    res = mysql_store_result(conn);
    if (!res) {
        std::cerr << "No result set: " << mysql_error(conn) << std::endl;
        return;
    }

    std::cout << "\n\t\t\t\t=== Weekly Sales Report ===\n\t\t\t\t";
    while ((row = mysql_fetch_row(res))) {
        std::cout << "Year: " << (row[0] ? row[0] : "NULL")
             << " | Week: " << (row[1] ? row[1] : "NULL")
             << " | Total: $" << std::fixed << std::setprecision(2)
             << (row[2] ? row[2] : "0.00") << "\n\t\t\t\t";
    }

    mysql_free_result(res);
}

void generateMonthlyReport() {
    MYSQL *conn = MySQLConnection::getInstance()->getConn();
    MYSQL_RES *res = nullptr;
    MYSQL_ROW row;

    std::string query = "SELECT DATE_FORMAT(sale_date, '%Y-%m') AS month, "
                   "SUM(total_price) AS monthly_total "
                   "FROM sales "
                   "GROUP BY month";

    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Query error: " << mysql_error(conn) << std::endl;
        return;
    }

    res = mysql_store_result(conn);
    if (!res) {
        std::cerr << "No result set: " << mysql_error(conn) << std::endl;
        return;
    }

    std::cout << "\n\t\t\t\t=== Monthly Sales Report ===\n\t\t\t\t";
    while ((row = mysql_fetch_row(res))) {
        std::cout << "Month: " << (row[0] ? row[0] : "NULL")
             << " | Total: $" << (row[1] ? row[1] : "NULL") << "\n\t\t\t\t";
    }

    mysql_free_result(res);
}

void generateNetRevenueReport() {
    MYSQL *conn = MySQLConnection::getInstance()->getConn();
    MYSQL_RES *salesRes = nullptr;
    MYSQL_RES *expensesRes = nullptr;
    MYSQL_ROW salesRow;
    MYSQL_ROW expensesRow;

    std::string salesQuery = "SELECT SUM(total_price) AS total_sales FROM sales";
    std::string expensesQuery = "SELECT SUM(amount) AS total_expenses FROM transaction_log";

    if (mysql_query(conn, salesQuery.c_str())) {
        std::cerr << "Query error: " << mysql_error(conn) << std::endl;
        return;
    }

    salesRes = mysql_store_result(conn);
    if (!salesRes) {
        std::cerr << "No result set: " << mysql_error(conn) << std::endl;
        return;
    }

    double totalSales = 0;
    if ((salesRow = mysql_fetch_row(salesRes))) {
        totalSales = salesRow[0] ? std::stod(salesRow[0]) : 0.0;
    }

    mysql_free_result(salesRes);

    if (mysql_query(conn, expensesQuery.c_str())) {
        std::cerr << "Query error: " << mysql_error(conn) << std::endl;
        return;
    }

    expensesRes = mysql_store_result(conn);
    if (!expensesRes) {
        std::cerr << "No result set: " << mysql_error(conn) << std::endl;
        return;
    }

    double totalExpenses = 0;
    if ((expensesRow = mysql_fetch_row(expensesRes))) {
        totalExpenses = expensesRow[0] ? std::stod(expensesRow[0]) : 0.0;
    }

    mysql_free_result(expensesRes);

    double netRevenue = totalSales - totalExpenses;

    std::cout << "\n\t\t\t\t=== Net Revenue Report ===\n\t\t\t\t";
    std::cout << "Total Sales:    $" << totalSales << "\n\t\t\t\t";
    std::cout << "Total Expenses: $" << totalExpenses << "\n\t\t\t\t";
    std::cout << "Net Revenue:    $" << netRevenue << '\n';
}
