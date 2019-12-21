#ifndef WINDOW_H
#define WINDOW_H

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <cstdint>

namespace NAE
{
	// Forward Declarations
	class DisplaySettings;

	class Window
	{
	public:
		Window();
		~Window();

		void Init(const DisplaySettings& displaySettings);
		void UpdateWindowSize(uint32_t newWidth, uint32_t newHeight);

		inline const HWND GetWindowHandle() const { return mWindowHandle; };
		inline const HINSTANCE GetWindowInstance() const { return mInstance; };
		inline const uint32_t GetWidth() const { return mWindowWidth; };
		inline const uint32_t GetHeight() const { return mWindowHeight; };
		inline const bool IsFullScreen() const { return mFullScreen; };

	private:
		LPCSTR mAppName;
		HWND mWindowHandle;
		HINSTANCE mInstance;
		uint32_t mWindowWidth;
		uint32_t mWindowHeight;
		bool mFullScreen;
	};
}
#endif