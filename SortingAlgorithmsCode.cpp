#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void print(vector<int> v)
{   for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << '\n';
}

void random(int n, int maxx, vector<int> & v)
{   srand((unsigned)time(0)); // folosim srand cu timpul curent pentru a ne asigura ca de fiecare data
    //cand se apeleaza functia se vor genera numere diferite
    int randomnumber;
    for(int i = 0; i < n; i++)
    {   randomnumber = rand()*rand()% maxx;
        v.push_back(randomnumber + 1);
    }
}

bool test(vector<int> & v, int n)
{   for(int i = 1; i <= n-1; i++)
        if(v[i] < v[i-1])
            return false;
    return true;
}

void shift_down(vector<int>& heap,int i, int max)
{   int i_big, c1, c2;
    while(i < max)
    {   i_big = i;
        c1 = (2*i) + 1;
        c2 = c1 + 1;
        if( c1<max && heap[c1]>heap[i_big] )
            i_big = c1;
        if( c2<max && heap[c2]>heap[i_big] )
            i_big = c2;
        if(i_big == i) return;
        swap(heap[i],heap[i_big]);
        i = i_big;
    }
}

void to_heap(vector<int>& arr)
{   int i = (arr.size()/2) - 1;
    while(i >= 0)
    {   shift_down(arr, i, arr.size());
        --i;
    }
}

void heap_sort(vector<int>& arr)
{   to_heap(arr);
    int end = arr.size() - 1;
    while (end > 0)
    {   swap(arr[0], arr[end]);
        shift_down(arr, 0, end);
        --end;
    }
}

void _merge(vector<int>& arr, int s, int m, int e)
{   vector<int> temp;
	int i, j;
	i = s;
	j = m + 1;
	while (i <= m && j <= e)
    {   if (arr[i] <= arr[j])
        {   temp.push_back(arr[i]);
			++i;
		}
		else
		{   temp.push_back(arr[j]);
			++j;
		}
	}
	while (i <= m)
	{   temp.push_back(arr[i]);
		++i;
	}
	while (j <= e)
	{   temp.push_back(arr[j]);
		++j;
	}
	for (int i = s; i <= e; ++i)
		arr[i] = temp[i - s];
}

void MergeSort(vector<int>& arr, int s, int e)
{   if (s < e)
    {   int m = (s + e) / 2;
		MergeSort(arr, s, m);
		MergeSort(arr, m + 1, e);
		_merge(arr, s, m, e);
    }
}

