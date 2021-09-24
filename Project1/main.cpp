#include"customArray.h"
#include<iostream>

using namespace std;
int main(void)
{
    int arrayLength;
    cin >> arrayLength;
    float* array = new float[arrayLength];
    InitializeWithRandomValues(array, arrayLength);
    StdOutput(array, arrayLength);
    int a, b;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B:";
    cin >> b;

    /*auto count = ElementValuesCount(array, arrayLength, [a,b](float value) 
        {
            if (value >= 1 && value <= 4) {
                return true;
            }
            return false;
        });*/

    //cout << count;

    int maxValueIndex = FindMaxValueIndex(array, arrayLength);
    float sum = Sum(array, arrayLength, maxValueIndex+1, arrayLength - 1, [](float value) {return true; });
    cout << sum;

}

