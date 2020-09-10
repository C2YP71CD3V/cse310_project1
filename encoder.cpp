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

    getline(cin, input);
    cout << input << endl;

    if(sortingAlgo == "insertion"){
        cout << "insertion" << endl;
        // call the insertion sort algorithm with the redirected input file
    } else if(sortingAlgo == "quick"){
        cout << "quicksort" << endl;
        // call the quicksort algorithm with the redirected input file
    } else {
        cout << "Incorrect sorting algorithm input, please use 'insertion' or 'quick'" << endl;
    }


}