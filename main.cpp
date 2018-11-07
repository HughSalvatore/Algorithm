#include <iostream>

using namespace std;

int binarySearch(int arr[], int length, int target)
{
    int low = 0, high = length - 1;
    while(low < high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        
    }
}

//count  the amount of three-number-group in a array which the sum=0
int threeSumSlow(int arr[], int length)
{
    int cnt = 0;
    for (int i = 0; i < length; ++i)
    {
        for (int j = i + 1; j < length; ++j)
        {
            for (int k = j + 1; k < length; ++k)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    ++cnt;
                }
            }
        }
    }

    return cnt;
}

int threeSumBinarySearch(int arr[], int length)
{
    
}

int threeSumTwoPointer(int arr[], int length)
{
    int cnt = 0;
    for (int i = 0; i < length - 2; ++i)
    {
        int low = i + 1, high = length - 1, target = -arr[i];
        if( i > 0 && arr[i] == arr[i-1])
            continue;
              
        while(low < high){
            int sum = arr[low] + arr[high];
            if(sum == target)
            {
                cnt++;
                while(low < high && arr[low] == arr[low + 1])
                    low++;
                while(low < high && arr[high] == arr[high - 1])
                    high--;
                low++;
                high--;
            }
            else if (sum < target){
                low++;
            }
            else
                high--;
        }
        
    }

    return cnt;
}

/**********************************/
/*        SORT MODULE             */
/**********************************/
static int countOfSwap = 0;

template<typename T>
bool lessFunc(T a, T b)
{
    return a < b;
}

template<typename T>
void swapFunc(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;

    ++countOfSwap;
}

/*********** SelSort ***************/
template<typename T>
void selSort(T *arr, int length)
{   
    for(int i = 0; i < length - 1; i++)
    {
        int min = i;
        
        for(int j = i + 1; j < length; j++)
        {
            if (lessFunc(arr[j], arr[min]))
            {
                min = j;
            }
        }
        swapFunc(arr[i], arr[min]);
    }    
}

/*********** BubSort **************/
template<typename T>
void bubSort(T *arr, int length)
{
    bool hasSorted = false;
    
    for(int i = length - 1; i > 0 && !hasSorted; i++)
    {
        hasSorted = true;

        for (int j = 0; j < i; j++)
        {
            if (lessFunc(arr[j+1], arr[j]))
            {
                hasSorted = false;
                swapFunc(arr[j + 1], arr[j]);
            }
        }
    }  
}

/********** InsertSort ***************/
template<typename T>
void insertSort(T *arr, int length)
{
    
    for(int i = 1; i < length; i++)
    {
        for (int j = i; j > 0 && lessFunc(arr[j], arr[j - 1]); j--)
        {
            swapFunc(arr[j], arr[j - 1]);
        }
    }
    
}



int main()
{
    int array[] = {1, 4, 2, 8, 5, 7};

    //selSort(array, 6);
    bubSort(array, 6);

    for(int i = 0; i < 6; i++)
    {
        cout << array[i] << endl;
    }

    cout << "countOfSwap=" << countOfSwap << endl;

    return 0;
}