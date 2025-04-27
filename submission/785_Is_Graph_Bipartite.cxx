/*
 * 785_Is_Graph_Bipartite.cxx
 *
 * Copyright 2021 RedaKerouicha <redakerouicha@localhost>
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

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n);  // 0: uncolored; 1: color A; -1: color B

    queue<int> q;  // queue, resusable for BFS

    for (int i = 0; i < n; i++) {
        if (color[i]) continue;  // skip already colored nodes

        // BFS with seed node i to color neighbors with opposite color
        color[i] = 1;  // color seed i to be A (doesn't matter A or B)
        for (q.push(i); !q.empty(); q.pop()) {
            int cur = q.front();
            for (int neighbor : graph[cur]) {
                if (!color[neighbor])  // if uncolored, color with opposite color
                {
                    color[neighbor] = -color[cur];
                    q.push(neighbor);
                }

                else if (color[neighbor] == color[cur])
                    return false;  // if already colored with same color, can't be
                                   // bipartite!
            }
        }
    }

    return true;
}

int main(int argc, char** argv) { return 0; }
