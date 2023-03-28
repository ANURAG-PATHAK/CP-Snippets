#include<bits/stdc++.h>
class Disjoint_Set{
    private:
        std::vector<int> rank, parent, size;
    public:
        Disjoint_Set(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
        }
        int findUpar(int u){
            if(u == parent[u]) return u;
            return parent[u] = findUpar(parent[u]);
        }
        void unionByRank(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            } else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            } else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
