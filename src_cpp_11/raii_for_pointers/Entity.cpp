//
// Created by ubuntu on 03.06.24.
//

#include "Entity.h"
#include <iostream>

Entity::Entity(int x) : ptr(new int{x}) {
  std::cout << "Constructor called \n";
}

Entity::~Entity() {
  delete ptr;
  ptr = nullptr;
  std::cout << "Destructor called \n";
}