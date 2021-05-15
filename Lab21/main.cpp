#include "graph.h"
#include <QApplication>
#include <queue>
#include <iostream>
#include <Windows.h>
using namespace std;

vector <vector<int>> mat = { {0, 34, 8, 0, 2, 21 },
                                    {24, 0, 57, 45, 5, 0 },
                                    {8, 57, 0, 0, 0, 0 },
                                    {0, 45, 0, 0, 3, 0 },
                                    {2, 5, 0, 3, 0, 13 },
                                    {21, 0, 0, 0, 13, 0 } };
int result[6] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX,INT_MAX, INT_MAX };
bool visited[6] = { 0, 0, 0, 0, 0, 0 };
void Dejkstra();

int main(int argc, char *argv[])
{

    cout << "Shortest paths from each point" << endl;
    Dejkstra();
    QApplication a(argc, argv);
    Graph w;
    w.show();
    return a.exec();
}

void Dejkstra()
{
    int top = 0; //вершина с номером 1
    queue<int> line;
    line.push(top);
    result[0] = 0;
    while (!line.empty()) {
        int vertex = line.front();
        line.pop();
        for (int i = 0; i < mat[vertex].size(); i++) {
            if (!visited[i] && mat[vertex][i] && (mat[vertex][i] + result[vertex] < result[i])) {
                result[i] = mat[vertex][i] + result[vertex];
                line.push(i);
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ": " << result[i] << endl;
    }
}
