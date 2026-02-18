#include <iostream>
using namespace std;

/*

    Welcome to the messiest part of my repo
    This is where I try everything before changing it in main/cpp_backend
    Mad respect to this file honestly

*/

template<typename T>
class DynArr{
    T* arr; //array of dynamic type and size
    int capacity;//initial capacity
    bool resizable;//boolean to control resizability
    int itop;//top index

    public:
    DynArr(int c=5, bool dynamic=true):capacity(c), resizable(dynamic),itop(-1){arr=new T[capacity];}
    ~DynArr(){delete[] arr;}

    void add(T x)//since I'll only need to add to the top of the list I've skipped index-specific adding
    {
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
        T* tempArr=new T[capacity];//be super careful of capacity, it can break the destructor.
        int j;
        for(j=0;j<i;j++){
            tempArr[j]=arr[j];
        }
        ++i;
        for(j=i;j<=itop;j++){
            tempArr[j]=arr[j];
        }

        /*
        arr=tempArr;
        delete[] tempArr;

        ^This'll cause arr to point to an empty memory location, don't do this.
        */

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

        /*
        arr=tempArr;
        delete[] tempArr;

        ^This'll cause arr to point to an empty memory location, don't do this.
        */

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
    int find(T f){
        int i;
        for(i=0;i<=itop;i++){
            if(i!=(itop+1)&&arr[i]==f){return i;}
            }
        return -1;   
    }
};

template<typename K, typename V>
class Dictionary{
    int dict_cap;
    bool resize;
    DynArr<K> keys;
    DynArr<V> values;

    public:

    Dictionary(int capacity=16, bool resize=true):dict_cap(capacity),resize(resize), keys(dict_cap,resize), values(dict_cap, resize){}

    void dict_add(K key, V value){
        if(keys.find(key)==-1)
        {
            keys.add(key);
            values.add(value);
        }               
    }
    void dict_remove(int i){
        if(i<keys.size()){
            keys.remove(i);
            values.remove(i);
        }
    }
    void dict_remove_key(K k){
        int i=keys.find(k);
        if(i!=-1){dict_remove(i);}
        
    }

    V give_value(K k){
       return values[keys.find(k)];
    }


};


int main(){

    int i;
    for(i=0;i<=5;++i){
        cout<<i<<"\n";
    }
    cout<<i<<"\n";
    
}