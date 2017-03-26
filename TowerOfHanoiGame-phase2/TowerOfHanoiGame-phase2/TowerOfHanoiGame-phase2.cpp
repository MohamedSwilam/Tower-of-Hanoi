// TowerOfHanoiGame-phase2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack.h"



int main()
{
	stack game;
	int n=0;
	cout << "Enter number of disks: ";
	cin >> n;
	game.TowerOfHanoi(n);
	cout << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << endl;
	stack st1,st2,Sum,Multiply,Minus,copy;
	/*  ********* PUSH ********** */
	for (int i = 0; i < 7; i++) {
	st1.push(i);
	}

	cout << "MY FIRST STACK:" << endl;
	st1.display();
	cout << endl;
	/*  ********* POP ********** */
	st1.pop();
	st1.pop();
	cout << "MY FIRST STACK AFTER POP TWO TIMES:" << endl;
	st1.display();
	cout << endl;
	/*  ********* REVERSE ********** */
	st1.reverse();
	cout << "MY FIRST STACK AFTER REVERSE: " << endl;
	st1.display();
	cout << endl;
	/*  ********* SWAP ********** */
	st1.swap(4, 0);
	cout << "MY FIRST STACK AFTER SWAP 0 AND 4: " << endl;
	st1.display();
	cout << endl;
	/*  ********* SEARCH ********** */
	cout << "SEARCHING ON THE POSITIONS OF ELEMENT 3 IN THE FIRST STACK:  " ;
	st1.search(3);
	cout << endl;
	cout << endl;
	/*  ********* COUNT ********** */
	cout << "NUMBER OF THE ELEMENTS IN THE FIRST STACK: "<< st1.count()<<endl<<endl;
	/*  ********* = OPERATOR ********** */
	st2 = st1;
	cout << "THE SECOND STACK AFTER EQUALIZING IT WITH THE FIRST STACK: " << endl;
	st2.display();
	cout << endl;
	/*  ********* + OPERATOR ********** */
	cout << "ADDING THE FIRST STACK WITH THE SECOND STACK: " << endl;
	Sum = st1 + st2;
	Sum.display();
	cout << endl;
	/*  ********* * OPERATOR ********** */
	cout << "MULTIPLYING THE FIRST STACK WITH THE SECOND STACK: " << endl;
	Multiply = st1*st2;
	Multiply.display();
	cout << endl;
	/*  ********* - OPERATOR ********** */
	cout << "SUBTRACTING THE SECOND STACK FROM THE FIRST STACK: " << endl;
	Multiply = st1-st2;
	Multiply.display();
	cout << endl;
	/*  ********* CONCATINATE ********** */
	cout << "NESTING THE SECOND STACK IN THE FIRST STACK: " << endl;
	st2.concatenate(st1);
	st1.display();
	cout << endl;
	/* ********* COPY CONSTRUCTOR ********* */
	copy=stack(st1);
	cout << "Copy of stack1: " << endl;
	copy.display();
	cout << endl;
	return 0;
}
