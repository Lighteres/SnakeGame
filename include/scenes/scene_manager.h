#ifndef INCLUDE_SCENES_SCENE_MANAGER_H_
#define INCLUDE_SCENES_SCENE_MANAGER_H_

#include <map>
#include <memory>
#include <string>
#include "scenes/context.h"
#include "scenes/i_scene.h"

class SceneManager {
  const Context& ctx_;
  std::string current_scene_ = "";

 public:
  std::map<std::string, std::unique_ptr<IScene>> scenes_;
  explicit SceneManager(const Context& ctx);

  void OnRender();
  void OnExit() const;

  void Put(const std::string& name, IScene* scene);
};

#endif  // INCLUDE_SCENES_SCENE_MANAGER_H_
