#pragma once
#include <iostream>
#include "GL/glut.h"
#include <windows.h>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

class Tree
{
	int data;
	Tree* left;
	Tree* right;
	Tree* parent;	
public:
	GLfloat x = 0, y = 4; //(0;4) - координаты корня
	int state, level = 1;	
	Tree();
	Tree(int newData);
	~Tree();
	void insertRight(int newData);
	void insertLeft(int newData);
	void insertNewNode(Tree*& root, int newData);
	void InOrder(Tree* node);
	int getHeight();
	Tree* Find_a_Node(int newData);	
	int FindMax();	
	friend void LevelCounter(Tree* root);
	friend void CountLevels(Tree* root, void (*LevelCounter)(Tree* root));
	friend void Coords(Tree* node);
	friend void CoordsCalculate(Tree* node, void (*Coords)(Tree* node));
	friend void DrawOneNode(Tree* root);
	friend void DrawNodes(Tree* root, void (*DrawOneNode)(Tree* root));
	friend void DrawOneLine(Tree* root);
	friend void DrawLines(Tree* root, void (*DrawOneLine)(Tree* root));
	void drawTree(int argc, char** argv, int win_height, int win_width);
};

//friend void CoordsCounting(Tree* root, int windows_height, int window_width);
