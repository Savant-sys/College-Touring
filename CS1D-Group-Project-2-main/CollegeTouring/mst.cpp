#include "mst.h"

//MST::MST()
//{

//}

DSU::DSU(int n)
 {
     parent = new int[n];
     rank = new int[n];

     for (int i = 0; i < n; i++) {
         parent[i] = -1;
         rank[i] = 1;
     }
 }


 // union function
 void DSU::unite(int x, int y)
 {
     x = round(x);
     y = round(y);
     int s1 = find(x);
     int s2 = find(y);

     if (s1 != s2) {
         if (rank[s1] < rank[s2]) {
             parent[s1] = s2;
             rank[s2] += rank[s1];
         }
         else {
             parent[s2] = s1;
             rank[s1] += rank[s2];
         }
     }
 }


 void Graph::kruskals_mst()
 {
     // 1. Sort all edges
     sort(edgelist.begin(), edgelist.end());

     // Initialize the DSU
     DSU s(V);
     //int ans = 0;
     //QDebug << "Following are the edges in the " + "constructed MST" << endl;
     for (auto edge : edgelist) {
         double w = edge[0];
         double x = edge[1];
         double y = edge[2];

         // take that edge in MST if it does form a cycle
         if (s.find(round(x)) != s.find(round(y))) {
             s.unite(round(x), round(y));
             ans += w;
             ansList.push_back({x,y,w});
            // cout << x << " -- " << y << " == " << w << endl;
         }
     }
    // cout << "Minimum Cost Spanning Tree: " << ans;
 }
