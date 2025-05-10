#ifndef SRC_H
#define SRC_H

// #define WIN32_LEAN_AND_MEAN
// #define NOMINMAX

// #include "medicine.h"
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <mysql.h> // / mysql.h is a header file that provides the MySQL C API.
void startProgram(MYSQL *conn);

void showInventoryMenu();
void showSalesMenu();
// void addMedicine();
// void updateMedicine();
// void checkExpiry();
// void searchMedicine();
// void processSale();
// void viewSalesReport();
// void loadingAnimation(const string &message);
#endif