#pragma once
#include<functional>
namespace Structural {

	template<typename T,typename...Args>
	class Func {
	private:
		std::function<T(Args...)> func;
	public:
		
		Func(std::function<T(Args...)> lambda) {
			this->func = lambda;
		}

		T operator()(Args...a) {
			return this->func(a...);
		}
	};
}