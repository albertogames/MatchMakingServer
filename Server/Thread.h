#include <boost\thread.hpp>

#ifndef __Thread_H
#define __Thread_H

/*
enum ThreadState
{
			READY,
			RUNNING,
			BLOCKED,
			TERMINATED
};
*/


class IThread{

public:
	IThread():
	  _finish(false)
	  {};

	virtual ~IThread();

	void run();

	void stop();
	
	/*
	ThreadState getThreadState();

	bool isReady();
	bool isRunning();
	bool isBlocked();
	bool isTerminated();
	*/
protected:
	bool _finish;

private:

	virtual void startThread() = 0;
	
	boost::thread* _thread;
	/*
	ThreadState _threadState;
	*/
};

#endif