
#include"ncurses.h"
#include"snake.h"
#include<vector>
#include<utility>
std::vector<std::pair<int,int>>snake{};
std::pair<int,int>snake_head{};
//if tail is index0
//remove item at 0th index
//add item at the end
int last_snake_x;
int last_snake_y;
void InitSnake(){
    //initial lenght and initial corrdinates
    snake.clear();
    snake.push_back({LINES/2,COLS/2});
    snake.push_back({LINES/2,(COLS/2)+1});
    snake.push_back({LINES/2,(COLS/2)+2});
    snake_head={LINES/2,COLS/2};
    last_snake_x=LINES/2;
    last_snake_y=COLS/2 +3;
    PrintSnake();

}
void PrintSnake(){
    for(int i=0;i<snake.size();i++){
        int x=snake[i].first;
        int y=snake[i].second;
        move(x,y);
        addstr("\u2588");
    }
}
std::pair<int,int> MoveSnake(int key){
    last_snake_x=snake[0].first;
    last_snake_y=snake[0].second;
//removing tail
snake.pop_back();
int previous_head_x=snake_head.first;
int previous_head_y=snake_head.second;
int next_head_x;
int next_head_y;
if(key==KEY_UP){
    next_head_x=previous_head_x-1;
    next_head_y=previous_head_y;
}else if(key==KEY_DOWN){
    next_head_x=previous_head_x+1;
    next_head_y=previous_head_y;
}else if(key==KEY_LEFT){
    next_head_x=previous_head_x;
    next_head_y=previous_head_y-1;
}else if(key==KEY_RIGHT){
    next_head_x=previous_head_x;
    next_head_y=previous_head_y+1;
}
    snake.insert(snake.begin(),{next_head_x,next_head_y});
    snake_head={next_head_x,next_head_y};
    return snake_head;
}

bool DetectCollission(){
//check if head of snake doesnt collide with boundary
//check if head of snake doesnt collide with itself
int head_x=snake[0].first;
int head_y=snake[0].second;
if(head_x==0 || head_x==LINES-1){
    return TRUE;
}
if(head_y==0||head_y==COLS-1){
    return TRUE;
}
for(int i=0;i<snake.size()-1;i++){
    if(snake[i]==std::make_pair(head_x,head_y)){
        return TRUE;
    }
}
return FALSE;
}

void GrowSnake(){
    snake.push_back(std::make_pair(last_snake_x,last_snake_y));
}