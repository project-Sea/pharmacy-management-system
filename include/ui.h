#ifndef UI_H
#define UI_H
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <vector>
#include "sales.h"
void showMainMenu();
void showWelcomeScreen();
void showStartupAnimation();
void loadingAnimation(const std::string &);
void showInventoryMenu();
void showSalesMenu();
void processSale();
std::vector<Sale> getAllSales();
void addExpenses();
void addMedicine();
void updateMedicine();
void checkExpiry();
void searchMedicine();
void viewSalesReport();
#endif