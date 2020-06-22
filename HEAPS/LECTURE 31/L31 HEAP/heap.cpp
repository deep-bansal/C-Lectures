#include <bits/stdc++.h>
using namespace std;
///max heap
void upheapify(vector<int>& heap, int index)
{
	if (index == 0)
	{
		return;
	}
	int parentindex = (index - 1) / 2;
	if (heap[parentindex] < heap[index])
	{
		swap(heap[parentindex], heap[index]);
		upheapify(heap, parentindex);
	}
	else
	{
		return;
	}
}
void downheapify(vector<int>& heap, int index)
{
	int leftchildidx = (2 * index) + 1;
	int rightchildidx = (2 * index) + 2;

	/// Leaf node
	if (leftchildidx >= heap.size() and rightchildidx >= heap.size())
	{
		return;
	}
	int largechildindex = index;
	if (leftchildidx < heap.size() and heap[leftchildidx] > heap[index])
	{
		largechildindex = leftchildidx;
	}
	if (rightchildidx < heap.size() and heap[rightchildidx] > heap[largechildindex])
	{
		largechildindex = rightchildidx;
	}

	if (largechildindex == index)
	{
		return;
	}
	swap(heap[index], heap[largechildindex]);
	downheapify(heap, largechildindex);

}

void deleteroot(vector<int> &heap)
{
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	downheapify(heap, 0);
}
void deletenode(vector<int>& heap, int index)
{
	heap[index] = INT_MAX;
	upheapify(heap, index);
	deleteroot(heap);
}

void insert(vector<int>& heap, int num)
{
	heap.push_back(num);
	upheapify(heap, heap.size() - 1);
}

void buildHeap(vector<int> &heap)
{
	for (int i = 0; i < heap.size(); i++)
	{
		upheapify(heap, i);
	}
}

void buildHeapOPt(vector <int>& heap)
{
	for (int i = heap.size() - 1; i >= 0; i--)
	{
		downheapify(heap, i);
	}
}

void displayHeap(vector<int> heap)
{
	for (int i = 0; i < heap.size(); i++)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	vector <int> heap;

	insert(heap, 10);
	insert(heap, 5);
	insert(heap, 1);
	insert(heap, 12);
	insert(heap, 190);
	insert(heap, 18);

	displayHeap(heap);

	deleteroot(heap);

	displayHeap(heap);

	deletenode(heap, 2);

	displayHeap(heap);

	// int n;
	// cin>>n;
	// for (int i = 0; i < n; ++i)
	// {
	// 	int ele;
	// 	cin>>ele;
	// 	heap.push_back(ele);
	// }
	// //displayHeap(heap);
	// //buildHeap(heap);
	// displayHeap(heap);
	// buildHeapOPt(heap);
	// displayHeap(heap);


	return 0;
}