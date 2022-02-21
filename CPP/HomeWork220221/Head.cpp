#include "Head.h"
#include <conio.h>

std::list<Body*>::iterator iter;

Head::Head()
{
}

Head::~Head()
{
	
}


void Head::Update()
{
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		// ȭ��ٱ����� �̵��ϸ� �̵��� �ȵǰ� ���ּ���.
		InScreenMovement({ -1, 0 });
		break;
	case 'd':
	case 'D':
		InScreenMovement({ 1, 0 });
		break;
	case 'w':
	case 'W':
		InScreenMovement({ 0, -1 });
		break;
	case 's':
	case 'S':
		InScreenMovement({ 0, 1 });
		break;
	case 'q':
	case 'Q':
		// �������ΰ��� ��������
		// ������ ����ȴ�.
		Death();
		return;
	default:
		break;
	}

	return;
}

void Head::OverLap(ConsoleObject* _Link)
{
	AllBody.push_back((Body*)_Link);
}


void Head::ListDestroy() {
	while (AllBody.empty() == false)
	{
		iter = AllBody.begin();
		delete (ConsoleObject*)(*iter);
		AllBody.erase(iter);
	}
}