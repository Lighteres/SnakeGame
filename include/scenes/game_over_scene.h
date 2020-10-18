#ifndef INCLUDE_SCENES_GAME_OVER_SCENE_H_
#define INCLUDE_SCENES_GAME_OVER_SCENE_H_

#include <game_statistics.h>

#include "../controls.h"
#include "scenes/scene_manager.h"
#include "scenes/i_scene.h"

class GameOverScene : public IScene {
  const Controls& controls_;
  GameStatistics* gs_;

 public:
  GameOverScene(Context* ctx, const Controls& controls, GameStatistics* gs);
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_SCENES_GAME_OVER_SCENE_H_
