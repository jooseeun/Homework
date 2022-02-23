
#include <iostream>

int Value = 0;

void Func()
{
    std::cout << ++Value << std::endl;
    while(Value<30) {
        Func();
    }
}

int main()
{
    Func();
}
