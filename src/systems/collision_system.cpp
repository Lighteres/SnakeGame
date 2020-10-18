#include "systems/collision_system.h"

#include <components/collider_component.h>
#include <components/player_control_component.h>
#include <components/previous_transform_component.h>
#include <components/texture_component.h>
#include <components/transform_component.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>

#include <cmath>

static bool PlayerFilter(const Entity& entity) {
  return entity.Contains<PlayerControlComponent>();
}

static bool Filter(const Entity& entity) {
  return entity.Contains<ColliderComponent>() && entity.Contains<TransformComponent>();
}

static void HandleCollision(Entity* entity_1, Entity* entity_2, GameStatistics* gs) {
  auto tc2 = entity_2->Get<TextureComponent>();
  if ((tc2->symbol_ == '#') || (tc2->symbol_ == '*')) {
    gs->IsGameOver = true;
  } else if (tc2->symbol_ == 'F') {
    entity_2->Delete<TextureComponent>();
    entity_2->Delete<ColliderComponent>();
    gs->score_++;
    gs->AddTail = true;
    // gs->AddFruit = true;
  }
}

static void Collide(Entity* entity_1, Entity* entity_2, GameStatistics* gs) {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  auto tc1 = entity_1->Get<TransformComponent>();
  auto tc2 = entity_2->Get<TransformComponent>();

  if (tc1->pos_x == tc2->pos_x && tc1->pos_y == tc2->pos_y) {
    HandleCollision(entity_1, entity_2, gs);
  }
}

CollisionSystem::CollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                 GameStatistics* gs)
    : ISystem(entity_manager, system_manager), gs_(gs) {}

void CollisionSystem::OnUpdate() {
  for (auto& entity_1 : GetEntityManager()) {
    if (PlayerFilter(entity_1)) {
      for (auto& entity_2 : GetEntityManager()) {
        if (Filter(entity_2)) {
          Collide(&entity_1, &entity_2, gs_);
        }
      }
    }
  }

}
