#include<iostream>

namespace NetSupport {


	class IClientSocket {
	public:
		virtual bool Open(std::string IpAddress,int port) = 0;
		virtual bool Close() = 0;
		template<typename T> 
		void Send(T* data) {

		}
		template<typename T>
		T Read() {

		}
	private:
		virtual void Send(void * data, int length);
		virtual char * Read() = 0;
	};


	class IServerSocket {
	public:
		virtual bool Open(int port) = 0;
		virtual bool Close() = 0;
		virtual void Accept(void(*callback)()) = 0;
		template<typename T>
		void Send(T* data) {

		}
	private:
		virtual void Send(void* data, int length) = 0;
		virtual char* Read() = 0;
	};

}