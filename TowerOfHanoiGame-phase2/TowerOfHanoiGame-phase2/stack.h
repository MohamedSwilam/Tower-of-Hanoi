#pragma once
#include <iostream>
using namespace std;


class node
{
public:

	node(int);

	int data=0;
	node *next;
};

class stack
{

public:
	stack();
	~stack();

	void push(int);
	void pop();
	void game();
	void TowerOfHanoi(int);
	void displayTowerOfHanoi(node * ptr, node * ptr2, node * ptr3, stack st1, stack st2, stack st3);
	bool empty();
	void swap(int, int);
	void reverse();
	stack& concatenate(stack&);
	void display();
	stack& operator =(stack&);
	int Top();
	int count();
	void search(int);
	int mysize;
	node *top=0;
	stack::stack(const stack & original);
};
stack operator +(stack, stack);
stack operator *(stack, stack);
stack operator -(stack, stack);
