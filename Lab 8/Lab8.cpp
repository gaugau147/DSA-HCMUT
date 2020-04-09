#include <iostream>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <stdbool.h>


using namespace std;

#define		ARRAY_SIZE	50

#define		INC_SORT	0
#define		DEC_SORT	1

#define		MAX_HEAP	0
#define		MIN_HEAP	1

#define     MIN_SIZE    16

void printArr(int *arr);
void reheapUp (int* heap, int newNode);
void reheapDown (int* heap, int root, int last);

class Heap
{
public:
	int*	arr;
	int		count;
	int		capacity;
	int		heap_type;
public:
	int	getCount() { return count;}
	void CopyData(int* data, int size)
	{
		memcpy(this->arr, data, sizeof(int)*size);
		this->count = size;
	}
	void CreateHeap(int capacity, int heap_type)
	{
		this->heap_type = heap_type;
		this->count = 0;
		this->capacity = capacity;
		this->arr = new int[this->capacity];
		if(this->arr == NULL)
		{
			cout << "Not enough memory";
			exit(-1);
		}
	}
	~Heap()
	{
		delete [] this->arr;
	}
	void ReheapUp(long position)
	{
		if(position > 0)
		{
			long parent = (position - 1)/2;

			// For max-heap
			if(this->heap_type == MAX_HEAP && this->arr[position] > this->arr[parent])
			{
				int temp = this->arr[position];
				this->arr[position] = this->arr[parent];
				this->arr[parent] = temp;
				ReheapUp(parent);
			}

			// For min-heap
			else if (this->heap_type == MIN_HEAP && this->arr[position] < this->arr[parent])
            {
                int temp = this->arr[position];
                this->arr[position] = this->arr[parent];
				this->arr[parent] = temp;
				ReheapUp(parent);
            }
		}
	}
	void ReheapDown(int position, int lastPosition)
	{
		long leftChild = 2*position + 1;
		long rightChild = 2*position + 2;
		long child;

		//For max-heap
		if(this->heap_type == MAX_HEAP)
		{
			if(leftChild <= lastPosition)
			{
				if(rightChild <= lastPosition && this->arr[rightChild] > this->arr[leftChild])
					child = rightChild;
				else
					child = leftChild;

				if(this->arr[child] > this->arr[position])
				{
					int temp = this->arr[child];
					this->arr[child] = this->arr[position];
					this->arr[position] = temp;
					ReheapDown(child, lastPosition);
				}
			}
		}

		// For min-heap
		else
        {
            if(leftChild >= lastPosition)
			{
				if(rightChild >= lastPosition && this->arr[rightChild] < this->arr[leftChild])
					child = rightChild;
				else
					child = leftChild;

				if(this->arr[child] < this->arr[position])
				{
					int temp = this->arr[child];
					this->arr[child] = this->arr[position];
					this->arr[position] = temp;
					ReheapDown(child, lastPosition);
				}
			}
        }
	}
	bool InsertHeap(int DataIn)
	{
		if(this->count == this->capacity)
			return false;
		else
		{
			this->arr[this->count]= DataIn;
			ReheapUp(this->count);
			this->count++;
			return true;
		}
	}
	bool DeleteHeap(int &DataOut)
	{
		if(this->count <= 0)
			return false;
		else
		{
			DataOut = this->arr[0];
			this->arr[0] = this->arr[count - 1];
			count = count - 1;
			ReheapDown(0, count-1);
			return true;
		}
	}
	void BuildHeap()
	{
		long position = this->count/2 - 1;

		while(position >= 0)
		{
			ReheapDown(position, count - 1);
			position--;
		}

	}
	bool IsHeap()
	{
		long position = this->count/2 - 1;
		long lastPosition = this->count - 1;

		while(position >= 0)
		{
			long leftChild = 2*position + 1;
			long rightChild = 2*position + 2;
			long child;

			//For max-heap
			if(this->heap_type == MAX_HEAP)
			{
				if(leftChild <= lastPosition)
				{
					if(rightChild <= lastPosition && this->arr[rightChild] > this->arr[leftChild])
						child = rightChild;
					else
						child = leftChild;

					if(this->arr[child] > this->arr[position])
						return false;
				}
			}

			// For min-heap
			else
            {
                if(leftChild >= lastPosition)
				{
					if(rightChild >= lastPosition && this->arr[rightChild] < this->arr[leftChild])
						child = rightChild;
					else
						child = leftChild;

					if(this->arr[child] < this->arr[position])
						return false;
				}
            }

			position--;
		}
		return true;
	}
	void PrintHeap()
	{
		for(long i=0; i<this->count; i++)
			cout << this->arr[i] << " ";
		cout << endl;
	}
};
int*	arr1=NULL;
Heap	heap;

