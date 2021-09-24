#include "Tree.h"
#include <vector>
#include <algorithm>
int depth = 0, width = 0, maxim = 0;
Tree* tree = new Tree(5);
float radiusA = 0.35; //радиус окружности
void PrintingInfo(int &maxim, vector<int> &arr);
void DrawCircle(char colour, GLfloat x, GLfloat y, float radiusB, int count);
void DrawOutline(float tmp_x, float tmp_y, float radiusB);
void drawNode(const char* str, GLfloat x, GLfloat y, char colour);
void reshape(int height, int width);
void display();
void LevelCounter(Tree* root);
void Coords(Tree* node);

void Tree::drawTree(int argc, char** argv, int win_height, int win_width)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(win_height, win_width);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("My Tree");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);	
	glutMainLoop();
}

int main(int argc, char** argv)
{
	system("chcp 1251>nul");
    vector<int> arr = { 3,8,6,10,4,7,1,12,-1,3 };	
    for (int i = 0; i < arr.size(); i++) {
        tree->insertNewNode(tree, arr[i]);
    }   
	PrintingInfo(maxim, arr);
	CountLevels(tree, LevelCounter);
	CoordsCalculate(tree, Coords);
    tree->drawTree(argc, argv, 960, 720);	
    return 0;
}

void LevelCounter(Tree* root)
{
	if (root->parent != NULL)
		root->level = root->parent->level + 1; //если предок существует, то +1	
	if (depth < root->level) //глубина дерева
		depth = root->level;
}

void CountLevels(Tree* root, void (*LevelCounter)(Tree* root))
{
	if (root == NULL)
		return;
	(*LevelCounter)(root);	
	CountLevels(root->left, LevelCounter);
	CountLevels(root->right, LevelCounter);
}

void Coords(Tree* node)
{
	if (node->parent != NULL) {
		if (node->level == 2)
			node->x = node->parent->x + node->state * (pow(2, depth - 1) / 2);
		else
			node->x = node->parent->x + node->state * 
			(pow(2, depth - 1) / pow(2, node->level - 1));
		node->y = node->parent->y - 1;
	}
}

void CoordsCalculate(Tree* node, void (*Coords)(Tree* node))
{
	if (node == NULL) 
		return;
	(*Coords)(node);
	if (node->left != NULL) {
		node->left->state = -1;
		CoordsCalculate(node->left, Coords);
	}
	if (node->right != NULL) {
		node->right->state = 1;
		CoordsCalculate(node->right, Coords);
	}
	return;
}

void DrawCircle(char colour, GLfloat x, GLfloat y, float radiusB, int count)
{
	if (colour == 'g')	{
		glColor3f(0.0, 250.0, 0.0); //зелёный цвет для отрисовки треугольников		
	}
	else if (colour == 'r') {
		glColor3f(250.0, 0.0, 0.0); //красный цвет для отрисовки треугольников		
	}	
	glBegin(GL_TRIANGLE_FAN); //отрисовка треугольников вокруг одной вершины, используется для рисования окружности
	glVertex2f(x, y); //задание первой точки
	for (int i = 0; i <= count; i++) { //отрисовка 50 треугольников для получения "плавности окружности"
		glVertex2f(
			(x + (radiusA * cos(i * count))),
			(y + (radiusB * sin(i * count)))); //параметрическое задание окружности
	}
	glEnd();
}

void DrawOutline(float tmp_x, float tmp_y, float radiusB)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = 0; i <= radiusA; i++) {
		for (int j = 0; j <= 540; j++) {
			tmp_x = radiusA * sin(j) + tmp_x;
			tmp_y = radiusB * cos(j) + tmp_y;
			glVertex2f(tmp_x - 0.35, tmp_y - 0.1);
		}
	}
	glEnd();
}

