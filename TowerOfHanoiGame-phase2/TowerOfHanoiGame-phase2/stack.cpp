#include "stdafx.h"
#include "stack.h"

stack::stack() :top(NULL), mysize(0) {}

stack::~stack()
{
	while (empty() == false) {
		pop();
	}
}

node::node(int x) :data(x), next(NULL) {}

void stack::push(int data)
{
	node *newnode = new node(data);
	if (mysize == 0) {
		top = newnode;
	}
	else {
		newnode->next = top;
		top = newnode;
	}
	mysize++;
}

void stack::pop()
{
	if (mysize == 0) {
		cout << "stack is empty";
	}
	else {
		node *ptr = top;
		top = top->next;
		delete(ptr);
	}
	mysize--;

}

void stack::game() {
	stack st1, st2, st3;
	for (int i = 5; i >0; i--) {
		st1.push(i);
	}
	int ctr = 0;
	int from;
	int to;
	while (st1.empty() == false || st2.empty() == false) {
		system("CLS");
		cout << "Number of moves: " << ctr << endl;
		cout << endl;
		node *dis1 = st1.top;
		node *dis2 = st2.top;
		node *dis3 = st3.top;
		cout << " Stack 1   Stack 2    Stack3 " << endl;
		cout << "------------------------------" << endl;
		while (dis1 != NULL || dis2 != NULL || dis3 != NULL) {

			if (dis1 != 0 && dis2 != 0 && dis3 != 0) {
				cout << "   " << dis1->data << "         " << dis2->data << "          " << dis3->data << endl;
				dis1 = dis1->next;
				dis2 = dis2->next;
				dis3 = dis3->next;
			}

			else if (dis1 == NULL && dis2 != NULL && dis3 != NULL) {
				cout << "             " << dis2->data << "          " << dis3->data << endl;
				dis2 = dis2->next;
				dis3 = dis3->next;
			}
			else if (dis1 != NULL && dis2 == NULL && dis3 != NULL) {
				cout << "   " << dis1->data << "                    " << dis3->data << endl;
				dis1 = dis1->next;
				dis3 = dis3->next;
			}
			else if (dis1 != NULL && dis2 != NULL && dis3 == NULL) {
				cout << "   " << dis1->data << "         " << dis2->data << endl;
				dis1 = dis1->next;
				dis2 = dis2->next;
			}
			else if (dis1 == NULL && dis2 == NULL && dis3 != NULL) {
				cout << "                        " << dis3->data << endl;
				dis3 = dis3->next;
			}
			else if (dis1 == NULL && dis2 != NULL && dis3 == NULL) {
				cout << "             " << dis2->data << endl;
				dis2 = dis2->next;
			}
			else if (dis1 != NULL && dis2 == NULL && dis3 == NULL) {
				cout << "   " << dis1->data << endl;
				dis1 = dis1->next;
			}
		}
		cout << endl;
		cout << "Move from: ";
		cin >> from;
		cout << "  Move to: ";
		cin >> to;
		if (from == 1 && to == 2) {
			if (st1.empty() == true) {
				cout << "operation failed!" << endl;
				continue;
			}
			else if (st2.empty() == true || st2.Top() > st1.Top()) {

				st2.push(st1.Top());
				st1.pop();
				ctr++;
				continue;
			}
			else {
				cout << "operation failed!" << endl;
				continue;
			}
		}
		else if (from == 1 && to == 3) {
			if (st1.empty() == true) {
				cout << "operation failed!" << endl;
				continue;
			}
			else if (st3.empty() == true || st3.Top() > st1.Top()) {
				st3.push(st1.Top());
				st1.pop();
				ctr++;
			}
			else {
				cout << "operation failed!" << endl;
				continue;
			}
		}
		else if (from == 2 && to == 1) {
			if (st2.empty() == true) {
				cout << "operation failed!" << endl;
				continue;
			}
			else if (st1.empty() == true || st1.Top() > st2.Top()) {
				st1.push(st2.Top());
				st2.pop();
				ctr++;
			}
			else {
				cout << "operation failed!" << endl;
				continue;
			}
		}
		else if (from == 2 && to == 3) {
			if (st2.empty() == true) {
				cout << "operation failed!" << endl;
				continue;
			}
			else if (st3.empty() == true || st3.Top() > st2.Top()) {
				st3.push(st2.Top());
				st2.pop();
				ctr++;
			}
			else {
				cout << "operation failed!" << endl;
				continue;
			}
		}
		else if (from == 3 && to == 1) {
			if (st3.empty() == true) {
				cout << "operation failed!" << endl;
				continue;
			}
			else if (st1.empty() == true || st1.Top() > st3.Top()) {
				st1.push(st3.Top());
				st3.pop();
				ctr++;
			}
			else {
				cout << "operation failed!" << endl;
				continue;
			}
		}
		else if (from == 3 && to == 2) {
			if (st3.empty() == true) {
				cout << "operation failed!" << endl;
				continue;
			}
			else if (st2.empty() == true || st2.Top() > st3.Top()) {
				st2.push(st3.Top());
				st3.pop();
				ctr++;
			}
			else {
				cout << "operation failed!" << endl;
				continue;
			}
		}
		else
			cout << "Invalid operation" << endl;
	}
	system("CLS");
	cout << "******* CONGRATULATIONS *******" << endl;
	cout << "Your score is: " << ctr << endl << endl;
}

