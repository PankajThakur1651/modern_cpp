//
// Created by ubuntu on 30.05.24.
//

#ifndef MODERN_CPP_COMPOSITION_H
#define MODERN_CPP_COMPOSITION_H


#include <iostream>
#include <tuple>
#include <set>
#include <cassert>
#include <memory>

class Room {

private:

public:
    ~Room() {
        std::cout << "Room destructor \n";
    }

    Room() {
        std::cout << "Room constructor \n";
    }

    Room(Room const & /*obj*/) = delete;

    Room(Room && /*obj*/) noexcept = delete;

    Room &operator=(Room const & /*obj*/) = delete;

    Room &operator=(Room &&/*obj*/) noexcept = delete;
};

class House {
private:
    std::unique_ptr<Room> m_Room;

public:
    House();
    ~House();

    House(House const &/*obj*/) = delete;
    House(House &&obj) noexcept;

    House &operator=(House const &/*obj*/) = delete;

    House &operator=(House &&obj) noexcept = delete;

public:
    static House Create_obect() ;
};


#endif //MODERN_CPP_COMPOSITION_H
