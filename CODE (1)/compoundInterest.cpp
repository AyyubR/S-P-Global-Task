#include <iostream>
#include <string>
#include<cmath> //to allow me to square in equation
#include <iomanip> //outputs at 2dp

class CompoundInterest {
private:
  float initial;
  float rate;
  float years;

public:
  CompoundInterest(float initial, float rate, float years) : initial(initial), rate(rate), years(years) {
  }

  float getInitial() const {
    return initial;
  }
  float getRate() const {
    return rate;
  }
  float getYears() const {
    return years;
  }

  void calculate() const {

    float total = initial * pow((1 + rate / 100), years); //equation to calculate compound interest
    float returns = total - initial;
    
    std::cout << "\nInitial investment: £" << std::fixed << std::setprecision(2) << initial << std::endl;
    std::cout << "Total returns: £" << std::fixed << std::setprecision(2) << returns << std::endl;
    std::cout << "Total value: £" << std::fixed << std::setprecision(2) << total << std::endl;
  }
};