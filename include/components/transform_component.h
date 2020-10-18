#ifndef INCLUDE_COMPONENTS_TRANSFORM_COMPONENT_H_
#define INCLUDE_COMPONENTS_TRANSFORM_COMPONENT_H_
#include <lib/ecs/component.h>

class TransformComponent : public IComponent {
 public:
  int pos_x;
  int pos_y;

  TransformComponent(int posX, int posY) : pos_x(posX), pos_y(posY) {}
};
#endif  // INCLUDE_COMPONENTS_TRANSFORM_COMPONENT_H_
