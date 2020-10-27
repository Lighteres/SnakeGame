#include "systems/player_control_system.h"

#include <components/movement_component.h>
#include <components/player_control_component.h>
#include <components/transform_component.h>

#include "lib/ecs/entity_manager.h"

PlayerControlSystem::PlayerControlSystem(EntityManager *entity_manager, SystemManager *system_manager,
                                         const Controls &controls, GameStatistics *gs)
    : ISystem(entity_manager, system_manager), controls_(controls), gs_(gs) {}

static bool Filter(const Entity& entity) {
  return entity.Contains<PlayerControlComponent>();
}

void PlayerControlSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      OnUpdateEntity(&entity, gs_);
    }
  }

}

void PlayerControlSystem::OnUpdateEntity(Entity *entity, GameStatistics *gs) const {
  auto mc = entity->Get<MovementComponent>();
  auto pcc = entity->Get<PlayerControlComponent>();

  if ((controls_.IsPressed(pcc->up_button_)) && !(mc->down_)) {
    mc->right_ = false;
    mc->left_ = false;
    mc->down_ = false;
    mc->up_ = true;
  }
  if ((controls_.IsPressed(pcc->right_button_)) && !(mc->left_)) {
    mc->up_ = false;
    mc->left_ = false;
    mc->down_ = false;
    mc->right_ = true;
  }
  if ((controls_.IsPressed(pcc->left_button_)) && !(mc->right_)) {
    mc->up_ = false;
    mc->right_ = false;
    mc->down_ = false;
    mc->left_ = true;
  }
  if ((controls_.IsPressed(pcc->down_button_)) && !(mc->up_)) {
    mc->up_ = false;
    mc->right_ = false;
    mc->left_ = false;
    mc->down_ = true;
  }
}