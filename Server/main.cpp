#include "ConnectionsServer.h"
#include "GameServer.h"

using namespace std;

int main()
{
	CGameServer* server = new CGameServer("127.0.0.1",9999,128);
}