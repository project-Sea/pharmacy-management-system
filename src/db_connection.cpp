#include "../include/db_connection.h"
#include <iostream>

// initiaze static member
MySQLConnection *MySQLConnection::instance = nullptr;

MySQLConnection::MySQLConnection()
{
    conn = mysql_init(NULL);
    if (!conn)
    {
        std::cerr << "mysql_init() failed\n";
        return;
    }
    // Disable SSL
    int ssl_mode = SSL_MODE_DISABLED;
    mysql_options(conn, MYSQL_OPT_SSL_MODE, &ssl_mode);
    conn = mysql_real_connect(conn, "localhost", "root", "your password", "fop_db2", 3306, NULL, 0);
    if (conn)
    {
    }
    else
    {
        std::cerr << "Connection failed: " << mysql_error(conn) << std::endl;
        exit(1); // Exit with an error code
    }
}

// get the singleton instance
MySQLConnection *MySQLConnection::getInstance()
{
    if (instance == nullptr)
    {
        instance = new MySQLConnection();
    }
    return instance;
}

// get raw MYSQL connection
MYSQL *MySQLConnection::getConn()
{
    return conn;
}
// execute a query
void MySQLConnection::executeQuery(const std::string &query)
{
    if (mysql_query(conn, query.c_str()))
    {
        std::cerr << "Query failed: " << mysql_error(conn) << std::endl;
    }
}
// fetch results from a query
std::vector<std::map<std::string, std::string>> MySQLConnection::fetchResults(const std::string &query)
{
    std::vector<std::map<std::string, std::string>> resultData;

    if (mysql_query(conn, query.c_str()))
    {
        std::cerr << "Query failed: " << mysql_error(conn) << std::endl;
        return resultData;
    }
    MYSQL_RES *result = mysql_store_result(conn);
    if (!result)
    {
        std::cerr << "Failed to retrieve result set: " << mysql_error(conn) << std::endl;
        return resultData;
    }
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
    {
        std::map<std::string, std::string> rowMap;
        int numFields = mysql_num_fields(result);
        MYSQL_FIELD *fields = mysql_fetch_fields(result);
        for (int i = 0; i < numFields; ++i)
        {
            std::string columnName = fields[i].name;
            std::string value = row[i] ? row[i] : "NULL";
            rowMap[columnName] = value;
        }
        resultData.push_back(rowMap);
    }
    mysql_free_result(result);
    return resultData;
}

// destructor to close the connection
MySQLConnection::~MySQLConnection()
{
    if (conn)
    {
        mysql_close(conn);
        std::cout << "Connection closed." << std::endl;
    }
}

// MYSQL *createConnection()
// {
//     MYSQL *conn = mysql_init(NULL);
//     if (!conn)
//     {
//         std::cerr << "mysql_init() failed\n";
//         return nullptr;
//     }

//     // Disable SSL
//     int ssl_mode = SSL_MODE_DISABLED;
//     mysql_options(conn, MYSQL_OPT_SSL_MODE, &ssl_mode);

//     std::cout << "Trying to connect...\n";

//     if (mysql_real_connect(conn, "localhost", "root", "getamaze09780922", "fop_db2", 3306, NULL, 0))
//     {
//         std::cout << "Connected to database!" << std::endl;

//         return conn;
//     }
//     else
//     {
//         std::cerr << "Connection failed: " << mysql_error(conn) << std::endl;
//         return nullptr;
//     }
// }

// void closeConnection(MYSQL *conn)
// {
//     if (conn)
//     {
//         mysql_close(conn);
//         std::cout << "Connection closed." << std::endl;
//     }
// }