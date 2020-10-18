#include "systems/tail_system.h"

#include <components/collider_component.h>
#include <components/movement_component.h>
#include <components/player_control_component.h>
#include <components/previous_transform_component.h>
#include <components/tail_component.h>
#include <components/texture_component.h>
#include <components/transform_component.h>
#include <lib/ecs/entity_manager.h>

static bool PlayerFilter(const Entity& entity) {
  return entity.Contains<PlayerControlComponent>();
}

void TailSystem::OnUpdate() {
  if ((gs_->score_ == 1) && (gs_->AddTail)) {
    for (auto& entity : GetEntityManager()) {
      if (PlayerFilter(entity)) {
        head_ = &entity;
        FirstTail();
        HandleTails();
      }
    }
  } else {
    HandleTails();
  }
}

void TailSystem::FirstTail() {
  if (gs_->AddTail) {
    auto tail = engine.GetEntityManager()->CreateEntity();
    auto ptc = head_->Get<PreviousTransformComponent>();
    tail->Add<TextureComponent>('*');
    tail->Add<TailComponent>();
    tail->Add<ColliderComponent>();

    tail->Add<TransformComponent>(ptc->pos_x, ptc->pos_y);
    tail->Add<PreviousTransformComponent>(gs_->pX, gs_->pY);
    gs_->tails[gs_->score_ - 1] = tail;
    gs_->AddTail = false;
    gs_->AddFruit = true;
  }
}
void TailSystem::HandleTails() {
  if ((gs_->AddTail) && (gs_->score_ > 1)) {
    auto tail = engine.GetEntityManager()->CreateEntity();
    auto entity_tail = gs_->tails[gs_->score_ - 2];
    auto ptc_tail = entity_tail->Get<PreviousTransformComponent>();
    // auto ptc = head_->Get<PreviousTransformComponent>();
    tail->Add<TextureComponent>('*');
    tail->Add<TailComponent>();
    tail->Add<ColliderComponent>();
    tail->Add<TransformComponent>(ptc_tail->pos_x, ptc_tail->pos_y);
    tail->Add<PreviousTransformComponent>(gs_->pX, gs_->pY);

    gs_->tails[gs_->score_ - 1] = tail;
    gs_->AddTail = false;
    gs_->AddFruit = true;
  }
}
