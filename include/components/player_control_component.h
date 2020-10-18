#ifndef INCLUDE_COMPONENTS_PLAYER_CONTROL_COMPONENT_H_
#define INCLUDE_COMPONENTS_PLAYER_CONTROL_COMPONENT_H_

#include <lib/ecs/component.h>

class PlayerControlComponent : public IComponent {
 public:
  int up_button_;
  int right_button_;
  int left_button_;
  int down_button_;

  PlayerControlComponent(int upButton, int rightButton, int leftButton, int downButton)
      : up_button_(upButton), right_button_(rightButton), left_button_(leftButton), down_button_(downButton) {}
};

#endif  // INCLUDE_COMPONENTS_PLAYER_CONTROL_COMPONENT_H_
