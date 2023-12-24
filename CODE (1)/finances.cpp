#include <iostream>
#include <string>
#include <iomanip> //outputs at 2dp

class Finance { //class to store finance data
private:
  float income;
  float tax;
  float essential;
  float extra;

public:
  Finance(float income, float tax, float essential, float extra) : income(income), tax(tax), essential(essential), extra(extra) {
    //Constructor to initialize the variables
  }

  float getIncome() const { //method to get the var for later use
    return income;
  }
  float getTax() const {
    return tax;
  }
  float getEssential() const {
    return essential;
  }
  float getExtra() const {
    return extra;
  }
  //calculation methods
  float calculateNetIncome() const {
    return income - (income * tax / 100);
  }
  float taxPaid() const {
    return income * tax / 100;
  }
  void financeReport() const { //make report using data and results from calculations 
    float taxes = taxPaid();
    float netIncome = calculateNetIncome();
    
    std::cout << "\nFinancial Report:" << "\n"; //feedback from data
    std::cout << "\nCurrent Budget:" << "\n";
    std::cout << "Total Tax Paid: £" << std::fixed << std::setprecision(2) << taxes << "\n"; //rounded to 2dp
    std::cout << "Total Income: £" << std::fixed << std::setprecision(2) << netIncome << "\n";
    std::cout << "Total Expenses: £" << std::fixed << std::setprecision(2) << (essential + extra) << "\n";
    std::cout << "Amount Left: £" << std::fixed << std::setprecision(2) << (netIncome - (essential + extra)) << "\n";
  
    std::cout << "\nRecommended Budget:" << "\n"; //recommendations
    std::cout << "Needs(50%): £" << std::fixed << std::setprecision(2) << (netIncome * 0.5) << "\n"; 
    std::cout << "Wants(30%): £" << std::fixed << std::setprecision(2) << (netIncome * 0.3) << "\n";
    std::cout << "Savings(20%): £" << std::fixed << std::setprecision(2) << (netIncome * 0.2) << "\n";
  }
};