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

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <string> vec = {"string","string1","string2"};
    vector <int> sizere = {0,0,0};
    vector <int> scsave = {0,0,0};
int n,sc;
    for(int i=0;i<vec.size();i++)
    {
    cout<<"Enetr n - "<<endl;
    cin>>n;
    sizere[i]=n;
    sc=vec[i].size();
    scsave[i]=sc;
    vec[i].resize(n);
    cout<<vec[i];
    cout<<endl;
    }
    ArrCompare(vec);
    for(int i=0;i<vec.size();i++)
    {
        int in=0;
        int j=scsave[i]-sizere[i];
    if(j>=3){
        vec[i]+="...";
        in=1;
    }
    if(j>=2&&in==0){
        vec[i]+="..";
        in=1;
    }
    if(j>=1&&in==0){
        vec[i]+='.';
        in=1;
    }
    cout<<vec[i];
     cout<<endl;
    }
    return 0;
}




