/*
 * 310_Minimum_Height_Trees.cxx
 * 
 * Copyright 2020 RedaKerouicha <redakerouicha@localhost>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
void addEdge(std::vector<int> adj_list[], int u, int v) 
{ 
	adj_list[u].push_back(v); 
	adj_list[v].push_back(u); 
}
void printGraph(std::vector<int> adj[], int V) 
{ 	
	for (int v = 0; v < V; ++v)  // v specific node
	{ 
		std::cout << "\n "<< v;
		for (auto x : adj[v]) // x the adjacent node
		std::cout << " -- " << x; 		 
	} 
	std::cout<<std::endl;
}
int getHeight(std::vector<int> adj[],int root,int vertices){

}

int main(int argc, char **argv)
{
	
	std::vector<std::vector<int>> edges= {{1,0},{1,2},{1,3}};
	int vertices = 4;
	std::vector<int> adj[vertices];
	
	for(std::vector<int> pair : edges){
		addEdge(adj,pair[0],pair[1]);
	}
	printGraph(adj,vertices);
	
	std::cout << getHeight(adj,0,vertices)<<std::endl;
	return 0;
}

