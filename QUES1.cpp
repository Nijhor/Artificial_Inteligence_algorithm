
#include<iostream>
#include<vector>

using namespace std;

    vector <int> adj[10];
    bool visited[10];
    bool flag;


 bool IDS(int source, int dest , int level) {
    if (level == -1){
        return false;
    }
    else{
        if(source==dest){
            return true;
        }
        else{
                for(int i = 0;i < adj[source].size();i++){
                //if(visited[adj[source][i]] == false){
                IDS(adj[source][i],dest, level-1)==true;
                return true;

                return false;
        }


    }



 }
}
//}


 //void init() {
   //     for(int i = 0;i < 10;++i)
     //   visited[i] = false;
    //}

int main(){
    bool flag,test;
    int nodes, edges, x, y, s , d,l;
    cin >> nodes;
    cin >> edges;

    for(int i = 0;i < edges;i++) {
         cin >> x >> y;
         adj[x].push_back(y);
         adj[y].push_back(x);
        }
    cin >> s;
    cin >> d;
    cin >> l;
if (IDS(s,d,l)==true){
    cout<<"reacheable";
}
else cout<<"NOt";



}
