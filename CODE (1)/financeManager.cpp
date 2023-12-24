#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip> //outputs at 2dp
#include "finances.cpp" // Include the header file for the Finance class
#include "transactions.cpp" // Include the header file for the Transaction class
#include "compoundInterest.cpp" // Include the header file for the CompoundInterest class
#include "validInput.cpp"

class FinanceManager {
private:
  std::vector<Finance> finances; // Declare a vector to store Finance objects
  std::vector<Transaction> transactions; // Declare a vector to store Transaction objects
  std::vector<CompoundInterest> compoundInterests; // Declare a vector to store CompoundInterest objects
  std::vector<ValidInput<float>> validInput;

public:
  void inputFinance() { //method for user to input data 
    float income, tax, essential, extra; //local var for parameters for class

    ValidInput<float> validInputIncome("\nEnter your monthly income: £"); //makes an instance of valid input using the following prompt to display to terminal
    income = validInputIncome.getValidInput();  //uses input from user checks if valid if true returns input
    
    ValidInput<float> validInputTax("\nEnter the percentage taxed on your income (0 - 100%): ");
    tax = validInputTax.getValidInput(); 
    
    ValidInput<float> validInputEssential("\nEnter your monthly essential expenses: £");
    essential = validInputEssential.getValidInput(); 
    
    ValidInput<float> validInputExtra("\nEnter your monthly extra Expenses: £");
    extra = validInputExtra.getValidInput(); 

    Finance finance(income, tax, essential, extra); //inputs stored in variables then used to make instance of finance class
    finances.push_back(finance); //push element into vector
    std::cout << "Finances added successfully." << std::endl;
  }

  void addTransaction() { //method for user to store transactions
    float amount;
    std::string comment, date;
    
    ValidInput<float> validInputAmount("\nEnter the amount: £");
    amount = validInputAmount.getValidInput(); 
    
    std::cout << "Enter the comment: ";
    std::getline(std::cin >> std::ws, comment);  // Read the entire line including whitespaces
    
    ValidInput<std::string> validInputDate("Enter the date (DD/MM/YYYY): ");
    date = validInputDate.getValidDateInput();

    Transaction transaction(amount, comment, date);
    transactions.push_back(transaction);
    std::cout << "Transaction added successfully." << std::endl;
  }

  float netIncome() const {
    if (finances.empty()) { //if no data been added by user no objects
      std::cerr << "No finances added." << std::endl;
      return 0;
    }
    else {
      const Finance& finance = finances.back(); //retrives the last stored finance object (newest inputted data)
      return finance.calculateNetIncome(); //returns income after tax deductions
    }
  }

  void compoundIntCalc() { //calculate compound interest method
    float initial, rate, years;
    
    std::cout << "\nCompound Interest Calculator:" << std::endl;
    ValidInput<float> validInputInitial("\nEnter initial investment: ");
    initial = validInputInitial.getValidInput(); 
    
    ValidInput<float> validInputRate("Enter annual interest rate (%): ");
    rate = validInputRate.getValidInput(); 
    
    ValidInput<float> validInputYears("Enter number of years: ");
    years = validInputYears.getValidInput(); 
    
    CompoundInterest compoundInterest(initial, rate, years);
    compoundInterests.push_back(compoundInterest);
    return compoundInterest.calculate(); //use user inputs into calculation
  }

  float report() const {
    if (finances.empty()) { //no finances added
      std::cerr << "No finances added." << std::endl;
      displayTransactions(); //displays all transactions
      return 0;
    }
    else {
      const Finance& finance = finances.back();
      finance.financeReport(); //displays finance report in Finance class
      displayTransactions();
      return 0;
    }
  }

  void displayTransactions() const {
    if (transactions.empty()) { //no transactions added
      std::cerr << "No transactions added." << std::endl;
      return;
    }
    else {
      std::cout << "\nTransaction List:" << std::endl;
      int transactionNum = 1;
      for (const Transaction& transaction : transactions) { //loop to go through each element in tracsactions vector
        transaction.displayTransaction(transactionNum);
        transactionNum++; //increment to display next transaction
      }
      std::cout << "End of Report" << std::endl;
    }
  }

  void password() const { //method for password before access to menu
    std::string password;
    
    while (true) {
      std::cout << "\nEnter Password: ";
      std::cin >> password;

      if (password == "1234") {
        std::cout << "Success" << std::endl;
        break;
      } 
      else {
        std::cout << "\nIncorrect. Please try again\nHint: 1234" << std::endl;
      }
    }
  }

  void menu() {
    int choice;
    
    while (true) {
      std::cout << "\nPersonal Finance Manager Menu:" << "\n";
      std::cout << "1. Input your monthly income and expenditures" << "\n";
      std::cout << "2. Add a transaction" << "\n";
      std::cout << "3. Calculate your total income" << "\n";
      std::cout << "4. Calculate Compound Interest Returns" << "\n";
      std::cout << "5. Generate your financial report" << "\n";
      std::cout << "6. Quit" << "\n";
  
      ValidInput<int> validInputChoice("Enter your choice: ");
      choice = validInputChoice.getValidInput(); 
  
      switch (choice) {
        case 1:
          inputFinance();
          break;
        case 2:
          addTransaction();
          break;
        case 3: {
          float net = netIncome();
          std::cout << "Net Income after taxes: £" << std::fixed << std::setprecision(2) << net << std::endl; //displays net income after taxes rounded to 2DP
          break;
        }
        case 4:
          compoundIntCalc();
          break;
        case 5:
          report();
          break;
        case 6:
          password();
          break;
      }
    }
  }
};



