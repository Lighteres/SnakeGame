#ifndef INCLUDE_SCENES_GAME_SCENE_H_
#define INCLUDE_SCENES_GAME_SCENE_H_

#include <controls.h>
#include <game_statistics.h>
#include <lib/ecs/engine.h>
#include <scenes/context.h>
#include <scenes/i_scene.h>

#include "scenes/scene_manager.h"

class GameScene : public IScene {
  const Engine engine{};
  const Controls& controls_;
  GameStatistics* gs_;

 public:
  GameScene(Context* ctx, const Controls& controls, GameStatistics* gs);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_SCENES_GAME_SCENE_H_
