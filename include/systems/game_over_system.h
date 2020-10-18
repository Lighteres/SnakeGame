#ifndef INCLUDE_SYSTEMS_GAME_OVER_SYSTEM_H_
#define INCLUDE_SYSTEMS_GAME_OVER_SYSTEM_H_

#include <game_statistics.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/system.h>
#include <scenes/context.h>

class GameOverSystem : public ISystem {
  GameStatistics* gs_;
  Context* ctx_;
 public:
  GameOverSystem(EntityManager *entityManager, SystemManager *systemManager, GameStatistics *gs, Context* ctx);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_SYSTEMS_GAME_OVER_SYSTEM_H_
