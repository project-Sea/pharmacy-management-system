#include <iostream>
#include "../include/expiryF.h"
#include "../include/db_connection.h"
#include "../include/ui.h"

void checkExpiryAll() {
    system("COLOR 6");
    showStartupAnimation();
    // Get a fresh connection instance for this function
    MYSQL *conn = MySQLConnection::getInstance()->getConn();
    MYSQL_RES *res = nullptr; // Initialize to nullptr
    MYSQL_ROW row;

    // Execute query
    const char *query = "SELECT name, expiration_date FROM drug WHERE expiration_date < CURDATE();";

    if (mysql_query(conn, query)) {
        std::cerr << "Query error: " << mysql_error(conn) << std::endl;
    } else { // Only proceed if the query was successful
        // Store result
        res = mysql_store_result(conn);

        // Check if result is empty
        if (res) {
            int num_fields = mysql_num_fields(res);
            int num_rows = mysql_num_rows(res);

            if (num_rows > 0) {
                system("COLOR C");
                std::cout << "\n\n\n";
                std::cout << "\t\t\t\t!!!ALERT!!!\n";
                std::cout << "\t\t\t\tExpired Medicines (" << num_rows << " found):\n";
                std::cout << "\n\n\n";
                std::cout << "\t\t\t\t####################################\n";

                // Print table header
                MYSQL_FIELD *field;
                std::cout<<"\t\t\t\t";
                while ((field = mysql_fetch_field(res))) {
                    std::cout << field->name<<"\t\t\t";
                }
                std::cout << "\n\t\t\t\t####################################\n";

                // Print rows
                while ((row = mysql_fetch_row(res))) {
                    std::cout<<"\t\t\t\t";
                    for (int i = 0; i < num_fields; i++) {
                        std::cout << (row[i] ? row[i] : "NULL")<<"\t\t\t";
                    }
                    std::cout <<"\t\t\t\t"<< std::endl;
                }
            } else {
                system("COLOR A");
                std::cout << "\n\n\n";
                std::cout << "\t\t\t\t### No Expired Drugs Detected ###\n";
            }

            mysql_free_result(res); // <--- IMPORTANT: Free the result set
        } else {
            // Check if error occurred or just empty result
            if (mysql_errno(conn)) {
                std::cout << "\n\n\n";
                std::cerr << "\t\t\t\t### Error retrieving results: " << mysql_error(conn) << std::endl;
            } else {
                system("COLOR A");
                std::cout << "\n\n\n";
                std::cout << "\t\t\t\t### No Expired Drugs Detected ###\n";
            }
        }
    }
}