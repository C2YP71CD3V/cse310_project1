/*
 * Name: Joseph Feruglio
 * Class: CSE310
 * Assignment: Project-1
 */
/*
 * This program takes a .txt file using redirection and compresses
 * and encodes the data and outputs using redirection
 * There are two sorting algorithms used in this encoding: insertion and quicksort
 * Command line arguments are required to choose a sorting method
 */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>


using namespace std;

/*
 * partition helper method for quicksort
 * takes last element as pivot and places
 * the pivot in the correct place in sorted array
 */
int partition(string* arr, int low, int high){

    string pivot = arr[high];

    int indexOfSmaller = (low-1);

    for(int j = low; j < high; j++ ){

        if(arr[j].compare(pivot) < 0){
            indexOfSmaller++;
            string temp = arr[indexOfSmaller];
            arr[indexOfSmaller] = arr[j];
            arr[j] = temp;
        }
    }

    string temp2 = arr[indexOfSmaller + 1];
    arr[indexOfSmaller + 1] = arr[high];
    arr[high] = temp2;
    return (indexOfSmaller + 1);
}
/*
 * quicksort method used to sort pointer array
 */
void quicksort(string* arr, int low, int high){

    if(low < high){

        int partitioned = partition(arr, low, high);

        quicksort(arr, low, (partitioned - 1));
        quicksort(arr, (partitioned + 1), high);

    }
}



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

    } else if(sortingAlgo == "quick"){

        // Getting data input from cin redirection
        while(getline(cin, input)) {

            // Size used to determine size of arrays
            int size = input.length();

            // Checks if its a blank line
            if (size == 0) {
                cout << endl;
                continue;
            }

            // Declaring my arrays, one is a pointer
            string strArray1D[size];
            string *strPtrArray = strArray1D;

            // setting up the 1d array with the input data
            int inputIndex = 0;
            for (int i = 0; i < size; i++) {
                inputIndex = i;
                for (int j = 0; j < size; j++) {
                    if (inputIndex == size) {
                        inputIndex = 0;
                    }
                    strArray1D[i] += input[inputIndex];
                    inputIndex++;
                }
            }

            // setting up the pointer array
            for (int j = 0; j < size; j++) {
                strPtrArray[j] = strArray1D[j];
            }

            // saving the original string
            string originalStr = strPtrArray[0];

            //quick sort on pointer array
            quicksort(strPtrArray, 0, strPtrArray->length() - 1);

            // finding index of original string
            int originalStrIndex = 0;
            for (int k = 0; k < size; k++) {
                if (strPtrArray[k] == originalStr) {
                    originalStrIndex = k;
                    break;
                }
            }

            // gathering last letter of each sorted string to form 'last'
            string last;
            for (int l = 0; l < size; l++) {
                last.append(strPtrArray[l].substr(size - 1));
            }

            // compressing 'last' into an encoded cluster
            string eachLetter = "";
            int howMany = 0;
            cout << originalStrIndex << endl;
            for (int h = 0; h < last.length(); h++) {
                if (eachLetter == "") {
                    eachLetter = last[h];
                    howMany++;
                    if (h == last.length() - 1) {
                        cout << howMany << " " << eachLetter;
                    }
                } else if (eachLetter[0] == last[h]) {
                    howMany++;
                    if (h == last.length() - 1) {
                        cout << howMany << " " << eachLetter;
                    }
                } else if (eachLetter[0] != last[h]) {
                    cout << howMany << " " << eachLetter << " ";
                    eachLetter = "";
                    howMany = 1;
                    eachLetter += last[h];
                    if (h == last.length() - 1) {
                        cout << howMany << " " << eachLetter;
                    }
                }
            }
            // Checking if we are at end of the file yet
            if (!cin.eof()) {
                cout << endl;
            }

        }

        } else {
        cout << "Incorrect sorting algorithm input, please use 'insertion' or 'quick'" << endl;
    }

    return 0;
}





