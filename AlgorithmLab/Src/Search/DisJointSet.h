#pragma once


//Note：所查找的结点必须保证在集合中
//TODO:将此类改成模板类，现在只支持 size_t类型
//受制约太严重


//轶（rank）:
 /*“按秩合并”，即总是将更小的树连接至更大的树上。
 因为影响运行时间的是树的深度，更小的树添加到更深的树的根上将不会增加秩除非它们的秩相同。
 在这个算法中，术语“秩”替代了“深度”，因为同时应用了路径压缩时（见下文）秩将不会与高度相同。
 单元素的树的秩定义为0，当两棵秩同为r的树联合时，它们的秩r+1
 */


class DisjointSets
{
public:
	DisjointSets();
	
	DisjointSets(size_t count);
   
    DisjointSets(const DisjointSets& s);
	
	~DisjointSets();

	size_t findSet(size_t element) const;
	
	void mergeSet(size_t setId1, size_t setId2);

	void addElements(size_t numToAdd);

	void deleteAllElements();
	
	size_t numElements() const;
	
	size_t numSets() const;

	void printElementSets();
	
	bool isInSameSet(size_t param1,size_t param2);
	bool isInSameSet(size_t countparam,...);

private:

	struct Node
	{
		//轶(rank):
		int rank;
		
		//某元素在数组中下标
		int index; 
		Node* parent;
		Node() :rank(0), index(0), parent(nullptr) {}
	};

	//元素的个数
	size_t m_numElements;
	
	//集合的个数
	size_t m_numSets;

	//存放结点的容器
	std::vector<Node*> m_nodes; 
};