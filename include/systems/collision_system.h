#ifndef INCLUDE_SYSTEMS_COLLISION_SYSTEM_H_
#define INCLUDE_SYSTEMS_COLLISION_SYSTEM_H_

#include <game_statistics.h>
#include <lib/ecs/system.h>
class CollisionSystem : public ISystem {
  GameStatistics* gs_;

 public:
  CollisionSystem(EntityManager* entity_manager, SystemManager* system_manager, GameStatistics* gs);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_SYSTEMS_COLLISION_SYSTEM_H_
