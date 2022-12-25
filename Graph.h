#pragma once
#include <iostream>
#include <vector>
#include <list>
//using namespace std;
#pragma once
class Graph {
	class Node {
	public:
		Node(short v = -1, bool isBomb = false) {
			value = v;
			bomb = isBomb;
			explored = false;
			top = NULL;
			bot = NULL;
			left = NULL;
			right = NULL;
		}
		~Node() {

		}
		//value indicating number of bombs around this node
		short value;
		//boolean indicating if this node is a bomb.
		bool bomb;
		//explored boolean to clarify if node visited or not
		bool explored;
		//adjacent pointers for the four vertices to point to adjacent vertices
		Node* top;
		Node* bot;
		Node* left;
		Node* right;
	};
	//side nodes are connected to 3 adjacent nodes and other nodes are connected to 8 adjacent nodes.
	//nodes for number of vertices of graph represented by the board size.
	int rows, columns;
	//list for nodes.
	std::vector<Node*>* myN;

public:
	//constructor: initialize
	Graph(int r = 8, int c = 8);
	~Graph();
	//add an edge between 2 vertices.
	//void addEdge(int index1, int index2);
	//traverse all nodes of the graph
	void traverse();
	//initialize node by providing the index of the node and the value.
	void initializeNode(int index, short value);
	//traverse adjacent list of given index of node.
	void traverseNodeAdj(int index);
	//check if this node is a bomb.
	bool checkBomb(int index);
	//initialize some nodes randomly with n number of bombs.
	void initializeBombs(int n);
	//initialize vertices with numbers around bombs.
	void initializeNodes();
	//connect nodes with each node adjacent to it by initializing the adjList.
	void connectNodes();
	//get the value of the node with passed index, will be used when node is clicked.
	int getNodeValue(int index);

	void explore(int index);
	void exploreNodeAdj(Node* ptr);
	void firstClick(int index);
};

/*

*/

/*
class Node{
	public:
		Node(short v=-1,bool b=false) {
			value = v;
			bomb = b;
			explored = false;
			adjList = new list<Node*>;
		}
		//value indicating number of bombs around this node
		short value;
		//boolean indicating if this node is a bomb.
		bool bomb;
		//explored boolean to clarify if node visited or not
		bool explored;
	//adjacent list for every vertix to point to adjacent virtices
		list<Node*>* adjList;
	};
*/