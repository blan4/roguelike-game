/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_FAMILYTYPEID_H
#define ROGUELIKE_FAMILYTYPEID_H

#include "ECS/Platform.h"
namespace ECS::Internal {
template<class T>
class FamilyTypeID {
  static TypeID count;

 public:
  template<class U>
  static TypeID Get() {
    static const ECS::TypeID STATIC_TYPE_ID{count++};
    return STATIC_TYPE_ID;
  }

  static TypeID Get() {
    return count;
  }
};
}

#endif  // ROGUELIKE_FAMILYTYPEID_H
