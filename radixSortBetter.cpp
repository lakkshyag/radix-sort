#include <iostream>                             
using namespace std;

class elemPair
{
    public:
    int num;
    int digit;

    elemPair()
    {
        num = 0;
        digit = 0;
    }

    elemPair(int x, int divideTimes)
    {
        bool isNeg = x < 0;
        if ( isNeg )
        {
            num = x;
            x *= -1;
            int i = 1;
            while ( i <= divideTimes )
            {
                x /= 10;
                i++;
            }
            x %= 10;
            (*this).digit = x;
        }
        else
        {
            num = x;
            int i = 1;
            while ( i <= divideTimes )
            {
                x /= 10;
                i++;
            }
            x %= 10;
            (*this).digit = x + 9;
        }
    }
};

void arrayCreate(int* arr, int const &n)
{
    int i = 0;
    while ( i <= n-1 )
    {
        cin>>*(arr+i);
        i++;
    }
}

void arrayPrint(int* arr, int const &n)
{
    int i = 0;
    while ( i <= n-1 )
    {
        cout<<*(arr+i)<<" ";
        i++;
    }
    cout<<endl;
}

int arrayMaxElement(int* arr, int const &n)
{
    int max = *(arr);
    int i = 0;
    while ( i <= n-1 )
    {
        if ( *(arr+i) > max )
        {
            max = *(arr+i);
        }
        i++;
    }
    return max;
}

int arrayMinElement(int* arr, int const &n)
{
    int min = *(arr);
    int i = 0;
    while ( i <= n-1 )
    {
        if ( *(arr+i) < min )
        {
            min = *(arr+i);
        }
        i++;
    }
    return min;
}

int numDigits(int x1, int x2)
{
    int i1 = 0;
    while ( x1 > 0 )
    {
        x1 /= 10;
        i1++;
    }

    x2 *= -1;
    int i2 = 0;
    while ( x2 > 0 )
    {
        x2 /= 10;
        i2++;
    }

    if (i1 >= i2 )
    {
        return i1;
    }    
    else
    {
        return i2;
    }
}

void arrayElementCount(elemPair** arr, int* arrCount, int const &n)
{
    int i = 0;
    while ( i <= 18 )
    {
        *(arrCount+i) = 0;
        i++;
    }

    i = 0;
    while ( i <= n-1 )
    {
        int curr = (*(*(arr+i))).digit;
        (*(arrCount+curr))++;
        i++;
    }

    int sum = 0;
    i = 0;
    while ( i <= 18 )
    {
        *(arrCount+i) += sum;
        
        sum = *(arrCount+i);
        i++;
    }
}

void countArrayRotate(int* arrCount)
{
    int i = 18;
    while ( i >= 1 )
    {
        *(arrCount+i) = *(arrCount+i-1);
        i--;
    }
    *(arrCount) = 0;
}

void fillPairArray(int* arr, elemPair** arrOutPair, int const &n, int const &times)
{
    int i = 0;
    while ( i <= n-1 )
    {
        int curr = *(arr+i);
        elemPair* currPair = new elemPair(curr, times);
        *(arrOutPair+i) = currPair;
        i++;
    }
}

void deletePairArray(elemPair** arrOutPair, int const &n)
{
    int j = 0;
    while ( j <= n-1 )
    {
        elemPair* delCurr = *(arrOutPair+j);
        delete delCurr;
        j++;
    }
}

void sortingElements(elemPair** arr, int* arrCount, int* arrOut, int const &n)
{
    int i = 0;
    while ( i <= n-1 )
    {
        elemPair* currElem = *(arr+i);
        int index =  *( arrCount + (*currElem).digit);

        *(arrOut+index) = (*currElem).num;
        (* (arrCount + (*currElem).digit) )++;

        i++;
    }
}

void arrayCopy(int* arr, int* arrOut, int const &n)
{
    int i = 0;
    while ( i <= n-1 )
    {
        *(arr+i) = *(arrOut+i);
        i++;
    }
}

int numNegative(int* arr, int const &n)
{
    int i = 0;
    int neg = 0;
    while ( i <= n-1 )
    {
        if ( *(arr+i) < 0 )
        {
            neg++;
        }
        i++;
    }

    return neg;
}

void arrayReverse(int* arr, int ei)
{
    int i = 0;
    while ( i <= ei/2 )
    {
        int temp = *(arr+i);
        *(arr+i) = *(arr+ei-i);
        *(arr+ei-i) = temp;
        i++;
    }
}

void radixSort(int* arr, int const &n)
{
    int max = arrayMaxElement(arr, n);
    int min = arrayMinElement(arr, n);
    int maxDigits = numDigits(max, min);
    cout<<maxDigits<<endl<<endl;

    int times = 0;
    while ( times <= maxDigits-1 )
    {
        elemPair** arrOutPair = new elemPair*[n];   
        fillPairArray(arr, arrOutPair, n, times);
        
        int* arrCount = new int[19];
        arrayElementCount(arrOutPair, arrCount, n);
        //arrayPrint(arrCount, 19);
        countArrayRotate(arrCount);
        //arrayPrint(arrCount, 19);                                   // checking status of the count array

        int* arrOut = new int[n];
        sortingElements(arrOutPair, arrCount, arrOut, n);
        arrayPrint(arrOut, n);                                      // checking status of the sorted array
        //cout<<endl;                                                 //

        arrayCopy(arr, arrOut, n);
        deletePairArray(arrOutPair, n);



        delete[] arrOutPair;
        delete[] arrCount;
        delete[] arrOut;
        times++;
    }

    int numNeg = numNegative(arr, n);
    arrayReverse(arr, numNeg-1);
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    arrayCreate(arr, n);
    
    radixSort(arr, n);
    arrayPrint(arr, n);



    delete[] arr;
    return 0;
}