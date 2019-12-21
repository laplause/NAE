#include <iostream>
#include "NAEEngine.h"
using namespace std;
using namespace NAE;

int main()
{
	cout << "Starting NAE Engine Test\n";

	NAEEngine engine;
	engine.Init("NAE Test");
	engine.Run();

	cout << "NAE Engine has shutdown\n";

	return 0;
}