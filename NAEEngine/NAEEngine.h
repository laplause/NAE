#ifndef NAE_H
#define NAE_H

#define FULLSCREEN 0

#include "System.h"

#include <unordered_map>
#include <assert.h>

namespace NAE
{
	class Camera;
	class Renderer;
	class DisplaySettings;
	class InputManager;

	class NAEEngine : public Type
	{
		TYPE_DECLARATIONS(NAEEngine, Type);
	public:
		virtual ~NAEEngine();

		static LRESULT WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
		LRESULT HandleMessage(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
		HWND MainWindowHandle();
		HINSTANCE MainWindowInstance();

		void Run();

		static void Initialize(const std::string& appName);
		static inline NAEEngine* Engine() { assert(sInstance); return sInstance; };
		static inline const double DeltaTime() { return Engine()->mClock.DeltaTime(); };
		static inline const double TotalTime() { return Engine()->mClock.TotalGameTime(); };
		static inline InputManager* Input() { return Engine()->mInputManager; };

	private:
		
		NAEEngine();
		NAEEngine(const NAEEngine&) = delete;
		NAEEngine(NAEEngine&&) = delete;
		NAEEngine& operator=(const NAEEngine&) = delete;
		NAEEngine& operator=(NAEEngine&&) = delete;

		void Init(DisplaySettings& ds);

		static void CreateInstance();

		static NAEEngine* sInstance;

		Camera* mMainCamera;
		Renderer* mRenderer;
		InputManager* mInputManager;
		GameClock mClock;
		std::unordered_map<Type::IdType, System*> mSystems;
	};
}
#endif
