#ifndef UI_H
#define UI_H
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
void showMainMenu();
void showWelcomeScreen();
void showStartupAnimation();
void loadingAnimation(const std::string &);
void showInventoryMenu();
void showSalesMenu();
void addMedicine();
void updateMedicine();
void checkExpiry();
void searchMedicine();
void processSale();
void viewSalesReport();
#endif