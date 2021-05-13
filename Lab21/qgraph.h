#ifndef QGRAPH_H
#define QGRAPH_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QString>
#include <QGraphicsTextItem>
#include <vector>
#include <cmath>

class QGraph
{
    std::vector<std::vector<int>> matrix;
public:
    QGraph();
    ~QGraph();
    void DrawGraph(QGraphicsScene* scene);
private:
    int GetWeight(const int vertex1, const int vertex2);
    void DrawNodes(QGraphicsScene* scene);
    void DrawLines(QGraphicsScene* scene);
};

#endif // QGRAPH_H
