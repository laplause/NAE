#include "NAEEngine.h"
#include "InputManager.h"

#include <iostream>
#include <math.h>
using namespace std;
using namespace NAE;

int main()
{
	cout << "Starting NAE Engine Test\n";

	NAEEngine::Initialize("NAE Test");
	NAEEngine::Input()->AddActionInputMapping("MoveForward", Keys::KEY_W);
	NAEEngine::Input()->AddActionInputMapping("MoveBack", Keys::KEY_S);

	NAEEngine::Engine()->Run();

	cout << "NAE Engine has shutdown\n";

	return 0;
}