#pragma once
template <class T>
class Singleton {
public:
	virtual ~Singleton() {
	}
	static T& get() {
		return instance;
	}
private:
	T& operator = (const T&) = delete;
	static T instance;
};
template <class T>
T Singleton<T>::instance;
