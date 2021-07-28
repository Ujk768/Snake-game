#include<chrono>
#include"constants.h"
#include"ui.h"
#include"snake.h"
#include"game.h"
#include"food.h"

using namespace std;
int key =ERR;
void event_loop(){
    auto last_time=chrono::system_clock::now();
    auto current_time=chrono::system_clock::now();
    int delta_t;
   
    while(true){
        current_time=chrono::system_clock::now();
        delta_t=chrono::duration_cast<chrono::milliseconds>(current_time-last_time).count();
        if(delta_t>TICK_INTERVAL){
            int k = getch();
            if(k!=ERR){
                key=k;
            }
            tick(key);
            refresh();
            last_time=current_time;
        }
    }
}
int main(){
  
    init_ui();
    event_loop();
    tear_down_ui();
    return 0;
}