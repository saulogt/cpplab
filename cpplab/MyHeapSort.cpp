//
//  MyHeapSort.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-05.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include "MyHeapSort.hpp"

#define parent(i) (((i+1)/2)-1)
#define left(i) (((i + 1)*2) -1)
#define right(i) ((i + 1)*2)


#define COMP >


void swap(vector<int>& v, int i1, int i2){
    auto tmp = v[i1];
    v[i1] = v[i2];
    v[i2] = tmp;
}


void swapUp(vector<int>& v, int i){
    if (i > 0 && v[i] COMP v[parent(i)]){
        swap(v, i, parent(i));
        swapUp(v, parent(i));
    }
}

void swapDown(vector<int>& v, int i, int limit){
    if (i < limit){
        int ileft = left(i);
        int iRight = right(i);
        if (iRight < limit && v[iRight] COMP v[ileft] && v[iRight] COMP v[i]){
            swap(v, i, iRight);
            swapDown(v, iRight, limit);
        } else if (ileft < limit && v[ileft] COMP v[i]){
            swap(v, i, ileft);
            swapDown(v, ileft, limit);
        }
    }
}

void MyHeapSort(vector<int>& v){
    
    for (int i = 1; i < v.size(); ++i){
        if (i > 0){
            
            swapUp(v, i);
            
//            if (v[i] % 2 == 0 && v[i] COMP v[i-1]){
//                swap(v, i, i-1);
//            }
            
            
        }
    }
    
    for (int i = v.size() -1 ; i > 0 ; --i){
        swap(v, i, 0);
        swapDown(v, 0, i);
        
        
    }
    
}