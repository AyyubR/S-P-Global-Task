#include <iostream>
#include <limits>
#include <sstream>  // Include for string stream


template <typename T> // Template to allow for different types of data
class ValidInput {
private:
  T userInput; //variable for user input
  std::string prompt; //message to diplay to terminal


public:
  ValidInput(std::string prompt) : prompt(prompt){} //messsage can be customised with consturctor

  T getValidInput() { //method to validate user input
    while (true) {
      std::cout << prompt; //output message
      std::cin >> userInput; 
  
      if (std::cin.fail()) {
        std::cin.clear();  // Clear the error 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //Remove invalid input
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
      } 
      else {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //Remove extra input
        break;  // Exit the loop if input is valid
      }
    }
    return userInput; //after loop return the input190
  }

  // Add method to get valid date input in the format DD/MM/YYYY
  T getValidDateInput() {
    while (true) {
      std::cout << prompt;
      std::string userInputStr;
      std::getline(std::cin, userInputStr); // Use getline to read the entire line

      std::istringstream iss(userInputStr); //creates a string stream object from the user input

      int day, month, year;
      char delimiter;
      
      if (iss >> day >> delimiter >> month >> delimiter >> year && //checks if follows format (DD/MM/YYYY)
        delimiter == '/' &&
        (day >= 1 && day <= 31) &&
        (month >= 1 && month <= 12) && //will not work to identify months that have less than 31 days eg feb30
        (year >= 1900 && year <= 2024)) { //between 1900 and 2024
        userInput = userInputStr;
        break;  // Exit the loop if input is a valid date
      } 
      else {
        std::cin.clear();
        std::cout << "Invalid date format. Please enter a date in DD/MM/YYYY format." << std::endl;
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }
    return userInput;
  }
};

