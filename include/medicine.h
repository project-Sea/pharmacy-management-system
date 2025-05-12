#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>
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
    // void deleteMedicine(long long id);
    // void searchMedicine(long long id);
};
void searchMedicine();
void addNewMedicine();
void updateMedicine();
void updateMedicineInfo();
#endif