void drawNode(const char* str, GLfloat x, GLfloat y, char colour)
{
	double coefficient = 0;
	coefficient = (4 + depth) / pow(2, depth); //нахождение полуоси эллипса  по Y
	float radiusB = coefficient * radiusA;	
	int count = 50;
	DrawCircle(colour, x, y, radiusB, count);
	DrawOutline(x, y, radiusB);
	glColor3f(0.0, 0.0, 0.0); // чёрный цвет для текста
	glRasterPos2f(x - 0.075, y - 0.075); //сдвиг текста по центру относительно узла (простой подбор констант)
	const char* p;
	for (p = str; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p); //задание шрифта для текста, значение
	}
}
//отрисовка линий (используется в Display)
void DrawOneLine(Tree* root)
{
	if (root->parent != NULL) {
		glBegin(GL_LINES);
		glVertex2d(root->parent->x, root->parent->y); //соединяем предка и потомка
		glVertex2d(root->x, root->y);
		glEnd();
	}
}
//также прямой проход для отрисовки всех линий между узлами
void DrawLines(Tree* root, void (*DrawOneLine)(Tree* root))
{
	if (root == NULL)
		return;	
	(*DrawOneLine)(root);	
	DrawLines(root->left, DrawOneLine);
	DrawLines(root->right, DrawOneLine);
}

//void CoordsCounting(Tree* root, int windows_height, int window_width)
//{
//	if (root->parent == NULL) {
//		root->x = 0;
//		root->y = 4;		
//	}
//	else {		
//		root->y = root->parent->y - 1;
//		if (root->parent->data <= root->data) {			
//			if (root->right != NULL)
//				root->x = root->parent->x + 1;//++cor.x;//			
//			return;
//		}
//		else {
//			if (root->left != NULL)
//				root->x = root->parent->x - 1;			
//			return;
//		}
//	}
//	/*if (width != depth) {
//		int k_x = (window_width - 2 * (10 + radiusA)) / (width - 1);
//		int k_y = (windows_height - 2 * (10 + radiusA)) / (depth - 1);
//		root->x = k_x * root->x + 10 + radiusA;
//		root->y = windows_height - k_y*root->y-10-radiusA;
//	}
//	else {
//		root->x = window_width / 2;
//		root->y = windows_height / 2;
//	}*/
//}

void DrawOneNode(Tree* root)
{
	char colour;
	if (root->parent != NULL) {
		if (root->data == maxim)
			colour = 'r';
		else
			colour = 'g';
		drawNode(to_string(root->data).c_str(), root->x, root->y, colour);
	}
}

void DrawNodes(Tree* root, void (*DrawOneNode)(Tree* root))
{
	char colour;
	if (root == NULL)
		return;
	(*DrawOneNode)(root);
	DrawNodes(root->left, DrawOneNode);
	DrawNodes(root->right, DrawOneNode);
	if (root->data == maxim) {
		colour = 'r';
	}
	else {
		colour = 'g';
	}
	drawNode(to_string(tree->data).c_str(), tree->x, tree->y, colour);
}

void reshape(int height, int width)
{
	glMatrixMode(GL_PROJECTION); //все последующие изменения будут применяться к проекционной матрице
	glLoadIdentity();
	glViewport(0, 0, height, width); //область просмотра (c точки 0:0) на ширину и длину окна
	gluOrtho2D(-pow(2, depth - 1), pow(2, depth - 1), -depth, 5); //ортогональная проекция
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2); //задание ширины линий
	DrawLines(tree, DrawOneLine); //рекурсивная функция отрисовки линий между узлами
	DrawNodes(tree, DrawOneNode); //функция отрисовки узлов с текстом внутри
	glutSwapBuffers(); //обмен между 2 матрицами (двойная буферизация)
}

void PrintingInfo(int &maxim, vector<int> &arr)
{
	maxim = *max_element(arr.begin(), arr.end());
	cout << "Максимальный элемент в дереве=" << maxim << endl;
	depth = tree->getHeight();//глубина дерева
	width = pow(2, depth - 1);//ширина (максимальная)
	cout << "Глубина дерева: " << depth << endl
		<< "Ширина дерева: " << width << endl;
}