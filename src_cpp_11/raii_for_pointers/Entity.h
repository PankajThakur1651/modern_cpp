//
// Created by ubuntu on 03.06.24.
//

#ifndef MODERN_CPP_ENTITY_H
#define MODERN_CPP_ENTITY_H
class Entity {

public:
  Entity(int x);
  ~Entity();
  Entity(Entity const &obj) = delete;
  Entity &operator=(Entity const &obj) = delete;

  Entity(Entity &&obj) noexcept = delete;
  Entity &operator=(Entity &&obj) noexcept = delete;

private:
  int *ptr;
};
#endif // MODERN_CPP_ENTITY_H
