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
class PathManager // ��� ã�� Manager, bot���� ���� ��û�Ѵ�.
{
private:

  //a container of all the active search requests
  std::list<path_planner*>  m_SearchRequests; // bot���� ��� ã�� ��û�� list�� �����Ѵ�.

  //this is the total number of search cycles allocated to the manager. 
  //Each update-step these are divided equally amongst all registered path
  //requests
  unsigned int              m_iNumSearchCyclesPerUpdate; // Game�� ���ã�⿡ �ο��� �ð�

public:
    
  PathManager(unsigned int NumCyclesPerUpdate):m_iNumSearchCyclesPerUpdate(NumCyclesPerUpdate){}

  //every time this is called the total amount of search cycles available will
  //be shared out equally between all the active path requests. If a search
  //completes successfully or fails the method will notify the relevant bot
  void UpdateSearches(); // �ð����� list�� �ִ� ���� ó���ϴ� �Լ� // ������ �˻�

  //a path planner should call this method to register a search with the 
  //manager. (The method checks to ensure the path planner is only registered
  //once)
  void Register(path_planner* pPathPlanner); // ����ߴٰ�
  void UnRegister(path_planner* pPathPlanner); // ���� �Լ�

  //returns the amount of path requests currently active.
  int  GetNumActiveSearches()const{return m_SearchRequests.size();} // ��û �� return
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
  int NumCyclesRemaining = m_iNumSearchCyclesPerUpdate; // �Ҵ��� �ð� �ޱ�

  //iterate through the search requests until either all requests have been
  //fulfilled or there are no search cycles remaining for this update-step.
  std::list<path_planner*>::iterator curPath = m_SearchRequests.begin(); 
  while (NumCyclesRemaining-- && !m_SearchRequests.empty())// �Ҵ��� �ð� ��ŭ�� while���� ����.
  {
    //make one search cycle of this path request
    int result = (*curPath)->CycleOnce(); // pathPlanner�� ������ CycleOnce�� �ѹ��� �����ش�.(A* or Dji)
    // list���� �ϳ��� ������ CycleOnce�� �����ش�. : Manager�� �ϴ� ��

    //if the search has terminated remove from the list
    if ( (result == target_found) || (result == target_not_found) ) // �ѹ� ���Ҵµ� target�� ���� ���
    {
      //remove this path from the path list
      curPath = m_SearchRequests.erase(curPath);  // �´� �������ϱ� ����� list�� ���� ���ʸ� ������     
    }
    //move on to the next
    else // ������ �ʾ����� ������ �ʰ� ���� ���ʸ� ����
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