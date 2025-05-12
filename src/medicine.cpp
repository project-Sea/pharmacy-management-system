#include "../include/medicine.h"

void clearInputBuffer()
{
    std::cin.clear();            // clear the error flag
    std::cin.ignore(1000, '\n'); // ignore up to 1000 characters or until newline
}

void displayDrugsTable(MYSQL_RES *result)
{
    // Print the table header
    std::cout << "\n\t\t\t\t+--------+-------------------------+-------+------------+------------+------------+---------------------+-------------------------+--------------------+\n";
    std::cout << "\t\t\t\t|  ID    |         Name            |  Qty  |  Purchase  |  Selling   |   Expiry   |      Added          |       Description       |    Category        |\n";
    std::cout << "\t\t\t\t+--------+-------------------------+-------+------------+------------+------------+---------------------+-------------------------+--------------------+\n";

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
    {
        // Ensure consistent column width
        std::cout << "\t\t\t\t| "
                  << std::setw(6) << (row[0] ? row[0] : "N/A") << " | "
                  << std::setw(25) << (row[1] ? row[1] : "N/A") << " | "
                  << std::setw(5) << (row[2] ? row[2] : "N/A") << " | "
                  << std::setw(10) << (row[3] ? row[3] : "N/A") << " | "
                  << std::setw(10) << (row[4] ? row[4] : "N/A") << " | "
                  << std::setw(10) << (row[5] ? row[5] : "N/A") << " | "
                  << std::setw(19) << (row[6] ? row[6] : "N/A") << " | "
                  << std::setw(25) << (row[7] ? row[7] : "N/A") << " | "
                  << std::setw(18) << (row[8] ? row[8] : "N/A") << " |\n";
    }

    std::cout << "\t\t\t\t+--------+-------------------------+-------+------------+------------+------------+---------------------+-------------------------+--------------------+\n";
}
std::string getValidDate(const std::string &prompt)
{
    std::string date;
    while (true)
    {
        std::cout << prompt;
        std::cin >> date;

        if (date.size() == 10 && date[4] == '-' && date[7] == '-')
        {
            try
            {
                int y = std::stoi(date.substr(0, 4));
                int m = std::stoi(date.substr(5, 2));
                int d = std::stoi(date.substr(8, 2));

                if (m >= 1 && m <= 12)
                {
                    int maxDay = 31;
                    if (m == 4 || m == 6 || m == 9 || m == 11)
                        maxDay = 30;
                    else if (m == 2)
                    {
                        bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
                        maxDay = leap ? 29 : 28;
                    }

                    if (d >= 1 && d <= maxDay)
                    {
                        // check if the date is in the future
                        time_t now = time(0);
                        tm *ltm = localtime(&now);
                        if (y < ltm->tm_year + 1900 || (y == ltm->tm_year + 1900 && m < ltm->tm_mon + 1) || (y == ltm->tm_year + 1900 && m == ltm->tm_mon + 1 && d < ltm->tm_mday))
                        {
                            std::cout << "\t\t\t\tDate cannot be in the past. Try again.\n";
                            continue;
                        }
                        // clear the input buffer
                        std::cin.ignore(1000, '\n'); // Clears up to 10,000 characters or until '\n'

                        return date;
                    }
                }
            }
            catch (...)
            {
            }
        }

        std::cout << "\t\t\t\tInvalid date format or values. Try YYYY-MM-DD.\n";
    }
}

long long getPositiveLong(const std::string &prompt)
{
    long long value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value <= 0)
        {
            std::cout << "\t\t\t\tPlease enter a number greater than 0.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
        {
            std::cin.ignore(10000, '\n');
            return value;
        }
    }
}

std::string getNonEmptyString(const std::string &prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin >> std::ws, input); // std::ws clears leftover newline
        if (!input.empty())
            break;
        std::cout << "\t\t\t\tInput cannot be empty.\n";
    }
    return input;
}

