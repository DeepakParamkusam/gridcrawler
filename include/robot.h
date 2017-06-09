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
  Robot();
  void moveForward();
  void moveBackward();
  void turnRight();
  void turnLeft();

  void initRobot();
  int getXPos();
  int getYPos();
  int getDirec();
};

class Hero : public Robot{
public:
  Hero();
  void initHero();
  void getInput();
  bool isHeroOut();
  bool isHeroCaught(int numEnemy,Robot enemy[]);
};

void dispBoard(int numEnemy, Robot enemy[],Hero hero);
void enemyAI(int numEnemy, Robot all_enemy[], Robot& enemy, Hero& hero);
bool enemyCollision(int numEnemy, Robot all_enemy[], Robot enemy);
void dispRules(int flag);

#endif
