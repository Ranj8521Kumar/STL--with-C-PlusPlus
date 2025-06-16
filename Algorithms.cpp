#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Comparator function to sort in ascending order
bool  comp(int el1, int el2){
    if(el1 <= el2){
        return true;
    }

    return false;
}

//arr
//pair<int, int> arr[] = {{1, 4}, {5, 2}, {5, 9}};
//after sorting arr[] = {{1, 4}, {5, 9}, {5, 2}};
// I want to sort the array in such a way that in pair,
// smaller appears first, and if first is equal then sort
// accoring to the second and keep larger second

bool conpa(pair<int, int> el1, pair<int, int> el2){
    if(el1.first < el2.first){
        return true;
    }
    else if(el1.first == el2.first){
        if(el1.second > el2.second){
            return true;
        }
    }

    return false;
}

int main()
{
    // Algorihm

    // 1. sort
    // array, vector

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n); // sort the array in ascending order
    // sort from index 1 to 3
    sort(arr + 1, arr + 4); // sort the array from index 1 to 3 (exclusive of 4)

    // Remember to free the allocated memory
    delete[] arr;

    vector<int> vec(5, 0);        // vector of size 5 initialized with 0
    sort(vec.begin(), vec.end()); // sort the vector in ascending order//[)

    // vec -> {1, 8, 7, 9, 10}
    //  sort it so that only indexes from 1 to 3 are sorted
    //  final vec -> {1, 7, 8, 9, 10}
    sort(vec.begin() + 1, vec.begin() + 4); // sort the vector from index 1 to 3 // [1, 4) is the range to be sorted

    // 2. reverse
    reverse(arr, arr + n);                     // reverse the entire array // [0, n) is the range to be reversed
    reverse(vec.begin(), vec.end());           // reverse the entire vector // [)
    reverse(vec.begin() + 1, vec.begin() + 4); // reverse the vector from index 1 to 3 // [1, 4) is the range to be reversed
    reverse(vec.begin() + 1, vec.end());       // reverse the vector from index 1 to the end // [1, end) is the range to be reversed

    // 3. max_element
    // i to j give me maximum element

    int maxi = INT_MIN; // Initialize to the smallest possible integer
    int i;
    int j;
    cin >> i >> j; // Input the range [i, j)
    for (int k = i; k < j; k++)
    {
        maxi = max(maxi, arr[k]); // Update maxi with the maximum value found
    }

    // int maxElement = *max_element(arr, arr + n); // Using STL to find the maximum element in the entire array
    int maxElement = *max_element(arr + i, arr + j); // Using STL to find the maximum element in the range [i, j)
    int minElement = *min_element(arr + i, arr + j); // Using STL to find the minimum element in the range [i, j)

    int maxVec = *max_element(vec.begin() + 1, vec.begin() + 4); // Using STL to find the maximum element in the range [1, 4)
    int minVec = *min_element(vec.begin() + 1, vec.begin() + 4); // Using STL to find the minimum element in the range [1, 4)

    // 4. sum
    int sum = 0;
    for (int k = i; k < j; k++)
    {
        sum += arr[k]; // Calculate the sum of elements in the range [i, j)
    }

    // accumulate(startIterator, endIterator, initialValue)
    int totalSum = accumulate(arr + i, arr + j, 0);                    // Using STL to calculate the sum of elements in the range [i, j)
    int totalVecSum = accumulate(vec.begin() + 1, vec.begin() + 4, 0); // Using STL to calculate the sum of elements in the range [1, 4)
    int totalVecSum2 = accumulate(vec.begin(), vec.end(), 0);          // Using STL to calculate the sum of elements from index 0 to the end

    // 5. count
    // how many times a number appears in the range [i, j)
    // O(n) time complexity
    int cnt = 0;
    for (int k = i; k < j; k++)
    {
        if (arr[k] == 5)
        { // Change 5 to the number you want to count
            cnt++;
        }
    }

    // count(startIterator, endIterator, value)
    int countVec = count(vec.begin(), vec.end(), 5); // Using STL to count occurrences of 5 in the entire vector
    int countArr = count(arr, arr + n, 5);           // Using STL to count occurrences of 5 in the entire array

    // 6. find
    // find first occurrence of a number in the range [i, j)

    int ind = -1; // Initialize to -1 to indicate not found
    for (int k = i; k < j; k++)
    {
        if (arr[k] == 5)
        {            // Change 5 to the number you want to find
            ind = k; // Store the index of the first occurrence
            break;   // Exit the loop once found
        }
    }
    cout << ind << endl; // Print the index of the first occurrence

    // find(startIterator, endIterator, value)
    auto it = find(arr, arr + n, 5); // return an iterator to the first occurrence of 5 in the entire array
    // to find the index, I have to subtract the start iterator from the found iterator
    int idx = it - arr;  // Calculate the index of the first occurrence of 5
    cout << idx << endl; // Print the index of the first occurrence

    auto itVec = find(vec.begin(), vec.end(), 5); // return an iterator to the first occurrence of 5 in the entire vector
    int idxVec = itVec - vec.begin();             // Calculate the index of the first occurrence of 5 in the vector
    cout << idxVec << endl;                       // Print the index of the first occurrence in the vector

    // int arr[] -> {1, 5, 6, 2, 3, 5, 6}
    //  x = 4
    auto itVec2 = find(vec.begin(), vec.end(), 4); // return an iterator to the first occurrence of 4 in the vector
    if (itVec2 != vec.end())
    {                                                                       // Check if the element was found
        cout << "Element found at index: " << itVec2 - vec.begin() << endl; // Print the index of the first occurrence
    }
    else
    {
        cout << "Element not found" << endl; // Print if the element was not found
    }

    // 7. binary_search
    // Check if an element exists in a sorted array or vector
    // O(log n) time complexity
    // arr[] -> {1, 2, 3, 4, 5, 6, 7, 8, 9}
    // x  = 5
    // true if 5 exists in the array, false otherwise

    // binary_search(startIterator, endIterator, value)
    // returns true if the value is found in the range [startIterator, endIterator)

    bool found = binary_search(arr, arr + n, 5);              // Check if 5 exists in the entire array
    bool foundVec = binary_search(vec.begin(), vec.end(), 5); // Check if 5 exists in the entire vector

    // 8. lower_bound //Binary Search Implemented Inside a Lower Bound function
    // O(log n) time complexity
    // return an iterator to the first element which is not less than the given value
    // arr[] -> {1, 2, 3, 5, 5, 6, 7, 8, 9}
    // x = 5 points to the first 5 in the array
    // x= 4 points to the first element which is not less than 4, which is first 5
    // x= 10 points to the end of the array, as there is no element which is not less than 10

    auto lb = lower_bound(arr, arr + n, 5);              // Find the first element not less than 5 in the entire array
    auto lbVec = lower_bound(vec.begin(), vec.end(), 5); // Find the first element not less than 5 in the entire vector

    // To get the index of the lower bound
    int lbIndex = lb - arr; // Calculate the index of the first element not less than 5 in the array

    int lbVecIndex = lbVec - vec.begin();                          // Calculate the index of the first element not less than 5 in the vector
    cout << "Lower bound index in array: " << lbIndex << endl;     // Print the index of the lower bound in the array
    cout << "Lower bound index in vector: " << lbVecIndex << endl; // Print the index of the lower bound in the vector

    // 9. upper_bound
    // O(log n) time complexity
    // return an iterator to the first element which is just greater than the given value
    // arr[] -> {1, 2, 3, 5, 5, 6, 7, 8, 9}
    // x = 5 points to the first 6 in the array
    // x = 4 points to the first element which is just greater than 4, which is first 5
    // x = 10 points to the end of the array, as there is no element which is just greater than 10
    // x = 9 points to the end of the array, as there is no element which is just greater than 9

    auto ub = upper_bound(arr, arr + n, 5);              // Find the first element greater than 5 in the entire array
    auto ubVec = upper_bound(vec.begin(), vec.end(), 5); // Find the first element greater than 5 in the entire vector
    // To get the index of the upper bound
    int ubIndex = ub - arr;                                        // Calculate the index of the first element greater than 5 in the array
    int ubVecIndex = ubVec - vec.begin();                          // Calculate the index of the first element greater than 5 in the vector
    cout << "Upper bound index in array: " << ubIndex << endl;     // Print the index of the upper bound in the array
    cout << "Upper bound index in vector: " << ubVecIndex << endl; // Print the index of the upper bound in the vector

    // Q1. find the first index of the element where the element x lies
    // find fuction can be  used but that takes O(n) times
    //  the array is sorted

    int x;
    cin >> x; // Input the element to find
    int n;
    cin >> n; // Input the size of the array
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input the elements of the array
    }

    // there are couple of ways to do this
    // 1. using binary search
    if (binary_search(arr, arr + n, x))
    {                                                               // Check if x exists in the array
        auto it = lower_bound(arr, arr + n, x);                     // Find the first occurrence of x
        int index = it - arr;                                       // Calculate the index of the first occurrence
        cout << "First index of " << x << " is: " << index << endl; // Print the index
    }
    else
    {
        cout << "Element not found" << endl; // Print if the element was not found
    }

    // 2. using lower_bound
    int ind = lower_bound(arr, arr + n, x) - arr; // Find the first occurrence of x using lower_bound
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}
    //////////// 0  1  2  3  4  5   6   7   8   9   10
    // find x = 13 -> ind = 11, which is out of bound
    // hence arr[11] will give you runtime error
    if (ind != n && arr[ind] == x)
    {                                                             // Check if the found index is valid and the element at that index is x
        cout << "First index of " << x << " is: " << ind << endl; // Print the index
    }
    else
    {
        cout << "Element not found" << endl; // Print if the element was not found
    }

    // Q2. find me the last  occurrence of the element x in the array
    //  arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}
    //////////// 0  1  2  3  4  5   6   7   8   9   10

    // last occurrence of x = 10 , ans = 7th index
    int lastIndex = upper_bound(arr, arr + n, x) - arr; // Find the last occurrence of x using upper_bound
    lastIndex--;                                        // Decrement to get the last occurrence index
    if (arr[lastIndex] == x && lastIndex >= 0)
    {                                                                  // Check if the last occurrence index is valid and the element at that index is x
        cout << "Last index of " << x << " is: " << lastIndex << endl; // Print the index
    }
    else
    {
        cout << "Element not found" << endl; // Print if the element was not found
    }

    // Q3. tell me the number of times the x appears in the array
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}
    //////////// 0  1  2  3  4  5   6   7   8   9   10

    // x = 10, ans = 3
    // x= 7, ans = 2

    int firstIndex = lower_bound(arr, arr + n, x) - arr; // Find the first occurrence of x using lower_bound
    int lastIndex2 = upper_bound(arr, arr + n, x) - arr; // Find the last occurrence of x using upper_bound

    int count = lastIndex2 - firstIndex; // Calculate the count of x in the array

    // 10. Next Permutation, find the next lexicographical permutation of the string
    // O(n) time complexity
    // string s = "abc"
    // all permutations of s are:

    // abc
    // acb
    // bac
    // bca
    // cab
    // cba


    string s= "bca"; // Input the string for which we want to find the next permutation
    bool res = next_permutation(s.begin(), s.end()); // string automaticaly gets to the next permutation automatically, if it get to the next permutation then return true, else return false, in this case s = "bca" and return true


    string st = "cba"; // Input the string for which we want to find the next permutation
    bool res2 = next_permutation(st.begin(), st.end()); // string automaticaly gets to the next permutation automatically, if it get to the next permutation then return true, else return false, in this case st = "cba" and return false as there is no next permutation of cba, so string remains the same



    /////IMP --> //if  I give the any random string s = "bca"
    //I want to print all the  permutations
    string s2 = "bca";
    sort(s2.begin(), s2.end()); // Sort the string to start with the smallest permutation

    do{
        cout<< s2 << endl; // Print the current permutatio
    } while(next_permutation(s2.begin(), s2.end())); // Generate all permutations of the string until no more permutations are left
