#include "robot.h"

int main(){
  // Seed rand
  srand (time(NULL));

  // Display rules and request number of enemies
  int numEnemy;
  dispRules(0);
  std::cout << "Enter number of enemies:\n";
  std::cin >> numEnemy;

  // Makes sure input is an integer between 0-20. Then ignore newline character
  while(std::cin.fail()||numEnemy>20||numEnemy<0) {
    std::cout << "Invalid input. Please enter integer <= 15" << std::endl;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cin >> numEnemy;
  }
  std::cin.clear();
  std::cin.ignore(256,'\n');

  // Initialise objects
  Hero hero;
  Robot enemy[numEnemy];

  // Display board and start game
  dispBoard(numEnemy,enemy,hero);
  while(1){
    if(hero.isHeroOut()){
      std::cout << "You have won!\n";
      break;
    }
    else if(hero.isHeroCaught(numEnemy,enemy)){
      std::cout << "You lost!\n";
      break;
    }
    else{
      hero.getInput();
      for(int i = 0; i<numEnemy; i++){
        enemyAI(numEnemy,enemy,enemy[i],hero);
      }
      dispBoard(numEnemy,enemy,hero);
    }
  }

  return 0;
}
