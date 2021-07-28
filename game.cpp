
#include"game.h"
#include"ui.h"
#include"ncurses.h"
#include"constants.h"
#include"food.h"
#include"snake.h"


int current_game_state = kStateGameNotStarted;
int current_score=0;
int current_direction=KEY_UP;

void PrintStatus(){
 if(current_game_state==kStateGameNotStarted){
 move((LINES/2),COLS/2);    
printw("UJK SNAKE GAME");
move((LINES/2)+1,(COLS/2)+1);
printw("Press any key to start");
 }
 if(current_game_state==kStateGameStarted){
      move(0,1);
      printw("Current Score: %d",current_score);
 }
}
void StartGame(){
     current_score=0;
     current_game_state=kStateGameStarted;
     current_direction=KEY_UP;
     erase();
     InitFood();
     InitSnake();
     PrintFood();
}

void tick(int key){
     if(current_game_state==kStateGameNotStarted){
     erase();
     print_border();
     PrintStatus();
     if(key!=ERR){
          StartGame();
     }
     }else{
     erase();
     std::pair<int,int>snake_head_cords;
     if(key==KEY_UP && current_direction!=KEY_DOWN){
       
          current_direction=KEY_UP;
     }else if(key==KEY_DOWN && current_direction!=KEY_UP){
     
          current_direction=KEY_DOWN;
     }else if(key==KEY_RIGHT && current_direction!=KEY_LEFT){
         
          current_direction=KEY_RIGHT;
     }else if(key==KEY_LEFT && current_direction!=KEY_RIGHT){
         
          current_direction=KEY_LEFT;
     }
     snake_head_cords=MoveSnake(current_direction); 

          if(key!=ERR){
          if (ConsumeFood(snake_head_cords.first,snake_head_cords.second)){
               GrowSnake();
               current_score+=1;
          }     
          }
     
     
     
     print_border();
     PrintStatus();
     PrintSnake();
     PrintFood();
     if(DetectCollission()){
          
          current_game_state=kStateGameNotStarted;
     }

}
}
     


