DisjointSet(int n){
      rank.resize(n, 0);
      parent.resize(n);
      for(int i=0; i<n; i++)
          parent[i] = i;      
  }

  int findParent(int node){
      if(node == parent[node])
          return node;
      parent[node] = findParent(parent[node]);
      return parent[node];
  }

  void unionByRank(int x, int y){
      int xParent = findParent(x);
      int yParent = findParent(y);

      if(xParent == yParent)
          return;

      if(rank[xParent] > rank[yParent])
          parent[yParent] = xParent;
      else if(rank[xParent] < rank[yParent])
          parent[xParent] = yParent;
      else{
          parent[xParent] = yParent;
          rank[yParent]++;
      }
  }

  void printParent(int i){
      cout<<parent[i]<<" "<<rank[i]<<"\n";
  }
  
private:
  vector<int> rank;
  vector<int> parent;
};
