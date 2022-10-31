//
// Created by Sumit Suman on 05/09/22.
//

#include<iostream>
using namespace std;

int main(){
    int AT[100], BT[100], i, WT[100], j;
    int np = 100;
    cout << "Enter Arrival Time and Burst Time: " << endl;
    for(i = 0; i < np; i++){
        cin >> AT[i] >> BT[i];
    }
    WT[0] = 0;
    for(i = 1; i < np; i++){
        WT[i] = 0;
        for(j = 0; j < i; j++){
            WT[i] += BT[j];
        }
    }
    int avWT = 0, avTAT =0;

    cout << "Turn Around Time:" << endl;
    for(i = 0; i < np; i++){
        TAT[i] = BT[i] + WT[i];
        avWT += WT[i];
        avTAT += TAT[i];


    }

    avWT /= i;
    avTAT /= i;

    cout << "Average Waiting Time:" << avWT;
    cout << "Average Turn Around Time:" << avTAT;


    return 0;

}