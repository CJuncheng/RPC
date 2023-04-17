#include <string>
#include <iostream>
#include "buttonrpc.hpp"

void cat() {
	printf("server cat\n");
}
void dog() {
	printf("server dog\n");
}

int pig(int arg) {
	printf("server pig: %d\n", arg);

	return arg;
}

int main()
{
	buttonrpc server;
	server.as_server(5555);
	server.bind("cat", cat);
	server.bind("dog", dog);
	server.bind("pig", std::function<int(int)>(pig));
	printf("server port: 5555\n");
	server.run();
	return 0;
}
