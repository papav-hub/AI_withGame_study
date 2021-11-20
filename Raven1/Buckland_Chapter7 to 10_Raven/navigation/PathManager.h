#ifndef PATH_MANAGER_H
#define PATH_MANAGER_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   PathManager.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   a template class to manage a number of graph searches, and to 
//          distribute the calculation of each search over several update-steps
// 
//-----------------------------------------------------------------------------
#include <list>
#include <cassert>



template <class path_planner>
class PathManager // 경로 찾기 Manager, bot들이 여기 요청한다.
{
private:

  //a container of all the active search requests
  std::list<path_planner*>  m_SearchRequests; // bot들의 경로 찾기 요청을 list로 저장한다.

  //this is the total number of search cycles allocated to the manager. 
  //Each update-step these are divided equally amongst all registered path
  //requests
  unsigned int              m_iNumSearchCyclesPerUpdate; // Game이 경로찾기에 부여한 시간

public:
    
  PathManager(unsigned int NumCyclesPerUpdate):m_iNumSearchCyclesPerUpdate(NumCyclesPerUpdate){}

  //every time this is called the total amount of search cycles available will
  //be shared out equally between all the active path requests. If a search
  //completes successfully or fails the method will notify the relevant bot
  void UpdateSearches(); // 시간동안 list에 있는 것을 처리하는 함수 // 실제로 검색

  //a path planner should call this method to register a search with the 
  //manager. (The method checks to ensure the path planner is only registered
  //once)
  void Register(path_planner* pPathPlanner); // 등록했다가
  void UnRegister(path_planner* pPathPlanner); // 빼는 함수

  //returns the amount of path requests currently active.
  int  GetNumActiveSearches()const{return m_SearchRequests.size();} // 요청 수 return
};

///////////////////////////////////////////////////////////////////////////////
//------------------------- UpdateSearches ------------------------------------
//
//  This method iterates through all the active path planning requests 
//  updating their searches until the user specified total number of search
//  cycles has been satisfied.
//
//  If a path is found or the search is unsuccessful the relevant agent is
//  notified accordingly by Telegram
//-----------------------------------------------------------------------------
template <class path_planner>
inline void PathManager<path_planner>::UpdateSearches()
{
  int NumCyclesRemaining = m_iNumSearchCyclesPerUpdate; // 할당한 시간 받기

  //iterate through the search requests until either all requests have been
  //fulfilled or there are no search cycles remaining for this update-step.
  std::list<path_planner*>::iterator curPath = m_SearchRequests.begin(); 
  while (NumCyclesRemaining-- && !m_SearchRequests.empty())// 할당한 시간 만큼만 while문이 돈다.
  {
    //make one search cycle of this path request
    int result = (*curPath)->CycleOnce(); // pathPlanner에 설정된 CycleOnce를 한번씩 돌려준다.(A* or Dji)
    // list에서 하나씩 꺼내서 CycleOnce를 돌려준다. : Manager가 하는 일

    //if the search has terminated remove from the list
    if ( (result == target_found) || (result == target_not_found) ) // 한번 돌았는데 target이 없는 경우
    {
      //remove this path from the path list
      curPath = m_SearchRequests.erase(curPath);  // 걔는 끝났으니까 지우고 list의 다음 차례를 돌려줌     
    }
    //move on to the next
    else // 끝나지 않았으면 지우지 않고 다음 차례를 돌림
    {
      ++curPath;
    }

    //the iterator may now be pointing to the end of the list. If this is so,
    // it must be reset to the beginning.
    if (curPath == m_SearchRequests.end())
    {
      curPath = m_SearchRequests.begin();
    }

  }//end while
}

//--------------------------- Register ----------------------------------------
//
//  this is called to register a search with the manager.
//-----------------------------------------------------------------------------
template <class path_planner>
inline void PathManager<path_planner>::Register(path_planner* pPathPlanner)
{
  //make sure the bot does not already have a current search in the queue
  if(std::find(m_SearchRequests.begin(),
               m_SearchRequests.end(),
               pPathPlanner) == m_SearchRequests.end())
  { 
    //add to the list
    m_SearchRequests.push_back(pPathPlanner);
  }
}

//----------------------------- UnRegister ------------------------------------
//-----------------------------------------------------------------------------
template <class path_planner>
inline void PathManager<path_planner>::UnRegister(path_planner* pPathPlanner)
{
  m_SearchRequests.remove(pPathPlanner);

}

#endif