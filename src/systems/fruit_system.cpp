#include "systems/fruit_system.h"

#include <components/collider_component.h>
#include <components/texture_component.h>
#include <components/transform_component.h>

#include <random>
void FruitSystem::OnUpdate() {
  if (gs_->AddFruit) {
    if (gs_->score_ == 1000) {
      gs_->IsGameOver = true;
      gs_->IsGoodGameOver = true;
    }
    gs_->AddFruit = false;

    std::random_device rd;
    std::mt19937 mersenne(rd());
    auto fruit = engine.GetEntityManager()->CreateEntity();
    int x, y;
    if (gs_->score_ == 0) {
      x = mersenne() % (gs_->n_ - 3) + 1;
      y = mersenne() % 9 + 1;
    } else {
      while (true) {
        x = mersenne() % (gs_->n_ - 3) + 1;
        y = mersenne() % (gs_->m_ - 3) + 1;
        for (int i = 0; i < gs_->score_; i++) {
          auto tail = gs_->tails[i];
          auto tc = tail->Get<TransformComponent>();
          if ((tc->pos_x == x) && (tc->pos_y == y)) {
            continue;
          }
        }
        break;
      }
    }
    fruit->Add<TransformComponent>(x, y);
    fruit->Add<TextureComponent>('F');
    fruit->Add<ColliderComponent>();
  }
}
