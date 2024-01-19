#include <bits/stdc++.h>

using namespace std;
int INF = 1000000000;
int main(){
    ios_base::sync_with_stdio(false);
    int n,w,d;
    cin>>n>>w>>d;
    vector<vector<int>> walk(n,vector<int>());
    for(int i = 0; i < w; i++){
        int a,b;
        cin>>a>>b;
        
        walk[b-1].push_back(a-1);
    }
    vector<int> station(n);
    for(int i = 0; i < n; i++){
        cin>>station[i];
        station[i]--;
    }
    

    // find short distance from dest to every station using BFS
    
    vector<int> dist(n,INF);
    queue<int> q;
    q.push(n-1);
    dist[n-1] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : walk[v]){
            if(dist[u] ==INF){
                dist[u] = dist[v]+1;
                q.push(u);
            }
        }
    }



    multiset<int> D;
    for(int i = 0; i < n; i++){
        D.insert(i+dist[station[i]]);
    }

    for(int i = 0; i < d; i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        D.extract(a+dist[station[a]]);
        D.extract(b+dist[station[b]]);
        swap(station[a],station[b]);
        D.insert(a+dist[station[a]]);
        D.insert(b+dist[station[b]]);
        cout<<*D.begin()<<endl;
    }
}