long lrand()
{
#define	CHAR_BITS	8
	long r = 0;
	for (int i = 0; i < sizeof(long)/sizeof(int); i++)
	{
		r = r << (sizeof(int) * CHAR_BITS);
		r |= rand();
	}
	return r;
}

bool IsSorted(int nType)
{
	if(nType == DEC_SORT)
		for(int i = 0; i< ARRAY_SIZE; i++)
			if(arr1[i] != ARRAY_SIZE - 1 - i)
				return false;
	else if(nType == INC_SORT)
		for(int i = 0; i< ARRAY_SIZE; i++)
			if(arr1[i] != i)
				return false;

	return true;
}

void ShuffleData(int *arr)
{
	// Shuffle data
	long i;
	srand(time(NULL));
	for(i = ARRAY_SIZE - 1; i>0 ; i--)
	{
		long j = lrand() % ARRAY_SIZE;

		int	temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void InsertionSort(int* arr)
{
	long count = ARRAY_SIZE, current;

	current = 1;

	while(current < count)
	{
		long temp = arr[current];
		long walker = current - 1;

		while(walker >= 0 && temp < arr[walker])
		{
			arr[walker + 1] = arr[walker];
			walker--;
		}

		arr[walker+1] = temp;
		current++;
	}
}

// Shell Sort Implement
void ShellSort(int *arr)
{
    int hold;
    int incre = ARRAY_SIZE/2;
    int walker;

    while (incre != 0)
    {

        for (int curr = incre; curr <= ARRAY_SIZE-1; curr++)
        {
            // Hold arr[curr] value until we find its proper position
            hold = arr[curr];
            walker = curr - incre;
            while (walker >= 0 && hold < arr[walker])
            {
                arr[walker + incre] = arr[walker];
                walker = ( walker - incre );
            }
            // Insert hold in proper position
            arr[walker + incre] = hold;
        }
        // Move to next segment dividing
        incre = incre / 2;
    }
}

// Selection Sort Implement
void SelectionSort(int *arr)
{
    int smallest;
    int hold;
    for(int curr=0; curr<ARRAY_SIZE-1; curr++)
    {
        smallest = curr;
        for (int i=curr+1; i<ARRAY_SIZE; i++)
        {
            if (arr[i] < arr[smallest])
            {
                smallest = i;
            }
        }
        swap(arr[smallest], arr[curr]);
    }
}

void HeapSort(int *arr)
{
    int sorted;
    int holdData;
    for (int walker = 1; walker < ARRAY_SIZE; walker++)
    {
        reheapUp(arr, walker);
    }

    // Heap created. Now sort it.
    sorted = ARRAY_SIZE-1;
    while (sorted > 0)
    {
        holdData = arr[0];
        arr[0] = arr[sorted];
        arr[sorted] = holdData;
        sorted--;
        reheapDown (arr, 0, sorted);
    }

}

void reheapUp (int* heap, int newNode)
{
    int parent;
    int hold;

    // if not at root of heap
    if (newNode)
    {
        parent = (newNode - 1)/ 2;
        if ( heap[newNode] < heap[parent] )
        {
            hold = heap[parent];
            heap[parent] = heap[newNode];
            heap[newNode] = hold;
            reheapUp (heap, parent);
        }
    }

}

void reheapDown (int* heap, int root, int last)
{
    int hold;
    int leftKey;
    int rightKey;
    int largeChildKey;
    int largeChildIndex;

    if ((root * 2 + 1) <= last)
    // There is at least one child
    {
        leftKey = heap[root * 2 + 1];
        if ((root * 2 + 2) <= last)
        {
            rightKey = heap[root * 2 + 2];
        }
        else
        {
           rightKey = -1;
        }

        // Determine which child is smaller
        if (leftKey < rightKey)
        {
            largeChildKey = leftKey;
            largeChildIndex = root * 2 + 1;
        }
        else
        {
            largeChildKey = rightKey;
            largeChildIndex = root * 2 + 2;
        }
        // Test if root < smaller subtree
        if (heap[root] > heap[largeChildIndex])
        {
            // parent > children
            hold = heap[root];
            heap[root] = heap[largeChildIndex];
            heap[largeChildIndex] = hold;
            reheapDown (heap, largeChildIndex, last);
        }
    }
    return;
}

void bubbleSort (int* arr)
{
    int temp;
    // Each iteration is one sort pass
    for (int current = 0, sorted = 0; current < ARRAY_SIZE && !sorted; current++) // sorted flag
    {
        for (int walker = ARRAY_SIZE-1, sorted = 1; walker > current; walker--)
        {
            if (arr[walker] < arr[walker-1])
            // Any exchange means list is not sorted
            {
                sorted = 0;
                swap(arr[walker], arr[walker-1]);
            }
        }
    }
}

// Insertion sort for Quick sort
void quickInsertion (int *arr, int first, int last)
{
    int hold;
    int walker;

    for (int current = first + 1; current <= last; current++)
    {
        hold = arr[current];
        walker = current - 1;
        while (walker >= first && hold < arr[walker])
        {
            arr[walker+1] = arr[walker];
            walker = walker - 1;
        }
        arr[walker+1] = hold;
    }
}

// Find median pivot for Quick sort
void medianLeft (int *arr, int left, int right)
{
    int mid;
    int hold;
    mid = (left + right)/2;
    if (arr[left] > arr[mid])
    {
        swap(arr[left], arr[mid]);
    }
    if (arr[left] > arr[right])
    {
        swap(arr[left], arr[right]);
    }
    if (arr[mid] > arr[right])
    {
        swap(arr[mid], arr[right]);
    }
    swap(arr[left], arr[mid]);
}

//left: first index, right: last index
void quickSort(int *arr, int left, int right)
{
    int sortLeft, sortRight, pivot, hold;

    if ((right-left) > MIN_SIZE)
    {
        medianLeft(arr, left, right);
        pivot = arr[left];
        sortLeft = left + 1;
        sortRight = right;
        while (sortLeft <= sortRight)
        {
            // find elements on the left that belongs to the right
            while (arr[sortLeft] < pivot)
            {
                sortLeft++;
            }
            while (arr[sortRight] >= pivot)
            {
                sortRight--;
            }
            if (sortLeft <= sortRight)
            {
                swap(arr[sortLeft], arr[sortRight]);
                sortLeft++;
                sortRight--;
            }
        }
        arr[left] = arr[sortLeft-1];
        arr[sortLeft-1] = pivot;
        if (left < sortRight)
        {
            quickSort(arr, left, sortRight-1);
        }
        if (sortLeft < right)
        {
            quickSort(arr, sortLeft, right);
        }
    }
    else
    {
        quickInsertion(arr, left, right);
    }
}


// Merge sort
void Merge (int *arr, int left, int mid, int right)
{
    int *temp;
    int i = left;
    int j = mid + 1;
    temp = new int [right - left + 1];
    for (int k=0; k <= right-left; k++)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        // Check if there is any element left on the left, if not, move all elements on the right to temp
        if (i == mid+1)
        {
            while (j <= right)
            {
                k++;
                temp[k] = arr[j];
                j++;
            }
            break;
        }
        // Check if there is any element left on the right, if not, move all elements on the left to temp
        if (j == right+1)
        {
            while (i <= mid)
            {
                k++;
                temp[k] = arr[i];
                i++;
            }
            break;
        }
    }
    // Copy elements from temp to arr, then delete temp
    for (int k=0; k <= right-left; k++)
    {
        arr[left+k] = temp[k];
    }
    delete temp;
}

void mergeSort (int *arr, int left, int right)
{
    if (right > left)
    {
        int mid;
        mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        Merge(arr, left, mid, right);
    }
}


void Sorting(void (*SortFunc)(int*), int nSortType = INC_SORT)
{
	DWORD startTime;
	DWORD endTime;
	long i;
	char	strMessage[80];

	if(nSortType == INC_SORT)
		strcpy(strMessage, "The array is sorted in increasing order");
	else
		strcpy(strMessage, "The array is sorted in decreasing order");
	//Sorting random array
	cout << "Sorting an random array ... " << endl;

	startTime = GetTickCount();
	(*SortFunc)(arr1);
	endTime = GetTickCount();

	if(IsSorted(nSortType))
		cout << strMessage << endl;
	else
		cout << "The array is unorder" << endl;

	cout << "Time (ms) :  "<< (endTime - startTime)/1000.0 << endl;

	//Sorting increasing array
	for(i = 0; i<ARRAY_SIZE; i++)
		arr1[i] = i;

	cout << "Sorting an increasing array ... " << endl;

	startTime = GetTickCount();
	(*SortFunc)(arr1);
	endTime = GetTickCount();

	if(IsSorted(nSortType))
		cout << strMessage << endl;
	else
		cout << "The array is unorder" << endl;

	cout << "Time (ms) :  "<< (endTime - startTime)/1000.0 << endl;

	//Sorting decreasing array
	for(i = 0; i<ARRAY_SIZE; i++)
		arr1[i] = ARRAY_SIZE - 1 - i;

	cout << "Sorting an decreasing array ... " << endl;

	startTime = GetTickCount();
	(*SortFunc)(arr1);
	endTime = GetTickCount();

	if(IsSorted(nSortType))
		cout << strMessage << endl;
	else
		cout << "The array is unorder" << endl;

	cout << "Time (ms) :  "<< (endTime - startTime)/1000.0 << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Create array;
	arr1 = new int[ARRAY_SIZE];

	if(arr1 == NULL)
	{
		cout << "Not enough memory";
		return 0;
	}
	for(long i = 0; i<ARRAY_SIZE; i++)
		arr1[i] = i;

	heap.CreateHeap(ARRAY_SIZE, MIN_HEAP);

	cout << "ARRAY SIZE: "<< ARRAY_SIZE << endl << endl;

	cout << "================================================"<<endl;
	cout << "			INSERTION SORT" << endl;
	cout << "================================================"<<endl;
	ShuffleData(arr1);
	Sorting(InsertionSort);

	//Release memory
	delete [] arr1;

	return 0;
}

void printArr(int *arr)
{
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        if (arr[i]<10)
        {
            cout<<"  "<<arr[i];
        }
        else
        {
            cout<<" "<<arr[i];
        }
        if ((i+1)%10 == 0) cout<<"\n";
    }
    cout<<"\n";
}

