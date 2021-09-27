#ifndef STATE_H
#define STATE_H
//------------------------------------------------------------------------
//
//  Name:   State.h
//
//  Desc:   abstract base class to define an interface for a state
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

class Baker;

class State
{
public:

	virtual ~State() {}

	//this will execute when the state is entered
	virtual void Enter(Baker*) = 0;

	//this is the state's normal update function
	virtual void Execute(Baker*) = 0;

	//this will execute when the state is exited. (My word, isn't
	//life full of surprises... ;o))
	virtual void Exit(Baker*) = 0;

};

#endif