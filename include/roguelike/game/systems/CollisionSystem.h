/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_COLLISIONSYSTEM_H
#define ROGUELIKE_COLLISIONSYSTEM_H

#include <ECS/system/IteratingSystem.h>
#include <game/components/BoxColliderComponent.h>
#include <game/components/TransformComponent.h>

/**
 * Respond to calculate collisions of the all ColliderComponents
 */
class CollisionSystem : public ECS::IteratingSystem<CollisionSystem> {
  LOG_INIT("CollisionSystem");

 public:
  void PreProcessEntity(ECS::IEntity *entity, double dt) override;

  void ProcessEntity(ECS::IEntity *entity, double dt) override;

  bool FamilyFilter(ECS::IEntity const *entity) const override;
};

#endif  // ROGUELIKE_COLLISIONSYSTEM_H
