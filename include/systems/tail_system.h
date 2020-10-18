#ifndef INCLUDE_SYSTEMS_TAIL_SYSTEM_H
#define INCLUDE_SYSTEMS_TAIL_SYSTEM_H

#include <game_statistics.h>
#include <lib/ecs/engine.h>
#include <lib/ecs/system.h>

class Entity;

class TailSystem : public ISystem {
  GameStatistics *gs_;
  Entity* head_;
  const Engine& engine{};
  void FirstTail();
  void HandleTails();


 protected:
  void OnUpdate() override;

 public:
  TailSystem(EntityManager *entityManager, SystemManager *systemManager, GameStatistics *gs, const Engine& engine)
      : ISystem(entityManager, systemManager), gs_(gs), engine(engine) {}
};

#endif  // INCLUDE_SYSTEMS_TAIL_SYSTEM_H
