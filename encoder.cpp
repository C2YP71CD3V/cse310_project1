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
    string input, totalStr;


    if(sortingAlgo == "insertion"){

        int strIndex = 0;
        while(getline(cin, input)){
            char nullCh = '\0';
            int size = input.length();
            char strArray2D[size][size];
            char *(strArray)[size];
            for(int row = 0; row < size; row++){
                strIndex = row;
                for(int column = 0; column < size; column++){
                    if(strIndex == size){
                        strIndex = 0;
                    }
                    strArray2D[row][column] = input[strIndex];
                    strIndex++;
                }
                strArray2D[row][size] = nullCh;
                for(int index = 0; index < size; index++){
                    strArray[index] = strArray2D[index];
                    //cout << "index:" << index << " " << strArray[index] << endl;
                }
                //cout << "index:" << row << " " << strArray[row] << endl;
            }

        }




        // call the insertion sort algorithm with the redirected input file
    } else if(sortingAlgo == "quick"){
        // call the quicksort algorithm with the redirected input file
    } else {
        cout << "Incorrect sorting algorithm input, please use 'insertion' or 'quick'" << endl;
    }


}





