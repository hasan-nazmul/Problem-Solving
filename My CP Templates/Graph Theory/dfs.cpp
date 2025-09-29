#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) : vertices(v), adjList(v) {}
    
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        // For undirected graph, uncomment the line below:
        // adjList[v].push_back(u);
    }
    
    // Iterative DFS for connected graph
    void iterativeDFS(int start) {
        vector<bool> visited(vertices, false);
        stack<int> st;
        
        st.push(start);
        visited[start] = true;
        
        cout << "DFS traversal starting from vertex " << start << ": ";
        
        while (!st.empty()) {
            int current = st.top();
            st.pop();
            cout << current << " ";
            
            // Push neighbors in reverse order to maintain DFS order
            for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    st.push(*it);
                }
            }
        }
        cout << endl;
    }
    
    // Iterative DFS for disconnected graph
    void iterativeDFSDisconnected() {
        vector<bool> visited(vertices, false);
        stack<int> st;
        
        cout << "DFS traversal for disconnected graph: ";
        
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                st.push(i);
                visited[i] = true;
                
                while (!st.empty()) {
                    int current = st.top();
                    visited[current] = true;
                    st.pop();
                    cout << current << " ";
                    
                    for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                        if (!visited[*it]) {
                            st.push(*it);
                        }
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    
    // Perform DFS
    g.iterativeDFS(0);
    
    return 0;
}