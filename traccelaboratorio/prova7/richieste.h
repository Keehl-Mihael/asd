#include <map>
#include <list>

template< class I>
class richieste{
private:

public:

// Prints all paths from 's' to 'd'
	void printAllPaths(int s, int d)
	{
        int V = 5;
		// Mark all the vertices as not visited
		bool *visited = new bool[V];

		// Create an array to store paths
		int *path = new int[V];
		int path_index = 0; // Initialize path[] as empty

		// Initialize all vertices as not visited
		for (int i = 0; i < V; i++)
			visited[i] = false;

		// Call the recursive helper function to print all paths
		printAllPathsUtil(s, d, visited, path, path_index);
	}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
	void printAllPathsUtil(int u, int d, bool visited[],
								  int path[], int &path_index)
	{
		// Mark the current node and store it in path[]
		visited[u] = true;
		path[path_index] = u;
		path_index++;

		// If current vertex is same as destination, then print
		// current path[]
		if (u == d)
		{
			for (int i = 0; i<path_index; i++)
				cout << path[i] << " ";
			cout << endl;

		}
		else // If current vertex is not destination
		{
			// Recur for all the vertices adjacent to current vertex
			list<int>::iterator i;
			for (i = adj[u].begin(); i != adj[u].end(); ++i)
				if (!visited[*i])
					printAllPathsUtil(*i, d, visited, path, path_index);
		}

		// Remove current vertex from path[] and mark it as unvisited
		path_index--;
		visited[u] = false;
	}



};