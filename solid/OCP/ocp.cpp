#include <iostream>

using namespace std;
// A software component should be extendable to add a new feature or to add a
// new behavior to it

// New feature getting added to the s/w component should NOT have to modify
// existing code

class Customer_profile {
public:
  virtual bool is_loyal_customer() = 0;

public:
  bool is_loyal;
};

class Vehicle_insurance_customer : public Customer_profile {
public:
  Vehicle_insurance_customer(bool loyal) { is_loyal = loyal; }

  bool is_loyal_customer() { return is_loyal; }
};

class Health_insurance_customer : public Customer_profile {
public:
  Health_insurance_customer(bool loyal) { is_loyal = loyal; }

  bool is_loyal_customer() { return is_loyal; }
};

class Insurance_premium_discount_calculator {
public:
  int calculate_premium_discount(Customer_profile &cs) {
    if (cs.is_loyal_customer()) {
      return 20;
    }
    return 0;
  }
};

int main() {
  Health_insurance_customer health_insurance_customer(true);
  Insurance_premium_discount_calculator insurance_premium_calculator;
  std::cout << "Premium Discount is: "
            << insurance_premium_calculator.calculate_premium_discount(
                   health_insurance_customer)
            << std::endl;

  Vehicle_insurance_customer vehicle_insurance_customer(false);
  std::cout << "Premium Discount is: "
            << insurance_premium_calculator.calculate_premium_discount(
                   vehicle_insurance_customer)
            << std::endl;
}
