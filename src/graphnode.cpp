#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot;  // Removing the initial bug

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) // changed for task 4
{
    _childEdges.push_back(std::move(edge));

}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) // removed  pointer for task 5
{
    _chatBot = std::move(chatbot);  // using move semantics for task 5
    _chatBot.SetCurrentNode(this);

}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere( std::move(_chatBot));   // move semantics for task 5
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get(); // task 4

    ////
    //// EOF STUDENT CODE
}