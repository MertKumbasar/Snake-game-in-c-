#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define height 15
#define width 30
using namespace std;

struct cor {
  int x;
  int y;
};
// function to move cursor to top
void gotoxy(int x, int y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
// function to move cursor to top


int main(){
    int i,j,k,m,print,dir_x=1,dir_y=0,size=4,score = 0,num = 10;;
    bool game_is_on = true;
    cor snake[50];
    cor food;
    srand(time(NULL)); 
    food.x = rand() % 18 + 1;
    food.y = rand() % 18 + 1;
    for(i=0; i <= 3; i++){
        snake[i].x = num;
        snake[i].y = 10;
        num --;
    }
    while(game_is_on){
        gotoxy(0,0);
        // print the game area
        for(i = 0; i < height; i++){
            for (j = 0; j < width; j++){
                print = 1;
                for(k = 0; k < size; k++){
                    if (snake[k].x == j && snake[k].y == i && k != size - 1){
                    	if(k==0){
                    		cout << "O";	
						}
						else{
							cout << "o";
						}
                        print = 0;
                    }
                    
                }
                if(i==0 || j == 0 || i == height-1 || j == width - 1){
                    cout << "#";
                }
                else if(i == food.y && j == food.x ){
                    cout << "F";
                }
                else{
                    if (print == 1){
                        cout << ".";
                    }
                    
                }
            }
            cout << endl;
        }
        cout << "Score:"<< score;
        // print the game area

		Sleep(100);

        // geting user keybord hit
        if (_kbhit()){
            switch (getch()){
            
            case 'w':

                if(dir_x != 0 && dir_y != 1){
                    dir_x = 0;
                    dir_y = -1;
                }
                break;

            case 's':
                if(dir_x != 0 && dir_y != -1){
                    dir_x = 0;
                    dir_y = 1;
                }
                break;

            case 'a':
                if (dir_x != 1 && dir_y != 0){
                
                    dir_x = -1;
                    dir_y = 0;
                }
                break;

            case 'd':
                if(dir_x != -1 && dir_y != 0){
                    dir_x = 1;
                    dir_y = 0;
                }
                break;
            
            default:
                break;
            }
        }
        // geting user keybord hit

        // moving the snake
        for (m= size - 1; m > 0; m--){ 
            snake[m].x = snake[m-1].x;
            snake[m].y = snake[m-1].y;
        }
        snake[0].x = snake[0].x + dir_x;
        snake[0].y = snake[0].y + dir_y; 
        // moving the snake
        
        // detect collision to walls
        if(snake[0].x == 0 || snake[0].y == 0 || snake[0].x == width - 1 || snake[0].y == height - 1){
            game_is_on = false;
        }
        // detect collision to walls

        // detect collision to walls
        if(snake[0].x == food.x && snake[0].y == food.y){
        	srand(time(NULL));
            food.x = rand() % 18 + 1;
            food.y = rand() % 18 + 1;
            size++;
            snake[size - 1].x = snake[size-2].x;
            snake[size - 1].y = snake[size-2].y;
            score++;
        }
        // detect collision to walls

        // detect collision to sanke it self
        for(m=size - 2; m > 0; m--){
        	if(snake[0].x == snake[m].x && snake[0].y == snake[m].y ){
        		game_is_on = false;
			}
		}
        // detect collision to sanke it self
	} 
    return 0;
}
