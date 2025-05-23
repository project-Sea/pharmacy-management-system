#include "../include/ui.h"
#include "../include/medicine.h"
#include "../include/reports.h"
void showMainMenu()
{
    int choice;

    do
    {
        system("cls");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t" << std::setfill('=') << std::setw(43) << "=" << std::endl;
        std::cout << "\t\t\t\t|     PHARMACY MANAGEMENT SYSTEM      |\n";
        std::cout << "\t\t\t\t" << std::setfill('=') << std::setw(43) << "=" << std::endl;
        std::cout << "\t\t\t\t| 1. Medicine Inventory Management    |\n";
        std::cout << "\t\t\t\t| 2. Sales & Financial Management     |\n";
        std::cout << "\t\t\t\t| 3. Exit System                      |\n";
        std::cout << "\t\t\t\t" << std::setfill('=') << std::setw(43) << "=" << std::endl;
        std::cout << "\n\t\t\t\tEnter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            showInventoryMenu();
            break;
        case 2:
            showSalesMenu();
            break;
        case 3:
            system("cls");
            system("COLOR A");
            std::cout << "\n\n\n\t\t\t\tThank you for using the system!\n";
            std::cout << "\t\t\t\tGoodbye!\n";
            Sleep(1500);
            break;
        default:
            std::cout << "\n\t\t\t\tInvalid choice! Try again.\n";
            Sleep(1000);
        }
    } while (choice != 3);
}

void showWelcomeScreen()
{
    system("cls");
    system("COLOR B");

    std::cout << "\n\n\n";
    std::cout << "\t\t\t\t####################################\n";
    std::cout << "\t\t\t\t#                                  #\n";
    std::cout << "\t\t\t\t#         Welcome to the           #\n";
    std::cout << "\t\t\t\t#     Pharmacy Management System   #\n";
    std::cout << "\t\t\t\t#                                  #\n";
    std::cout << "\t\t\t\t####################################\n";
    system("Pause");
    checkExpiry();
    system("COLOR B");
}

void showStartupAnimation()
{
    int bar1 = 177, bar2 = 219;
    std::cout << "\n\n\n\t\t\t\tChecking Expiring Dates...";
    std::cout << "\n\n\n\t\t\t\tLoading...";
    std::cout << "\n\n\n\t\t\t\t";

    for (int i = 0; i < 30; i++)
        std::cout << (char)bar1;
    std::cout << "\r\t\t\t\t";

    for (int i = 0; i < 30; i++)
    {
        std::cout << (char)bar2;
        Sleep(30);
    }

    system("cls");
}

void loadingAnimation(const std::string &message)
{
    system("cls");
    std::cout << "\n\n\t\t\t\t" << message;
    for (int i = 0; i < 3; i++)
    {
        std::cout << ".";
        Sleep(500); // Delay for 500 milliseconds
    }
    std::cout << std::endl;
}

void showInventoryMenu()
{
    int inventoryChoice;
    do
    {
        system("cls");
        system("COLOR B");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t|     Medicine Inventory Management   |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t| 1. Add New Medicine                 |\n";
        std::cout << "\t\t\t\t| 2. Update Medicine Details          |\n";
        std::cout << "\t\t\t\t| 3. get All Medicines               |\n";
        std::cout << "\t\t\t\t| 4. Check Expiry Dates               |\n";
        std::cout << "\t\t\t\t| 5. Search Medicines                 |\n";
        std::cout << "\t\t\t\t| 6. Return to Main Menu              |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\n\t\t\t\tEnter your choice: ";
        std::cin >> inventoryChoice;

        switch (inventoryChoice)
        {
        case 1:
            addNewMedicine();
            break;
        case 2:
            updateMedicineInfo();
            break;
        case 3:

            showAllMedicines();

            break;
        case 4:
            checkExpiry();
            break;
        case 5:
        {   
            loadingAnimation("Loading Search Medicines Page");
            system("cls");
            searchMedicine();
            break;
        }
        case 6:
            break;
        default:
            std::cout << "\n\t\t\t\tInvalid choice! Try again.\n";
            Sleep(1000);
        }
    } while (inventoryChoice != 6);
}

