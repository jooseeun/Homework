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
int pow(int i) {
	int sum = 1;
	if (i == 0)
	{
		return 1;
	}

	else
	{
		for (int k = 1; k <= i; k += 1)
		{
			sum *= 10;
		}
		return sum;
	}
}
int ToInt(const char* _Left) {
	int Len = StringLen(_Left);
	int arr[100] = { 0 , };
	int sum = 0;

	for (int i = 0; i < Len; i += 1) {
		arr[i] = _Left[Len - 1 - i] - 48;
		sum += arr[i] * pow(i);
	}


	return sum;
}

int main() {
	const char* Text = "123";
	int Count = (int)Text[1];

	int Value = ToInt("15815");
	int a = 0;

}
