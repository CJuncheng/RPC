#include <string>
#include <iostream>
#include <ctime>
#include "buttonrpc.hpp"


int main()
{
	buttonrpc client;
	client.as_client("127.0.0.1", 5555);
	client.set_timeout(2000);

	int callcnt = 0;
	printf("RPC start\n");
	while (1){
		std::cout << "current call count: " << ++callcnt << std::endl;
		client.call<void>("cat");
		printf("call cat end\n");
		client.call<void>("dog");
		printf("call dog end\n");
		int pig = client.call<int>("pig", 10).val();
		printf("call dog end, result: %d\n", pig);
		Sleep(1000);
	}
	printf("RPC end\n");

	return 0;
}
