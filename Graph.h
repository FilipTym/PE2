#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
public:
    std::vector<std::vector<int>> matrix;

    // Function to read the graph from a file
    bool readFromFile(const std::string& nameOfFile);

    // Function to randomly generate a graph
    void randomGenerateGraph(int numOfVertices);

    // Function to print the graph matrix
    void printMatrix() const;

private:
    int generateRandomCost();
};

#endif // GRAPH_H
