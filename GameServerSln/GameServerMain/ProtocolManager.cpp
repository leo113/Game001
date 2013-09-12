#include "ProtocolManager.h"


ProtocolManager ProtocolManager::GetInstance()
{
	if(_instance == NULL)
	{
		_instance = new ProtocolManager();
	}
	return _instance;
}

void ProtocolManager::DiapathMessage(unsigned char message[]){}