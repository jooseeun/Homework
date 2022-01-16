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

void CharChange(char* _Text, char _Prev, char _Next) {
	int Len = StringLen(_Text);
	for (int i = 0; i < Len; i += 1) {
		if (_Text[i] == _Prev) {
			_Text[i] = _Next;
		}
	}
}


int main()
{char Text[100] = "aa, bb, cc, dd";

		CharChange(Text, ',', '|');
		// aa| bb| cc| dd
		printf_s(Text);
}
