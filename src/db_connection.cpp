#include "../include/db_connection.h"

MYSQL *createConnection()
{
    MYSQL *conn = mysql_init(NULL);
    if (!conn)
    {
        std::cerr << "mysql_init() failed\n";
        return nullptr;
    }

    // Disable SSL
    int ssl_mode = SSL_MODE_DISABLED;
    mysql_options(conn, MYSQL_OPT_SSL_MODE, &ssl_mode);

    std::cout << "Trying to connect...\n";

    if (mysql_real_connect(conn, "localhost", "root", "0nyxx", "fop_db2", 3306, NULL, 0))
    {
        std::cout << "Connected to database!" << std::endl;

        return conn;
    }
    else
    {
        std::cerr << "Connection failed: " << mysql_error(conn) << std::endl;
        return nullptr;
    }
}

void closeConnection(MYSQL *conn)
{
    if (conn)
    {
        mysql_close(conn);
        std::cout << "Connection closed." << std::endl;
    }
}