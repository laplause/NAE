#ifndef ASSET_H
#define ASSET_H

#include <string>

namespace NAE
{
	class Asset
	{
	public:
		Asset();
		virtual ~Asset();

		inline const bool Loaded() const { return mLoaded; };
		inline const std::string& Name() { return mName; };

		inline void SetName(const std::string& name) { mName = name; };
		inline void SetResourcePath(const std::string& resourcePath) { mResourcePath = resourcePath; };

	protected:
		bool mLoaded;

	private:
		std::string mResourcePath;
		std::string mName;
	};
}
#endif
