#ifndef INCLUDE_SCENES_TITLE_SCENE_H_
#define INCLUDE_SCENES_TITLE_SCENE_H_

#include <game_statistics.h>
#include <lib/ecs/engine.h>

#include "../controls.h"
#include "scenes/i_scene.h"
#include "scenes/scene_manager.h"

class TitleScene : public IScene {
  const Engine engine{};
  const Controls& controls_;
  GameStatistics* gs_;

 public:
  TitleScene(Context* ctx, const Controls& controls, GameStatistics* gs);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_SCENES_TITLE_SCENE_H_