int main()
{
    bool dup = false;
    int arr[ARRAY_SIZE];
    srand(time(0));
    //while (true)
    //{
        for (int i=0;i<ARRAY_SIZE; i++)
        {
            bool dup = false;
            int temp = (rand() % (50));
            for (int j=0; j<i; j++)
            {
                if (temp == arr[j])
                    dup = true;
            }
            if (dup == false)
            {
                arr[i] = temp;
            }
            else
            {
                i--;
            }
        }
    //}
    /*
    for (int i=0; i<ARRAY_SIZE; i++){
        int temp = (rand() % (50));

        for (int j=0; j<=i; j++)
        {
            if (temp == arr[j])
            {
                temp = (rand() % (50));
            }
            else
            {
                break;
            }
        }
        arr[i] = temp;
    }
    */
    int *pt;
    pt = arr;
    printArr(pt);
    /*
    std::srand(std::time(nullptr));
        std::cout << (std::rand() % 6 + 1);
        */
    mergeSort(pt, 0, ARRAY_SIZE-1);
    printArr(pt);
    /*
    Heap H;
    H.CreateHeap(ARRAY_SIZE, MAX_HEAP);
    for (int i=0; i<ARRAY_SIZE; i++){
        H.CopyData(pt, ARRAY_SIZE);
        pt++;
    }
    H.PrintHeap();

    //int arr[ARRAY_SIZE];
    //int *pt;
    //pt = arr;
    void (*fcnPtr)(int *pt);
	fcnPtr = InsertionSort;

	Sorting(fcnPtr, INC_SORT);
    */
}
