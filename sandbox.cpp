#include <iostream>
using namespace std;

/*

    Welcome to the messiest part of my repo
    This is where I try everything before changing it in main/cpp_backend
    Mad respect to this file honestly

*/

template<typename T>
class MyVect{
    T* arr;
    int capacity;
    bool resizable;
    int itop;
    public:
    MyVect(int c=5, bool dynamic=true):capacity(c), resizable(dynamic),itop(-1){arr=new T[capacity];}
    ~MyVect(){delete[] arr;}

    void add(T x){
        if(itop==(capacity-1)&&resizable==false){
            cout<<"Overflow";return;
        }
        else if(itop==(capacity-1)&&resizable==true){
            resize();
        }
        ++itop;arr[itop]=x;
    }
    void remove(int i){
        if(itop==-1){cout<<"Underflow";return;}
        --itop;
        T* tempArr=new T[capacity];
        int j;
        for(j=0;j<i;j++){
            tempArr[j]=arr[j];
        }
        ++i;
        for(j=i;j<=itop;j++){
            tempArr[j]=arr[j];
        }
        delete[] arr;
        arr=tempArr;
    }
    void resize(){
        T* tempArr=new T[2*capacity];
        int j;
        for(j=0;j<capacity;j++){
            tempArr[j]=arr[j];
        }
        capacity=2*capacity;
        delete[] arr;
        arr=tempArr;
    }
    
    int size(){
    
        return itop+1;
    
    }

    void info(){
        int i;
        cout<<"\n[";
        for(i=0;i<itop;i++){
            cout<<arr[i]<<", ";
        }
        string r=(resizable==1)?"true":"false";
        cout<<arr[itop]<<"]";
        cout<<"\ncapacity: "<<capacity;
        cout<<"\nsize: "<<size();
        cout<<"\nresizable: "<<r<<endl;
    }
};




int main(){

    MyVect<int> a(5, false);
    a.add(3);
    a.add(7);
    a.add(91);
    a.info();
    a.remove(2);
    a.info();
    
}

/*template <typename Key, typename Value>
class Dict{
   
    Key k; //key arg for functions
    Key* arr_k; //array of keys
    Value v;//value arg for functions
    Value* arr_v;//array of values
    int capacity=15;//array capacity
    int i=-1;

    arr_k= new Key[capacity];
    arr_v= new Value[capacity];

    template <typename T>
    void resize(T* &arr, &capacity){
        
    }

    public:
    int x;
    void assign(k, v){

    }
    void find(k){}

};*/