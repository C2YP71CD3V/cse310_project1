//
// Created by josep on 10/1/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    string input;

    while(getline( cin, input)){
        int size = input.size(), clusters = 0;

        if(input.size() > 2){
            for(int i = 0; i < size; i++){

                if(input[i] == *" "){
                    i = i+3;
                    clusters++;

                }
            }
            cout << clusters << endl;
        }
    }


    return 0;
}


