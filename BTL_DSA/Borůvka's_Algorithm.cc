#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V;
    vector<vector<int>> graph;
    vector<Edge> mstEdges;
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) {
            return i;
        }
        return find(parent, parent[i]);
    }

    void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot]) {
            parent[xroot] = yroot;
        }
        else if (rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        }
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
    }

    void addEdge(int u, int v, int w) {
        graph.push_back({u, v, w});
    }
    vector<Edge> boruvkaMST() {
        vector<int> parent(V);
        vector<int> rank(V);
        vector<vector<int>> cheapest(V, vector<int>(3, -1));
        mstEdges.clear();
    
        int numTrees = V;
        int MSTweight = 0;
    
        for (int node = 0; node < V; node++) {
            parent[node] = node;
            rank[node] = 0;
        }
    
        while (numTrees > 1) {
            for (int i = 0; i < graph.size(); i++) {
                int u = graph[i][0], v = graph[i][1], w = graph[i][2];
                int set1 = find(parent, u), set2 = find(parent, v);
    
                if (set1 != set2) {
                    if (cheapest[set1][2] == -1 || cheapest[set1][2] > w) {
                        cheapest[set1] = {u, v, w};
                    }
                    if (cheapest[set2][2] == -1 || cheapest[set2][2] > w) {
                        cheapest[set2] = {u, v, w};
                    }
                }
            }
    
            for (int node = 0; node < V; node++) {
                if (cheapest[node][2] != -1) {
                    int u = cheapest[node][0], v = cheapest[node][1], w = cheapest[node][2];
                    int set1 = find(parent, u), set2 = find(parent, v);
                    
                    if (set1 != set2) {
                        MSTweight += w;
                        unionSet(parent, rank, set1, set2);
                        mstEdges.push_back({u, v, w});  // <== Thêm dòng này
                        cout << "Cạnh " << u << "-" << v << " với trọng số " << w << " trong MST\n";
                        numTrees--;
                    }
                }
            }
    
            for (int node = 0; node < V; node++) {
                cheapest[node][2] = -1;
            }
        }
    
        cout << "Tổng trọng lượng của MST là " << MSTweight << endl;
        return mstEdges; // <== Trả về danh sách các cạnh
    }
    
};

int main() {
    // Hiển thị thông tin về thuật toán
    cout << "===============================================" << endl;
    cout << "THUẬT TOÁN BORUVKA - CÂY KHUNG NHỎ NHẤT (MST)" << endl;
    cout << "===============================================" << endl;
    
    // Nhập thông tin đồ thị
    int V, E;
    cout << "Nhập số đỉnh (V): ";
    cin >> V;
    cout << "Nhập số cạnh (E): ";
    cin >> E;
    
    // Tạo đồ thị
    Graph g(V);
    
    cout << "\nNhập thông tin cho các cạnh (u, v, trọng số):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cout << "Cạnh " << (i+1) << " (đỉnh nguồn, đỉnh đích, trọng số): ";
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    
    // Tìm cây khung nhỏ nhất bằng thuật toán Boruvka
    vector<Edge> result = g.boruvkaMST();
    
    // Hiển thị kết quả
    cout << "\n=================== KẾT QUẢ ===================" << endl;
    cout << "Các cạnh thuộc cây khung nhỏ nhất (MST):" << endl;
    
    int totalWeight = 0;
    for (const Edge& e : result) {
        cout << e.src << " -- " << e.dest << " : " << e.weight << endl;
        totalWeight += e.weight;
    }
    
    cout << "\nTổng trọng số của cây khung nhỏ nhất: " << totalWeight << endl;
    cout << "===============================================" << endl;
    
    return 0;
}
