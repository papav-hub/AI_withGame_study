#include "PasserBy.h"

bool PasserBy::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}



void PasserBy::Update()
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	m_pStateMachine->Update();
}