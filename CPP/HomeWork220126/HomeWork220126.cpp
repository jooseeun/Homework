// HomeWork220126.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class MyInt 
{
public:
	int Value;

public:
	MyInt& operator++()
	{
		Value = this->Value + 1;
		return *this;
	}
	MyInt operator++(const int _one)
	{
		int cost = this->Value;
		this->Value = this->Value + 1;
		return MyInt(cost);
	}

public:
	MyInt(int _Value)
		:Value(_Value)
	{

	}

};

int main()
{
	int Value = 0;
	int Result = 0;
	

	Result = ++Value;
	printf_s("Result : %d Value : %d \n",Result, Value);

	Result = 0;
	Result = Value++;
	printf_s("Result : %d Value : %d \n\n", Result, Value);



	MyInt MyValue = 0;
	MyInt MyResult = 0;

	MyResult = ++MyValue;
	printf_s("MyResult : %d MyValue : %d \n", MyResult.Value, MyValue.Value);
	
	MyResult = 0;
	MyResult = MyValue++;
	printf_s("MyResult : %d MyValue : %d \n", MyResult.Value, MyValue.Value);
}
