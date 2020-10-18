#ifndef INCLUDE_SYSTEMS_MOVEMENT_SYSTEM_H_
#define INCLUDE_SYSTEMS_MOVEMENT_SYSTEM_H_

#include <controls.h>
#include <game_statistics.h>
#include <lib/ecs/system.h>

class Entity;

class MovementSystem : public ISystem {
  GameStatistics* gs_;

 public:
  MovementSystem(EntityManager* entity_manager, SystemManager* system_manager, GameStatistics* gs);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_SYSTEMS_MOVEMENT_SYSTEM_H_
