#include "NAEEngine.h"
#include "DisplaySettings.h"
#include <cassert>
using namespace NAE;

NAEEngine::NAEEngine() :
	mRenderer()
{

}

NAEEngine::~NAEEngine()
{

}

void NAEEngine::Init(const std::string& appName)
{
	DisplaySettings ds;
	ds.mAppName = appName.c_str();
	ds.mMessagePumpCallback = WndProc;
	ds.creator = this;

	mRenderer.Init(ds);
}

void NAEEngine::Run()
{
	MSG msg;
	bool done = false;

	ZeroMemory(&msg, sizeof(MSG));

	while (!done)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT || msg.message == WM_CLOSE)
		{
			done = true;
			mRenderer.WaitForDevice();
		}
		else
		{
			mRenderer.Draw();
		}
	}
}

LRESULT NAEEngine::HandleMessage(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
		case WM_KEYDOWN:
		{
			return 0;
		}
		
		case WM_KEYUP:
		{
			return 0;
		}

		case WM_SIZE:
		{
			uint32_t width = static_cast<uint32_t>(LOWORD(lparam));
			uint32_t height = static_cast<uint32_t>(HIWORD(lparam));

			// TODO: Handle the minimize case by blocking a thread until a new resize message comes through
			mRenderer.HandleWindowResize(width, height);
			return 0;
		}

		default:
		{
			return DefWindowProc(hwnd, message, wparam, lparam);
		}
	}
}

LRESULT NAEEngine::WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	static NAEEngine* engine = nullptr;

	if (message == WM_CREATE)
	{
		const CREATESTRUCT* createStruct = reinterpret_cast<const CREATESTRUCT*>(lparam);
		assert(createStruct);
		
		engine = reinterpret_cast<NAEEngine*>(createStruct->lpCreateParams);
		assert(engine);
	}
	else
	{
		switch (message)
		{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}

		case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}

		default:
		{
			return engine->HandleMessage(hwnd, message, wparam, lparam);
		}
		}
	}
}