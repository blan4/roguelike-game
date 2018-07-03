/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#ifndef ROGUELIKE_RENDERCOMPONENT_H
#define ROGUELIKE_RENDERCOMPONENT_H

#include <ECS/Component.h>

struct Texture1D {
  const char symbol;
  const int color;
  explicit Texture1D(const char symbol, const int color = 0) : symbol(symbol), color(color) {}
};

class RenderComponent : public ECS::Component<RenderComponent> {
 public:
  // TODO: we may need 2D textures fot big objects, like a wall or smth else.
  Texture1D texture;
  explicit RenderComponent(Texture1D texture) : texture(texture) {}
};

#endif //ROGUELIKE_RENDERCOMPONENT_H
