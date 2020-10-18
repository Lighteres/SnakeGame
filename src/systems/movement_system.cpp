#include "systems/movement_system.h"

#include <components/player_control_component.h>
#include <components/previous_transform_component.h>

#include <cmath>

#include "components/movement_component.h"
#include "components/transform_component.h"
#include "lib/ecs/entity_manager.h"

int to_pos(float x) {
  return static_cast<int>(std::round(x));
}

void MovementSystem::OnUpdate() {
  for (auto &entity : GetEntityManager()) {
    if (entity.Contains<MovementComponent>()) {
      auto mc = entity.Get<MovementComponent>();
      auto tc = entity.Get<TransformComponent>();
      auto ptc = entity.Get<PreviousTransformComponent>();

      if (mc->up_) {
        gs_->y -= mc->speed * 0.6;
      }
      if (mc->down_) {
        gs_->y += mc->speed * 0.6;
      }
      if (mc->left_) {
        gs_->x -= mc->speed;
      }
      if (mc->right_) {
        gs_->x += mc->speed;
      }
      if (((abs(tc->pos_x - to_pos(gs_->x))) + ((abs(tc->pos_y - to_pos(gs_->y))) == 1)))  {
        if (gs_->score_ == 0) {
          gs_->pX = ptc->pos_x;
          gs_->pY = ptc->pos_y;
        } else if (gs_->score_ > 0) {
          auto tail = gs_->tails[gs_->score_ - 1];
          auto ttc = tail->Get<TransformComponent>();
          auto tptc = tail->Get<PreviousTransformComponent>();
          if (abs(ttc->pos_x - gs_->pX) + abs(ttc->pos_y - gs_->pY) > 1) {
            gs_->pX = tptc->pos_x;
            gs_->pY = tptc->pos_y;
          }
        }
        ptc->pos_x = tc->pos_x;
        ptc->pos_y = tc->pos_y;
        tc->pos_x = to_pos(gs_->x);
        tc->pos_y = to_pos(gs_->y);
        if (gs_->score_ > 0) {
          // auto ptc = head_->Get<PreviousTransformComponent>();
          for (int i = 0; i < gs_->score_; i++) {
            auto current_tail = gs_->tails[i];
            auto cttc = current_tail->Get<TransformComponent>();
            auto ctptc = current_tail->Get<PreviousTransformComponent>();
            if (i == 0) {
              ctptc->pos_x = cttc->pos_x;
              ctptc->pos_y = cttc->pos_y;
              cttc->pos_x = ptc->pos_x;
              cttc->pos_y = ptc->pos_y;
            } else {
              auto previous_tail = gs_->tails[i - 1];
              auto ptptc = previous_tail->Get<PreviousTransformComponent>();
              ctptc->pos_x = cttc->pos_x;
              ctptc->pos_y = cttc->pos_y;
              cttc->pos_x = ptptc->pos_x;
              cttc->pos_y = ptptc->pos_y;
            }
          }
        }
      }
    }
  }
}
MovementSystem::MovementSystem(EntityManager *entity_manager, SystemManager *system_manager, GameStatistics *gs)
    : ISystem(entity_manager, system_manager), gs_(gs) {}
