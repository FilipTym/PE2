#include "TSPBranchAndBound.h"
#include <iostream>
#include <limits>
using namespace std;

TSPBranchAndBound::TSPBranchAndBound(const Graph& g) : graph(g) {}

void TSPBranchAndBound::breadthFirstSearch() {
    cout << "Przeszukiwanie wszerz (BFS) " << endl;
}

void TSPBranchAndBound::depthFirstSearch() {
    cout << "Przeszukiwanie wglab (DFS) " << endl;
}

void TSPBranchAndBound::lowestCostFirstSearch() {
    cout << "Przeszukiwanie pod katem najnizszego kosztu (Best First Search) " << endl;
}


int TSPBranchAndBound::calculatePathCost(const vector<int>& path) {
    int cost = 0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        cost += graph.matrix[path[i]][path[i + 1]];
    }
    cost += graph.matrix[path.back()][path[0]];
    return cost;
}


int TSPBranchAndBound::calculateBound(const Node& node) {
    int bound = node.cost;
    return bound;
}
