#include <boost\thread.hpp>

#ifndef __Thread_H
#define __Thread_H


enum ThreadState
{
			READY,
			RUNNING,
			BLOCKED,
			TERMINATED
};

class IThread{

public:
	IThread();

	virtual ~IThread();

	void run();

	ThreadState getThreadState();

	bool isReady();
	bool isRunning();
	bool isBlocked();
	bool isTerminated();

private:

	virtual void startThread() = 0;
	
	boost::thread* _thread;

	ThreadState _threadState;
};

#endif