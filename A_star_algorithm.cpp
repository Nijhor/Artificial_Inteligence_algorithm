#include<stdio.h>
#include<math.h>

struct myQueue{
    int x, y;
    int par_i,par_j;
    double g, h, f ;
    bool flag ;
}Q[100], temp;

struct parent {
    int x,y;
}par[100][100];

int grid[100][100];
double heuristicCost[100][100], dis[100][100] ;

void initialization(int n, int m, int stri, int strj)
{
    int k = 0 ;
    dis[stri][strj] = 0.0 ;
    par[stri][strj].x = stri;
    par[stri][strj].y = strj;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            Q[k].x = i ;
            Q[k].y = j ;
            Q[k].g = dis[i][j] ;
            Q[k].h = heuristicCost[i][j] ;
            Q[k].f = Q[k].g + Q[k].h ;
            Q[k].flag = true ;
            k++ ;
        }
    }
}

bool isEmpty(int n, int m){
    for(int i = 0 ; i < n*m ; i++){
        if(Q[i].flag)
		return false ;
    }
    return true ;
}

int pop(int n, int m)
{
    int min = 1000000 ;
    int index ;
    for(int i = 0 ; i < n*m ; i++)
    {
        if(Q[i].f < min && Q[i].flag == true){
            min = Q[i].f ;
            index = i ;
        }
    }
    Q[index].flag = false ;
    return index ;
}

void updateQueueCost(int i, int j, double cost, int n, int m){
    for(int k = 0 ; k < n*m ; k++){
        if(Q[k].x == i && Q[k].y == j){
            Q[k].g = cost ;
            Q[k].f = Q[k].g + Q[k].h ;
        }
    }
}
void aStarSearch(int n, int m)
{
    while(!isEmpty(n, m)){
        int index = pop(n,m) ;
        temp = Q[index] ;
        int i = temp.x ;
        int j = temp.y ;


        if(grid[i-1][j] > -1 && i-1>=0){
            if(dis[i-1][j] > dis[i][j] + grid[i-1][j]){
                dis[i-1][j] = dis[i][j] + grid[i-1][j] ;
                updateQueueCost(i-1, j, dis[i-1][j], n, m) ;
                /*Parents*/

               par[i-1][j].x =i;
               par[i-1][j].y =j;
            }

        }
         if(grid[i+1][j] > -1 && i+1<n){
            if(dis[i+1][j] > dis[i][j] + grid[i+1][j]){
                dis[i+1][j] = dis[i][j] + grid[i+1][j] ;
                updateQueueCost(i+1, j, dis[i+1][j], n, m) ;
                /*Parents*/
                par[i+1][j].x =i;
                par[i+1][j].y =j;
            }

        }
         if(grid[i][j-1] > -1 && j-1>=0){
            if(dis[i][j-1] > dis[i][j] + grid[i][j-1]){
                dis[i][j-1] = dis[i][j] + grid[i][j-1] ;
                updateQueueCost(i, j-1, dis[i][j-1], n, m) ;
                /*Parents*/
                par[i][j-1].x =i;
                par[i][j-1].y =j;
            }

        }
         if(grid[i][j+1] > -1 && j+1< m){
            if(dis[i][j+1] > dis[i][j] + grid[i][j+1]){
                dis[i][j+1] = dis[i][j] + grid[i][j+1] ;
                updateQueueCost(i, j+1, dis[i][j+1], n, m) ;
                /*Parents*/
                 par[i][j+1].x =i;
                 par[i][j+1].y =j;
            }

        }



    }
}

int main()
{
    int n, m, i , j ;
    int stri, strj, dsti, dstj ;
    scanf("%d %d", &n, &m) ;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            scanf("%d", &grid[i][j]) ;

        }
    }
    scanf("%d %d %d %d", &stri, &strj, &dsti, &dstj) ;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            heuristicCost[i][j] = sqrt(pow((1.00*dsti-i),2)+pow((1.00*dstj-j),2)) ;
            dis[i][j] = 99999.00 ;
           // par[i][j] = -1;
        }
    }
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            printf("%.3lf ", heuristicCost[i][j]) ;
        }
        printf("\n") ;
    }
    initialization(n, m, stri, strj) ;
    aStarSearch(n, m) ;

 /*      printf("\nparent will be : \n");
     for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            printf(" %d", grid[i][j] );
            printf("(%d ,%d)\t", par[i][j].x,par[i][j].y) ;
        }
        printf("\n") ;
    }*/
    printf("\n Path will be: ");
    while(par[dsti][dstj].x != dsti || par[dsti][dstj].y !=dstj){
        printf("%d",grid[dsti][dstj]);
        printf("||(%d,%d) >> ",dsti,dstj);

        dsti = par[dsti][dstj].x;
        dstj = par[dsti][dstj].y;
    }
   // printf(" %d|| ",);
    printf(" %d ||(%d,%d)\n\n",grid[stri][strj],stri,strj);
}


/*
4 4
10 -1 -1 1
7 5 9 7
-1 3 3 14
-1 2 1 -1
0 0 3 2
*/
