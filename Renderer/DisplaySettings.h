#ifndef DISPLAYSETTINGS_H
#define DISPLAYSETTINGS_H

#include <Windows.h>
#include <cstdint>

namespace NAE
{
	class DisplaySettings
	{
	public:
		typedef LRESULT(CALLBACK *MessagePumpCallback)(HWND, UINT, WPARAM, LPARAM);

		DisplaySettings();
		~DisplaySettings();

		MessagePumpCallback mMessagePumpCallback;
		void* creator;
		uint32_t mRequestedWidth;
		uint32_t mRequestedHeight;
		bool mFullScreen;
		bool mBorderless;
		LPCSTR mAppName;
	};
}
#endif