#include "graph.h"
#include "ui_graph.h"
#include <cmath>
using namespace std;

/* CALCULATING COORDS FOR PRINTING */
//
int     radiusA = 18,
        radiusB = 170;

int Graph::GetWeight(const int vertex1, const int vertex2)
{
    if (vertex1 >= 0 && vertex1 < copyOfMatrix.size() && vertex2 >=0 && vertex2 < copyOfMatrix.size())
        return copyOfMatrix[vertex1][vertex2];
    else
        return 0;
}

void Graph::DrawLines(QGraphicsScene* scene)
{
    int     centerX= scene->width() / 2,
            centerY = scene->height() / 2;
    QPen pen(Qt::black);
    pen.setWidth(3);
    double iter = 2 * 3.1415 / copyOfMatrix.size();
    for (int i = 0; i < copyOfMatrix.size(); i++){
        for (int j = 0; j < i; j++){
            if (GetWeight(i, j) > 0){
                int     vertex1_x = centerX + cos(iter * i) * radiusB,
                        vertex1_y = centerY - sin(iter * i) * radiusB,
                        vertex2_x = centerX + cos(iter * j) * radiusB,
                        vertex2_y = centerY - sin(iter * j) * radiusB;
                QGraphicsItem *line = scene->addLine(vertex1_x, vertex1_y, vertex2_x, vertex2_y, pen);
                scene->addItem(line);
                QGraphicsTextItem *number = scene->addText(QString::number(GetWeight(i, j)), QFont("Times"));
                number->setPos((vertex2_x + vertex1_x) / 2, (vertex2_y + vertex1_y) / 2);
            }
        }
    }
}

void Graph::DrawNodes(QGraphicsScene* scene)
{
    int     centerX = scene->width() / 2,
            centerY = scene->height() / 2;
    double iter = 2 * 3.1415 / copyOfMatrix.size();
    QPen pen(Qt::black);
    pen.setWidth(2);
    for (int i = 0; i < copyOfMatrix.size(); i++){
        QGraphicsItem *node = scene->addEllipse(centerX + cos(iter * i) * radiusB - radiusA,
                                                centerY - sin(iter * i) * radiusB - radiusA, 2*radiusA, 2*radiusA,
                                                pen, QBrush(Qt::red));
        scene->addItem(node);
        QGraphicsTextItem *number = scene->addText(QString::number(i+1), QFont("Times"));
        number->setPos(centerX + cos(iter * i) * radiusB - radiusA,
                       centerY - sin(iter * i) * radiusB - radiusA);
    }
}

void Graph::DrawGraph(QGraphicsScene* scene)
{
    DrawLines(scene);
    DrawNodes(scene);
}
//

void Graph::PrintMatrix()
{
    cout << endl;
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    cout << "\t" <<matrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
}

void Graph::reductRow()
{
    for (int i = 0; i < matrix.size(); i++) {
        int min = INT_MAX; // специально завышаем значение до максимума
        for (int j = 0; j < matrix[0].size(); j++) {
            if (min > matrix[i][j] && matrix[i][j] >= 0)
                min = matrix[i][j];
        }
        if (min != INT_MAX) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] >= 0)
                    matrix[i][j] -= min;
            }
        }
    }
}

void Graph::reductCol()
{
    for (int i = 0; i < matrix.size(); i++) {
        int min = INT_MAX; // специально завышаем значение до максимума
        for (int j = 0; j < matrix[0].size(); j++) {
            if (min > matrix[j][i] && matrix[j][i] >= 0)
                min = matrix[j][i];
        }
        if (min != INT_MAX) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[j][i] >= 0)
                    matrix[j][i] -= min;
            }
        }
    }
}

int Graph::findMinCol(int a, int b)
{
    int min = INT_MAX;
    for (int i = 0; i < matrix.size(); i++) {
        if (min > matrix[i][b] && matrix[i][b] >= 0 && i != a) {
            min = matrix[i][b];
        }
    }
    if (min == INT_MAX) return 0;
    return min;
}

int Graph::findMinRow(int a, int b)
{
    int min = INT_MAX;
        for (int j = 0; j < matrix[0].size(); j++) {
            if (min > matrix[a][j] && matrix[a][j] >= 0 && b != j)
                min = matrix[a][j];
        }
        if (min == INT_MAX) return 0;
    return min;
}

