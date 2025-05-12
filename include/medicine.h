#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "db_connection.h"
#include <vector>
#include <ctime>
#include <limits>
class Medicine
{
private:
    long long quantity, price_sale, price_purchase;
    std::string name, expiryDate, category;

public:
    static void addMedicine();
    static void updateMedicine();
    static void getAllMedicines();
    
};
void searchMedicine();
void addNewMedicine();
void updateMedicine();
void updateMedicineInfo();
void showAllMedicines();
void displayDrugsTable(MYSQL_RES *result);
#endif
