//
// Created by ubuntu on 30.05.24.
//

#include "composition.h"

House::House() : m_Room(std::make_unique<Room>()) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

House::~House() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

House::House(House &&obj) noexcept {
  if (this != &obj) {
    m_Room = std::move(obj.m_Room);
    obj.m_Room = nullptr;
  }
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

House House::Create_obect() { return {}; }