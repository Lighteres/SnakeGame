#ifndef INCLUDE_SYSTEMS_GAME_STATISTICS_SYSTEM_H_
#define INCLUDE_SYSTEMS_GAME_STATISTICS_SYSTEM_H_

#include <game_statistics.h>
#include <lib/ecs/system.h>

class GameStatisticsSystem : public ISystem {
 private:
  GameStatistics* gs_;

 public:
  GameStatisticsSystem(EntityManager* entity_manager, SystemManager* system_manager, GameStatistics* gs);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_SYSTEMS_GAME_STATISTICS_SYSTEM_H_
