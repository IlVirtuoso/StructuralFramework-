namespace StructuralFramework {

	struct SerializedObject
	{
		void* data;
		int length;
		int dimensions;
	};

	class ISerializable {
	public:
		virtual SerializedObject Serialize() = 0;
		template<class T>
		virtual T Deserialize() = 0;
	};


}