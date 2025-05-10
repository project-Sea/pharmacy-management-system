#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H
#include "mysql/mysql.h"
MYSQL *createConnection();
void closeConnection(MYSQL *); // Close the connection
#include <iostream>
using namespace std;
#endif
// This header file declares the function connectToDatabase, which is used to establish a connection to a MySQL database.