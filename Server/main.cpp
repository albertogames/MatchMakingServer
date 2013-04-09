#include "Server.h"

using namespace std;

int main()
{
	CServer* server = new CServer("192.168.1.100",9999,128);
	server->run();
}