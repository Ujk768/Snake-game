#include<utility>
#ifndef SLITHER_SNAKE_H
#define SLITHER_SNAKE_H
void InitSnake();
void PrintSnake();
std::pair<int,int> MoveSnake(int key);
void GrowSnake();
bool DetectCollission();

#endif