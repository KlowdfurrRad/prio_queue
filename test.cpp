#include <bits/stdc++.h>
#include "heap.h"
#include "prio_queue.hpp"
using namespace std;
using rollbear::prio_queue;

void insert_ele_cache(int n){
    prio_queue<524288,int,void> pq;
    for(int i = 0;i<n;i++)
        pq.push(i);
}

void insert_ele_heap(int n){
    heap<int> pq(n);
    for(int i = 0;i<n;i++){
        pq.insert(i);
    }
}

int main(){
    prio_queue<32768, int, void> pq;

    int n = 524288;

    auto start = std::chrono::high_resolution_clock::now();
    insert_ele_cache(n);
    auto end = std::chrono::high_resolution_clock::now();
    cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << ",";

    start = std::chrono::high_resolution_clock::now();
    insert_ele_heap(n);
    end = std::chrono::high_resolution_clock::now();
    cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << ",";
    
}