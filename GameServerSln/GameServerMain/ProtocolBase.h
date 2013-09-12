#pragma once

class ProtocolBase
{
public:
	ProtocolBase(void);
	~ProtocolBase(void);

	virtual void DecodeMessage(unsigned char message[]) = 0;

	virtual void EncodeMessage(unsigned char message[]) = 0;

};
