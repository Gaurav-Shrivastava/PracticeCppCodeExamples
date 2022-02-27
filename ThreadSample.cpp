#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//mutex cout_mutex;

class TestThread
{
public:

	void foo(string threadname) 
	{ 
		cout_mutex.lock();
		cout << threadname << " --- Thread id: " << std::hash<std::thread::id>()(std::this_thread::get_id()) << endl;
		cout << threadname << " called foo()." << endl; 
		cout_mutex.unlock();	
	}

	void bar(string threadname) 
	{
		cout_mutex.lock(); 
		cout << threadname << " --- Thread id: " << std::hash<std::thread::id>()(std::this_thread::get_id()) << endl;
		cout << threadname << " called bar()." << endl; 
		cout_mutex.unlock();	
	}

	mutex cout_mutex;
};

int main()
{
	TestThread tobj;
	
	thread t1(&TestThread::foo, &tobj, "Thread-t1-foo");
	thread t2(&TestThread::bar, &tobj, "Thread-t2-bar");
	//thread t1(&TestThread::foo, &tobj, "Thread-t1");
	
	t1.join();
	t2.join();
	
	cout << "C++ Version: " << __cplusplus << endl;
	return 0;
}
