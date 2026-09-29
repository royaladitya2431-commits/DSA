#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    vector<int> adj[20];
    int n;

public:

    Graph()
    {
        n = 0;
    }

    void createGraph()
    {
        cout << "\nEnter number of vertices (maximum 20): ";
        cin >> n;

        if (n <= 0 || n > 20)
        {
            cout << "Invalid number of vertices!" << endl;
            n = 0;
            return;
        }

        // Clear previous graph data
        for (int i = 0; i < 20; i++)
        {
            adj[i].clear();
        }

        int edges;

        cout << "Enter number of edges: ";
        cin >> edges;

        if (edges < 0)
        {
            cout << "Invalid number of edges!" << endl;
            return;
        }

        cout << "\nEnter edges (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            int u, v;

            cout << "Edge " << i + 1 << ": ";
            cin >> u >> v;

            if (u < 0 || u >= n || v < 0 || v >= n)
            {
                cout << "Invalid vertex! Enter vertices between 0 and "
                     << n - 1 << "." << endl;

                i--;
                continue;
            }

            // For an undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);

            // For a directed graph, remove:
            // adj[v].push_back(u);
        }

        cout << "\nGraph created successfully!" << endl;
    }

    void displayList()
    {
        if (n == 0)
        {
            cout << "\nGraph is not created yet!" << endl;
            return;
        }

        cout << "\n===== Adjacency List =====\n";

        for (int i = 0; i < n; i++)
        {
            cout << i << " -> ";

            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j];

                if (j < adj[i].size() - 1)
                {
                    cout << " -> ";
                }
            }

            cout << endl;
        }
    }

    void BFS(int start)
    {
        if (n == 0)
        {
            cout << "\nGraph is not created yet!" << endl;
            return;
        }

        if (start < 0 || start >= n)
        {
            cout << "\nInvalid starting vertex!" << endl;
            return;
        }

        bool visited[20] = {false};

        queue<int> q;

        // Mark starting vertex as visited
        visited[start] = true;

        // Insert starting vertex into queue
        q.push(start);

        cout << "\nBFS Traversal: ";

        while (!q.empty())
        {
            // Get front vertex
            int current = q.front();

            // Remove vertex from queue
            q.pop();

            cout << current << " ";

            // Visit all adjacent vertices
            for (int i = 0; i < adj[current].size(); i++)
            {
                int vertex = adj[current][i];

                // If vertex is not visited
                if (!visited[vertex])
                {
                    visited[vertex] = true;
                    q.push(vertex);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g;

    int choice;
    int start;

    do
    {
        cout << "\n\n==============================";
        cout << "\n       GRAPH MENU";
        cout << "\n==============================";

        cout << "\n1. Create a Graph";
        cout << "\n2. Display Graph";
        cout << "\n3. BFS Traversal";
        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayList();
            break;

        case 3:
            cout << "\nEnter starting vertex: ";
            cin >> start;

            g.BFS(start);
            break;

        case 4:
            cout << "\nProgram Exited Successfully.";
            break;

        default:
            cout << "\nInvalid Choice! Please try again.";
        }

    } while (choice != 4);

    return 0;
}
