#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Queue
{
public:
	Queue() :size(10), front(-1), rear(-1) { array = new T[size]; };
	~Queue() { delete array; };
	bool Full();
	bool Empty();
	void Push(T);
	T Pop();
	void PrintQueue();
private:
	T *array;
	int size;
	int front;
	int rear;
};

int main()
{
	Queue<int> queue;
	queue.Push(10);
	queue.Push(11);
	queue.Push(12);
	queue.Pop();
	queue.Push(13);
	queue.PrintQueue();

	Queue<char> queue1;
	queue1.Push('A');
	queue1.Push('B');
	queue1.Push('C');
	queue1.Pop();
	queue1.Push('D');
	queue1.PrintQueue();

	system("pause");
	return 0;
}

template <class T>
bool Queue<T>::Full()
{
	if (rear + 1 == size) { return true; }
	else { return false; };
}

template <class T>
bool Queue<T>::Empty()
{
	if (rear == -1) { return true; }
	else { return false; };
}

template <class T>
void Queue<T>::Push(T x)
{
	if (Full() == true)
	{
		size++;
	}
	array[++rear] = x;
	front++;
}

template <class T>
T Queue<T>::Pop()
{
	if (Empty() == true) { cout << "Queue is empty!!" << endl;}
	else
	{
		T tmp = array[front--];
		for (int i = 0; i < rear; i++)
		{
			array[i] = array[i + 1];
		}
		rear--;
		return tmp;
	}
}

template <class T>
void  Queue<T>::PrintQueue()
{
	for (int i = 0; i <= rear; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}