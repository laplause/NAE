#ifndef NAE_H
#define NAE_H

#define FULLSCREEN 0

#include "Renderer.h"

namespace NAE
{
	class NAEEngine
	{
	public:
		NAEEngine();
		~NAEEngine();

		static LRESULT WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
		LRESULT HandleMessage(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

		void Init(const std::string& appName);
		void Run();

	private:
		
		NAEEngine(const NAEEngine&) = delete;
		NAEEngine(NAEEngine&&) = delete;
		NAEEngine& operator=(const NAEEngine&) = delete;
		NAEEngine& operator=(NAEEngine&&) = delete;
		
		Renderer mRenderer;
	};
}
#endif
