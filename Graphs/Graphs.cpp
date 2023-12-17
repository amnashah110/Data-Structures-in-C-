#include <iostream>
using namespace std;

class Graph {
    int numVertices;         // number of vertices
    int **adj;               // adjacency matrix (2D array)

public:
    Graph(int v) {
        numVertices = v;
        adj = new int*[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new int[v];
            for (int j = 0; j < v; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int start, int end) {
        // for directed graph
        adj[start][end] = 1;
        //adj[end][start] = 1;   // Comment this line for directed graph
    }

    void DFSUntil(int v, bool visited[], int result[], int& index) {
        visited[v] = true;
        for (int i = 0; i < numVertices; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                DFSUntil(i, visited, result, index);
            }
        }
        result[index--] = v;
    }

    void topologicalSort() {
        int result[numVertices];
        bool visited[numVertices] = {false};
        int index = numVertices - 1;

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                DFSUntil(i, visited, result, index);
            }
        }

        cout << "Topological Sort: ";
        for (int i = 0; i < numVertices; i++) {
            char vertex = result[i] + 65;
            cout << vertex << " ";
    	}
    }

    void DFS(int start) {
        bool visited[numVertices] = {false};
        int stack[numVertices];
        int top = -1;

        visited[start] = true;
        char startV = start + 'A';
        cout << startV << " ";
        stack[++top] = start;

        while (top != -1) {
            int v = stack[top--];
            for (int i = 0; i < numVertices; i++) {
                if (adj[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    char iV = i + 'A';
                    cout << iV << " ";
                    stack[++top] = i;
                }
            }
        }
    }

    void BFS(int start) {
        bool visited[numVertices] = {false};
        int queue[numVertices];
        int front = -1;
        int rear = -1;

        visited[start] = true;
        char startV = start + 'A';
        cout << startV << " ";
        front++;
        queue[++rear] = start;

        while (front <= rear) {
            int v = queue[front++];
            for (int i = 0; i < numVertices; i++) {
                if (adj[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    char iV = i + 'A';
                    cout << iV << " ";
                    queue[++rear] = i;
                }
            }
        }
    }

    void dijkstra(int start, int target) {
	queue <int> q;
	int path[numV];
	int distance[numV];
	for(int i = 0; i < numV; i++) {
	    distance[i] = INT_MAX;
	    path[i] = -1;
	}
		
	distance[start] = 0;
	q.push(start);
		
	while(!q.empty()) {
	    int v = q.front();
	    q.pop();
			
	    for(int i = 0; i < numV; i++) {
	        if(adj[v][i] == 1) {
		    if(distance[i] > distance[v] + cost[v][i]) {
		        q.push(i);
		        distance[i] = distance[v] + cost[v][i];	
		        path[i] = v;
	   	    }
	        }
	    }
	}
	stack <int> pathStack;
	int current = target;
	while(current != start) {
	    pathStack.push(current);
	    current = path[current];
	}
	pathStack.push(start);
		
	cout << "Shortest Path from " << start << " to " << target << ": ";
	while(pathStack.top() != target) {
	    cout << pathStack.top() << " --> ";
	    pathStack.pop();
	}
	cout << pathStack.top();
	pathStack.pop();
    	cout << endl << "Shortest Distance from " << start << " to " << target << ": " << distance[target] << endl;
    }

    void printList() {
        for (int i = 0; i < numVertices; i++) {
            char iV = i + 'A';
            cout << iV << " --> ";
            for (int j = 0; j < numVertices; j++) {
                if (adj[i][j] == 1) {
                    char jV = j + 'A';
                    cout << jV << " ";
                }
            }
            cout << endl;
        }
    }

    void printMatrix() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.printList();
    cout << endl;
    g.printMatrix();
    cout << endl;

    g.topologicalSort();
    cout << endl;
    cout << endl;

    for (int i = 0; i < 4; i++) {
        char iV = i + 'A';
        cout << "DFS starting from vertex " << iV << ": ";
        g.DFS(i);
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 4; i++) {
        char iV = i + 'A';
        cout << "BFS starting from vertex " << iV << ": ";
        g.BFS(i);
        cout << endl;
    }
}
