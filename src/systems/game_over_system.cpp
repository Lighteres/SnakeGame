#include "systems/game_over_system.h"

#include <components/transform_component.h>
#include <lib/ecs/entity_manager.h>
GameOverSystem::GameOverSystem(EntityManager *entityManager, SystemManager *systemManager, GameStatistics *gs,
                               Context *ctx)
    : ISystem(entityManager, systemManager), gs_(gs), ctx_(ctx) {}

void GameOverSystem::OnUpdate() {
  if (gs_->IsGameOver) {
    ctx_->scene_ = "game_over";
    gs_->IsGameOver = false;
  }
}
