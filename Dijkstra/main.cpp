#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> ipair; //integer pair


class Graph {
    int v; //number of vertices

    list<pair<int, int> >* adj; //vertices and weighted pair

    public:
        Graph(int v);
        void addEdge(int u, int v, int w);
        void shortestPath(int src);
};

Graph::Graph(int v){
    this->v = v;
    adj = new list<ipair>[v];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void Graph::shortestPath(int src) {

    priority_queue<ipair, vector<ipair>, greater<ipair> >pq;
    vector<int> dist(v, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;

        pq.pop();

        list<pair<int, int> >::iterator i;

        for(i = adj[u].begin(); i != adj[u]. end(); i++) {
            int v = (*i).first;
            int weight = (*i).second;

            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex distance from Source\n");
    for(int i = 0; i < v; i++){
        printf("%d \t\t %d\n", i, dist[i]);
    }
    
}

int main() {




    return 0;
}