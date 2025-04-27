/*
 * 133_Clone_Graph.cxx
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
#include <list>
#include <queue>
#include <unordered_map>

Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->neighbors.empty()) {
        return new Node(node->val);
    }
    std::list<Node*> discovered;
    std::queue<Node*> Q;
    Node* vertex;

    Q.push(node);
    discovered.push_back(node);
    while (!Q.empty()) {
        vertex = Q.front();
        Q.pop();
        for (Node* p : vertex->neighbors) {
            if (std::find(discovered.begin(), discovered.end(), p) == discovered.end()) {
                Q.push(p);
                discovered.push_back(p);
            }
        }
    }
    std::unordered_map<int, Node*> util;
    for (Node* p : discovered) {
        util.insert(std::make_pair(p->val, new Node(p->val)));
    }
    for (Node* p : discovered) {
        for (Node* t : p->neighbors) {
            util[p->val]->neighbors.push_back(util[t->val]);
        }
    }
    return util[node->val];
}

int main(int argc, char** argv) { return 0; }
