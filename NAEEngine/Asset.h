#ifndef ASSET_H
#define ASSET_H

#include "NAEObject.h"

namespace NAE
{
	class Asset : public NAEObject
	{
		TYPE_DECLARATIONS(Asset, NAEObject);
	public:
		Asset();
		Asset(const std::string& name, const std::string& resourcePath);
		explicit Asset(const std::string& name);
		virtual ~Asset();

		virtual void Load() = 0;
		virtual void Unload() = 0;

		inline const bool Loaded() const { return mLoaded; };

		inline void SetResourcePath(const std::string& resourcePath) { mResourcePath = resourcePath; };

	protected:
		bool mLoaded;

	private:
		std::string mResourcePath;
	};
}
#endif
