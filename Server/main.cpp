#include "Server.h"

using namespace std;

int main()
{
	CServer* server = new CServer("127.0.0.1",9999,128);
	server->run();
}