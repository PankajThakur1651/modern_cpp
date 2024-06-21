//
// Created by ubuntu on 21.06.24.
//

#ifndef MODERN_CPP_RACING_CAR_LSP_H
#define MODERN_CPP_RACING_CAR_LSP_H

namespace lsp_good_example {

class Vehicle {
public:
  virtual double get_interior_width() = 0;
};

class Car_lsp : public Vehicle {

public:
  double get_interior_width() override;

private:
  double get_cabin_width();
};

class Racing_car_lsp : public Vehicle {
public:
  double get_interior_width() override;

private:
  double get_cockpit_width();
};
} // namespace lsp_good_example

#endif // MODERN_CPP_RACING_CAR_LSP_H
