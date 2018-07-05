/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_RECTANGLE_H
#define ROGUELIKE_RECTANGLE_H

#include <assert.h>
#include <core/vector2.h>

namespace Core {
class Rectangle {
  Vector2 leftUpper;
  Vector2 size;

 public:
  explicit Rectangle(const Vector2 leftUpper, const Vector2 size) : leftUpper(leftUpper), size(size) {
    assert(size.x >= 0);
    assert(size.y >= 0);
  }
  Vector2 const GetLeftUpper() const {
    return leftUpper;
  }
  Vector2 const GetSize() const {
    return size;
  }
  int GetX1() const {
    return leftUpper.x;
  }
  int GetY1() const {
    return leftUpper.y;
  }
  int GetX2() const {
    return leftUpper.x + GetWidth();
  }
  int GetY2() const {
    return leftUpper.y + GetHeight();
  }
  int GetWidth() const {
    return size.x;
  }
  int GetHeight() const {
    return size.y;
  }
};
}

#endif  // ROGUELIKE_RECTANGLE_H
