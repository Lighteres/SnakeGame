#ifndef INCLUDE_COMPONENTS_PREVIOUS_TRANSFORM_COMPONENT_H_
#define INCLUDE_COMPONENTS_PREVIOUS_TRANSFORM_COMPONENT_H_

#include <lib/ecs/component.h>

class PreviousTransformComponent : public IComponent {
 public:
  int pos_x;
  int pos_y;

  PreviousTransformComponent(int posX, int posY) : pos_x(posX), pos_y(posY) {}
};
#endif  // INCLUDE_COMPONENTS_PREVIOUS_TRANSFORM_COMPONENT_H_
