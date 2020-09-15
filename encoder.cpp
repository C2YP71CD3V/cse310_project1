/*
 * Name: Joseph Feruglio
 * Class: CSE310
 * Assignment: Project-1-Milestone
 */
/*
 * This project milestone takes a .txt file using redirection and compresses
 * and encodes the data and outputs using redirection
 * Currently only implements the insertion sorting method
 */
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

        // Getting data input from cin redirection
        while(getline(cin, input)){

            // Size used to determine size of arrays
            int size = input.length();

            // Checks if its a blank line
            if(size == 0){
                cout << endl;
                continue;
            }

            // Declaring my arrays, one is a pointer
            string strArray1D[size];
            string* strPtrArray = strArray1D;

            // setting up the 1d array with the input data
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

            // saving the original string
            string originalStr = strPtrArray[0];

            //insertion sort on pointer array
            for(int index = 1; index < size; index++){
                for(int m = index -1; m >= 0; m--){
                    if(strPtrArray[m].compare(strPtrArray[m + 1]) > 0) {
                        string temp = strPtrArray[m + 1];
                        strPtrArray[m + 1] = strPtrArray[m];
                        strPtrArray[m] = temp;
                    } else {
                        break;
                    }
                }
            }

            // finding index of original string
            int originalStrIndex = 0;
            for(int k = 0; k < size; k++){
                if(strPtrArray[k] == originalStr){
                    originalStrIndex = k;
                    break;
                }
            }

            // gathering last letter of each sorted string to form 'last'
            string last;
            for(int l = 0; l < size; l++){
                last.append(strPtrArray[l].substr(size - 1));
            }

            // compressing 'last' into an encoded cluster
            string eachLetter = "";
            int howMany = 0;
            cout << originalStrIndex << endl;
            for(int h = 0; h < last.length(); h++){
                if(eachLetter == ""){
                    eachLetter = last[h];
                    howMany++;
                    if(h == last.length() - 1){
                        cout << howMany << " " << eachLetter;
                    }
                } else if(eachLetter[0] == last[h]){
                    howMany++;
                    if(h == last.length() - 1){
                        cout << howMany << " " << eachLetter;
                    }
                } else if(eachLetter[0] != last[h]){
                    cout << howMany << " " << eachLetter << " ";
                    eachLetter = "";
                    howMany = 1;
                    eachLetter += last[h];
                    if(h == last.length() - 1){
                        cout << howMany << " " << eachLetter;
                    }
                }
            }
            // Checking if we are at end of the file yet
            if(!cin.eof()){
                cout << endl;
            }

        }




        // call the insertion sort algorithm with the redirected input file
    } else if(sortingAlgo == "quick"){
        // call the quicksort algorithm with the redirected input file
    } else {
        cout << "Incorrect sorting algorithm input, please use 'insertion' or 'quick'" << endl;
    }

    return 0;
}





