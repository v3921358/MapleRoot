#pragma once
#include <string>
#include <memory>

template <class T> class ZXString {
public:
	T* _m_pStr;
	ZXString();
	ZXString(const char* s);
	ZXString<T>* operator=(const char* s);
	ZXString<char>* operator=(ZXString<char>* s);
	ZXString<T>* Assign(const char* s, size_t length);
	~ZXString();

	void SetText(std::string const& text);
	int GetLength();
};