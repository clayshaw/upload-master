#include <iostream>
#include <vector>


using namespace std;

class Sort
{
public:
    Sort();
    ~Sort();
    void selectSort(std::vector<int> &v);
    void quickSort(std::vector<int> &v, int left, int right);
    void boubleSort(std::vector<int> &v);
    void heapSort(std::vector<int> &v);
    void insertSort(std::vector<int> &v);
    void bucketSort(std::vector<int> &v);
    void countSort(std::vector<int> &v);
    void radixSort(std::vector<int> &v);
    void shellSort(std::vector<int> &v);
    void mergeSort(std::vector<int> &v, int left, int right);

    void randomData(std::vector<int> &v, int n);
    void nearlyOrderData(std::vector<int> &v, int n);
    void reverseData(std::vector<int> &v, int n);
    void sameData(std::vector<int> &v, int n);
    void testSort(std::vector<int> &v, int n);
private:

    void heapify(std::vector<int> &v, int n, int i);
    void merge(std::vector<int> &v, int left, int mid, int right);
    void heapAdjust(std::vector<int> &v, int s, int m);
};

Sort::Sort()
{
}

Sort::~Sort()
{
}

void Sort::selectSort(std::vector<int> &v)
{
    int minIndex = 0;
    for (int i = 0; i < v.size(); i++)
    {
        minIndex = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[minIndex])
            {
                minIndex = j;
            }
        }
        swap(v[i], v[minIndex]);
    }
}

void Sort::quickSort(std::vector<int> &v, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    int key = v[left];
    while (i < j)
    {
        while (i < j && v[j] >= key)
        {
            j--;
        }
        v[i] = v[j];
        while (i < j && v[i] <= key)
        {
            i++;
        }
        v[j] = v[i];
    }
    v[i] = key;
    quickSort(v, left, i - 1);
    quickSort(v, i + 1, right);
}

void Sort::boubleSort(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void Sort::heapify(std::vector<int> &v, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && v[l] > v[largest])
    {
        largest = l;
    }
    if (r < n && v[r] > v[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void Sort::heapSort(std::vector<int> &v)
{
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

void Sort::insertSort(std::vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
    }
}

void Sort::bucketSort(std::vector<int> &v)
{
    int i, j, k, max, min, *bucket;
    max = min = v[0];
    for (i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    bucket = new int[max - min + 1];
    for (i = 0; i < max - min + 1; i++)
    {
        bucket[i] = 0;
    }
    for (i = 0; i < v.size(); i++)
    {
        bucket[v[i] - min]++;
    }
    for (i = 0, j = 0; i < max - min + 1; i++)
    {
        for (k = bucket[i]; k > 0; k--)
        {
            v[j++] = i + min;
        }
    }
    delete[] bucket;
}

void Sort::countSort(std::vector<int> &v)
{
    int max = v[0];
    int min = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    vector<int> count(max - min + 1);
    for (int i = 0; i < v.size(); i++)
    {
        count[v[i] - min]++;
    }
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    vector<int> temp(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        temp[count[v[i] - min] - 1] = v[i];
        count[v[i] - min]--;
    }
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = temp[i];
    }
}

void Sort::radixSort(std::vector<int> &v)
{
    int max = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    int maxDigit = 0;
    while (max)
    {
        max /= 10;
        maxDigit++;
    }
    int mod = 10;
    int div = 1;
    vector<vector<int>> bucket(10);
    for (int i = 0; i < maxDigit; i++, mod *= 10, div *= 10)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int num = (v[j] % mod) / div;
            bucket[num].push_back(v[j]);
        }
        int index = 0;
        for (int j = 0; j < bucket.size(); j++)
        {
            for (int k = 0; k < bucket[j].size(); k++)
            {
                v[index++] = bucket[j][k];
            }
        }
        for (int j = 0; j < bucket.size(); j++)
        {
            bucket[j].clear();
        }
    }
}

void Sort::shellSort(std::vector<int> &v)
{
    int gap = v.size() / 2;
    while (gap > 0)
    {
        for (int i = gap; i < v.size(); i++)
        {
            int temp = v[i];
            int j = i - gap;
            while (j >= 0 && v[j] > temp)
            {
                v[j + gap] = v[j];
                j -= gap;
            }
            v[j + gap] = temp;
        }
        gap /= 2;
    }
}

void Sort::merge(std::vector<int> &v, int left, int mid, int right)
{
    vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = v[i++];
    }
    while (j <= right)
    {
        temp[k++] = v[j++];
    }
    for (int i = 0; i < temp.size(); i++)
    {
        v[left + i] = temp[i];
    }
}

void Sort::mergeSort(std::vector<int> &v, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
}

void Sort::heapAdjust(std::vector<int> &v, int i, int len)
{
    int temp = v[i];
    for (int k = 2 * i + 1; k < len; k = 2 * k + 1)
    {
        if (k + 1 < len && v[k] < v[k + 1])
        {
            k++;
        }
        if (v[k] > temp)
        {
            v[i] = v[k];
            i = k;
        }
        else
        {
            break;
        }
    }
    v[i] = temp;
}