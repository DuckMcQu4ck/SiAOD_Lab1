#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

namespace Array 
{

    void RandomInit(void)
    {
        srand(time(NULL));
    }

    int RandomRange(int bottom, int top)
    {
        return bottom + rand() % (top - bottom + 1);
    }

    float RandomRange(int bottom, int top, int digits)
    {
        return (bottom + rand() % (top - bottom + 1)) / (float)digits;
    }

    void InitializeWithRandomValues(int* array, size_t size)
    {
        RandomInit();
        for (size_t i = 0; i < size; ++i)
            array[i] = (rand() % 10) + 1;
    }

    void InitializeWithRandomValues(float* array, size_t size)
    {
        RandomInit();
        for (size_t i = 0; i < size; ++i)
            array[i] = ((rand() % 10) + 1) * 0.1f;
    }

    int Sum(int* array, size_t size, size_t from, size_t to, bool (*predicate)(int value))
    {
        int sum = 0;
        for (size_t i = from; i <= to; ++i)
            if (predicate(array[i]))
                sum += array[i];

        return sum;
    }

    float Sum(float* array, size_t size, size_t from, size_t to, bool (*predicate)(float value))
    {
        float sum = 0;
        for (size_t i = from; i <= to; ++i)
            if (predicate(array[i]))
                sum += array[i];

        return sum;
    }

    int Product(int* array, size_t size, size_t from, size_t to, bool (*predicate)(int value))
    {
        int res = 1;
        for (size_t i = from; i < to; ++i)
            if (predicate(array[i]))
                res *= array[i];

        return res;
    }

    float Product(float* array, size_t size, size_t from, size_t to, bool (*predicate)(float value))
    {
        float res = 1;
        for (size_t i = from; i < to; ++i)
            if (predicate(array[i]))
                res *= array[i];

        return res;
    }

    void ShiftRight(int* array, size_t size, size_t startIndex)
    {
        for (size_t i = size - 1; i > startIndex; --i)
        {
            array[i] = array[i - 1];
        }
    }

    void ShiftRight(float* array, size_t size, size_t startIndex)
    {
        for (size_t i = size - 1; i > startIndex; --i)
        {
            array[i] = array[i - 1];
        }
    }

    void ShiftLeft(int* array, size_t size, size_t startIndex)
    {
        for (size_t i = startIndex; i < size - 1; ++i)
        {
            array[i] = array[i + 1];
        }
    }

    void ShiftLeft(float* array, size_t size, size_t startIndex)
    {
        for (size_t i = startIndex; i < size - 1; ++i)
        {
            array[i] = array[i + 1];
        }
    }

    void Insert(int* array, size_t size, size_t index, int value, int** out_array, size_t* out_size)
    {
        int* array_temp = new int[size + 1];

        for (size_t i = 0; i < size + 1; ++i)
            array_temp[i] = array[i];

        delete[] array;

        ShiftRight(array_temp, size + 1, index);

        array_temp[index] = value;

        *out_array = array_temp;
        *out_size = size + 1;
    }

    void Insert(float* array, size_t size, size_t index, float value, float** out_array, size_t* out_size)
    {
        float* array_temp = new float[size + 1];

        for (size_t i = 0; i < size + 1; ++i)
            array_temp[i] = array[i];

        delete[] array;

        ShiftRight(array_temp, size + 1, index);

        array_temp[index] = value;

        *out_array = array_temp;
        *out_size = size + 1;
    }

    void RemoveElement(int* array, size_t size, size_t index, int** out_array, size_t* out_size)
    {
        int* array_temp = new int[size - 1];

        ShiftLeft(array, size, index);

        for (size_t i = 0; i < size - 1; ++i)
            array_temp[i] = array[i];

        delete[] array;

        *out_array = array_temp;
        *out_size = size - 1;
    }

    void RemoveElement(float* array, size_t size, size_t index, float** out_array, size_t* out_size)
    {
        float* array_temp = new float[size - 1];

        ShiftLeft(array, size, index);

        for (size_t i = 0; i < size - 1; ++i)
            array_temp[i] = array[i];

        delete[] array;

        *out_array = array_temp;
        *out_size = size - 1;
    }

    void BubbleSort(int* array, size_t size)
    {
        for (size_t j = 1; j < size; ++j)
            for (size_t i = 0; i < size - j; ++i)
            {
                if (array[i + 1] < array[i])
                {
                    int temp = array[i + 1];
                    array[i + 1] = array[i];
                    array[i] = temp;
                }
            }
    }

    void BubbleSort(float* array, size_t size)
    {
        for (size_t j = 1; j < size; ++j)
            for (size_t i = 0; i < size - j; ++i)
            {
                if (array[i + 1] < array[i])
                {
                    float temp = array[i + 1];
                    array[i + 1] = array[i];
                    array[i] = temp;
                }
            }
    }

