#pragma once


//Note�������ҵĽ����뱣֤�ڼ�����
//TODO:������ĳ�ģ���࣬����ֻ֧�� size_t����
//����Լ̫����


//��rank��:
 /*�����Ⱥϲ����������ǽ���С������������������ϡ�
 ��ΪӰ������ʱ�����������ȣ���С������ӵ���������ĸ��Ͻ����������ȳ������ǵ�����ͬ��
 ������㷨�У�����ȡ�����ˡ���ȡ�����ΪͬʱӦ����·��ѹ��ʱ�������ģ��Ƚ�������߶���ͬ��
 ��Ԫ�ص������ȶ���Ϊ0����������ͬΪr��������ʱ�����ǵ���r+1
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
		//��(rank):
		int rank;
		
		//ĳԪ�����������±�
		int index; 
		Node* parent;
		Node() :rank(0), index(0), parent(nullptr) {}
	};

	//Ԫ�صĸ���
	size_t m_numElements;
	
	//���ϵĸ���
	size_t m_numSets;

	//��Ž�������
	std::vector<Node*> m_nodes; 
};