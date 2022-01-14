#include <iostream>

int main()
{
    { //짝수로 채우기
        int Arr[10] = { 0, };
        int Index = 0;
        while (Index != 10) {
            //2 4 6 8 10 12 14 16 18 20
            Arr[Index] = 2 * (Index + 1);
            Index += 1;
        }
        int a = 0;
    }
    { //홀수로 채우기
        int Arr[10] = { 0, };
        int Index = 0;
        while (Index != 10) {
            //1 3 5 7 9 11 13 15 17 19
            Arr[Index] = Index * 2 + 1;
            Index += 1;
        }
        int a = 0;
    }
}
