#include "graph.h"
using namespace std;

Graph::Graph()
{
    matrix = { {0, 34, 8, 0, 2, 21 },
               {24, 0, 57, 45, 5, 0 },
               {8, 57, 0, 0, 0, 0 },
                {0, 45, 0, 0, 3, 0 },
                {2, 5, 0, 3, 0, 13 },
               {21, 0, 0, 0, 13, 0 } };
}

Graph::~Graph()
{
}