int getMax(vector<int> &arr, int size)
{   int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void CountingSort(vector<int> &arr, int size, int div)
{   vector<int> output(size -1);
    vector<int> count(10, 0);
    for (int i = 0; i < size; i++)
        count[ (arr[i]/div)%10 ]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {   output[count[ (arr[i]/div)%10 ] - 1] = arr[i];
        count[ (arr[i]/div)%10 ]--;
    }
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}
void lsd_radix_sort(vector<int> &arr, int size)
{   int m = getMax(arr, size);
    for (int div = 1; m/div > 0; div *= 10)
        CountingSort(arr, size, div);
}

void radixsort_256(vector <int> &arr)
{   vector <int> output(arr.size());
    vector <int> count(256);
    for(int b = 0; b <= 31; b += 8)
    {   for(auto x : arr)
            count[(x >> b) & 255]++;
        for(int i = 1; i <= 255; i++)
            count[i] += count[i - 1];
        for(int i = arr.size() - 1; i >= 0; i--)
            output[--count[(arr[i] >> b) & 255]] = arr[i];
        arr = output;
        fill(count.begin(), count.end(), 0);
    }
}

void radixsort_1024(vector <int> &arr)
{   vector <int> output(arr.size());
    vector <int> count(1024);
    for(int b = 0; b <= 31; b += 10)
    {   for(auto x : arr)
            count[(x >> b) & 1023]++;
        for(int i = 1; i <= 1023; i++)
            count[i] += count[i - 1];
        for(int i = arr.size() - 1; i >= 0; i--)
            output[--count[(arr[i] >> b) & 1023]] = arr[i];
        arr = output;
        fill(count.begin(), count.end(), 0);
    }
}

void radixsort_65536(vector <int> &arr)
{   vector <int> output(arr.size());
    vector <int> count(65536);
    for(int b = 0; b <= 31; b += 16)
    {   for(auto x : arr)
            count[(x >> b) & 65535]++;
        for(int i = 1; i <= 65535; i++)
            count[i] += count[i - 1];
        for(int i = arr.size() - 1; i >= 0; i--)
            output[--count[(arr[i] >> b) & 65535]] = arr[i];
        arr = output;
        fill(count.begin(), count.end(), 0);
    }
}

void ShellSort(vector<int> &arr)
{   for (int gapSize = arr.size() / 2; gapSize > 0; gapSize /= 2)
    {   for (int currentIndex = gapSize; currentIndex < arr.size(); currentIndex++)
        {   int currentIndexCopy = currentIndex;
            int item = arr[currentIndex];
            while (currentIndexCopy >= gapSize && arr[currentIndexCopy - gapSize] > item)
            {   arr[currentIndexCopy] = arr[currentIndexCopy - gapSize];
                currentIndexCopy -= gapSize;
            }
            arr[currentIndexCopy] = item;
        }
    }
}

void ShellSort_Ciura(vector<int> &arr)
{   int c[16] = {510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701, 301, 132, 57, 23, 10, 4, 1};
    for(int x = 0; x < 16; ++x)
    {   int gapSize = c[x];
        for (int currentIndex = gapSize; currentIndex < arr.size(); currentIndex++)
        {   int currentIndexCopy = currentIndex;
            int item = arr[currentIndex];
            while (currentIndexCopy >= gapSize && arr[currentIndexCopy - gapSize] > item)
            {   arr[currentIndexCopy] = arr[currentIndexCopy - gapSize];
                currentIndexCopy -= gapSize;
            }
            arr[currentIndexCopy] = item;
        }
    }
}

void ShellSort_Hibbard(vector<int> &arr)
{   int h_size = floor(log(arr.size()+1)/log(2));
    int h_inc[h_size];
    for(int i=0; i < h_size; i++)
        h_inc[i] = pow(2, i+1) - 1;
    for (int r = (h_size - 1); r >= 0; r--)
    {   int gap = h_inc[r];
        for(int i = gap; i < arr.size(); i++)
        {   int tmp = arr[i], j;
            for(j = i; j >= gap && tmp < arr[j-gap]; j-=gap)
                arr[j] = arr[j-gap];
            arr[j] = tmp;
        }
    }
}
void ShellSort_Tokuda(vector<int> &arr)
{   double a = (double)9/4;
    int vec[25],vec_size = 0;
    int form = ceil((9*pow(9/4,0) - 4) / 5);
    while(form < 1000000001)
    {   vec[vec_size] = form;
        vec_size++;
        form = ceil((9*pow(9/4,vec_size) - 4) / 5);
    }
    for(int i=vec_size-1;i>=0;i--)
    {   int gapSize = vec[i];
        for (int currentIndex = gapSize; currentIndex < arr.size(); currentIndex++)
        {   int currentIndexCopy = currentIndex;
            int item = arr[currentIndex];
            while (currentIndexCopy >= gapSize && arr[currentIndexCopy - gapSize] > item)
            {   arr[currentIndexCopy] = arr[currentIndexCopy - gapSize];
                currentIndexCopy -= gapSize;
            }
            arr[currentIndexCopy] = item;
        }
    }
}

void ShellSort_Sedgewick(vector<int> &arr)
{   int vec[26],vec_size = 0;
    int form = 1;
    while(form < 1000000001)
    {   vec[vec_size] = form;
        vec_size++;
        form = pow(4,vec_size) + 3 * pow(2,vec_size - 1) + 1;
    }
    for(int i=vec_size-1;i>=0;i--)
    {   int gapSize = vec[i];
        for (int currentIndex = gapSize; currentIndex < arr.size(); currentIndex++)
        {   int currentIndexCopy = currentIndex;
            int item = arr[currentIndex];
            while (currentIndexCopy >= gapSize && arr[currentIndexCopy - gapSize] > item)
            {   arr[currentIndexCopy] = arr[currentIndexCopy - gapSize];
                currentIndexCopy -= gapSize;
            }
            arr[currentIndexCopy] = item;
        }
    }
}

void BubbleSort(vector<int> &arr)
{   int n = arr.size();
    while (n > 0)
    {   int lastModifiedIndex = 0;
        for (int currentIndex = 1; currentIndex < n; currentIndex++)
        {   if (arr[currentIndex - 1] > arr[currentIndex])
            {   int temp = arr[currentIndex - 1];
                arr[currentIndex - 1] = arr[currentIndex];
                arr[currentIndex] = temp;
                lastModifiedIndex = currentIndex;
            }
        }
        n = lastModifiedIndex;
    }
}

int main() {
    ifstream f("input.txt");
    ofstream g("output.txt");
    int N,n,maxx,i,j;
    vector <int> v, vec;
    f >> N;
    for(i = 0; i < N; i++)
    {   f >> n >> maxx;
        cout << "TEST " << i + 1 << " :n = " << n << " maxx = " << maxx << '\n';
        g << "TEST " << i + 1 << " :n = " << n << " maxx = " << maxx << '\n';
        random(n, maxx, v);
        if (n > 100000000)
            cout << "Sortarea din STL: Nu exista suficienta memorie pentru a aloca vectorul";
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start = high_resolution_clock::now();
            sort(vec.begin(), vec.end());
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            if (test(vec, n) == true)
            {   cout << "Sortarea din STL: CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g<< "Sortarea din STL: CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "Sortare din STL nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"HeapSort: Nu exista suficienta memorie pentru a aloca vectorul"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            heap_sort(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "HeapSort: CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "HeapSort: CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "HeapSort nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"MergeSort: Nu exista suficienta memorie pentru a aloca vectorul"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            MergeSort(vec, 0, n - 1);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "MergeSort: CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "MergeSort: CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "MergeSort nu a sortat bine" << '\n';
        }
       if(n > 100000000)
            cout<<"RadixSort LSD (baza 10): Nu exista suficienta memorie pentru a aloca vectorul/va da stack overflow"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            lsd_radix_sort(vec,n);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "RadixSort LSD (baza 10): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "RadixSort LSD (baza 10): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "RadixSort LSD (baza 10) nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"RadixSort LSD (baza 256): Nu exista suficienta memorie pentru a aloca vectorul/va da stack overflow"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            radixsort_256(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "RadixSort LSD (baza 256): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "RadixSort LSD (baza 256): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "RadixSort LSD (baza 256) nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"RadixSort LSD (baza 1024): Nu exista suficienta memorie pentru a aloca vectorul/va da stack overflow"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            radixsort_1024(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "RadixSort LSD (baza 1024): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "RadixSort LSD (baza 1024): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "RadixSort LSD (baza 1024) nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"RadixSort LSD (baza 2^16): Nu exista suficienta memorie pentru a aloca vectorul/va da stack overflow"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            radixsort_1024(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "RadixSort LSD (baza 2^16): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "RadixSort LSD (baza 2^16): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "RadixSort LSD (baza 2^16) nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"ShellSort (Donald Shell): Nu exista suficienta memorie pentru a aloca vectorul"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            ShellSort(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "ShellSort (Donald Shell): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "ShellSort (Donald Shell): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "ShellSort (Donald Shell) nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"ShellSort (Marcin Ciura): Nu exista suficienta memorie pentru a aloca vectorul"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            ShellSort_Ciura(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "ShellSort (Marcin Ciura): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "ShellSort (Marcin Ciura): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "ShellSort (Marcin Ciura) nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"ShellSort (Hibbard): Nu exista suficienta memorie pentru a aloca vectorul"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            ShellSort_Hibbard(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "ShellSort (Hibbard): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "ShellSort (Hibbard): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "ShellSort (Hibbard) nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"ShellSort (Tokuda): Nu exista suficienta memorie pentru a aloca vectorul"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            ShellSort_Tokuda(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "ShellSort (Tokuda): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "ShellSort (Tokuda): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "ShellSort (Tokuda) nu a sortat bine" << '\n';
        }
        if(n > 100000000)
            cout<<"ShellSort (Sedgewick - 1982): Nu exista suficienta memorie pentru a aloca vectorul"<<'\n';
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            ShellSort_Sedgewick(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "ShellSort (Sedgewick - 1982): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "ShellSort (Sedgewick - 1982): CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "ShellSort (Sedgewick - 1982) nu a sortat bine" << '\n';
        }
        if(n >100000)
        {   cout<<"BubbleSort: Nu exista suficienta memorie pentru a aloca vectorul"<<'\n'
            <<"De fapt dureaza ani sa faca sortarea"<<'\n';
            g << "BubbleSort: Nu exista suficienta memorie pentru a aloca vectorul"<<'\n'
            <<"De fapt dureaza ani sa faca sortarea"<<'\n';
        }
        else
        {   vec.clear();
            for (int j = 0; j < n; j++)
                vec.push_back(v[j]);
            auto start1 = high_resolution_clock::now();
            BubbleSort(vec);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            if (test(vec, n) == true)
            {   cout << "BubbleSort: CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
                g << "BubbleSort: CORECT- Timpul de rulare: " << setprecision(9) << showpoint
                << fixed << duration1.count() / 1000000.00000000000000
                     << " secunde" << '\n';
            }
            else
                cout << "BubbleSort nu a sortat bine" << '\n';
        }
        vec.clear();
        v.clear();
        cout << '\n';
        g << '\n';
    }
    g.close();
    return 0;
}
