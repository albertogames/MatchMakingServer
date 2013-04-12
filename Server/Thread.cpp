#include "Thread.h"

IThread::~IThread(){
	if (_thread){
		_thread->interrupt();
		delete(_thread);
	}
	_thread = NULL;
}

void IThread::run(){
	_thread = new boost::thread(&IThread::startThread,this);
}
/*
ThreadState IThread::getThreadState(){
	return _threadState;
}*/

void IThread::stop(){
	_finish = true;
}