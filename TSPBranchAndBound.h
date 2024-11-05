#ifndef TSPBRANCHANDBOUND_H
#define TSPBRANCHANDBOUND_H

#include "Graph.h"
#include <vector>

struct Node {
    int level; // Current level in the tree
    int cost; // Cost of the path so far
    int path[100]; // Stores the path taken
};

class TSPBranchAndBound {
public:
    TSPBranchAndBound(const Graph& g);

    void breadthFirstSearch();
    void depthFirstSearch();
    void lowestCostFirstSearch();
    int calculatePathCost(const std::vector<int>& path);

private:
    const Graph& graph;
    int calculateBound(const Node& node);
};

#endif // TSPBRANCHANDBOUND_H

