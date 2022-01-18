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
void TextChange(char* _Text, const char* _Prev, const char* _Next)
{
	int Len = StringLen(_Text);
	for (int i = 0; i < Len; i++)
	{
		if (_Text[i] == _Prev[0] && _Text[i + 1] == _Prev[1]) {
			_Text[i] = _Next[0];
			_Text[i + 1] = _Next[1];
			Len += 1;
			for (int j = Len; j > i+2; j-=1)
			{
				_Text[j] = _Text[j-1];
			}
			_Text[i + 2] = _Next[2];
		}

	}
}
int main()
{
	char Text[100] = "aa, bb, aa, bb aa aa aa aaaaaaa ccdffeds";

	TextChange(Text, "aa", "fff");
	// "fff, bb, fff, bb fff fff fff fffffffffa ccdffeds";
	// aa| bb| cc| dd
	printf_s(Text);
}
