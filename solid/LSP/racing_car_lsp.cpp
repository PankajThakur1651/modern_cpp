//
// Created by ubuntu on 21.06.24.
//
#include "racing_car_lsp.h"
using namespace lsp_good_example;

double Car_lsp::get_cabin_width() { return 5; }

double Car_lsp::get_interior_width() { return this->get_cabin_width(); }

double Racing_car_lsp::get_cockpit_width() { return 11; }

double Racing_car_lsp::get_interior_width() {

  return this->get_cockpit_width();
}