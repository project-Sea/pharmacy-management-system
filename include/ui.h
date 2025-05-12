#ifndef UI_H
#define UI_H
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <vector>
#include "sales.h"
#include "expiryF.h"
#include "reports.h"
void showMainMenu();
void showWelcomeScreen();
void showStartupAnimation();
void loadingAnimation(const std::string &);
void showInventoryMenu();
void showSalesMenu();
void processSale();
void transactionLog();
std::vector<Sale> getAllSales();
//
void checkExpiryAll();
void addExpenses();
void checkExpiry();
void viewSalesReport();
#endif