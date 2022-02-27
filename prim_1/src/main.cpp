#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N, M;

int main(){

    cout<<"Algoritmo de Prim"<<endl;
    
    while(cin>>N>>M and N){
        vector< vector< pair<int,int> > > G(N);
        for(int i=0; i<M; i++){
            int u,v,cost;
            cin>>u>>v>>cost;
            G[u].push_back({v, cost});
            G[v].push_back({u, cost});
        }

        priority_queue< pair<int, int> > prim;
        vector<bool> mark(N, false);

        mark[0] = true;
        for(pair<int, int> ed: G[0]){
            prim.push({-ed.second, ed.first});
        }

        int soma = 0;
        while(prim.size()){
            pair<int,int> menor = prim.top();
            prim.pop();
            if(mark[menor.second] == true) continue;
            soma += -menor.first;

            mark[menor.second] = true;
            for(pair<int,int> ed: G[menor.second]){
                prim.push({-ed.second, ed.first});
            }
        }
        cout << soma << endl;
    }

    return 0;
}