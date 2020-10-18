#ifndef INCLUDE_GAME_STATISTICS_H_
#define INCLUDE_GAME_STATISTICS_H_

#include <lib/ecs/entity.h>

#include <string>
class GameStatistics {
 public:
  Entity* tails[1044];
  int score_ = 0;
  int n_ = 0;
  int m_ = 0;
  bool IsGameOver = false;
  bool IsGoodGameOver = false;
  bool AddTail = false;
  bool AddFruit = true;
  bool IsEasy = true;
  bool IsMedium = false;
  bool IsHard = false;
  float x = 0;
  float y = 0;
  float speed = 0.1;
  int pX = 0;
  int pY = 0;
};
#endif  // INCLUDE_GAME_STATISTICS_H_
