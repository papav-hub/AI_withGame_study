#ifndef GRAPH_NODE_TYPES_H
#define GRAPH_NODE_TYPES_H
//-----------------------------------------------------------------------------
//
//  Name:   GraphNodeTypes.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   Node classes to be used with graphs
//-----------------------------------------------------------------------------
#include <list>
#include <ostream>
#include <fstream>
#include "2D/Vector2D.h"
#include "graph/NodeTypeEnumerations.h"




class GraphNode
{  
protected:

  //every node has an index. A valid index is >= 0
  int        m_iIndex;

public:
  
  GraphNode():m_iIndex(invalid_node_index){}
  GraphNode(int idx):m_iIndex(idx){}
  GraphNode(std::ifstream& stream){char buffer[50]; stream >> buffer >> m_iIndex;}

  virtual ~GraphNode(){}

  int  Index()const{return m_iIndex;}
  void SetIndex(int NewIndex){m_iIndex = NewIndex;}
  


  //for reading and writing to streams.
  friend std::ostream& operator<<(std::ostream& os, const GraphNode& n)
  {
    os << "Index: " << n.m_iIndex << std::endl; return os;
  }

};   



//-----------------------------------------------------------------------------
//
//  Graph node for use in creating a navigation graph.This node contains
//  the position of the node and a pointer to a BaseGameEntity... useful
//  if you want your nodes to represent health packs, gold mines and the like
// 
// 탐색 그래프를 만드는데 상용할 그래프노드 입니다.
// 이 노드에는 노드의 위치와 BaseGameEntity에 대한 포인터가 포함되어 있습니다.
// 노드가 health packs, gold mines 등을 나타낼 때 유용합니다.
// 
//-----------------------------------------------------------------------------
template <class extra_info = void*>
class NavGraphNode : public GraphNode
{
protected:

  //the node's position 노드의 위치
  Vector2D     m_vPosition;

  //often you will require a navgraph node to contain additional information.
  //For example a node might represent a pickup such as armor in which
  //case m_ExtraInfo could be an enumerated value denoting the pickup type,
  //thereby enabling a search algorithm to search a graph for specific items.
  //Going one step further, m_ExtraInfo could be a pointer to the instance of
  //the item type the node is twinned with. This would allow a search algorithm
  //to test the status of the pickup during the search. 
  // 종종 추가 정보를 포함시키기 위해 navgraph node가 필요합니다.
  // 예를 들어 노드는 m_ExtraInfo 픽업 유형을 나타내는 열거된 값이 될 수 있는 방어 장치와 같은 픽업을 나타낼 수 있습니다.
  // 따라서 검색 알고리즘이 그래프에서 특정 항목을 검색할 수 있습니다.
  // 더하여, m_ExtraInfo는 노드가 트윈된 항목 유형의 인스턴스에 포인터 일 수 있습니다.
  // 이렇게 하면 검색 알고리즘이 검색 중에 픽업 상태를 테스트할 수 있습니다.



  extra_info  m_ExtraInfo;

public:
  
  //ctors
  NavGraphNode():m_ExtraInfo(extra_info()){}

  NavGraphNode(int      idx,
               Vector2D pos):GraphNode(idx),
                             m_vPosition(pos),
                             m_ExtraInfo(extra_info())
  {}

  //stream constructor
  NavGraphNode(std::ifstream& stream):m_ExtraInfo(extra_info())
  {
    char buffer[50];
    stream >> buffer >> m_iIndex >> buffer >> m_vPosition.x >> buffer >> m_vPosition.y;
  }
 

  virtual ~NavGraphNode(){}

  Vector2D   Pos()const{return m_vPosition;}
  void       SetPos(Vector2D NewPosition){m_vPosition = NewPosition;}

  extra_info ExtraInfo()const{return m_ExtraInfo;}
  void       SetExtraInfo(extra_info info){m_ExtraInfo = info;}

  //for reading and writing to streams.
  friend std::ostream& operator<<(std::ostream& os, const NavGraphNode& n)
  {
    os << "Index: " << n.m_iIndex << " PosX: " << n.m_vPosition.x << " PosY: " << n.m_vPosition.y << std::endl;

    return os;
  }
  
};


#endif
