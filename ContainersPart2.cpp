#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <bitset>

using namespace std;

int main()
{
    // // set map
    // // set
    // // given n elements, tell me the number of unique elements
    // int arr[] = {2, 5, 2, 1, 5}; // 3 unique elements -> {1. 2. 5}
    // set<int> st;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     st.insert(x); // log(n) time complexity
    // }

    // cout << st.size() << endl;

    // // st -> {1, 2, 5}
    // // erase functionality
    // st.erase(st.begin()); // log(n) time complexty // st.erase(iterator) // st -> {2, 5}

    // // time complexity is the length for delete for below
    // st.erase(st.begin(), next(st.begin(), 2)); // -> [), st.begin() is a biderectioal iterator so used next and use prev(it, n) for backward move
    // // st.erase(startIterator, endIterator)

    // st.erase(5); // st.erase(key) //delete the 5 -> {1, 2}

    // set<int> st = {1, 5, 7, 8};
    // auto it = st.find(7); // log n // it will be iterator to 7
    // auto it = st.find(9); // it = st.end();
    // st.emplace(6);        // st.insert(6) -> faster than insert
    // cout << st.size() << endl;
    // set<int> st;
    // st.insert(5); // -> {5}
    // st.insert(5); // -> {5}
    // for (auto it = st.begin(); it != st.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // for (auto it : st)
    // {
    //     cout << it << endl;
    // }

    // // delete the entire set
    // st.erase(st.begin(), st.end()); // makes sure the entire set is de
    // unordered_set<int> st;
    // st.insert(2);
    // st.insert(3);
    // st.insert(1);
    // // average time complexity is 0(1)
    // // time limit error -> switch to set
    // // but the worst case is linear in nature, 0(set size)

    // multiset<int> ms;
    // ms.insert(1);
    // ms.insert(1);
    // ms.insert(2);
    // ms.insert(2);
    // ms.insert(3); // ms.emplace(3)
    // // st -> {1, 1, 2, 2, 3}
    // ms.erase(2);                    // all the instances will be erased
    // auto it = ms.find(2);           // returns an iterator pointing to the first
    // ms.clear();                     // deleted the entire set
    // ms.erase(ms.begin(), ms.end()); // deletes the entire set
    // // log(n)  time complexity
    // for (auto it = ms.begin(); it != ms.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // for (auto it : ms)
    // {
    //     cout << it << endl;
    // }

    // ms.erase(ms.find(2));
    // ms.erase(ms.find(2), next(ms.find(2), 2));

    // ms.count(2); // finds how  many times 2 occurs

    // // key - value concept --->

    // //  Key Value
    // // raj -> 27
    // // hima -> 31
    // // sandeep -> 67
    // // tank -> 89
    // // map only stores unique keys
    // // log(n) is the time complexity of the map
    // map<string, int> mpp;
    // mpp["raj"] = 27;
    // mpp["hima"] = 31;
    // mpp["kumar"] = 31;
    // mpp["sandeep"] = 67;
    // mpp["tank"] = 89;
    // mpp["raj"] = 29; // overrided to 27, store 29

    // mpp.emplace("ranjan", 45); // faster than mpp["reanjan"] = 45

    // mpp.erase("raj");                             // mpp.erase(key)
    // mpp.erase(mpp.begin());                       // mpp.erase(iterator)
    // mpp.clear();                                  // entire map is cleaned up
    // mpp.erase(mpp.begin(), next(mpp.begin(), 2)); // cleans up a given range
    // auto it = mpp.find("raj");                    // points to where raj lies
    // auto it1 = mpp.find("simran");                // points to the end since she does not exit
    // if (mpp.empty())
    // {
    //     cout << "Yes it is empty";
    // }
    // mpp.count("raj"); // always returns 1 as it stores only 1
    // // instance of raj

    // pair<int, int> pr;
    // pr.first = 1;
    // pr.second = 10;

    // // printing map
    // for (auto it : mpp)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    // for (auto it = mpp.begin(); it != mpp.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    // // does not stores in any order
    // unordered_map<int, int> mpp;
    // unordered_map<pair<int, int>, int> mpp; // is not possible with unordered map
    // // o(1) in almost all cases
    // // o(n) in the worst case, where n is the container size

    // // Pair class
    // // Simple pair
    // pair<int, int> pr1 = {1, 2};

    // // Nested pair: ((1, 2), 2)
    // pair<pair<int, int>, int> pr2 = {{1, 2}, 2};
    // cout << pr2.first.second << endl; // Output: 2

    // // Deep nested pair: ((1, 2), (2, 4))
    // pair<pair<int, int>, pair<int, int>> pr3 = {{1, 2}, {2, 4}};
    // cout << pr3.first.first << endl;   // Output: 1
    // cout << pr3.second.second << endl; // Output: 4

    // vector<pair<int, int>> vec;
    // set<pair<int, int>> st;
    // map<pair<int, int>, int> mpp;

    // multimap<string, int> mppms;
    // mppms.emplace("raj", 2);
    // mppms.emplace("raj", 5);

    // stack --->
    stack<int> st; // LIFO: Last In First Out

    // Push elements onto the stack
    st.push(2);
    st.push(4);
    st.push(3);
    st.push(1); // Stack is now: [2, 4, 3, 1] (1 is on top)

    cout << st.top() << endl; // ❌ Not 2 — it's 1 (last pushed element)
    st.pop();                 // Removes 1
    cout << st.top() << endl; // ✅ Prints 3
    st.pop();                 // Removes 3
    cout << st.top() << endl; // ✅ Prints 4

    bool flag = st.empty(); // returns true if stack is empty, or fals
    // deleted the entire stack
    while (!st.empty())
    {
        st.pop();
    }
    cout << st.size() << endl; // number of elements in the stack

    stack<int> st1;
    cout << st1.top() << endl; // throw an error, because we access top for an empty stack, so always write top as folloeing, means after checking the stack is empty or not
    if (!st1.empty())
    {
        cout << st1.top() << endl; // throw error
    }

    // queue // fifo operation ds
    // push
    // front
    // pop
    // size
    // All above operation takes O(1) time

    // empty
    queue<int> q;
    q.push(1);
    q.push(5);
    q.push(3);
    q.push(6);

    cout << q.front();
    // prints 1
    q.pop();           // pop 1
    cout << q.front(); // prints 5

    // linear time(only delete operation takes linear time)
    while (!q.empty())
    {
        q.pop();
    }

    // priority_queue
    // push
    // size
    // top pop empty
    priority_queue<int> pq;
    pq.push(1);
    pq.push(5);
    pq.push(2);
    pq.push(6);

    cout << pq.top(); // print 6
    pq.pop();
    cout << pq.top(); // print 5

    priority_queue<pair<int, int>> pq1; // By default max priority
    pq1.push({1, 5});
    pq1.push({1, 6});
    pq1.push({1, 7});

    // If first element is  same then stores by second element

    cout << pq1.top().second; // print 7
    pq1.pop();
    cout << pq1.top().second; // print 6

    priority_queue<int> pq;
    pq.push(-1); // pq.push(-1 * el);
    pq.push(-5);
    pq.push(-2);
    pq.push(-6);
    cout << ((-1) * pq.top()) << endl; // prints 1

    // min priority queue is
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(5);
    pq.push(2);
    pq.push(6);
    cout << pq.top() << endl; // prints 1

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    pq2.push({1, 5});
    pq2.push({1, 6});
    pq2.push({1, 7});

    // If first element is  same then stores by second element

    cout << pq2.top().second; // print 5
    pq2.pop();
    cout << pq2.top().second; // print 6

    deque<int> dq; // insert and delete from both ends
    // push_front()   // O(1)
    // push_back()    // O(1)
    // pop_front()    // O(1)
    // pop_back()     // O(1)
    // begin, end, rbegin, rend // O(1)
    // size          // O(1)
    // clear         // O(n)
    // empty         // O(1)
    // at            // O(1)

    list<int> ls; // Implemented using doubly linked list
    // push_front() // O(1)
    // push_back() // O(1)
    // pop_front() // O(1)
    // pop_back() // O(1)
    // begin, end, rbegin, rend
    // size // O(1)
    // clear // O(n)
    // empty // O(1)
    // at // O(1)
    // remove -> O(1)
    ls.push_front(1);
    ls.push_front(2);
    ls.push_front(3);
    ls.remove(2); // ->O(1) operation




    // Day 3
    // Bitset --> Can store only 0 and 1

    // int -> 16 bits
    // long long -> 64 bits
    // char -> 8 bits

    int a[100];
    char b[100];

    // bitset -> 1 bit

    bitset<5> bt;       // 5 bits, initialized to 0
    cin >> bt;          // input 5 bits, like 10101
    cout << bt << endl; // prints 10101

    // all
    cout << bt.all() << endl; // returns true if all bits are 1, else false

    // any
    cout << bt.any() << endl; // returns true if at least one bit is 1, else false

    // count
    cout << bt.count() << endl; // returns the number of bits that are 1

    // flip
    bt.flip();  // flips all bits, 0 to 1 and 1 to 0
    bt.flip(2); // flips the bit at index 2

    // none
    cout << bt.none() << endl; // returns true if all bits are 0, else false

    // set
    bt.set();     // sets all bits to 1
    bt.set(2);    // sets the bit at index 2 to 1
    bt.set(2, 0); // sets the bit at index 2 to 0

    // reset
    bt.reset();  // resets all bits to 0
    bt.reset(2); // resets the bit at index 2 to 0

    //size
    cout << bt.size() << endl; // returns the size of the bitset, which is 5 in this case

    //test
    cout << bt.test(2) << endl; // returns true if the bit at index 2 is 1, else false

    // to_string
    cout << bt.to_string() << endl; // converts the bitset to a string representation




    
    //Lambda Function in C++
    auto lambdaFunction = [](int x, int key){
        return x < key; // A simple lambda function that takes two integers and returns their sum
    };

    //this is just an example of how to use a lambda function
    int x = 5;
    vector<int> vec = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    // auto lb = lower_bound(vec.begin(), vec.end(), x, lambdaFunction); // Find the first element not less than x in the array
    // or we can use a lambda function directly
    auto lb = lower_bound(vec.begin(), vec.end(), x, [](int a, int key) {
        return a < key; // A lambda function that compares two integers
    });

    
}