//time complexity is O(n! * n)

    // 11. Previous Permutation, find the previous lexicographical permutation of the string
    // O(n) time complexity
    // string s = "cba"
    // all permutations of s are:

    // cba
    // cab
    // bca
    // bac
    // acb
    // abc

    string s3 = "cba"; // Input the string for which we want to find the previous permutation
    bool res3 = prev_permutation(s3.begin(), s3.end()); // string automaticaly gets to the previous permutation automatically, if it get to the previous permutation then return true, else return false, in this case s3 = "cba" and return true

    string st2 = "abc"; // Input the string for which we want to find the previous permutation
    bool res4 = prev_permutation(st2.begin(), st2.end()); // string automaticaly gets to the previous permutation automatically, if it get to the previous permutation then return true, else return false, in this case st2 = "abc" and return false as there is no previous permutation of abc, so string remains the same

    



    // 12. Comparator
    sort(arr, arr +n ); // Sort the array in ascending order

    sort(arr, arr+n, comp);

    //greater<int> is an inbuilt comparator that sorts the array in descending order
    sort(arr, arr + n, greater<int>()); // Sort the array in descending order
    sort(arr, arr+n, greater<pair<int, int>>()); // Sort the array of pairs in descending order based on the first element of the pair
    // Sort the array of pairs in descending order based on the first element of the pair


    return 0;
}