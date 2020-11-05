#include <iostream>
using namespace std;
template <typename T>
size_t delete_repeats(T*& arr);

template <typename T>
unsigned get_next_duplicate(T* arr, size_t sz, unsigned pos);

template <typename T>
void remove_duplicate(T* arr, size_t& sz, unsigned pos);

template <typename T>
void recreate(T*& arr, size_t sz);

template <typename T>
void input(T* arr)
{
	auto n = _msize(arr) / sizeof *arr;
	cout << "Введите " << n << " элементов:";
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

template <typename T>
void show(T* arr) {
	auto n = _msize(arr) / sizeof * arr;
	for (unsigned i = 0; i < n; i++)
	{
		cout << arr[i] << ((i < n - 1) ? " " : "\n");
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите число элементов массива:";
	int n;
	cin >> n;
	char* a = new char[n];
	input(a);
	delete_repeats(a);
	show(a);
	delete[] a;
	system("pause");
}

template <typename T>
size_t delete_repeats(T*& arr)
{
	auto sz = _msize(arr) / sizeof *arr;
	for (size_t i = 0; i < sz - 1; i++)
	{
		auto pos = get_next_duplicate(arr, sz, i);
		if (pos != i)
		{
			remove_duplicate(arr, sz, pos);
			i--;
		}
	}
	recreate(arr, sz);
	return sz;
}

template <typename T>
unsigned get_next_duplicate(T* arr, size_t sz, unsigned pos)
{
	if (!arr || pos >= sz-1 || !sz) return pos;
	for (size_t i = pos + 1; i < sz; i++)
	{
		if (arr[pos] == arr[i]) return i;
	}
	return pos;
}

template <typename T>
void remove_duplicate(T* arr, size_t& sz, unsigned pos)
{
	if (!arr || !pos || !sz) return;
	for (size_t i = pos+1; i < sz; i++)
	{
		arr[i - 1] = arr[i];
	}
	sz--;
}

template <typename T>
void recreate(T*& arr, size_t sz)
{
	T* t = new T[sz];
	memcpy_s(t, sz * sizeof *arr, arr, sz * sizeof *arr);
	delete[] arr;
	arr = t;
}