    void SelectionSort(int* array, size_t size)
    {
        for (size_t i = 0; i < size; ++i)
        {
            size_t min_index = i;

            for (size_t j = i + 1; j < size; ++j)
            {
                if (array[j] < array[min_index])
                    min_index = j;
            }

            if (min_index != i)
            {
                int temp = array[i];
                array[i] = array[min_index];
                array[min_index] = temp;
            }
        }
    }

    float* SelectionSort(float* array, size_t size)
    {
        for (size_t i = 0; i < size; ++i)
        {
            size_t min_index = i;

            for (size_t j = i + 1; j < size; ++j)
            {
                if (array[j] < array[min_index])
                    min_index = j;
            }

            if (min_index != i)
            {
                float temp = array[i];
                array[i] = array[min_index];
                array[min_index] = temp;
            }
        }
        return array;
    }

    void ShakerSort(int* array, size_t size)
    {
        int control = size - 1;
        int left = 0;
        int right = size - 1;
        do {
            for (int i = left; i < right; i++) {
                if (array[i] > array[i + 1])
                {
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                    control = i;
                }
            }
            right = control;
            for (int i = right; i > left; i--) {
                if (array[i] < array[i - 1])
                {
                    int temp = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = temp;
                    control = i;
                }
            }
            left = control;
        } while (left < right);
    }

    void ShakerSort(float* array, size_t size)
    {
        int control = size - 1;
        int left = 0;
        int right = size - 1;
        do {
            for (int i = left; i < right; i++) {
                if (array[i] > array[i + 1])
                {
                    float temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                    control = i;
                }
            }
            right = control;
            for (int i = right; i > left; i--) {
                if (array[i] < array[i - 1])
                {
                    float temp = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = temp;
                    control = i;
                }
            }
            left = control;
        } while (left < right);
    }

    size_t FindMaxValueIndex(int* array, size_t size)
    {
        size_t maxIndex = 0;
        for (size_t i = 0; i < size; ++i)
        {
            if (array[i] > array[maxIndex])
                maxIndex = i;
        }

        return maxIndex;
    }

    size_t FindMaxValueIndex(float* array, size_t size)
    {
        size_t maxIndex = 0;
        for (size_t i = 0; i < size; ++i)
        {
            if (array[i] > array[maxIndex])
                maxIndex = i;
        }

        return maxIndex;
    }

    size_t FindMinValueIndex(int* array, size_t size)
    {
        size_t minIndex = 0;
        for (size_t i = 0; i < size; ++i)
        {
            if (array[i] < array[minIndex])
                minIndex = i;
        }

        return minIndex;
    }

    size_t FindMinValueIndex(float* array, size_t size)
    {
        size_t minIndex = 0;
        for (size_t i = 0; i < size; ++i)
        {
            if (array[i] < array[minIndex])
                minIndex = i;
        }

        return minIndex;
    }

    size_t Find(int* array, size_t size, bool (*predicate)(int value))
    {
        for (size_t i = 0; i < size; ++i)
            if (predicate(array[i]))
                return i;

        return -1;
    }

    size_t Find(float* array, size_t size, bool (*predicate)(float value))
    {
        for (size_t i = 0; i < size; ++i)
            if (predicate(array[i]))
                return i;

        return -1;
    }

    size_t FindFromEnd(int* array, size_t size, bool (*predicate)(int value))
    {
        for (size_t i = size - 1; i >= 0; --i)
            if (predicate(array[i]))
                return i;

        return -1;
    }

    size_t FindFromEnd(float* array, size_t size, bool (*predicate)(float value))
    {
        for (size_t i = size - 1; i >= 0; --i)
            if (predicate(array[i]))
                return i;

        return -1;
    }

    size_t BinarySearch(int* array, size_t size, int value)
    {
        size_t left = 0;
        size_t right = size;
        size_t middle = 0;

        while (left <= right)
        {
            middle = (left + right) / 2;

            if (array[middle] < value)
                left = middle + 1;
            else if (array[middle] > value)
                right = middle - 1;
            else
                return middle;
        }

        return -1;
    }

    size_t BinarySearch(float* array, size_t size, float value)
    {
        size_t left = 0;
        size_t right = size;
        size_t middle = 0;

        while (left <= right)
        {
            middle = (left + right) / 2;

            if (array[middle] < value)
                left = middle + 1;
            else if (array[middle] > value)
                right = middle - 1;
            else
                return middle;
        }

        return -1;
    }

    size_t ElementValuesCount(int* array, size_t size, bool (*predicate)(int value))
    {
        size_t count = 0;
        for (size_t i = 0; i < size; ++i)
            if (predicate(array[i]))
                count++;

        return count;
    }

    size_t ElementValuesCount(float* array, size_t size, bool (*predicate)(float value))
    {
        size_t count = 0;
        for (size_t i = 0; i < size; ++i)
            if (predicate(array[i]))
                count++;

        return count;
    }

