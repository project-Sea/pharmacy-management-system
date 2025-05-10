#include "include/db_connection.h"
#include "include/src.h"
#include <iostream>

int main()
{

    MYSQL *conn = createConnection();
    if (!conn)
    {
        std::cerr << "Failed to create connection with mysql." << std::endl;
        return 1; // Exit with an error code
    }

    // start the program
    startProgram(conn);

    // Close the connection
    closeConnection(conn);
    system("pause");
    return 0;
}