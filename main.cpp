#include "include/db_connection.h"
#include "include/src.h"
#include <iostream>

int main()
{

    startProgram();
    // clean up
    delete MySQLConnection::getInstance();
    return 0;
}