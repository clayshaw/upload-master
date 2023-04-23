#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>



using namespace std;

void selectSort(vector<int> &v)
{
    int i, j, min, temp;
    for (i = 0; i < v.size() - 1; i++)
    {
        min = i;
        for (j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

void quickSort(vector<int> &v, int left, int right)
{
    int i, j, temp;
    if (left > right)
    {
        return;
    }
    temp = v[left];
    i = left;
    j = right;
    while (i != j)
    {
        while (v[j] >= temp && i < j)
        {
            j--;
        }
        while (v[i] <= temp && i < j)
        {
            i++;
        }
        if (i < j)
        {
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
    }
    v[left] = v[i];
    v[i] = temp;
    quickSort(v, left, i - 1);
    quickSort(v, i + 1, right);
}

void boubleSort(vector<int> &v)
{
    int i, j, temp;
    for (i = 0; i < v.size() - 1; i++)
    {
        for (j = i; j < v.size() - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void heapSort(vector<int> &v)
{
    int i, j, temp;
    for (i = v.size() / 2 - 1; i >= 0; i--)
    {
        for (j = 2 * i + 1; j < v.size(); j = 2 * j + 1)
        {
            if (j + 1 < v.size() && v[j] < v[j + 1])
            {
                j++;
            }
            if (v[j] > v[i])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    for (i = v.size() - 1; i > 0; i--)
    {
        temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        for (j = 2 * i + 1; j < v.size(); j = 2 * j + 1)
        {
            if (j + 1 < v.size() && v[j] < v[j + 1])
            {
                j++;
            }
            if (v[j] > v[i])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

void insertSort(vector<int> &v)
{
    int i, j, temp;
    for (i = 1; i < v.size(); i++)
    {
        temp = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
    }
}

void bucketSort(vector<int> &v)
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

void countSort(vector<int> &v)
{
    int i, j, max, min, *count;
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
    count = new int[max - min + 1];
    for (i = 0; i < max - min + 1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < v.size(); i++)
    {
        count[v[i] - min]++;
    }
    for (i = 1; i < max - min + 1; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    int *temp = new int[v.size()];
    for (i = v.size() - 1; i >= 0; i--)
    {
        temp[count[v[i] - min] - 1] = v[i];
        count[v[i] - min]--;
    }
    for (i = 0; i < v.size(); i++)
    {
        v[i] = temp[i];
    }
    delete[] count;
    delete[] temp;
}

void shellSort(vector<int> &v)
{
    int i, j, temp, gap;
    for (gap = v.size() / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < v.size(); i++)
        {
            temp = v[i];
            j = i - gap;
            while (j >= 0 && v[j] > temp)
            {
                v[j + gap] = v[j];
                j -= gap;
            }
            v[j + gap] = temp;
        }
    }
}

void merge(vector<int> &v, int left, int mid, int right)
{
    int i, j, k, *temp;
    temp = new int[v.size()];
    i = left;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= right)
    {
        if (v[i] < v[j])
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
    for (i = 0; i < k; i++)
    {
        v[left + i] = temp[i];
    }
    delete[] temp;
}

void mergeSort(vector<int> &v, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct node *root, vector<int> &v, int &i)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v, i);
    v[i++] = root->data;
    inorder(root->right, v, i);
}

void radixSort(vector<int> &v)
{
    int i, j, k, max, exp;
    int *bucket;
    max = v[0];
    for (i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    bucket = new int[v.size()];
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        int *bucket = new int[v.size()];
        for (i = 0; i < v.size(); i++)
        {
            bucket[i] = 0;
        }
        for (i = 0; i < v.size(); i++)
        {
            bucket[(v[i] / exp) % 10]++;
        }
        for (i = 1; i < v.size(); i++)
        {
            bucket[i] = bucket[i] + bucket[i - 1];
        }
        int *temp = new int[v.size()];
        for (i = v.size() - 1; i >= 0; i--)
        {
            temp[bucket[(v[i] / exp) % 10] - 1] = v[i];
            bucket[(v[i] / exp) % 10]--;
        }
        for (i = 0; i < v.size(); i++)
        {
            v[i] = temp[i];
        }
        delete[] bucket;
        delete[] temp;
    }
}

//隨機生成數據
void randomData(vector<int> &v, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        v.push_back(rand() % INT32_MAX);
    }
}

//生成近乎有序的數據
void nearlyOrderData(vector<int> &v, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        int a = rand() % n;
        int b = rand() % n;
        swap(v[a], v[b]);
    }
}

//生成完全有序的數據
void orderData(vector<int> &v, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
}

int main(){
    system("chcp 65001");
    vector<int> v;
    int DATA_SIZE,DATA_TYPE,FUNCTION_TYPE;
    cout<<"請輸入數據大小和數據類型"<<endl;
    cout<<"數據大小：";    
    while(cin>>DATA_SIZE){
        cout<<"類型 :  1：隨機數據 2：近乎有序數據 3：完全有序數據"<<endl;
        cin>>DATA_TYPE;
        cout<<"排序方法 : 1：不排序 2：計數排序 3：基數排序 4：桶排序 5：堆排序 6：冒泡排序 7：選擇排序 8：插入排序 9：希爾排序 10：合併排序 11：快速排序"<<endl;
        cin>>FUNCTION_TYPE;
        if(DATA_TYPE==1){
            randomData(v,DATA_SIZE);
        }
        else if(DATA_TYPE==2){
            nearlyOrderData(v,DATA_SIZE);  
        }
        else if(DATA_TYPE==3){
            orderData(v,DATA_SIZE);
        }
        else{
            cout<<"輸入錯誤"<<endl;
            return 0;
        }
        time_t start,end;
        start = clock();
        switch(FUNCTION_TYPE){
            case 1:
                
                break;
            case 2:
                countSort(v);
                break;
            case 3:
                radixSort(v);
                break;
            case 4:
                bucketSort(v);
                break;
            case 5:
                heapSort(v);
                break;
            case 6:
                boubleSort(v);
                break;
            case 7:
                selectSort(v);
                break;
            case 8:
                insertSort(v);
                break;
            case 9:
                shellSort(v);
                break;
            case 10:
                mergeSort(v,0,v.size()-1);
                break;
            case 11:
                quickSort(v,0,v.size()-1);
                break;

            default:
                cout<<"輸入錯誤"<<endl;
                break;
        }
        end = clock();
        cout<<"執行時間："<<(double)(end-start)/CLOCKS_PER_SEC<<"秒"<<endl<<'\n';
        cout<<"請輸入數據大小和數據類型"<<endl;
        cout<<"數據大小：";   
    }
    
    return 0;
}