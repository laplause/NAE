#ifndef NAE_H
#define NAE_H

#define FULLSCREEN 0

#include "Transform.h"
#include "Component.h"

#include <unordered_map>
#include <vector>
#include <assert.h>

namespace NAE
{
	
	class Renderer;
	class InputManager;
	class DisplaySettings;
	class Camera;
	class Entity;

	class NAEEngine : public Type
	{
		TYPE_DECLARATIONS(NAEEngine, Type);
	public:
		virtual ~NAEEngine();

		static void Initialize(const std::string& appName);

		void Run();

		void AddDefaultTransform(uint32_t entityId);
		void AddTransform(uint32_t entityId, const glm::vec3& position, const glm::vec3& rotation, const float& veocity);

		static inline NAEEngine* Engine() { assert(sInstance); return sInstance; };
		static inline const double DeltaTime() { return Engine()->mClock.DeltaTime(); };
		static inline const double TotalTime() { return Engine()->mClock.TotalGameTime(); };
		static inline InputManager* Input() { return Engine()->mInputManager; };

		static LRESULT WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
		LRESULT HandleMessage(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
		HWND MainWindowHandle();
		HINSTANCE MainWindowInstance();

	private:
		
		NAEEngine();
		NAEEngine(const NAEEngine&) = delete;
		NAEEngine(NAEEngine&&) = delete;
		NAEEngine& operator=(const NAEEngine&) = delete;
		NAEEngine& operator=(NAEEngine&&) = delete;

		template<typename ComponentType>
		class ComponentStorage
		{
		public:
			void AddNewComponent(uint32_t entityId)
			{
				uint32_t index = GetNextInactive();
				if (index < 0)
				{
					index = components.size();
					components.push_back(ComponentType());
					
				}
				else
				{
					components[index] = ComponentType();
				}

				entityToComponentMap[entityId] = index;
			}

			ComponentType* GetComponent(uint32_t entityId)
			{
				if (std::unordered_map<uint32_t, uint32_t>::iterator it = entityToComponentMap.find(Entity) != entityToComponentMap.end())
				{
					uint32_t index = it->second;
					Component* component = components[index]->As<Component>();
					if (component->mActive)
					{
						return &(components[index]);
					}
				}

				return nullptr;
			}

			std::vector<ComponentType> components;
			std::unordered_map<uint32_t, uint32_t> entityToComponentMap;

		private:

			int64_t GetNextInactive() 
			{
				int64_t nextInactive = -1;
				for (uint32_t i = 0; i < components.size(); ++i)
				{
					Component* component = components[i]->As<Component>();
					if (!component->mActive)
					{
						nextInactive = i;
						break;
					}
				}

				return nextInactive;
			}
		};

		void Init(DisplaySettings& ds);

		static void CreateInstance();

		static NAEEngine* sInstance;

		Renderer* mRenderer;
		InputManager* mInputManager;

		Camera* mMainCamera;
		GameClock mClock;

		std::vector<Entity*> mEntities;

		// Entity Transforms
		ComponentStorage<Transform> mEntityTransforms;

		// A map of component types to their storage
		std::unordered_map<Type::IdType, ComponentStorage>
	};
}
#endif
