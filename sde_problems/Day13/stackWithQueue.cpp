#include<iostream>
#include<queue>
using namespace std;


template<typename T>
class stack
{
	queue<T> enter;
	queue<T> exit;
public:
	stack();
	~stack();
	
	bool isEmpty();
	void push(const T &item);
	void pop();
	T& top();	
};

template<typename T>
stack<T>::stack()
{}

template<typename T>
stack<T>::~stack()
{}

template<typename T>
bool stack<T>::isEmpty()
{
	if(enter.empty() && exit.empty())
		return true;
	return false;
}

template<typename T>
void stack<T>::push(const T &item)
{
	enter.push(item);
}

template<typename T>
void stack<T>::pop()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
		return;
	}

	
	while(enter.size() != 1)
	{
		exit.push(enter.front());
		enter.pop();
	}	

	enter.pop();

	swap(enter,exit);
}


template<typename T>
T& stack<T>::top()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
		return exit.front();
	}

	while(enter.size() != 1)
	{
		exit.push(enter.front());
		enter.pop();
	}	


	T& temp = enter.front();
	enter.pop();
	exit.push(temp);

	swap(enter,exit);

	return temp;
}





int main()
{
	stack<int> s;

	if(s.isEmpty())
		cout<<"\nQueue is empty";
	else
		cout<<"\nQueue is not empty";


	s.push(5);
	s.push(1);
	s.push(7);
	s.pop();
	s.push(0);
	s.push(4);
	s.push(6);
	s.pop();
	s.push(3);

	cout<<"\nTop: "<<s.top();	
}