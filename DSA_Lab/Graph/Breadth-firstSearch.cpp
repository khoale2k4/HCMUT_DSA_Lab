#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};

#include <map>
class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        Adjacency *rs = new Adjacency();
        list<int> travel;
        map<int, bool> visited;
        travel.push_back(v);
        if(visited[v] == false){
            travel.push_back(v);
            rs->push(v);
            visited[v] = true;
        }

        while(!travel.empty()){
            int n = travel.size();
            for(int i = 0; i < n; i++){
                int tem = travel.front();
                travel.pop_front();
                for(int k = 0; k < adj[tem].getSize(); k++){
                    int e = adj[tem].getElement(k);
                    if(visited[e] == false){
                        travel.push_back(e);
                        rs->push(e);
                        visited[e] = true;
                    }
                }
            }
        }
        return rs;
	}
};

int main(){
    
}