void stack::TowerOfHanoi(int NumberOfDisks)
{
	int top;
	stack st1, st2, st3;								
	for (int i = NumberOfDisks; i >= 1; i--) {
		st1.push(i);
	}
	for (int i = 0; i < pow(2, NumberOfDisks)-1; i++) {
		node *dis1 = st1.top;
		node *dis2 = st2.top;
		node *dis3 = st3.top;
		displayTowerOfHanoi(dis1, dis2, dis3,  st1,st2, st3);

		if (st1.empty() == false) {
			if (st1.Top() == 1)
				top = 1;
		}
		if (st2.empty() == false) {
			if (st2.Top() == 1)
				top = 2;
		}
		if (st3.empty() == false) {
			if (st3.Top() == 1)
				top = 3;
		}
		if (i % 2 == 0) {
			if (top == 1) {
				st3.push(st1.Top());
				st1.pop();
			}
			else if (top == 2) {
				st1.push(st2.Top());
				st2.pop();
			}
			else if (top == 3) {
				st2.push(st3.Top());
				st3.pop();
			}
		}
		else {
			if (top == 1) {
				if (st3.empty() == true) {
					st3.push(st2.Top());
					st2.pop();
				}
				else if (st2.empty() == true) {
					st2.push(st3.Top());
					st3.pop();
				}
				else if (st2.Top() < st3.Top()) {
					st3.push(st2.Top());
					st2.pop();
				}
				else if (st2.Top() > st3.Top()) {
					st2.push(st3.Top());
					st3.pop();
				}
			}
			else if (top == 2) {
				if (st3.empty() == true) {
					st3.push(st1.Top());
					st1.pop();
				}
				else if (st1.empty() == true) {
					st1.push(st3.Top());
					st3.pop();
				}
				else if (st1.Top() < st3.Top()) {
					st3.push(st1.Top());
					st1.pop();
				}
				else if (st1.Top() > st3.Top()) {
					st1.push(st3.Top());
					st3.pop();
				}
				
			}
			else if (top == 3) {
				if (st2.empty() == true) {
					st2.push(st1.Top());
					st1.pop();
				}
				else if (st1.empty() == true) {
					st1.push(st2.Top());
					st2.pop();
				}
				else if (st1.Top() < st2.Top()) {
					st2.push(st1.Top());
					st1.pop();
				}
				else if (st1.Top() > st2.Top()) {
					st1.push(st2.Top());
					st2.pop();
				}
			}
		}
	}
	
	node *dis1 = st1.top;
	node *dis2 = st2.top;
	node *dis3 = st3.top;
	displayTowerOfHanoi(dis1, dis2, dis3, st1, st2, st3);
	cout << endl << endl;
	cout << "*************** DONE***************" << endl;
	
}

