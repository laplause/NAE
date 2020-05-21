#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <cstdint>

namespace NAE
{
	class Type
	{
	public:
		using IdType = std::uint64_t;

		virtual ~Type() = default;

		virtual IdType TypeIdInstance() const = 0;

		virtual bool Is(IdType) const
		{
			return false;
		}

		virtual bool Is(const std::string& typeName) const
		{
			return false;
		}

		template<typename T>
		T* As() const
		{
			return (Is(T::TypeId()) ? reinterpret_cast<T*>(const_cast<Type*>(this)) : nullptr);
		}

		virtual std::string ToString() const
		{
			return "Type";
		}
	};

#define TYPE_DECLARATIONS(Class, ParentClass)										\
	public:																			\
		static std::string TypeName() { return std::string(#Class); }				\
		static IdType TypeId() { return sRunTimeTypeId; }							\
		virtual IdType TypeIdInstance() const override { return Class::TypeId(); }	\
		virtual bool Is(IdType id) const override									\
		{																			\
			return (id == sRunTimeTypeId ? true : ParentClass::Is(id));				\
		}																			\
		virtual bool Is(const std::string& name) const override						\
		{																			\
			return (name == TypeName() ? true : ParentClass::Is(name));				\
		}																			\
	private:																		\
		static IdType sRunTimeTypeId;												\

#define TYPE_DEFINITIONS(Class) Type::IdType Class::sRunTimeTypeId = reinterpret_cast<Type::IdType>(&Class::sRunTimeTypeId);

}
#endif
