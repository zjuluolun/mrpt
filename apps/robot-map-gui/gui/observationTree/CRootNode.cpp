#include "CRootNode.h"
#include "CPairNode.h"


using namespace mrpt;
using namespace mrpt::maps;

CRootNode::CRootNode(const CSimpleMap &simplemap)
	: CNode (nullptr)
{
	for (auto iter = simplemap.begin(); iter != simplemap.end(); ++iter)
	{
		CPairNode *node = new CPairNode(this, *iter);
		m_posesNode.push_back(node);

	}
}

int CRootNode::childCount() const
{
	return m_posesNode.size();
}

CNode* CRootNode::child(int id)
{
	assert(id <= m_posesNode.size());
	return m_posesNode[id];
}


CNode::ObjectType CRootNode::type() const
{
	return ObjectType::Root;
}

std::string CRootNode::displayName() const
{
	return "root";
}
