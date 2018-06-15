/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_SYSTEM_H
#define ROGUELIKE_SYSTEM_H

#include "ECS/FamilyTypeID.h"
#include "ISystem.h"
#include "IUpdate.h"
namespace ECS {

/**
 * General System. Update commands will be called on every world update.
 * If you need iterates over Entities, use IteratingSystem.
 *
 * @tparam T
 */
template<class T>
class System : public ISystem {
  friend class SystemManager;
  static const SystemTypeID STATIC_TYPE_ID;
 public:
  const SystemTypeID GetTypeID() const override {
      return STATIC_TYPE_ID;
  }

 private:
  void _PreUpdate(double dt) override { PreUpdate(dt); };
  void _Update(double dt) override { Update(dt); };
  void _PostUpdate(double dt) override { PostUpdate(dt); };
 public:

  virtual void PreUpdate(double dt) {};
  virtual void Update(double dt) {};
  virtual void PostUpdate(double dt) {};
};

template<class T>
const ECS::SystemTypeID ECS::System<T>::STATIC_TYPE_ID = ECS::Internal::FamilyTypeID<ECS::ISystem>::Get<T>();

}

#endif //ROGUELIKE_SYSTEM_H