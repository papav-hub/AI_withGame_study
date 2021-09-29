#include "EntityManager.h"
#include "BaseGameEntity.h"


//-----------------------------------------------------------------------------
EntityManager* EntityManager::Instance()
{
	static EntityManager instance;

	return &instance;
}

//-----------------------------------------------------------------------------
BaseGameEntity* EntityManager::GetEntityFromID(int id)const
{
	//find the entity
	EntityMap::const_iterator ent = m_EntityMap.find(id);

	//assert that the entity is a member of the map
	assert((ent != m_EntityMap.end()) && "<EntityManager::GetEntityFromID>: invalid ID");

	return ent->second;
}

//-----------------------------------------------------------------------------
void EntityManager::RemoveEntity(BaseGameEntity* pEntity)
{
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}

//-----------------------------------------------------------------------------
void EntityManager::RegisterEntity(BaseGameEntity* NewEntity)
{
	m_EntityMap.insert(std::make_pair(NewEntity->ID(), NewEntity));
}
