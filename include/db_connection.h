#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H
#include <mysql.h>
#include <string>
#include <vector>
#include <map>

// MYSQL *createConnection();
// void closeConnection(MYSQL *); // Close the connection
class MySQLConnection
{
private:
    MYSQL *conn;
    static MySQLConnection *instance; // singleton instance

    // private constructor
    MySQLConnection();

public:
    static MySQLConnection *getInstance();                                                  // get the singleton instance
    MYSQL *getConn();                                                                       // access raw connection
    void executeQuery(const std::string &query);                                            // execute a query
    std::vector<std::map<std::string, std::string>> fetchResults(const std::string &query); // fetch results from a query
    ~MySQLConnection();                                                                     // destructor to close the connection
};
#endif
// This header file declares the function connectToDatabase, which is used to establish a connection to a MySQL database.