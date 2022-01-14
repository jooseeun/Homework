#include <iostream>

void StringTrimRemove(const char* _Left, char* _Right) {
    int countL = 0;
    int countR = 0;
    while (0 != _Left[countL]) {
        if (_Left[countL] != ' ') {
            _Right[countR] = _Left[countL];
            countR += 1;
        }
        countL += 1;
    }
    _Right[countR] = _Left[countL];
}

int main()
{
    char Text[1024] = { 0 };
    StringTrimRemove("a a a              b b b c c c d d d", Text);
    //"aaabbbcccddd"
    printf_s(Text);

}