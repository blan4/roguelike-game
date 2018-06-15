/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_INTERVALITERATINGSYSTEM_H
#define ROGUELIKE_INTERVALITERATINGSYSTEM_H

#include <ECS/EntityManager.h>
#include "ECS/FamilyTypeID.h"
#include "ISystem.h"
namespace ECS {

/**
 * It's a combination of interval and iterating systems.
 *
 * @tparam T
 */
template<class T>
class IntervalIteratingSystem : public ISystem {
  friend class SystemManager;
  static const SystemTypeID STATIC_TYPE_ID;
  const double interval{};
  double currentTime{};

  void _PreUpdate(double dt) override {
      PreUpdate(dt);
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              PreProcessEntity(entity.second, dt);
          }
      }
      currentTime += dt; // Every PRE update increment timer
      if (currentTime >= interval) {
          _PreUpdateInterval(currentTime);
      }
  }

  void _Update(double dt) override {
      Update(dt);
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              ProcessEntity(entity.second, dt);
          }
      }
      if (currentTime >= interval) {
          _UpdateInterval(currentTime);
      }
  }

  void _PostUpdate(double dt) override {
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              PostProcessEntity(entity.second, dt);
          }
      }
      PostUpdate(dt);
      if (currentTime >= interval) {
          _PostUpdateInterval(currentTime);
          currentTime -= interval;  // Every POST update decrement timer
      }
  }

  void _PreUpdateInterval(double dt) {
      PreUpdateInterval(dt);
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              PreProcessEntityInterval(entity.second, dt);
          }
      }
  }
  void _UpdateInterval(double dt) {
      UpdateInterval(dt);
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              ProcessEntityInterval(entity.second, dt);
          }
      }
  }
  void _PostUpdateInterval(double dt) {
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              PostProcessEntityInterval(entity.second, dt);
          }
      }
      PostUpdateInterval(dt);
  }

 public:
  explicit IntervalIteratingSystem(const double interval) : interval(interval) {
      currentTime = 0;
  }

  const SystemTypeID GetTypeID() const override {
      return STATIC_TYPE_ID;
  }

  virtual void PreUpdate(double dt) {};
  virtual void Update(double dt) {};
  virtual void PostUpdate(double dt) {};

  virtual void PreProcessEntity(IEntity *entity, double dt) {};
  virtual void ProcessEntity(IEntity *entity, double dt) {};
  virtual void PostProcessEntity(IEntity *entity, double dt) {};

  virtual void PreUpdateInterval(double dt) {};
  virtual void UpdateInterval(double dt) {};
  virtual void PostUpdateInterval(double dt) {};

  virtual void PreProcessEntityInterval(IEntity *entity, double dt) {};
  virtual void ProcessEntityInterval(IEntity *entity, double dt) {};
  virtual void PostProcessEntityInterval(IEntity *entity, double dt) {};

  /**
   * Filter and pass only IEntities that satisfy the predicate.
   * @return true if satisfy and false otherwise.
   */
  virtual const bool FamilyFilter(IEntity *entity) const {
      return false;
  };
};

template<class T>
const ECS::SystemTypeID
    ECS::IntervalIteratingSystem<T>::STATIC_TYPE_ID = ECS::Internal::FamilyTypeID<ECS::ISystem>::Get<T>();

}

#endif //ROGUELIKE_INTERVALITERATINGSYSTEM_H
