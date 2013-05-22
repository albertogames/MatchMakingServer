#include "ConnectionsServer.h"
#include "GameServer.h"

using namespace std;

int main()
{
	CGameServer* server = new CGameServer("192.168.1.102",9999,128);
}