    void StdInput(int* array, size_t size)
    {
        cout << "Enter " << size << "elements" << endl;

        for (size_t i = 0; i < size; ++i)
        {
            cout << "array[" << i << "] = " << array[i];
            cin >> array[i];
        }
    }

    void StdInput(float* array, size_t size)
    {
        cout << "Enter " << size << "elements" << endl;

        for (size_t i = 0; i < size; ++i)
        {
            cout << "array[" << i << "] = " << array[i];
            cin >> array[i];
        }
    }

    void FileInput(int** out_array, size_t* out_size, const char* fileName)
    {
        ifstream file(fileName);
        string value;
        size_t size;


        file >> value;

        size = stoll(value);

        int* array = new int[size];

        for (size_t i = 0; i < size; ++i)
        {
            file >> value;
            array[i] = stoi(value);
        }

        file.close();

        *out_size = size;
        *out_array = array;
    }

    void FileInput(float** out_array, size_t* out_size, const char* fileName)
    {
        ifstream file(fileName);
        string value;
        size_t size;


        file >> value;

        size = stoll(value);

        float* array = new float[size];

        for (size_t i = 0; i < size; ++i)
        {
            file >> value;
            array[i] = stof(value);
        }

        file.close();

        *out_size = size;
        *out_array = array;
    }

    void BinaryFileInput(int** out_array, size_t* out_size, const char* fileName)
    {
        ifstream file(fileName);

        size_t size;

        file.read(reinterpret_cast<char*>(&size), sizeof(size_t));

        int* array = new int[size];

        for (size_t i = 0; i < size; ++i)
        {
            file.read(reinterpret_cast<char*>(&array[i]), sizeof(int));
        }

        file.close();

        *out_array = array;
    }

    void BinaryFileInput(float** out_array, size_t* out_size, const char* fileName)
    {
        ifstream file(fileName);

        size_t size;

        file.read(reinterpret_cast<char*>(&size), sizeof(size_t));

        float* array = new float[size];

        for (size_t i = 0; i < size; ++i)
        {
            file.read(reinterpret_cast<char*>(&array[i]), sizeof(float));
        }

        file.close();

        *out_array = array;
    }

    void StdOutput(int* array, size_t size)
    {
        for (size_t i = 0; i < size; ++i)
            cout << "array[" << i << "] = " << array[i] << endl;
    }

    void StdOutput(float* array, size_t size)
    {
        for (size_t i = 0; i < size; ++i)
            cout << "array[" << i << "] = " << array[i] << endl;
    }

    void FileOutput(int* array, size_t size, const char* fileName)
    {
        ofstream file(fileName);
        string value;

        value = to_string(size);

        file.write(value.c_str(), value.size());
        file.put('\n');

        for (size_t i = 0; i < size; ++i)
        {
            value = to_string(array[i]);
            file.write(value.c_str(), value.size());
            file.put('\n');
        }

        file.close();
    }

    void FileOutput(float* array, size_t size, const char* fileName)
    {
        ofstream file(fileName);
        string value;

        value = to_string(size);

        file.write(value.c_str(), value.size());
        file.put('\n');

        for (size_t i = 0; i < size; ++i)
        {
            value = to_string(array[i]);
            file.write(value.c_str(), value.size());
            file.put('\n');
        }

        file.close();
    }

    void BinfileOutput(int* array, size_t size, const char* fileName)
    {
        ofstream file(fileName);

        file.write(reinterpret_cast<char*>(&size), sizeof(size_t));

        for (size_t i = 0; i < size; ++i)
        {
            file.write(reinterpret_cast<char*>(&array[i]), sizeof(int));
        }

        file.close();
    }

    void BinfileOutput(float* array, size_t size, const char* fileName)
    {
        ofstream file(fileName);

        file.write(reinterpret_cast<char*>(&size), sizeof(size_t));

        for (size_t i = 0; i < size; ++i)
        {
            file.write(reinterpret_cast<char*>(&array[i]), sizeof(float));
        }

        file.close();
    }

    bool predicate_true(int value)
    {
        return true;
    }

    bool predicate_true(float value)
    {
        return true;
    }

    bool predicate_false(int value)
    {
        return false;
    }

    bool predicate_false(float value)
    {
        return false;
    }

    bool predicate_positive(int value)
    {
        return value >= 0;
    }

    bool predicate_positive(float value)
    {
        return value >= 0.f;
    }

    bool predicate_negative(int value)
    {
        return value < 0;
    }

    bool predicate_negative(float value)
    {
        return value < 0.f;
    }

    int* CopyArray(int* origin, size_t size)
    {
        int* newArray = new int[size];
        for (size_t i = 0; i < size; ++i)
        {
            newArray[i] = origin[i];
        }
        return newArray;
    }

    float* CopyArray(float* origin, size_t size)
    {
        float* newArray = new float[size];
        for (size_t i = 0; i < size; ++i)
        {
            newArray[i] = origin[i];
        }
        return newArray;
    }

}




