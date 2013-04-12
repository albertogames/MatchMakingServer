#include "ConnectionsServer.h"

using namespace std;

int main()
{
	CConnectionsServer* server = new CConnectionsServer("127.0.0.1",9999,128);
	server->run();
}