#ifndef UI_H
#define UI_H
#include <iostream>
using namespace std;
#include <iomanip>
#include <windows.h>
void showMainMenu();
void showWelcomeScreen();
void showStartupAnimation();
void loadingAnimation(const string &);
void showInventoryMenu();
void showSalesMenu();
void addMedicine();
void updateMedicine();
void checkExpiry();
void searchMedicine();
void processSale();
void viewSalesReport();
#endif