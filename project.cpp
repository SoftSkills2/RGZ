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

//input data
void input_strings(vector<string> &vec){
    std::cout << "Please enter count of strings: ";
    int count;
    std::cin >> count;
    for(int i = 0; i < count; ++i){
        string str;
        std::cin >> str;
        vec.push_back(str);
    }
}

// this funtion receives strings, finds out to which character it is necessary to reduce the string and reduces
void reduction_to_character(vector <int> &sizere, vector <int> &scsave, vector<string> &vec, const int &i){
    cout<<"Enter n - ";
    int n;
    cin>>n;
    sizere[i]=n;
    scsave[i]=vec[i].size();
    vec[i].resize(n);
    cout<<vec[i];
    cout<<endl;
}

//this funtion add 3 points in the end of string
void add3_points(vector <string> &vec, int &in, const int &i){
    vec[i]+="...";
    in=1;
}

//this funtion add 2 points in the end of string
void add2_points(vector <string> &vec, int &in, const int &i){
    vec[i]+="..";
    in=1;
}

//this funtion add 1 points in the end of string
void add1_points(vector <string> &vec, int &in, const int &i){
    vec[i]+=".";
    in=1;
}

//this funtion reduction strings to the entered character
void reduction(vector <string> &vec){
    vector <int> sizere = {0,0,0}; // array save size before reduction
    vector <int> scsave = {0,0,0}; // array save size After reduction
    
    for(int i=0;i<vec.size();i++)
    {
      reduction_to_character(sizere, scsave, vec, i);  
    }
    ArrCompare(vec);
    for(int i=0;i<vec.size();i++)
    {
        int in=0;
        int j=scsave[i]-sizere[i];
        
        if(j>=3)
           add3_points(vec, in, i); 
        if(j>=2&&in==0)
            add2_points(vec, in, i);
        if(j>=1&&in==0)
            add1_points(vec, in, i);
            
        cout<<vec[i] << endl;
    }
}
int main()
{
    vector <string> vec; // save strings
    input_strings(vec);
    reduction(vec);
    return 0;
}
