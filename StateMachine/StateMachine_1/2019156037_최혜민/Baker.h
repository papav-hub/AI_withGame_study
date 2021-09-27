#ifndef BAKER_H
#define BAKER_H
//------------------------------------------------------------------------
//
//  Name:   Miner.h
//
//  Desc:   A class defining a goldminer.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>

#include "BaseGameEntity.h"
#include "BakerLocation.h"


class State;

//the amount of gold a miner must have before he feels comfortable
const int pocket_max = 5;
//the amount of nuggets a miner can carry
const int health_min = 1;
//above this value a miner is thirsty
const int ingredient_min = 3;



class Baker : public BaseGameEntity
{
private:

    State* m_pCurrentState;

    location_type         m_Location;

    //how many nuggets the miner has in his pockets
    int                   m_cookie;

    int                   m_health;

    //the higher the value, the thirstier the miner
    int                   m_ingredient;

    //the higher the value, the more tired the miner
    int                   m_money;

    int                   m_displayed;

public:

    Baker(int id);

    //this must be implemented
    void Update();

    //this method changes the current state to the new state. It first
    //calls the Exit() method of the current state, then assigns the
    //new state to m_pCurrentState and finally calls the Entry()
    //method of the new state.
    void ChangeState(State* new_state);



    location_type Location()const { return m_Location; }
    void ChangeLocation(const location_type loc) { m_Location = loc; }

    void makeCookies() { m_cookie += 1; m_health -= 1; m_ingredient += 1; };
    int currentCookie() { return m_cookie; }
    bool pocketFull() const;
    bool noIngredient() const;
    bool checkHealth() const;


    void sellCookies() { m_cookie -= 1; m_health -= 1; m_money += 1; };
    bool displayEmpty() const;

    void decreaseHealth() { m_health -= 1; }
    void increaseHealth() { m_health += 1; }

    void buyIngredient() { m_ingredient += 10; m_money -= 1; }

};




#endif
