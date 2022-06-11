#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* This function compares elements of array and if two strings are equal
   to each other - adds number 1 or two to the end of these strings.
   After that funtion returns itself using recursion, until all elements
   of array won't be unique
*/
void ArrCompare(vector<string>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        for (int j = i + 1; j < arr.size(); ++j)
            if (arr[i] == arr[j]) {
                arr[i] += '1';
                arr[j] += '2';

                return ArrCompare(arr);
            }
}

int main()
{
    vector <string> vec = { "str", "str","str"};

    ArrCompare(vec);

    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';

    return 0;
}

