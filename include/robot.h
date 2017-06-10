#ifndef ROBOT_H
#define ROBOT_H

#include<iostream>
#include<stdlib.h>

class Robot{
protected:
  int x_pos;
  int y_pos;
  int direc;

public:
  void moveForward();
  void moveBackward();
  void turnRight();
  void turnLeft();

  void initRobot();
  int getXPos();
  int getYPos();
  int getDirec();
  int collisions(int numEnemy, Robot all_enemy[]);
};

class Hero : public Robot{
public:
  Hero();
  void initHero();
  void getInput();
  bool isHeroOut();
  bool isHeroCaught(int numEnemy,Robot enemy[]);
};

class ChasingRobot : public Robot{
public:
  ChasingRobot();
  void chaseAI(int numEnemy, Robot all_enemy[], Hero hero);
};

void dispBoard(int numEnemy, Robot enemy[],Hero hero);
void dispRules(int flag);

#endif
