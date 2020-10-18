#ifndef INCLUDE_COMPONENTS_MOVEMENT_COMPONENT_H_
#define INCLUDE_COMPONENTS_MOVEMENT_COMPONENT_H_
#include <lib/ecs/component.h>

class MovementComponent : public IComponent {
 public:
  bool left_ = false;
  bool up_ = true;
  bool right_ = false;
  bool down_ = false;
  float speed = 0.2;

  explicit MovementComponent(float speed) : speed(speed) {}
};
#endif  // INCLUDE_COMPONENTS_MOVEMENT_COMPONENT_H_
