// Jacob Marshall // 2876707 // EECS560 // Lab3 // 24 Sept 2018 //

#include<math.h>
#include "HashTableDH.h"
using namespace std;



template <int M>
HashTableDH<M>::HashTableDH(int kvalue, int pvalue){
    k = kvalue;
    p = pvalue;
    for(int i =0; i <M; i++){
        buckets[i] = -1;
        flags[i] = false;
    }
}

template <int M>
HashTableDH<M>::~HashTableDH(){
    delete[] buckets;
}

template <int M>
double HashTableDH<M>::getLoadFactor(){
    double loadFactor = 0.0;
    for(int i =0; i < M; i++){
        if(buckets[i] != -1){
            loadFactor = loadFactor + 1.0;
        }
    }
    loadFactor = loadFactor/M;
    return loadFactor;
}

template <int M>
void HashTableDH<M>::deleteEntry(int x){
    int index = hash(x);
    if(find(x) == false){
    }
    else{
        buckets[index] = -1;
    }

}

template <int M>
void HashTableDH<M>::printAll(){

    for(int i =0; i < M; i++){
        if(buckets[i] != -1){
            cout<<i<<": "<<buckets[i]<<"\n";
        }
    }
}


template <int M>
void HashTableDH<M>::insert(int x){
    int index = hash(x);
    if(buckets[index] == -1){
        buckets[index] = x;
        flags[index] = true;
    }
    
}


template <int M>
bool HashTableDH<M>::find(int x){
    int index = hash(x);
    if(index == -1){
        return false;
    }
    else{
        if(buckets[index] == x){
            return true;
        }
        else{
            return false;
        }
    }



}

template <int M>
int HashTableDH<M>::hash(int x){
  int hashNum = 0;
  int i = 0;
  int indexToSearch = x%M;
  int hash1 = indexToSearch;
  int hash2 = (p - (x%p));
  for(int i = 0; i < k + 1; i++){
      indexToSearch = (hash1 + i*hash2)%M;  
      if(i == k){
          indexToSearch = -1;
          break;
      }
      else if(buckets[indexToSearch] == -1){
          if(flags[indexToSearch] == false){
              break;
          }
      }
      else if(buckets[indexToSearch] == x){
          break;
      }
  }
  return indexToSearch;
}

