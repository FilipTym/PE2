#include "Graph.h"
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

bool Graph::readFromFile(const string& nameOfFile) {
    ifstream file(nameOfFile);
    if (!file.is_open()) {
        cerr << "Blad: Nie mozna otworzyc pliku grafu" << endl;
        return false;
    }

    matrix.clear();
    int size;
    file >> size;
    matrix.resize(size, vector<int>(size));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
            if (matrix[i][j] < 0) {
                matrix[i][j] = numeric_limits<int>::max();
            }
        }
    }
    file.close();
    return true;
}

void Graph::randomGenerateGraph(int numOfVertices) {
    matrix.resize(numOfVertices, vector<int>(numOfVertices, -1));

    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++) {
            if (i == j) {
                matrix[i][j] = -1;
            } else {
                matrix[i][j] = generateRandomCost();
            }
        }
    }
}

int Graph::generateRandomCost() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    return dis(gen);
}

void Graph::printMatrix() const {
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            if (value == numeric_limits<int>::max()) {
                cout << "-1 ";
            } else {

                if (value < 10) {
                    cout << " " << value << " ";
                } else {
                    cout << value << " ";
                }
            }
        }
        cout << endl;
    }
}
