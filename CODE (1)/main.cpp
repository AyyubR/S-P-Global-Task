#include <iostream>
#include <vector>
#include <string>
#include "financeManager.cpp"

std::vector<FinanceManager> financeManagers; // Declare a vector to store FinanceManager objects

int main() {

  FinanceManager financeManager;
  financeManager.password();
  financeManager.menu();

  return 0;
}