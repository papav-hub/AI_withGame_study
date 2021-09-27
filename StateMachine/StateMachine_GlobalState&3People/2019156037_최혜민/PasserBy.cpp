#include "PasserBy.h"


void PasserBy::Update()
{
	//set text color to green
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	m_pStateMachine->Update();
}