Edge Graph::FindEdge()
{
    int max = -1;
    Edge edge{ 0, 0 }; // Edge – структура с полями from и to

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) { // ищем нулевой элемент
             // считаем сумму минимальных элементов в строке и столбце
                int t = findMinCol(i, j) + findMinRow(i, j);
                if (t > max) {
                    max = t;
                    edge.from = i;
                    edge.to = j;
                }
            }
        }
    }
    matrix[edge.from][edge.to] = -1;
    matrix[edge.to][edge.from] = INT_MAX;
    for (int i = 0; i < matrix.size(); i++) {
        matrix[edge.from][i] = -1; // чистим строку
        matrix[i][edge.to] = -1; // чистим столбец
    }
    PrintMatrix();
    return edge;
}

string Graph::getPath(vector<Edge> result)
{
    string res = "";
    Edge current = result[0];
    res += to_string(result[0].from + 1) + "->" + to_string(result[0].to + 1) + "->";
    int count = 0;
    while (count < result.size() - 1) {
        for (int i = 0; i < result.size(); i++) {
            Edge next = result[i];
            if (current.to == next.from) {
                count++;
                res += to_string(next.to + 1);
                current = next;
                if (count < result.size() - 1)
                    res += "->";
                break;
            }
        }
    }
    return res;
}

int Graph::getLength(vector<Edge> solution)
{
    int len = 0;
    Edge current = solution[0];
    len += copyOfMatrix[current.from][current.to]; // растояние от первой вершины до второй
    int count = 0;
    while (count < solution.size() - 1) {
        for (int i = 0; i < solution.size(); i++) {
            Edge next = solution[i];
            if (current.to == next.from) {
                count++;
                len += copyOfMatrix[current.to][next.to];
                current = next;
                break;
            }
        }
    }
    return len;
}

void Graph::ReadFunction()
{
    string row, tmpRow;
    int j = 0, k = 0;
   ifstream fin;
    fin.open("forMatrix.txt");
    while (getline(fin, row)){
        for (int i = 0; i < row.length(); i++){
            if (row[i] != ' ')
                tmpRow += row[i];
            else{
                copyOfMatrix[j][k] = stoi(tmpRow);
                k++;
            }
        }
        j++;
    }
    fin.close();
}

vector<Edge> Graph::KommiFunction()
{
    vector<vector<int>> matr = matrix;
    vector<Edge> result;
    int i = 0;
    int count = matr.size();
    while (i != count) {
         reductRow(); // редукция по строкам
         reductCol(); // редукция по cтолбцам
         result.push_back(FindEdge()); // сохраняем найденные границы
         i++;
         cout << "=======================================================";
    }
    cout << endl;
    return result;
}

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    copyOfMatrix = { {0, 7, 16, 21, 2, 17 },
                   {13, 0, 21, 15, 43, 23 },
                   { 25, 3, 0, 31, 17, 9 },
                   { 13, 10, 27, 0, 33, 12 },
                       { 9, 2, 19, 14, 0, 51 },
                       { 42, 17, 5, 9, 23, 0 } };
    matrix = { {INT_MAX, 7, 16, 21, 2, 17 },
    {13, INT_MAX, 21, 15, 43, 23 },
    { 25, 3, INT_MAX, 31, 17, 9 },
    { 13, 10, 27, INT_MAX, 33, 12 },
        { 9, 2, 19, 14, INT_MAX, 51 },
        { 42, 17, 5, 9, 23, INT_MAX } };

    vector<Edge> paths = KommiFunction();
    string path = getPath(paths);
    int len = getLength(paths);

    QPixmap backgR(":/prefix1/pics/188f46b234ec79b3823b31ac77c0fa52.jpg");
    backgR = backgR.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgR);
    this->setPalette(palette);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    scene->clear();

    QString p = QString::fromStdString(path);
    QString l = QString::number(len);
    ui->len->setText(l);
    ui->path->setText(p);
    DrawGraph(scene);
}

Graph::~Graph()
{
    delete ui;
    delete scene;
}
