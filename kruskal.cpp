#include <vector>
#include <iostream>
#include <algorithm>

class grafo{

    private:
    int *verticesReferencia;
    std::vector<std::pair<int, std::pair<int,int>>> G;
    std::vector<std::pair<int, std::pair<int,int>>> M;
    int verticesGrafo;
    public:
    grafo(int v){
        verticesReferencia = new int[v];

        for(int i = 0 ; i < v ; i+=1){
            verticesReferencia[i] = i;
        }
        G.clear();
        M.clear();
    }
    void AddWeightedEdge(int w, int s, int d){
        //D -> PESO
        //S -> ARESTA U
        //D -> ARESTA V
        G.push_back(std::make_pair(d,std::make_pair(w,s)));

    }

    int operacaoFind(int i){

        if(verticesReferencia[i] == i){
            return i;
        }
        return operacaoFind(verticesReferencia[i]);
    }

    void operacaoUnion(int s, int d){

        verticesReferencia[s] = verticesReferencia[d];
        
    }

    void kruskal(){
        int v1_set, v2_set;
        std::sort(G.begin(), G.end());
        for(int i = 0 ; i < G.size() ; i+=1){
            v1_set = operacaoFind(G[i].second.first);
            v2_set = operacaoFind(G[i].second.second);

            if(v1_set != v2_set){
                M.push_back(G[i]);
                operacaoUnion(v1_set, v2_set);
            }
        }
    }

    void imprimirMST(){
        std::cout << "Edge :"
     << " Weight" << std::endl;
  for (int i = 0; i < M.size(); i++) {
    std::cout << M[i].second.first << " - " << M[i].second.second << " : "
       << M[i].first;
    std::cout << std::endl;
  }
    }
};

int main(){

  grafo g{6};
  g.AddWeightedEdge(0, 1, 4);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 2);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 2);
  g.AddWeightedEdge(5, 4, 3);
  g.kruskal();
  g.imprimirMST();

}