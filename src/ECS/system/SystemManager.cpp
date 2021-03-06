/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#include <ECS/EntityManager.h>
#include <ECS/system/SystemManager.h>

namespace ECS {
SystemManager::SystemManager(const EntityManagerPtr &entityManager, const Event::EventDispatcherPtr &eventDispatcher,
                             IEngineControl *engineControl)
    : entityManager(entityManager), eventDispatcher(eventDispatcher), engineControl(engineControl) {
  LOG_INFO("SystemManager was initialized");
}

SystemManager::~SystemManager() {
  container.clear();
}

void SystemManager::Update(f64 delta) {
  // TODO: iterate over systems with some order which is set by priority property.

  for (auto system : container) {
    system.second->_PreUpdate(delta);
  }

  for (auto system : container) {
    system.second->_Update(delta);
  }

  for (auto system : container) {
    system.second->_PostUpdate(delta);
  }
}
void SystemManager::DestroyAllSystems() {
  for (auto system : container) {
    system.second->OnDestroy();
  }
  container.clear();
}
}