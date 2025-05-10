
#include "../include/db_connection.h"
#include "../include/sales.h"
#include "../include/ui.h"
void processSale()
{
    loadingAnimation("Loading Process Sales Transaction Page");
    system("cls");

    std::cout << "\n\n\t\t\t\tProcess Sales Transaction\n\n";
    int drugId, quantity;
    double unitPrice, totalPrice;
    MYSQL *conn = MySQLConnection::getInstance()->getConn();
    std::cout << "\t\t\t\tEnter Drug ID: ";
    std::cin >> drugId;

    // Check if drugId exists in the database
    // If it exists, get the unit price

    std::string selectDrug = "SELECT * FROM DRUG WHERE id = " + std::to_string(drugId);

    if (mysql_query(conn, selectDrug.c_str()))
    {
        std::cerr << "Query failed: " << mysql_error(conn) << std::endl;
        return;
    }
    MYSQL_RES *result = mysql_store_result(conn);
    if (!result)
    {
        std::cerr << "\t\t\t\tNo result set: " << mysql_error(conn) << std::endl;
        return;
    }
    MYSQL_ROW row = mysql_fetch_row(result);
    if (!row)
    {
        std::cerr << "\t\t\t\tDrug ID not found.\n";
        mysql_free_result(result);
        return;
    }
    unitPrice = std::stod(row[3]);                        // Assuming the unit price is in the 4th column
    std::cout << "\t\t\t\tDrug Name: " << row[1] << "\n"; // Assuming the drug name is in the 2nd column
    std::cout << "\t\t\t\tEnter Quantity Sold: ";
    std::cin >> quantity;

    // Check if quantity is available in stock
    int availableStock = std::stoi(row[2]); // Assuming the quantity in stock is in the 3rd column
    if (quantity > availableStock)
    {
        std::cerr << "\t\t\t\tInsufficient stock. Available stock: " << availableStock << "\n";
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);
    totalPrice = unitPrice * quantity;

    // Record the sale in the database
    std::string insertSale = "INSERT INTO Sales (drug_id, quantity_sold, total_price) VALUES (" +
                             std::to_string(drugId) + ", " +
                             std::to_string(quantity) + ", " +
                             std::to_string(totalPrice) + ")";

    if (mysql_query(conn, insertSale.c_str()))
    {
        std::cerr << "Query failed: " << mysql_error(conn) << std::endl;
    }
    else
    {
        std::cout << "\t\t\t\tDrug ID: " << drugId
                  << ", Quantity Sold: " << quantity
                  << ", Total Price: $" << totalPrice << "\n";
        // decrement the drug stock
        const std::string updateDrug = "UPDATE DRUG SET quantity_stock = quantity_stock - " +
                                       std::to_string(quantity) +
                                       " WHERE id = " + std::to_string(drugId);
        if (mysql_query(conn, updateDrug.c_str()))
        {
            std::cerr << "Query failed: " << mysql_error(conn) << std::endl;
        }
        else
        {
            std::cout << "\t\t\t\tStock updated successfully.\n";
        }

        std::cout << "\t\t\t\tSale recorded successfully.\n";
    }
    std::cout << "\n\t\t\t\tPress any key to return to the main menu...\n";
    system("pause");
}

// INSERT IGNORE INTO Sales (sale_id, drug_id, quantity_sold, total_price, sale_date) VALUES
// (1, 1, 10, 50.00, NOW() - INTERVAL 1 DAY),
// (2, 2, 20, 5.00, NOW()),
// (3, 3, 15, 15.00, NOW() - INTERVAL 2 DAY);

std::vector<Sale> getAllSales()
{
    std::vector<Sale> sales;
    std::string query = "SELECT * FROM Sales";

    MYSQL *conn = MySQLConnection::getInstance()->getConn();

    if (mysql_query(conn, query.c_str()))
    {
        std::cerr << "Query failed: " << mysql_error(conn) << std::endl;
        return sales;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (!result)
    {
        std::cerr << "No result set: " << mysql_error(conn) << std::endl;
        return sales;
    }

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
    {
        Sale sale;
        sale.sale_id = std::stoi(row[0]);
        sale.drug_id = std::stoi(row[1]);
        sale.quantity_sold = std::stoi(row[2]);
        sale.total_price = std::stod(row[3]);
        sale.sale_date = row[4] ? row[4] : "";

        sales.push_back(sale);
    }

    mysql_free_result(result);
    return sales;
}

// void viewSalesReport()
// {
//     loadingAnimation("Loading View Sales Reports Page");
//     system("cls");
//     std::cout << "\n\n\t\t\t\tView Sales Reports";
//     system("pause");
// }