void Medicine::addMedicine()
{
    try
    {
        std::string name = getNonEmptyString("\t\t\t\tEnter Name: ");
        std::string category = getNonEmptyString("\t\t\t\tEnter Category: ");
        long long quantity = getPositiveLong("\t\t\t\tEnter Quantity: ");
        long long price_sale = getPositiveLong("\t\t\t\tEnter Sale Price: ");
        long long price_purchase = getPositiveLong("\t\t\t\tEnter Purchase Price: ");
        std::string expiryDate = getValidDate("\t\t\t\tEnter Expiry Date (YYYY-MM-DD): ");
        std::string description = getNonEmptyString("\t\t\t\tEnter Description: ");

        // Create a connection to the database
        MYSQL *conn = MySQLConnection::getInstance()->getConn();
        if (conn == nullptr)
        {
            std::cerr << "\t\t\t\tFailed to connect to the database.\n";
            return;
        }
        // Prepare the SQL statement
        std::string query = "INSERT INTO DRUG (name, quantity_stock, price_purchase, price_selling, expiration_date,description) VALUES ('" +
                            name + "', " +
                            std::to_string(quantity) + ", " +
                            std::to_string(price_purchase) + ", " +
                            std::to_string(price_sale) + ", '" +
                            expiryDate + "', '" +
                            description + "')";
        // Execute the SQL statement
        if (mysql_query(conn, query.c_str()))
        {
            std::cerr << "\t\t\t\tQuery failed: " << mysql_error(conn) << std::endl;
            return;
        }
        // Get the last inserted ID
        long long drug_id = mysql_insert_id(conn);
        std::cout << "\t\t\t\tAdded! ID = " << drug_id << "\n";
        std::cout << "\t\t\t\tName: " << name << "\n"
                  << "\t\t\t\tCategory: " << category << "\n"
                  << "\t\t\t\tQty: " << quantity << "\n"
                  << "\t\t\t\tPrice Sale: " << price_sale << "\n"
                  << "\t\t\t\tPrice Purchase: " << price_purchase << "\n"
                  << "\t\t\t\tExpiry: " << expiryDate << "\n"
                  << "\t\t\t\tDescription: " << description
                  << "\n";

        // add the category to the category table if it does not exist,
        // if it exists, return the id of the category
        std::string categoryQuery = "INSERT IGNORE INTO category (category_name) VALUES ('" + category + "')";
        if (mysql_query(conn, categoryQuery.c_str()))
        {
            std::cerr << "\t\t\t\tQuery failed: " << mysql_error(conn) << std::endl;
            return;
        }
        // get the category id

        auto categoryId = mysql_insert_id(conn);
        // add the drug_id and category_id to the drug_category table
        std::string drug_cat_query = "INSERT INTO DRUG_CATEGORIES (drug_id, category_id) VALUES (" +
                                     std::to_string(categoryId) + ", " +
                                     std::to_string(categoryId) + ")";
        if (mysql_query(conn, drug_cat_query.c_str()))
        {
            std::cerr << "\t\t\t\tQuery failed: " << mysql_error(conn) << std::endl;
            return;
        }
        std::cout << "\t\t\t\tAdded to category table!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "\t\tError: " << e.what() << std::endl;
    }
}

