#ifndef BAKER_H
#define BAKER_H

#include <string>
#include <cassert>

#include "BaseGameEntity.h"
#include "BakerLocation.h"
#include "BakerOwnedStates.h"
#include "StateMachine.h"



//the amount of gold a miner must have before he feels comfortable
const int pocket_max = 5;
//the amount of nuggets a miner can carry
const int health_min = 1;
//above this value a miner is thirsty
const int ingredient_min = 3;



class Baker : public BaseGameEntity
{
private:

    StateMachine<Baker>* m_pStateMachine;

    location_type         m_Location;

    //how many nuggets the miner has in his pockets
    int                   m_cookie;

    int                   m_health;

    //the higher the value, the thirstier the miner
    int                   m_ingredient;

    //the higher the value, the more tired the miner
    int                   m_money;

public:

    Baker(int id) :BaseGameEntity(id),
        m_Location(Oven),
        m_cookie(0),
        m_health(5),
        m_ingredient(1),
        m_money(5)
    {
        m_pStateMachine = new StateMachine<Baker>(this);
        m_pStateMachine->SetCurrentState(Baking_Oven::Instance());
    }


    ~Baker() { delete m_pStateMachine; }

    //this must be implemented
    void Update();

    StateMachine<Baker>* GetFSM()const { return m_pStateMachine; }



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
