#pragma once
#include<iostream>
#include<string.h>
class myString
{
private:
	char* str;
public:
	myString()
	{
		str = "";
	}
	myString(myString& str2)
	{
		int l = str2.length();
		str = new char[l];
		memcpy(str, str2.cstr(), l);
	}
	myString(const char* a)
	{
		int l = strlen(a)+1;
		str = new char[l];
		memcpy(str, a, l);
	}
	const char* cstr()
	{
		return str;
	}
	int length()
	{
		return strlen(str)+1;
	}
};