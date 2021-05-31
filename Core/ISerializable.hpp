#pragma once
#include <typeinfo>
#include"Collections.hpp"
namespace Structural {

	union SerializedObject
	{
		int length;
		int dimensions;
		char* data;

	public:
		SerializedObject(char* data, int length, int dimensions) : data{data},length{length},dimensions{dimensions}{}
	};

	class ISerializable  {
	public:



		SerializedObject Serialize() {
			
		}

		template<class T>
		T Deserialize(SerializedObject object) {
			return dynamic_cast<T>(this->Deserialize(object));
		}
	private:

		 SerializedObject Deserialize(char* inputData) {
			
		}
	};


}