void Medicine::updateMedicine()
{
    MYSQL *conn = MySQLConnection::getInstance()->getConn();
    int drugId;
    std::cout << "\n\t\t\t\t=== Update Drug ===\n";
    std::cout << "\t\t\t\tEnter Drug ID to update: ";
    std::cin >> drugId;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cerr << "\t\t\t\tInvalid ID input.\n";
        return;
    }

    std::string checkQuery = "SELECT * FROM Drug WHERE id = " + std::to_string(drugId);
    if (mysql_query(conn, checkQuery.c_str()))
    {
        std::cerr << "\t\t\t\tQuery failed: " << mysql_error(conn) << "\n";
        return;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row = mysql_fetch_row(result);
    if (!row)
    {
        std::cout << "\t\t\t\tDrug ID not found.\n";
        mysql_free_result(result);
        return;
    }

    std::string oldName = row[1];
    int oldQuantity = std::stoi(row[2]);
    double oldPurchase = std::stod(row[3]);
    double oldSelling = std::stod(row[4]);
    std::string oldExpiry = row[5];
    std::string oldDescription = row[7];

    mysql_free_result(result);

    std::cin.ignore();
    std::string newName, newCategoryName, newExpiry, newDescription;
    long long newQuantity;
    double newPurchase, newSelling;

    std::cout << "\t\t\t\tEnter New Name [" << oldName << "]: ";
    std::getline(std::cin, newName);
    if (newName.empty())
        newName = oldName;

    std::cout << "\t\t\t\tEnter New Quantity [" << oldQuantity << "]: ";
    std::string qStr;
    std::getline(std::cin, qStr);
    newQuantity = qStr.empty() ? oldQuantity : std::stoll(qStr);

    std::cout << "\t\t\t\tEnter New Purchase Price [" << oldPurchase << "]: ";
    std::string pStr;
    std::getline(std::cin, pStr);
    newPurchase = pStr.empty() ? oldPurchase : std::stod(pStr);

    std::cout << "\t\t\t\tEnter New Selling Price [" << oldSelling << "]: ";
    std::string sStr;
    std::getline(std::cin, sStr);
    newSelling = sStr.empty() ? oldSelling : std::stod(sStr);

    std::cout << "\t\t\t\tEnter New Expiration Date (YYYY-MM-DD) [" << oldExpiry << "]: ";
    std::getline(std::cin, newExpiry);
    if (newExpiry.empty())
        newExpiry = oldExpiry;
    else
        newExpiry = getValidDate("\t\t\t\tEnter Expiration Date (YYYY-MM-DD): ");

    std::cout << "\t\t\t\tEnter New Description [" << oldDescription << "]: ";
    std::getline(std::cin, newDescription);
    if (newDescription.empty())
        newDescription = oldDescription;

    std::cout << "\t\t\t\tEnter New Category Name: ";
    std::getline(std::cin, newCategoryName);

    // Ensure category exists and fetch its id
    std::string insertCategory = "INSERT IGNORE INTO Category (category_name) VALUES ('" + newCategoryName + "')";
    mysql_query(conn, insertCategory.c_str());

    std::string selectCategoryId = "SELECT id FROM Category WHERE category_name = '" + newCategoryName + "'";
    if (mysql_query(conn, selectCategoryId.c_str()))
    {
        std::cerr << "\t\t\t\tCategory lookup failed: " << mysql_error(conn) << "\n";
        return;
    }

    MYSQL_RES *catResult = mysql_store_result(conn);
    MYSQL_ROW catRow = mysql_fetch_row(catResult);
    if (!catRow)
    {
        std::cerr << "\t\t\t\tFailed to get category ID.\n";
        mysql_free_result(catResult);
        return;
    }
    int categoryId = std::stoi(catRow[0]);
    mysql_free_result(catResult);

    // Final update query
    std::string updateQuery = "UPDATE Drug SET name = '" + newName +
                              "', quantity_stock = " + std::to_string(newQuantity) +
                              ", price_purchase = " + std::to_string(newPurchase) +
                              ", price_selling = " + std::to_string(newSelling) +
                              ", expiration_date = '" + newExpiry +
                              "', description = '" + newDescription +
                              "', category_id = " + std::to_string(categoryId) +
                              " WHERE id = " + std::to_string(drugId);

    if (mysql_query(conn, updateQuery.c_str()))
    {
        std::cerr << "\t\t\t\tUpdate failed: " << mysql_error(conn) << "\n";
        return;
    }

    std::cout << "\n\t\t\t\tDrug updated successfully!\n";
}
void Medicine::getAllMedicines()
{
    MYSQL *conn = MySQLConnection::getInstance()->getConn();

    if (!conn)
    {
        std::cerr << "\t\t\t\tDatabase connection failed.\n";
        return;
    }

    std::string query =
        "SELECT d.id, d.name, d.quantity_stock, d.price_purchase, d.price_selling, "
        "d.expiration_date, d.insertion_date, d.description, c.category_name "
        "FROM Drug d LEFT JOIN Category c ON d.category_id = c.id";

    if (mysql_query(conn, query.c_str()))
    {
        std::cerr << "\t\t\t\tQuery failed: " << mysql_error(conn) << "\n";
        return;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (!result)
    {
        std::cerr << "\t\t\t\tFailed to store result: " << mysql_error(conn) << "\n";
        return;
    }

    // Display the table with drug data
    displayDrugsTable(result);

    mysql_free_result(result);
}