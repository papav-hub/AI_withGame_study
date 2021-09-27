#ifndef PASSERBY_OWNED_STATES_H
#define PASSERBY_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinersWifeOwnedStates.h
//
//  Desc:   All the states that can be assigned to the MinersWife class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "State.h"

class PasserBy;

//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class PasserByGlobalState : public State<PasserBy>
{
private:

	PasserByGlobalState() {}

	//copy ctor and assignment should be private
	PasserByGlobalState(const PasserByGlobalState&);
	PasserByGlobalState& operator=(const PasserByGlobalState&);

public:

	static PasserByGlobalState* Instance();

	virtual void Enter(PasserBy* pb) {}

	virtual void Execute(PasserBy* pb);

	virtual void Exit(PasserBy* pb) {}
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class Takea_Walk : public State<PasserBy>
{

private:

	Takea_Walk() {}

	//copy ctor and assignment should be private
	Takea_Walk(const Takea_Walk&);
	Takea_Walk& operator=(const Takea_Walk&);

public:

	static Takea_Walk* Instance();

	virtual void Enter(PasserBy* pb);

	virtual void Execute(PasserBy* pb);

	virtual void Exit(PasserBy* pb);

};



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class Takea_Look : public State<PasserBy>
{
private:

	Takea_Look() {}

	//copy ctor and assignment should be private
	Takea_Look(const Takea_Look&);
	Takea_Look& operator=(const Takea_Look&);

public:

	static Takea_Look* Instance();

	virtual void Enter(PasserBy* pb);

	virtual void Execute(PasserBy* pb);

	virtual void Exit(PasserBy* pb);

};


#endif