#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
using namespace std;
class Graph
{
    vector<vector<int>> matrix;
public:
    Graph();
    ~Graph();
    int GetWeight(const int vertex1, const int vertex2);
};

#endif // GRAPH_H
