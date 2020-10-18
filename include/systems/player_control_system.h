#ifndef INCLUDE_SYSTEMS_PLAYER_CONTROL_SYSTEM_H
#define INCLUDE_SYSTEMS_PLAYER_CONTROL_SYSTEM_H

#include <controls.h>
#include <game_statistics.h>
#include <lib/ecs/system.h>

class Entity;

class PlayerControlSystem : public ISystem {
  const Controls& controls_;
  GameStatistics* gs_;
  void OnUpdateEntity(Entity* entity, GameStatistics* gs) const;

 protected:
  void OnUpdate() override;

 public:
  PlayerControlSystem(EntityManager* entity_manager, SystemManager* system_manager, const Controls& controls,
                    GameStatistics* gs);
};

#endif  // INCLUDE_SYSTEMS_PLAYER_CONTROL_SYSTEM_H
