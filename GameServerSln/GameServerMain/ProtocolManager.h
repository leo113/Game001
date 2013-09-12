#pragma once

class ProtocolManager
{

private:
	static ProtocolManager* _instance;

	ProtocolManager();

public:
	static ProtocolManager* GetInstance();

	void DiapathMessage(unsigned char message[]);
};
