// GameServerMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestServer.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	TestServer ser;

	ser.Start();
	ser.WaitStop();
	printf( "exit\n" );

	return 0;
}
