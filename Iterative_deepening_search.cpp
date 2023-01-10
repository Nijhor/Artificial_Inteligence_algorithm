#include<stdio.h>

#include<vector>



using namespace std ;

int col[100], d[100], par[100], f[100] ;

vector<int>adj[100] ;

int time = 0 ;


void DFS(int u,int l)

{

    time = time+1 ;

    d[u] = time ;

    col[u] = 1 ;

    for(int i = 0 ; i <  l; i++)

    {

        int v = adj[u][i] ;

        if(col[v] == 0){

            par[v] = u ;

            printf("%d -> %d tree edge\n",u, v) ;

            DFS(v,l) ;

        }

       else if(col[v] == 1){

            printf("%d -> %d back edge\n",u, v) ;

            printf("Cycle found\n") ;

        }

        else{

            if(d[u] < d[v])

                printf("%d -> %d forward edge\n",u, v) ;

            else

                printf("%d -> %d cross edge\n",u, v) ;

        }

    }

    time = time+1 ;

    f[u] = time ;

    col[u] = 2 ;

}


int main()

{

    int n, edge, i, j, u, v ;

    scanf("%d %d", &n , &edge) ;

    for(i = 0 ; i < edge ; i++){

        scanf("%d %d", &u, &v) ;

        adj[u].push_back(v) ;

        adj[v].push_back(u) ;

    }

    for(i = 0 ; i < n ; i++){

        col[i] = 0 ;

        par[i] = -1 ;

        d[i] = 99999 ;

        f[i] = 99999 ;


    }


    int source, dst,l ;

    printf("Source: ") ;

    scanf("%d", &source) ;

    printf("Destination: ") ;

    scanf("%d", &dst) ;

    for(int i=0;i<edge;i++){
    printf("Level input: %d\n",i);

   // scanf("%d",&l);
    DFS(source,i) ;
    if(col[dst] != 0) printf("Reachable\n") ;

    else printf("Not reachable\n") ;

    }


}

/*

9 8
0 1
0 2
1 4
1 3
2 5
2 6
4 7
4 8
0
7


*/
