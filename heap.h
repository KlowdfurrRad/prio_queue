#include<iostream>
using namespace std;

template<typename T>
class heap{
    public:
    T* base;
    int size;
    public:

    heap(int n){
        base = new T[n];
        size = 0;
    }

    bool empty(){
        return size == 0;
    }

    void insert(T x){
        size++;
        base[size] = x;
        int cur = size;
        cur >>=1;
        //cout<<cur<<endl;

        if(cur == 0)return;
        
        //first time it may be that the right side child is not there . i.e is more than max 

        if(2*cur + 1 > size){
            if(base[cur] > base[2*cur]){
                swap(base[cur],base[2*cur]);
            }
        }else{
            if(base[2*cur] > base[2*cur+1]){    //if the right one is less
                if(base[cur] > base[2*cur + 1]){
                    swap(base[cur] , base[2*cur+1]);
                }
            }else{  //if the left one is less
                if(base[cur] > base[2*cur]){
                    swap(base[cur] , base[2*cur]);
                }
            }
        }

        cur >>=1;

        while(cur > 0){

            if(base[2*cur] > base[2*cur+1]){    //if the right one is less
                if(base[cur] > base[2*cur + 1]){
                    swap(base[cur] , base[2*cur+1]);
                }
            }else{  //if the left one is less
                if(base[cur] > base[2*cur]){
                    swap(base[cur] , base[2*cur]);
                }
            }

            cur >>=1;
        }

    }

    void delete_min(){
        //cout<<base[1]<<endl;
        swap(base[1],base[size]);
        size--;

        int cur = 1;
        while(cur < size){
            if(2*cur > size)break;
            else if(2*cur + 1 > size){
                if(base[cur] > base[2*cur]){
                    swap(base[cur],base[2*cur]);
                    cur <<=1;
                    cur++;
                }else break;
            }else{
                if(base[2*cur] > base[2*cur+1]){    //if the right one is less
                    if(base[cur] > base[2*cur + 1]){
                        swap(base[cur] , base[2*cur+1]);
                        cur <<=1;
                        cur++;
                    }else break;
                }else{  //if the left one is less
                    if(base[cur] > base[2*cur]){
                        swap(base[cur] , base[2*cur]);
                        cur <<=1;
                    }else break;
                }
            }
        }
    }

    T top(){
        if(size == 0){
            T garbage;
            return garbage;
        }
        return base[1];
    }

    void print(){
        for(int i = 1;i<=size;i++){
            cout<<base[i]<<" ";
        }
    }
};
