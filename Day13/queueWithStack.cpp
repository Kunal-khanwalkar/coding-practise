#include<iostream>
#include<stack>
using namespace std;


template<typename T>
class queue
{
	stack<T> enter;
	stack<T> exit;
public:
	queue();
	~queue();
	
	bool isEmpty();
	void push(const T &item);
	void pop();
	T& front();
	T& back();
};

template<typename T>
queue<T>::queue()
{}

template<typename T>
queue<T>::~queue()
{}

template<typename T>
bool queue<T>::isEmpty()
{
	if(enter.empty() && exit.empty())
		return true;
	return false;
}

template<typename T>
void queue<T>::push(const T &item)
{
	enter.push(item);
}

template<typename T>
void queue<T>::pop()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
		return;
	}

	if(exit.empty())
	{
		while(!enter.empty())
		{
			exit.push(enter.top());
			enter.pop();
		}
	}

	exit.pop();
}


template<typename T>
T& queue<T>::front()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
		return exit.top();
	}

	if(exit.empty())
	{
		while(!enter.empty())
		{
			exit.push(enter.top());
			enter.pop();
		}
	}

	return exit.top();
}

template<typename T>
T& queue<T>::back()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
		return exit.top();
	}

	if(enter.empty())
	{
		while(!exit.empty())
		{
			enter.push(exit.top());
			exit.pop();
		}
	}

	return enter.top();
}






int main()
{
	queue<int> q;

	if(q.isEmpty())
		cout<<"\nQueue is empty";
	else
		cout<<"\nQueue is not empty";


	q.push(5);
	q.push(1);
	q.push(7);
	q.pop();
	q.push(0);
	q.push(4);
	q.push(6);
	q.pop();
	q.push(3);

	cout<<"\nFront: "<<q.front();
	cout<<"\nBack: "<<q.back();
}