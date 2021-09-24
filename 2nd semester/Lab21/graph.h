#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QString>
#include <QGraphicsTextItem>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class Graph; }
QT_END_NAMESPACE

class Graph : public QMainWindow
{
    Q_OBJECT
    std::vector<std::vector<int>> matrix;
public:
    Graph(QWidget *parent = nullptr);
    ~Graph();
    int GetWeight(const int vertex1, const int vertex2);
    void DrawLines(QGraphicsScene* scene);
    void DrawNodes(QGraphicsScene* scene);
    void DrawGraph(QGraphicsScene* scene);

private:
    Ui::Graph *ui;
    QGraphicsScene *scene;
};
#endif // GRAPH_H
