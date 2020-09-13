//
// Created by josep on 9/9/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>


using namespace std;

int main(int argc, char *argv[]) {

    string sortingAlgo = argv[1];
    string input;


    if(sortingAlgo == "insertion"){

        int strIndex = 0;
        while(getline(cin, input)){
            int size = input.length();
            string strArray1D[size];
            string* strPtrArray = strArray1D;
            //string originalStr = "";

            // setting up the 1d array
            int inputIndex = 0;
            for(int i = 0; i < size; i++){
                inputIndex = i;
                for(int j = 0; j < size; j++){
                    if(inputIndex == size){
                        inputIndex = 0;
                    }
                    strArray1D[i] += input[inputIndex];
                    inputIndex++;
                }
            }

            // setting up the pointer array
            for(int j = 0; j < size;j++){
                strPtrArray[j] = strArray1D[j];
            }

            string originalStr = strPtrArray[0];

            //insertion sort on pointer array
            for(int index = 1; index < size; index++){
                for(int m = index -1; m >= 0; m--){
                    if(strPtrArray[m].compare(strPtrArray[m + 1]) > 0) {
                        string temp = strPtrArray[m + 1];
                        strPtrArray[m + 1] = strPtrArray[m];
                        strPtrArray[m] = temp;
                    }
                }
            }

            for(int k = 0; k < size; k++){
                cout << "index:" << k << " " << strPtrArray[k] << endl;
            }

            // insertion sort

           /* while( n < size - 1){
                for(int i = n; i > 0; i--){

                    for(int j = i -1; j >= 0; j--){

                        if(strArray[j] > strArray[i]){
                            char* temp = strArray[j];
                            strArray[j] = strArray[i];
                            strArray[i] = temp;
                        } else {
                            i = 0;
                            break;
                        }
                    }
                }
                n++;
            } */


        }




        // call the insertion sort algorithm with the redirected input file
    } else if(sortingAlgo == "quick"){
        // call the quicksort algorithm with the redirected input file
    } else {
        cout << "Incorrect sorting algorithm input, please use 'insertion' or 'quick'" << endl;
    }


}