void stack::displayTowerOfHanoi(node *dis1, node *dis2, node *dis3, stack st1, stack st2, stack st3)
{


	cout << endl << endl;
	cout << " Stack 1   Stack 2    Stack3 " << endl;
	cout << "------------------------------" << endl;
	while (dis1 != NULL || dis2 != NULL || dis3 != NULL) {

		if (dis1 != 0 && dis2 != 0 && dis3 != 0) {
			cout << "   " << dis1->data << "         " << dis2->data << "          " << dis3->data << endl;
			dis1 = dis1->next;
			dis2 = dis2->next;
			dis3 = dis3->next;
		}

		else if (dis1 == NULL && dis2 != NULL && dis3 != NULL) {
			cout << "             " << dis2->data << "          " << dis3->data << endl;
			dis2 = dis2->next;
			dis3 = dis3->next;
		}
		else if (dis1 != NULL && dis2 == NULL && dis3 != NULL) {
			cout << "   " << dis1->data << "                    " << dis3->data << endl;
			dis1 = dis1->next;
			dis3 = dis3->next;
		}
		else if (dis1 != NULL && dis2 != NULL && dis3 == NULL) {
			cout << "   " << dis1->data << "         " << dis2->data << endl;
			dis1 = dis1->next;
			dis2 = dis2->next;
		}
		else if (dis1 == NULL && dis2 == NULL && dis3 != NULL) {
			cout << "                        " << dis3->data << endl;
			dis3 = dis3->next;
		}
		else if (dis1 == NULL && dis2 != NULL && dis3 == NULL) {
			cout << "             " << dis2->data << endl;
			dis2 = dis2->next;
		}
		else if (dis1 != NULL && dis2 == NULL && dis3 == NULL) {
			cout << "   " << dis1->data << endl;
			dis1 = dis1->next;
		}
	
	}
}
bool stack::empty()
{
	if (mysize == 0) {
		return true;
	}
	else {
		return false;
	}

}

void stack::reverse()
{
	node *previousP = NULL;
	node *nextP = NULL;
	node *currentP = top;
	while (currentP != NULL) {
		nextP = currentP->next;
		currentP->next = previousP;
		previousP = currentP;
		currentP = nextP;
	}
	top = previousP;
}

void stack::swap(int x, int y) {
	node *ptr1 = top;
	node *ptr2 = top;
	int temp;
	bool found1 = false;
	bool found2 = false;
	for (int i = 0; i < mysize; i++) {
		if (ptr1->data == x) {
			found1 = true;
			break;
		}
		ptr1 = ptr1->next;
	}
	for (int i = 0; i < mysize; i++) {
		if (ptr2->data == y) {
			found2 = true;
			break;
		}
		ptr2 = ptr2->next;
	}
	if (found1 == true && found2 == true) {
		temp = ptr1->data;
		ptr1->data = ptr2->data;
		ptr2->data = temp;
	}
	else {
		cerr << "not found!" << endl;
	}
}

stack & stack::concatenate(stack &s1)
{
	if (s1.empty() == true) {
		s1 = *this;
	}

	else {
		node *ptr1 = s1.top;
		node *ptr2 = this->top;

		for (int i = 0; i < s1.mysize - 1; i++) {
			ptr1 = ptr1->next;
		}
		for (int i = 0; i < this->mysize; i++) {
			node *newnode = new node(ptr2->data);
			ptr1->next = newnode;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
			s1.mysize++;
		}
		return s1;
	}
}

void stack::display()
{
	node *dis = top;
	cout << "  MY STACK \n ------------" << endl;
	for (int i = 0; i < mysize; i++) {
		cout << "      " << dis->data << endl;
		dis = dis->next;
	}

}

int stack::Top()
{
	return top->data;
}

int stack::count()
{
	return mysize;
}

void stack::search(int element)
{
	node *ptr = top;
	bool found = false;
	if (mysize == 0) {
		cerr << "THE STACK IS EMPTY" << endl;
	}
	else {
		for (int i = 0; i < mysize; i++) {
			if (ptr->data == element) {
				cout << i + 1;
				found = true;
			}
			ptr = ptr->next;
		}
		if (found == false) {
			cerr << "NOT FOUND!" << endl;
		}
	}
}

stack & stack::operator =(stack &s)
{
	this->~stack();
	this->mysize = s.mysize;
	top = 0;
	node *Rptr = s.top;
	node *newnode = new node(Rptr->data);
	top = newnode;
	node*Cptr = top;
	for (int i = 0; i < s.mysize; i++) {
		Rptr = Rptr->next;
		if (Rptr == NULL)
			break;
		node *newnode = new node(Rptr->data);
		Cptr->next = newnode;
		Cptr = Cptr->next;
	}
	return*this;
}

