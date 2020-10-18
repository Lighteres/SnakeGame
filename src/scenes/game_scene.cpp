#include "scenes/game_scene.h"

#include <components/collider_component.h>
#include <components/movement_component.h>
#include <components/player_control_component.h>
#include <components/previous_transform_component.h>
#include <components/tail_component.h>
#include <components/texture_component.h>
#include <components/transform_component.h>
#include <systems/collision_system.h>
#include <systems/fruit_system.h>
#include <systems/game_over_system.h>
#include <systems/game_statistics_system.h>
#include <systems/movement_system.h>
#include <systems/player_control_system.h>
#include <systems/rendering_system.h>
#include <systems/tail_system.h>

GameScene::GameScene(Context* ctx, const Controls& controls, GameStatistics* gs)
    : IScene(ctx), controls_(controls), gs_(gs) {}

char** GetMatrix(int n, int m, GameStatistics* gs) {
  char** matrix;
  matrix = new char*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new char[m];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i == 0) || (i == n - 1) || (j == 0) || (j == m - 1)) {
        matrix[i][j] = '#';
      } else {
        matrix[i][j] = '.';
      }
    }
  }
  matrix[30][14] = '@';
  return matrix;
}

void GameScene::OnCreate() {
  int n = 60;
  int m = 20;
  gs_->n_ = n;
  gs_->m_ = m;
  char** matrix = GetMatrix(n, m, gs_);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == '@') {
        auto head = engine.GetEntityManager()->CreateEntity();
        head->Add<PlayerControlComponent>(TK_UP, TK_RIGHT, TK_LEFT, TK_DOWN);
        head->Add<TransformComponent>(i, j);
        head->Add<PreviousTransformComponent>(i, j);
        head->Add<TextureComponent>('@');
        head->Add<MovementComponent>(gs_->speed);
        gs_->x = i;
        gs_->y = j;
        gs_->pX = i;
        gs_->pY = j;
      }
      if (matrix[i][j] == '#') {
        auto wall = engine.GetEntityManager()->CreateEntity();
        wall->Add<TransformComponent>(i, j);
        wall->Add<TextureComponent>('#');
        wall->Add<ColliderComponent>();
      }
    }
  }
  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>();
  sys->AddSystem<MovementSystem>(gs_);
  sys->AddSystem<PlayerControlSystem>(controls_, gs_);
  sys->AddSystem<CollisionSystem>(gs_);
  sys->AddSystem<GameOverSystem>(gs_, ctx_);
  sys->AddSystem<GameStatisticsSystem>(gs_);
  sys->AddSystem<TailSystem>(gs_, engine);
  sys->AddSystem<FruitSystem>(gs_, engine);
}
void GameScene::OnRender() {
  engine.OnUpdate();
}
void GameScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
