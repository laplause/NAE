#include "Window.h"
#include "DisplaySettings.h"
using namespace NAE;

Window::Window() :
	mWindowWidth(1920),
	mWindowHeight(1080),
	mInstance(nullptr),
	mWindowHandle(nullptr),
	mFullScreen(false)
{
}

Window::~Window()
{
	ShowCursor(true);

	if (mFullScreen)
	{
		ChangeDisplaySettings(nullptr, 0);
	}

	DestroyWindow(mWindowHandle);
	mWindowHandle = nullptr;

	UnregisterClass(mAppName, mInstance);
	mInstance = nullptr;
}

void Window::UpdateWindowSize(uint32_t newWidth, uint32_t newHeight)
{
	mWindowWidth = newWidth;
	mWindowHeight = newHeight;
}

void Window::Init(const DisplaySettings& displaySettings)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX = 0;
	int posY = 0;

	mInstance = GetModuleHandle(nullptr);
	mFullScreen = displaySettings.mFullScreen;
	mAppName = displaySettings.mAppName;

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = displaySettings.mMessagePumpCallback;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = mInstance;
	wc.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = displaySettings.mAppName;
	wc.lpszClassName = displaySettings.mAppName;
	wc.cbSize = sizeof(WNDCLASSEX);

	RegisterClassEx(&wc);

	DWORD windowStyle;
	
	if (displaySettings.mFullScreen)
	{
		mWindowWidth = GetSystemMetrics(SM_CXSCREEN);
		mWindowHeight = GetSystemMetrics(SM_CYSCREEN);

		// If full screen set the screen to maximum size of the users desktop and 32bit.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)mWindowWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)mWindowHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Change the display settings to full screen.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// Set the position of the window to the top left corner.
		posX = posY = 0;

		windowStyle = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP;
	}
	else
	{
		mWindowWidth = displaySettings.mRequestedWidth;
		mWindowHeight = displaySettings.mRequestedHeight;

		// Place the window in the middle of the screen.
		posX = (GetSystemMetrics(SM_CXSCREEN) - mWindowWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - mWindowHeight) / 2;

		windowStyle = WS_OVERLAPPEDWINDOW;
	}
	

	mWindowHandle = CreateWindowEx(
		WS_EX_APPWINDOW,
		displaySettings.mAppName, displaySettings.mAppName,
		windowStyle,
		posX, posY, mWindowWidth, mWindowHeight, nullptr, nullptr, mInstance, displaySettings.creator
	);

	ShowWindow(mWindowHandle, SW_SHOW);
	SetForegroundWindow(mWindowHandle);
	SetFocus(mWindowHandle);

	// TODO Should hide the cursor
	ShowCursor(true);
}