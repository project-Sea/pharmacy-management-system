#include <iostream>
#include <ctime>

struct ExpiryDate
{
    int year;
    int month;
    int day;
};

bool isExpired(const ExpiryDate &expiry)
{
    // Get the current time
    std::time_t currentTime = std::time(nullptr);
    // Convert to local time
    std::tm *localTime = std::localtime(&currentTime);
    // Get the current year, month, and day
    int currentYear = localTime->tm_year + 1900; // tm_year is years since 1900
    int currentMonth = localTime->tm_mon + 1;    // tm_mon is months since January (0-11)
    int currentDay = localTime->tm_mday;         // tm_mday is the day of the month (1-31)

    // Check if the expiry date has passed
    if (expiry.year < currentYear)
    {
        return true;
    }
    else if (expiry.year == currentYear)
    {
        if (expiry.month < currentMonth)
        {
            return true;
        }
        else if (expiry.month == currentMonth)
        {
            return expiry.day < currentDay;
        }
    }
    return false;
}

// Get the current time
ExpiryDate getCurrentDate()
{
    std::time_t currentTime = std::time(nullptr);
    std::tm *localTime = std::localtime(&currentTime);
    ExpiryDate currentDate;
    currentDate.year = localTime->tm_year + 1900; // tm_year is years since 1900
    currentDate.month = localTime->tm_mon + 1;    // tm_mon is months since January (0-11)
    currentDate.day = localTime->tm_mday;         // tm_mday is the day of the month (1-31)
    return currentDate;
}

// Function to print the current date
void printCurrentDate()
{
    ExpiryDate currentDate = getCurrentDate();
    std::cout << "Current date: " << currentDate.year << "-" << currentDate.month << "-" << currentDate.day << std::endl;
}
int main()
{
    getCurrentDate();
    printCurrentDate();

    return 0;
}