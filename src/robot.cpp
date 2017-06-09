#include "robot.h"

Robot::Robot(){
  initRobot();
}

void Robot::initRobot(){
  x_pos = rand()%22;
  y_pos = rand()%14;
  direc = rand()%4;
}

void Robot::turnRight(){
  direc--;
  if(direc==-1){
    direc = 3;
  }
}

void Robot::turnLeft(){
  direc++;
  if(direc==4){
    direc = 0;
  }
}

void Robot::moveForward(){
  switch(direc){
    case 0: ++x_pos;
    break;
    case 1: ++y_pos;
    break;
    case 2: --x_pos;
    break;
    case 3: --y_pos;
    break;
  }
}

void Robot::moveBackward(){
  switch(direc){
    case 0: --x_pos;
    break;
    case 1: --y_pos;
    break;
    case 2: ++x_pos;
    break;
    case 3: ++y_pos;
    break;
  }
}

int Robot::getXPos(){
  return x_pos;
}

int Robot::getYPos(){
  return y_pos;
}

int Robot::getDirec(){
  return direc;
}

Hero::Hero(){
  initHero();
}

void Hero::initHero(){
  x_pos = 11;
  y_pos = 7;
  direc = 1;
}

void Hero::getInput(){
  char temp;
  switch(direc){
    case 0: temp = '>';
    break;
    case 1: temp = '^';
    break;
    case 2: temp = '<';
    break;
    case 3: temp = 'v';
    break;
  }

  char input;
  std::cout << "You are facing " << temp << ". Enter next move:" << std::endl;
  bool flag = false;

  while(!flag){
    std::cin >> input;
    switch(input){
      case 'w': moveForward();
      flag = true;
      break;
      case 'd': turnRight();
      flag = true;
      break;
      case 's': moveBackward();
      flag = true;
      break;
      case 'a': turnLeft();
      flag = true;
      break;
      default: std::cout << "Please enter W/A/S/D\n";
      break;
    }
  }
  std::cin.clear();
  std::cin.ignore(256,'\n');
}

void dispBoard(int numEnemy, Robot enemy[],Hero hero){
  system("clear");
  std::cout << "\n";
  for(int i = 0; i<14 ; i++){
    int flag = 0;

    for(int j = 0; j<22 ; j++){
      if((hero.getXPos()==j)&&(hero.getYPos()==(13-i))){
        std::cout << "\033[1;32mH\033[0m ";
        flag = 1;
      }

      for(int z = 0; z<numEnemy; z++){
        if((enemy[z].getXPos()==j)&&(enemy[z].getYPos()==(13-i))&&(flag==0)){
          if(enemy[z].getDirec()%2==0){
            std::cout << "\033[1;31mX\033[0m ";
          }
          else{
            std::cout << "\033[1;34mX\033[0m ";
          }

          flag = 1;
        }
      }

      if(flag==0){
        std::cout << "0 ";
      }
      flag = 0;
    }
    std::cout <<"\n";
  }
  dispRules(1);
}

bool isHeroOut(Hero hero){
  return ((hero.getXPos()<0)||(hero.getXPos()>21)||(hero.getYPos()<0)||(hero.getYPos()>13));
}

bool isHeroCaught(int numEnemy, Robot enemy[], Hero hero){
  int flag = 0;
  for(int i = 0; i<numEnemy; i++){
    if((enemy[i].getXPos() == hero.getXPos())&&(enemy[i].getYPos() == hero.getYPos())){
      flag++;
    }
  }
  return flag>0;
}

void enemyAI(int numEnemy, Robot all_enemy[], Robot& enemy, Hero& hero){
  int e_pos;
  int h_pos;
  int g_direc;

  if(abs(enemy.getXPos()-hero.getXPos())<abs(enemy.getYPos()-hero.getYPos())){
    e_pos = enemy.getYPos();
    h_pos = hero.getYPos();
    g_direc = 1;
  }
  else{
    e_pos = enemy.getXPos();
    h_pos = hero.getXPos();
    g_direc = 0;
  }

  if(h_pos>=e_pos){
    if(enemy.getDirec()==g_direc){
      enemy.moveForward();
      if(enemyCollision(numEnemy,all_enemy,enemy)){
        enemy.moveBackward();
      }
    }
    else if(enemy.getDirec()==g_direc+2){
      enemy.moveBackward();
      if(enemyCollision(numEnemy,all_enemy,enemy)){
        enemy.moveForward();
      }
    }
    else{
      enemy.turnRight();
    }
  }
  else{
    if(enemy.getDirec()==g_direc){
      enemy.moveBackward();
      if(enemyCollision(numEnemy,all_enemy,enemy)){
        enemy.moveForward();
      }
    }
    else if(enemy.getDirec()==g_direc+2){
      enemy.moveForward();
      if(enemyCollision(numEnemy,all_enemy,enemy)){
        enemy.moveBackward();
      }
    }
    else{
      enemy.turnLeft();
    }
  }
}

bool enemyCollision(int numEnemy, Robot all_enemy[], Robot curr_enemy){
  int flag = 0;
  for(int i = 0; i<numEnemy; i++){
    if((all_enemy[i].getXPos()==curr_enemy.getXPos())&&(all_enemy[i].getYPos()==curr_enemy.getYPos())){
      flag++;
    }
  }
  return flag>1;
}

void dispRules(int flag){
  if(flag == 0){
    std::cout << "\nGRIDCRAWLER\n";
    std::cout << "===========\n\n";
    std::cout << "1. This is a turn based game. You move first and then each enemy moves one after another.\n2. You,the hero H, starts in the middle of a 22x14 grid. Reach the edge without getting caught to win!\n\n";
  }
  else{
    std::cout << "\nUse W/A/S/D + Enter to move your hero H.\n\nW - Move Forward\nS - Move Backward\nD - Turn Right\nA - Turn Left\n\nRed enemies are facing ^ or v. Blue enemies are facing < or >.\n\n";
  }
}
