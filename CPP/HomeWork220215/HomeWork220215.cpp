#include <iostream>
#include <assert.h>
#include <crtdbg.h>

using DataType = int;


class GameArray
{
private:
    int Size_;
    DataType* ArrData_;

public:
    int GetSize()
    {
        return Size_;
    }

    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    inline void operator=(const GameArray& _Other)
    {
        Release();
        ArrData_ = new DataType[_Other.Size_];
        Size_ = _Other.Size_;


        // 이걸 쉘로우 카피 
        // 혹은 얕은 복사라고 한다.
        //this->ArrData_ = _Other.ArrData_;
        //this->Size_ = _Other.Size_;

        // 이걸 딥 카피
        // 혹은 깊은 복사라고 한다.
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }

        return;
    }

    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }


    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    void ReSize(unsigned int _Size)
    {
        if (nullptr != ArrData_) 
        {
            int S;
            if (Size_ < _Size)
            {
                S = Size_;
            }
            else
            {
                S = _Size;
            }
            DataType* _temp = new DataType[S];

            for (size_t i = 0; i < S; i++)
            {
                _temp[i] = ArrData_[i];
            }

            Release();
            ArrData_ = new DataType[_Size];
            Size_ = _Size;

            AllValueSetting(0);

            for (size_t i = 0; i < S; i++)
            {
                ArrData_[i]= _temp[i];
            }

            delete[]  _temp;
            _temp = nullptr;
        }
        else 
        {
            Release();
            ArrData_ = new DataType[_Size];
            Size_ = _Size;
        }
    }

public:
    GameArray(unsigned int _Size)
        : ArrData_(nullptr)
        , Size_(0)
    {
        ReSize(_Size);
    }

    ~GameArray()
    {
        Release();
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameArray NewArray = GameArray(10);
    // GameArray NewArray2 = GameArray(5);
    GameArray NewArray2 = GameArray(20);

    int Size = sizeof(GameArray);

    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        NewArray[i] = i;
    }

    //NewArray.AllValueSetting(0);

    NewArray2 = NewArray;


     NewArray2.ReSize(5);

    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        std::cout << NewArray2[i] << std::endl;
    }



    //int Arr[10];
    //int Arr2[10];

    //for (size_t i = 0; i < 10; i++)
    //{
    //    Arr[i] = Arr2[i];
    //}

    std::cout << "Hello World!\n";
}
