#ifndef INCLUDE_SYSTEMS_FRUIT_SYSTEM_H
#define INCLUDE_SYSTEMS_FRUIT_SYSTEM_H

#include <game_statistics.h>
#include <lib/ecs/engine.h>
#include <lib/ecs/system.h>

class Entity;

class FruitSystem : public ISystem {
  GameStatistics *gs_;
  const Engine& engine{};
 protected:
  void OnUpdate() override;
 public:
  FruitSystem(EntityManager *entityManager, SystemManager *systemManager, GameStatistics *gs, const Engine& engine)
  : ISystem(entityManager, systemManager), gs_(gs), engine(engine) {}
};

#endif  // INCLUDE_SYSTEMS_FRUIT_SYSTEM_H
