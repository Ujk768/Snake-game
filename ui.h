#include<iostream>
#include<ncurses.h>

//Initializes the UI with different features.
void init_ui();
//prints the border all sides in UI with full block character
void print_border();
//closes ncurses mode 
void tear_down_ui();