#include "NAEEngine.h"
#include "Renderer.h"
#include "WindowsInputManager.h"
#include "DisplaySettings.h"
#include "PerspectiveCamera.h"
#include <cassert>
using namespace NAE;

TYPE_DEFINITIONS(NAEEngine);

NAEEngine* NAEEngine::sInstance = nullptr;

NAEEngine::NAEEngine() :
	mRenderer(nullptr),
	mMainCamera(nullptr),
	mClock()
{

}

NAEEngine::~NAEEngine()
{
	if (mMainCamera != nullptr)
	{
		delete mMainCamera;
		mMainCamera = nullptr;
	}

	if (mInputManager != nullptr)
	{
		delete mInputManager;
		mInputManager = nullptr;
	}

	if (mRenderer != nullptr)
	{
		delete mRenderer;
		mRenderer = nullptr;
	}

	mEntities.clear();
	mEntityTransforms.clear();
	mEntityToTransformMap.clear();
}

void NAEEngine::Initialize(const std::string& appName)
{
	// Create the engine
	NAEEngine::CreateInstance();

	// Initialize the engine
	DisplaySettings ds;
	ds.mAppName = appName.c_str();
	ds.mMessagePumpCallback = WndProc;
	ds.creator = sInstance;

	sInstance->Init(ds);
}

void NAEEngine::Init(DisplaySettings& ds)
{
	if (mRenderer == nullptr)
	{
		mRenderer = new Renderer();
	}

	mRenderer->Init(ds);

	if (mInputManager == nullptr)
	{
		mInputManager = new WindowsInputManager();
	}

	// TODO: make sure this is created with the camera type and settings from the loaded game project
	float aspectRatio = static_cast<float>(mRenderer->GetRenderWidth()) / static_cast<float>(mRenderer->GetRenderHeight());
	mMainCamera = new PerspectiveCamera(45.0f, aspectRatio, 1.0f, 100.0f);
	mMainCamera->SetPosition(glm::vec3(0.0f, 0.0f, 5.0f));

	mRenderer->SetCurrentCamera(mMainCamera);
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
			mRenderer->WaitForDevice();
		}
		else
		{
			mClock.Update();
			mInputManager->Update();
			mRenderer->Draw();
		}
	}
}

void NAEEngine::AddDefaultTransform(uint32_t entityId)
{
	AddTransform(entityId, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), 0);
}

void NAEEngine::AddTransform(uint32_t entityId, const glm::vec3& position, const glm::vec3& rotation, const float& velocity)
{
	if (entityId > mEntityTransforms.capacity())
	{
		mEntityTransforms.resize(entityId * 2, Transform());
	}

	Transform& newTransform = mEntityTransforms[entityId];
	newTransform.SetPosition(position);
	newTransform.SetRotationFromEulerAngles(rotation);
	newTransform.SetVelocity(velocity);
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
			mRenderer->HandleWindowResize(width, height);
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

void NAEEngine::CreateInstance()
{
	if (sInstance == nullptr)
	{
		sInstance = new NAEEngine();
	}
}

HWND NAEEngine::MainWindowHandle()
{ 
	return mRenderer->MainWindowHandle(); 
}
HINSTANCE NAEEngine::MainWindowInstance()
{ 
	return mRenderer->MainWindowInstance(); 
}