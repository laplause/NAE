#ifndef MODEL_H
#define MODEL_H

#include "Asset.h"

namespace NAE
{
	class Model : public Asset
	{
	public:
		Model();
		virtual ~Model();

		virtual void Load() = 0;
		virtual void Unload() = 0;

		inline const size_t IndexCount() const { return mNumIndices; };

	protected:
		size_t mNumIndices;
	};
}
#endif
