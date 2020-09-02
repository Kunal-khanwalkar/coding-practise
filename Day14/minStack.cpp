#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class minStack : public stack<T>
{
	stack<T> min;
public:
	void pop();
	T& top();
	void push(const T &item);
	T& getMin();
};


template<typename T>
void minStack<T>::push(const T &item)
{
	if(!stack<T>::empty())
	{
		stack<T>::push(item);
		min.push(item);
	}
	else
	{
		stack<T>::push(item);
		typename x = min.top();		
		if(item < x)
			min.push(item);
		else
			min.push(x);
	}
}


template<typename T>
void minStack<T>::pop()
{
	stack<T>::pop();
}

template<typename T>
T& minStack<T>::top()
{
	return stack<T>::top();
}

template<typename T>
T& minStack<T>::getMin()
{
	return min.top();
}




int main()
{
	minStack<int> ms;
	ms.push(10);
	ms.push(20);
	ms.push(30);
	cout<<ms.getMin()<<endl;
	ms.push(5);
	cout<<ms.getMin()<<endl;
	return 0;
}