#include <iostream>

int StringLen(const char* _Ptr)
{
	int Count = 0;

	while (0 != _Ptr[Count])
	{
		Count += 1;
	}

	return Count;
}
int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
	int Len = StringLen(_Text);
	for (int i = _Start; i < Len; i++)
	{
		if (_Text[i] == _FindStr[0] && _Text[i + 1] == _FindStr[1] && _Text[i + 2] == _FindStr[2])
		{
			return i;
		}
	}

	return -1;
}

////"cccc"
////"ccfc"
//int stringcompare(const char* _left, const char* _right) {
//	int count = 0;
//	while (0 == _left[count] || 0 == _right[count]) {
//		if (_left[count] != _right[count]) {
//			return false;
//		}
//		++count;
//	}
//	return true;
//}

int CountLast(const char* _Text, int _End, const char* _FindStr)
{
	int count = 0;
	int Len = StringLen(_Text);
	for (int i = _End; i > 1; i--)
	{
		if (_Text[i] == _FindStr[0] && _Text[i + 1] == _FindStr[1] && _Text[i + 2] == _FindStr[2])
		{
			return i;
		}
	}

	return -1;
}


int main()
{

	{
		int Count = CountFirst("aaa eee ttt asdfasd eee", 15, "eee");
		int a = 0;
	}
	{
		int Count = CountLast("aaa eee asdfasd eee", 50, "eee");
		int a = 0;
	}



}
