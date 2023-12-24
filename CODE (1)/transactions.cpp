#include <iostream>
#include <string>
#include <iomanip> //outputs at 2dp

class Transaction {
private:
  float amount;
  std::string comment;
  std::string date;

public:
  Transaction(float amount, std::string comment, std::string date) : amount(amount), comment(comment), date(date) {
  }

  float getAmount() const {
    return amount;
  }
  const std::string& getComment() const {
    return comment;
  }
  const std::string& getDate() const {
    return date;
  }

  void displayTransaction(int num) const { //format to display transaction info
    std::cout << "Transaction " << num << "\n";
    std::cout << "Amount: £" << std::fixed << std::setprecision(2) << amount << "\n";
    std::cout << "Comment: " << comment << "\n";
    std::cout << "Date: " << date << "\n";
    std::cout << "---------------------" << "\n";
  }
};