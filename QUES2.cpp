
#include <fstream>
#include <iomanip>
#include <iostream>
#include<stdio.h>
#include<queue>
using namespace std;

    struct state{
        int x,y;
        int dirt;
    }temp;
    int c,counts=0;
int grid[100][100], col[100][100];
queue<state>Q;
void BFS(){
    while (!Q.empty()){
       temp = Q.front();
        int i = temp.x;
        int j = temp.y;
        Q.pop();

    if(grid[i][j-1] == 1 && col[i][j-1] == 0){
        col[i][j-1] = 1;
        temp.x = i;
        temp.y = j-1;
        Q.push(temp);



    }
       if(grid[i][j+1] == 1 && col[i][j+1] == 0){
        col[i][j+1] = 1;
        temp.x = i;
        temp.y = j+1;
        Q.push(temp);


    }
    if(grid[i-1][j] == 1 && col[i-1][j] == 0){
        col[i-1][j] = 1;
        temp.x = i-1;
        temp.y = j;
        Q.push(temp);



    }
    if(grid[i+1][j] == 1 && col[i+1][j] == 0){
        col[i+1][j] = 1;
        temp.x = i+1;
        temp.y = j;
        Q.push(temp);



    }

    }
}

int main(){
    int h,l,number;
    printf("enter the area: ");
    scanf("%d %d",&h,&l);
    for(int i=0;i<h;i++){
        for(int j=0;j<l;j++){
            scanf("%d",&grid[i][j]);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<l;j++){
            col[i][j]= 0;
        }
    }


    for(int i=0;i<h;i++){
        for(int j=0;j<l;j++){
            if(grid[i][j]==1&& col[i][j]==0){

               temp.x = i;
               temp.y = j;
               temp.dirt = grid[i][j];
               Q.push(temp);
               BFS();
               counts++;
            }
        }

    }
    printf("Number Of Iland: %d",counts);


}