void showSalesMenu()
{
    int salesChoice;
    

    do
    {
        system("cls");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t|     Sales & Financial Management    |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t| 1. Process Sales Transaction        |\n";
        std::cout << "\t\t\t\t| 2. View Sales Reports               |\n";
        std::cout << "\t\t\t\t| 3. add expenses                     |\n";
        std::cout << "\t\t\t\t| 4. Transaction log                  |\n";
        std::cout << "\t\t\t\t| 5. Return to Main Menu              |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\n\t\t\t\tEnter your choice: ";
        std::cin >> salesChoice;

        switch (salesChoice)
        {
        case 1:
            processSale();
            break;
        case 2:
        {
            auto sales = getAllSales();

            std::cout << "\n\n\t\t\t\tSales Report\n";

            // for (const auto &s : sales)
            // {
            //     std::cout << "Sale ID: " << s.sale_id
            //               << ", Drug ID: " << s.drug_id
            //               << ", Quantity: " << s.quantity_sold
            //               << ", Total: $" << s.total_price
            //               << ", Date: " << s.sale_date << "\n";
            // }
            std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(50) << "-" << std::endl;
            std::cout << "\t\t\t\t| Sale ID | Drug ID | Quantity | Total Price |    Sale Date   |\n";
            std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(50) << "-" << std::endl;
            for (const auto &s : sales)
            {
                std::cout << "\t\t\t\t| " << std::setw(7) << s.sale_id
                          << " | " << std::setw(7) << s.drug_id
                          << " | " << std::setw(8) << s.quantity_sold
                          << " | " << std::setw(11) << "$" << std::fixed << std::setprecision(2) << s.total_price
                          << " | " << std::setw(10) << s.sale_date << " |\n";
            }
            break;
        }
        case 3:
            addExpenses();
            break;
        case 4:
            transactionLog();
            break;
        case 5:
            break;
        default:
            std::cout << "\n\t\t\t\tInvalid choice! Try again.\n";
            Sleep(1000);
        }
    } while (salesChoice != 5);
}

void addNewMedicine()
{
    loadingAnimation("Loading Add New Medicine Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tAdd New Medicine\n";
    Medicine::addMedicine();
    system("pause");
}
void showAllMedicines()
{
    loadingAnimation("Loading All Medicines Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tAll Medicines";
    Medicine::getAllMedicines();
    system("pause");
}

void updateMedicineInfo()
{
    loadingAnimation("Loading Update Medicine Details Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tUpdate Medicine Details";
    Medicine::updateMedicine();
    system("pause");
}

void checkExpiry()
{
    loadingAnimation("Loading Check Expiry Dates Page");
    system("cls");
    std::cout << "\n\n\t\t\t\tCheck Expiry Dates";
    checkExpiryAll();
    system("pause");
}

void transactionLog()
{
    loadingAnimation("Loading Transaction Log Page");
    system("cls");
    int TChoice;
    system("cls");

    do
    {
        std::cout << "\n\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t|     Transaction Log                 |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\t\t\t\t| 1. Daily Report                     |\n";
        std::cout << "\t\t\t\t| 2. Weekly Report                    |\n";
        std::cout << "\t\t\t\t| 3. Monthly Report                   |\n";
        std::cout << "\t\t\t\t| 4. Net Revenue Report               |\n";
        std::cout << "\t\t\t\t| 5. Return to Sales Menu             |\n";
        std::cout << "\t\t\t\t" << std::setfill('-') << std::setw(43) << "-" << std::endl;
        std::cout << "\n\t\t\t\tEnter your choice: ";
        std::cin >> TChoice;
        // C:\Users\HP\Documents\GitHub\Cpp resources and projects\fop_project
        switch (TChoice)
        {
        case 1:
            generateDailyReport();
            break;
        case 2:
            generateWeeklyReport();
            break;
        case 3:
            generateMonthlyReport();
            break;
        case 4:
            generateNetRevenueReport();
            break;
        case 5:
            break;
        }
    } while (TChoice != 5);
    // generateNetRevenueReport();
    //  Implement transaction log functionality here
    //  For example, you can read from a file or database and display the logs
    system("pause");
}