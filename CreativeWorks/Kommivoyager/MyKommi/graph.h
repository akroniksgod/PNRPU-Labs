#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include "Edge.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QString>
#include <QGraphicsTextItem>
#include <vector>
#include <string>
#include <fstream>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    Graph(std::vector<std::vector<int>> matr);
    ~Graph();
    void PrintMatrix();
    void reductRow();
    void reductCol() ;
    int findMinCol(int a, int b);
    int findMinRow(int a, int b);
    int getSize() const;
    Edge FindEdge();
    std::string getPath(std::vector<Edge> result);
    int getLength(std::vector<Edge> solution);
    QString way;
    std::vector<Edge> KommiFunction();
    int GetWeight(const int vertex1, const int vertex2);
    void DrawLines(QGraphicsScene* scene);
    void DrawNodes(QGraphicsScene* scene);
    void DrawGraph(QGraphicsScene* scene);

private:
    Ui::Graph *ui;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> copyOfMatrix;
    QGraphicsScene *scene;
    void ReadFunction();
};

#endif // GRAPH_H
