#pragma once

void* myMemset(void* dst, int num, size_t len)
{
	int* p = (int*)dst;
	while (len--)
	{
		*p++ = num;
	}
	return dst;
}

void* myMemcpy(void* dst, void* src, size_t len)
{
	if (!dst || !src)
		return nullptr;
	char* mdst = (char*)dst;
	char* msrc = (char*)src;
	if (mdst < msrc)
	{
		while (len--)
		{
			*mdst++ = *msrc++;
		}
	}
	else
	{
		mdst = mdst + len - 1;
		msrc = msrc + len - 1;
		while (len--)
		{
			*mdst-- = *msrc--;
		}
	}
	return dst;
}