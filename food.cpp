#include<vector>
#include<utility>
#include"ncurses.h"
#include"constants.h"
#include<experimental/random>

std::vector<std:: pair < int,int >>food_items{};
void AddFood(){
    int x=std::experimental::randint(1,LINES-2);
    int y=std::experimental::randint(1,COLS-2);
    food_items.push_back({x,y});
}


void InitFood(){
    food_items.clear();
    for(int i=0;i<kMaxFoodItems;i++){
       AddFood();
       
    }
}
bool ConsumeFood(int x,int y){
for(int i=0;i<kMaxFoodItems;i++){
   if(food_items[i] ==std::make_pair(x,y)){
       food_items.erase(food_items.begin()+i);
       AddFood();
    return true;
   }
}
return false;
}

void PrintFood(){
    int number_of_foods = food_items.size();
    for(int i=0;i<number_of_foods;i++){
        int x = food_items[i].first;
        int y = food_items[i].second;
        move(x,y);
        addstr("\u25cb");
    }
}
