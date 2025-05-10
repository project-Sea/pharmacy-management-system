#ifndef SALES_H
#define SALES_H

#include <string>
#include <mysql.h>
#include <iostream>
#include <vector>
void processSale();

// bool checkStock(int drugId, int quantity);
// double getUnitPrice(int drugId);
// std::string getDrugName(int drugId);
// bool updateStock(int drugId, int quantity);
// bool recordSale(int drugId, int quantity, double totalPrice);
// void viewSalesReport(std::string drugName, double unitPrice, int quantity, double total);

struct Sale
{
    int sale_id;
    int drug_id;
    int quantity_sold;
    double total_price;
    std::string sale_date;

    // Sale(int sale_id, int drug_id, int quantity_sold, double total_price, const std::string &sale_date)
    //     : sale_id(sale_id), drug_id(drug_id), quantity_sold(quantity_sold), total_price(total_price), sale_date(sale_date) {}
    // //: sale_id(sale_id) ~ this->sale_id = sale_id
};

std::vector<Sale> getAllSales();

#endif