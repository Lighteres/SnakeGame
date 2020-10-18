#include "systems/game_statistics_system.h"

#include <BearLibTerminal.h>
#include <components/previous_transform_component.h>
#include <components/transform_component.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>

#include <string>

static void PrintGold(int n) {
  std::string str = std::to_string(n);
  const char* charArray = str.c_str();
  terminal_print(1, 22, "Score:");
  terminal_print(8, 22, charArray);
}

GameStatisticsSystem::GameStatisticsSystem(EntityManager* entity_manager, SystemManager* system_manager,
                                           GameStatistics* gs)
    : ISystem(entity_manager, system_manager), gs_(gs) {}

void GameStatisticsSystem::OnUpdate() {
  PrintGold(gs_->score_);
}
