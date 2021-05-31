#pragma once

namespace Structural {

	template<typename T,typename...Args>
	class Delegate {
	private:
		T(*func)(Args...);
	public:
		Delegate(T(*func)(...)) {
			this->func = func;
		}

		T operator()(Args...) {
			static_assert(this->func != nullptr, "Function pointer required");
			this->func(...);
		}
	};
}