stack operator +(stack s1, stack s2) {
	node *ptr1 = s1.top;
	node *ptr2 = s2.top;
	stack s3;
	node *newnode = new node(ptr1->data + ptr2->data);
	s3.mysize++;
	s3.top = newnode;
	node *ptr3 = s3.top;
	while (true) {
		if (ptr1->next == 0 || ptr2->next == 0)
			break;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		node *newnode = new node(ptr1->data + ptr2->data);
		ptr3->next = newnode;
		ptr3 = ptr3->next;
		s3.mysize++;
	}
	if (s2.mysize > s1.mysize) {
		for (int i = 0; i < (s2.mysize - s1.mysize); i++) {
			ptr2 = ptr2->next;
			node *newnode = new node(ptr2->data);
			ptr3->next = newnode;
			ptr3 = ptr3->next;
			s3.mysize++;
		}
	}
	else if (s1.mysize > s2.mysize) {
		for (int i = 0; i < (s1.mysize - s2.mysize); i++) {
			ptr1 = ptr1->next;
			node *newnode = new node(ptr1->data);
			ptr3->next = newnode;
			ptr3 = ptr3->next;
			s3.mysize++;
		}
	}
	return s3;
}

stack operator *(stack s1, stack s2) {
	node *ptr1 = s1.top;
	node *ptr2 = s2.top;
	stack s3;
	node *newnode = new node(ptr1->data * ptr2->data);
	s3.mysize++;
	s3.top = newnode;
	node *ptr3 = s3.top;
	while (true) {
		if (ptr1->next == 0 || ptr2->next == 0)
			break;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		node *newnode = new node(ptr1->data * ptr2->data);
		ptr3->next = newnode;
		ptr3 = ptr3->next;
		s3.mysize++;
	}
	if (s2.mysize > s1.mysize) {
		for (int i = 0; i < (s2.mysize - s1.mysize); i++) {
			ptr2 = ptr2->next;
			node *newnode = new node(ptr2->data);
			ptr3->next = newnode;
			ptr3 = ptr3->next;
			s3.mysize++;
		}
	}
	else if (s1.mysize > s2.mysize) {
		for (int i = 0; i < (s1.mysize - s2.mysize); i++) {
			ptr1 = ptr1->next;
			node *newnode = new node(ptr1->data);
			ptr3->next = newnode;
			ptr3 = ptr3->next;
			s3.mysize++;
		}
	}
	return s3;
}

stack operator -(stack s1, stack s2) {
	node *ptr1 = s1.top;
	node *ptr2 = s2.top;
	stack s3;
	node *newnode = new node(ptr1->data - ptr2->data);
	s3.mysize++;
	s3.top = newnode;
	node *ptr3 = s3.top;
	while (true) {
		if (ptr1->next == 0 || ptr2->next == 0)
			break;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		node *newnode = new node(ptr1->data - ptr2->data);
		ptr3->next = newnode;
		ptr3 = ptr3->next;
		s3.mysize++;
	}
	if (s2.mysize > s1.mysize) {
		for (int i = 0; i < (s2.mysize - s1.mysize); i++) {
			ptr2 = ptr2->next;
			node *newnode = new node(ptr2->data);
			ptr3->next = newnode;
			ptr3 = ptr3->next;
			s3.mysize++;
		}
	}
	else if (s1.mysize > s2.mysize) {
		for (int i = 0; i < (s1.mysize - s2.mysize); i++) {
			ptr1 = ptr1->next;
			node *newnode = new node(ptr1->data);
			ptr3->next = newnode;
			ptr3 = ptr3->next;
			s3.mysize++;
		}
	}
	return s3;
}

stack::stack(const stack &original)
{
	mysize = original.mysize;
	if (mysize == 0) {}
	else {
		node *origptr, *ptr1;
		top = new node(original.top->data);
		ptr1 = top;
		origptr = original.top->next;
		while (origptr != 0)
		{
			ptr1->next = new node(origptr->data);
			origptr = origptr->next;
			ptr1 = ptr1->next;
		}
	}
}
