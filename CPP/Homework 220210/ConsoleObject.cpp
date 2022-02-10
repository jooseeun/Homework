#include "ConsoleObject.h"

ConsoleObject::ConsoleObject(
	TextScreen* _Screen,
	const char* _Text,
	const ConsoleVector& _Pos
)
	: Screen_(_Screen)
	, Pos_(_Pos)
{
	//if (nullptr == _Screen)
	//{
	//	assert(false);
	//}

	if (nullptr == _Text)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}
}

ConsoleObject::~ConsoleObject()
{
}

void ConsoleObject::Render()
{
	if (nullptr == Screen_)
	{
		assert(false);
	}

	Screen_->SetPixel(Pos_, Text_);
}

void ConsoleObject::SetMove(ConsoleVector _Value) {
	Pos_ += _Value;

	// screend을 넘어가면 screen 중앙으로 오게하기
	if (0 > Pos_.x_)
	{
		Pos_ = Screen_->GetSize().GetHalfVector();
		
	}

	if (0 > Pos_.y_)
	{
		Pos_ = Screen_->GetSize().GetHalfVector();
		
	}

	 if (Screen_->GetSize().x_ <= Pos_.x_)
	{
		 Pos_ = Screen_->GetSize().GetHalfVector();
		
	}

	if (Screen_->GetSize().y_ <= Pos_.y_)
	{
		Pos_ = Screen_->GetSize().GetHalfVector();
	
	}

}