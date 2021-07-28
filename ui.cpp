#include"ui.h"




void print_border(){
    
 
 for(int i=0;i<COLS;i++){
     move(0,i);
     printw("\u2588");
     move(LINES-1,i);
     printw("\u2588");
 }
 for(int i=0;i<LINES;i++){
     move(i,0);
     printw("\u2588");
     move(i,COLS-1);
     printw("\u2588");
 }
    refresh();
   
}
void init_ui(){
    setlocale(LC_ALL,"");//overide default locale
    initscr();//initializes ncurses mode
    curs_set(0);//hide cursor
    noecho();//prevents printing out what you typed
    cbreak();//generates an interupt when ctrl+c is pressed
    nodelay(stdscr,TRUE);//doesnt delay when waiting for input
    keypad(stdscr,TRUE);
    
    
}
void tear_down_ui(){
    endwin();
}