#include "Player.h"
#include <conio.h>

Player::Player(TextScreen* _Screen, const char* _Text)
	: Screen_(_Screen)
	, Pos_(_Screen->GetSize().GetHalfVector())
	, Text_()
{
	if (nullptr == _Screen)
	{
		assert(false);
	}

	//예외처리 : 플레이어가 입력한 문자열이 1글자가 아닐때
	if (_Text[2]!=0||_Text[1]==0)
	{
		assert(false);
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}

	// Pos_ = ;
}

Player::~Player()
{
}


void Player::Update()
{
	// Pos_.x_ += 1; // Pos_.y_ += 0;
	//   'a'
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		Pos_.x_ -= 1;
		break;
	case 'd':
	case 'D':
		Pos_.x_ += 1;
		break;
	case 'w':
	case 'W':
		Pos_.y_ -= 1;
		break;
	case 's':
	case 'S':
		Pos_.y_ += 1;
		break;
	default:
		break;
	}
}

void Player::Render()
{
	Screen_->SetPixel(Pos_, Text_);
}