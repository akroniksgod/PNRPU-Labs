#include "qgraph.h"
using namespace std;

int     radiusA = 30,
        radiusB = 200;

QGraph::QGraph()
{
    matrix = { {0, 34, 8, 0, 2, 21 },
               {24, 0, 57, 45, 5, 0 },
               {8, 57, 0, 0, 0, 0 },
               {0, 45, 0, 0, 3, 0 },
               {2, 5, 0, 3, 0, 13 },
               {21, 0, 0, 0, 13, 0 } };
}

QGraph::~QGraph() {}

int QGraph::GetWeight(const int vertex1, const int vertex2)
{
    if (vertex1 >= 0 && vertex1 < matrix.size() && vertex2 >=0 && vertex2 < matrix.size())
        return matrix[vertex1][vertex2];
    else
        return 0;
}

void QGraph::DrawLines(QGraphicsScene* scene)
{
    int     centerX= scene->width() / 2,
            centerY = scene->height() / 2;
    double iter = 2 * 3.1415 / matrix.size();
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix.size(); j++){
            if (GetWeight(i, j) > 0){
                int     vertex1_x = centerX + cos(iter * i) * radiusB,
                        vertex1_y = centerY - sin(iter * i) * radiusB,
                        vertex2_x = centerX + cos(iter * j) * radiusB,
                        vertex2_y = centerY - sin(iter * j) * radiusB;
                QGraphicsItem *line = scene->addLine(vertex1_x, vertex1_y, vertex2_x, vertex2_y);
                scene->addItem(line);
                QGraphicsTextItem *number = scene->addText(QString::number(i+1), QFont("Times"));
                number->setPos(centerX - cos(iter * i) * radiusB - radiusA,
                               centerY - sin(iter * i) * radiusB - radiusA);
            }
        }
    }
}

void QGraph::DrawNodes(QGraphicsScene* scene)
{
    int     centerX= scene->width() / 2,
            centerY = scene->height() / 2;
    double iter = 2 * 3.1415 / matrix.size();
    for (int i = 0; i < matrix.size(); i++){
        QGraphicsItem *node = scene->addEllipse(centerX - cos(iter * i) * radiusB - radiusA,
                                                centerY - sin(iter * i) * radiusB - radiusA, 2*radiusA, 2*radiusA,
                                                QPen(Qt::black), QBrush(Qt::red));
        scene->addItem(node);
        QGraphicsTextItem *number = scene->addText(QString::number(i+1), QFont("Times"));
        number->setPos(centerX - cos(iter * i) * radiusB - radiusA,
                       centerY - sin(iter * i) * radiusB - radiusA);
    }
}

void QGraph::DrawGraph(QGraphicsScene* scene)
{
    DrawLines(scene);
    DrawNodes(scene);
}
