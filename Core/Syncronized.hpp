#pragma once
#include <thread>
#include "Collections.hpp"
#include <condition_variable>
#include <mutex>
namespace Structural {
	namespace Collections {
		namespace Syncronized {
			using Structural::Collections::Generic::Queue;
			template<typename T>
			class BlockingQueue : public Queue<T>{
			private:
				
				std::unique_lock<std::mutex> lock{};
			public:
				void Enqueue(T elem) {
					lock.lock();
					Queue::Enqueue(elem);
					lock.unlock();
				}

				T Dequeue() {
					lock.lock();
					auto var = Queue::Dequeue();
					lock.unlock();
					return var;
				}
			};
		}
	}
}