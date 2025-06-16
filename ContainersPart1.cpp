// #include<bits/stdc++.h>

#include <iostream>
#include <array>
#include <vector>

using namespace std;

// int main(){
//     int val = 10;
//     double val = 10.0;

//     cout<<val<<endl; //error

//     return 0;
// }

// namespace ranjan{
//     int val = 50;
//     int getvalue(){
//         return val*10;
//     }
// }

// int main(){
//     double val = 10.0;

//     cout<<val<<endl; //10
//     cout<<ranjan::val<<endl; //50
//     cout<<ranjan::getvalue()<<endl; //500

//     return 0;
// }

// struct node
// {
//     string str;
//     int num;
//     double doub;
//     char x;

//     node(string str_, int num_, double doub_, char x_)
//     {
//         str = str_;
//         num = num_;
//         doub = doub_;
//         x = x_;
//     }
// };

// int main()
// {
//     double val = 10.0;

//     cout << val << endl; // 10

//     // create a data type where you store
//     // {string, int, double, char}
//     // {arr[], anything}

//     // wrong way of defining without constructor
//     // node raj;
//     // raj.str = "ranjan";
//     // raj.num = 10;
//     // raj.doub = 50.0;

//     node raj("ranjan", 10, 50.0, 'A'); // Correct way

    // node *raj = new node("striver", 79, 91.0, "");
    // node raj = node("striver", 79, 91.0, "");

//     return 0;
// }

// Arrays -> int arr[10];

// array<int, 3> arr; //-> {0, 0, 0}

// int main(){
//     // array<int, 3> arr; //-> {?, ?, ?}

//     // array<int, 5> arr = {1, 5, 6}; //->{1, 5, 6, 0, 0, 0}

//     // int arr[100] = {1}; //{1, 0, 0, ...}

//     // array<int, 5> arr;
//     // arr.fill(10); //{10, 10, 10, 10, 10}

//     //arr.at(index)

//     // for(int i = 0; i<5; i++){
//     //     cout<< arr.at(i)<<" "<<endl;
//     // }

//     //iterators
//     //begin()->forward iterator, end()-> forward Iterator, rbegin() -> Reverse Iterator, rend()-> Reverse Iterator

//     // end() points to right after the last element, means point to empty
//     // rend() points to left after the last element, means point to empty
//     // begin() points to the first element
//     // rbegin() points to the last element

//     array<int, 5> arr = {1,2,3,4,5};
//     for(auto it=arr.begin(); it!=arr.end(); it++){
//         cout<<*it<<" "<<endl;
//     }

//     // This is undefined behavior.
//     // arr.rbegin() returns a reverse_iterator.
//     // arr.end() returns a regular (forward) iterator.
//     // Comparing these two (reverse_iterator != iterator) is invalid.
//     // for(auto it=arr.rbegin(); it!=arr.end(); it++){
//     //     cout<<*it<<" "<<endl;
//     // }

//     for(auto it=arr.rbegin(); it>arr.rend(); it++){
//         cout<<*it<<" "<<endl;
//     }

//     for(auto it=arr.end() - 1; it>=arr.begin(); it--){
//         cout<<*it<<" "<<endl;
//     }

//     //for each loop, also valid for string
//     for(auto it: arr){
//         cout<<it<<" "<<endl;
//     }

//     string name = "Ranjan";
//     for(auto ch: name){
//         cout<<ch<<" ";
//     }
//     cout<<endl;

//     //size
//     cout<<arr.size()<<endl;

//     //front
//     cout<<arr.front()<<endl; //first element

//     //back
//     cout<<arr.back()<<endl; //last element

// }

// Important Notes
int arr[10000000]; // Globally maximum size array of 10^7 -> int, double, char
int arr[1000000];  // ocally maximum size array of 10^6-> int, double, char

bool arr[100000000]; // Globally maximum size array of 10^8-> bool
bool arr[10000000];  // Locally maximum size array of 10^7-> bool

// vector --->>
int main()
{
    //  segmentation fault if you push_back 10^7 times
    vector<int> arr;            // -> {}
    cout << arr.size() << endl; // -> print 0
    arr.push_back(0);           // {0}
    arr.push_back(2);           // {0,2}
    cout << arr.size() << endl; // -> print 2
    arr.pop_back();             // {0}
    cout << arr.size() << endl; // print 1

    arr.push_back(0); // {0,0}
    arr.push_back(2); // {0,0,2}

    arr.clear(); // --> erase all elements at once {}

    vector<int> vec1(4, 0);  // -> {0,0,0,0}
    vector<int> vec2(4, 10); // -> {10,10,10,10}

    // copy the entire vec2 into vec3
    vector<int> vec3(vec2.begin(), vec2.end()); // -> [) => '[' -> included, ')' -> excluded
    vector<int> vec3(vec2);

    vector<int> raj;
    raj.push_back(1); // we can also raj.amplace_back(1); //emplace_back is slightly faster than push_back
    raj.push_back(3);
    raj.push_back(2);
    raj.push_back(5); // -> {1, 3, 2, 5}

    vector<int> raj1(raj.begin(), raj.begin() + 2); //{1, 3}

    // lower bound, upper bound
    // swap swap(v1, v2)
    // begin(), end(), rbegin(), rend()
    // to defining 2d vectors
    vector<vector<int>> vec;

    vector<int> raj1;
    raj1.push_back(1);
    raj1.push_back(2);

    vector<int> raj2;
    raj2.push_back(10);
    raj2.push_back(20);

    vector<int> raj3;
    raj3.push_back(19);
    raj3.push_back(24);
    raj3.push_back(27);

    vec.push_back(raj1);
    vec.push_back(raj2);
    vec.push_back(raj3);

    // it is vector itself 2 19,
    for (auto vctr : vec)
    {
        for (auto it : vctr)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    for (int i = 0; i = vec.size(); i++)
    {
        for (int j = 0; j = vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    //define 20 * 30
    vector<vector<int>> vec2d(20, vector<int> (30, 0));
    vec2d.push_back(vector<int> (30, 0));
    vec2d[2].push_back(1);

    vector<int> arr2d[4];
    arr2d[1].push_back(2);

    //10*20*30 //int arr[10][20][30]
    vector<vector<vector<int>>> vec3d(10,  vector<vector<int>> (20, vector<int> (30, 0)));
}