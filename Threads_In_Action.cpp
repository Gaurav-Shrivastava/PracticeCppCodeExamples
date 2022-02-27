#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex cout_mutex;

class Shape
{
public:
	void Circle(string str)
	{ 
		PrintString(str);
	}
	
	void Square(string str)
	{ 
		PrintString(str);
	}

	void Rectange(string str)
	{ 
		PrintString(str);
	}
	
	void Triangle(string str)
	{ 
		PrintString(str);
	}
	
	void Pentagon(string str)
	{ 
		PrintString(str); 
	}
	
	void Hexagon(string str)
	{ 
		PrintString(str);
	}

	void PrintString(string str)
	{
		cout_mutex.lock(); 
		cout << str << endl; 
		cout_mutex.unlock();
	}
};

int main()
{
	Shape sobj;
	thread t1(&Shape::Circle, sobj, "Shape::Circle()");
	thread t2(&Shape::Square, sobj, "Shape::Square()");
	thread t3(&Shape::Rectange, sobj, "Shape::Rectange()");
	thread t4(&Shape::Triangle, sobj, "Shape::Triangle()");
	thread t5(&Shape::Pentagon, sobj, "Shape::Pentagon()");
	thread t6(&Shape::Hexagon, sobj, "Shape::Hexagon()");
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();

	return 0;
}