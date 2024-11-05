#include <iostream>
#include "Graph.h"
#include "TSPBranchAndBound.h"

using namespace std;

int main() {
    Graph graph;

    string filename ="C:\\Users\\user\\CLionProjects\\PEA2\\matrix_6x6";

    if (graph.readFromFile(filename)) {
        cout << "Graf wczytany poprawnie z pliku " << filename << ":\n";
        graph.printMatrix();
    } else {
        cout << "generuje graf losowy\n";
        int numOfVertices = 5;
        graph.randomGenerateGraph(numOfVertices);
        graph.printMatrix();
    }

    TSPBranchAndBound tsp(graph);

    tsp.breadthFirstSearch();
    tsp.depthFirstSearch();
    tsp.lowestCostFirstSearch();

    return 0;
}
