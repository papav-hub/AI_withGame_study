#ifndef PASSERBY_OWNED_STATES_H
#define PASSERBY_OWNED_STATES_H


#include "State.h"
#include "fsm/State.h"

class PasserBy;
struct Telegram;

//------------------------------------------------------------------------
class PasserByGlobalState : public State<PasserBy>
{
private:

	PasserByGlobalState() {}

	PasserByGlobalState(const PasserByGlobalState&);
	PasserByGlobalState& operator=(const PasserByGlobalState&);

public:

	static PasserByGlobalState* Instance();

	virtual void Enter(PasserBy* pb) {}

	virtual void Execute(PasserBy* pb);

	virtual void Exit(PasserBy* pb) {}

	virtual bool OnMessage(PasserBy* pb, const Telegram& msg);

};


//------------------------------------------------------------------------
class Takea_Walk : public State<PasserBy>
{

private:

	Takea_Walk() {}

	Takea_Walk(const Takea_Walk&);
	Takea_Walk& operator=(const Takea_Walk&);

public:

	static Takea_Walk* Instance();

	virtual void Enter(PasserBy* pb);

	virtual void Execute(PasserBy* pb);

	virtual void Exit(PasserBy* pb);

	virtual bool OnMessage(PasserBy* pb, const Telegram& msg);


};



//------------------------------------------------------------------------
class Takea_Look : public State<PasserBy>
{
private:

	Takea_Look() {}

	Takea_Look(const Takea_Look&);
	Takea_Look& operator=(const Takea_Look&);

public:

	static Takea_Look* Instance();

	virtual void Enter(PasserBy* pb);

	virtual void Execute(PasserBy* pb);

	virtual void Exit(PasserBy* pb);

	virtual bool OnMessage(PasserBy* pb, const Telegram& msg);


};


//------------------------------------------------------------------------
class HiTo_Owner : public State<PasserBy>
{
private:

	HiTo_Owner() {}

	//copy ctor and assignment should be private
	HiTo_Owner(const HiTo_Owner&);
	HiTo_Owner& operator=(const HiTo_Owner&);

public:

	static HiTo_Owner* Instance();

	virtual void Enter(PasserBy* pb);

	virtual void Execute(PasserBy* pb);

	virtual void Exit(PasserBy* pb);

	virtual bool OnMessage(PasserBy* pb, const Telegram& msg);


};

#endif