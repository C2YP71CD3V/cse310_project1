//
// Created by josep on 10/1/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

/*
 * partition helper method for quicksort
 * takes last element as pivot and places
 * the pivot in the correct place in sorted string
 */
int partition(string& str, int low, int high){

    char pivot = str[high];

    int smallerIndex = (low - 1);

    for(int j = low; j < high; j++){

        if(str[j] < pivot){
            smallerIndex++;
            char temp = str[smallerIndex];
            str[smallerIndex] = str[j];
            str[j] = temp;
        }
    }

    char temp2 = str[smallerIndex + 1];
    str[smallerIndex + 1] = str[high];
    str[high] = temp2;
    return (smallerIndex + 1);
}


/*
 * quicksort method used to sort the string sortedData
 */
void quicksort(string& str, int low, int high){

    if(low < high){

        int partitioned = partition(str, low, high);

        quicksort(str, low, (partitioned-1));
        quicksort(str, (partitioned+1), high);
    }
}

int main(int argc, char *argv[]) {

    // declaring and initializing variables for choosing sorting
    // method and input method
    string sortingAlgo = argv[1];
    string input;
    int origindex;

    if(sortingAlgo == "insertion"){

        while(getline(cin, input)){

            // finding the length of the input data
            int size = input.length();

            // recreating empty lines
            if(size == 0){
                cout << endl;
                continue;
            }

            // getting index of original string
            int found = input.find_first_not_of("1234567890");
            if(found == std::string::npos){
                string index = input;
                origindex = stoi(index);
                continue;
            }

            // declaring and initializing some variables used for recreating the last string
            string encodedData = input, parsedStr = "", last = "";
            bool flagForSpace = false, flagForInt = false;
            int howMany;


            // recreating the last string from encoded data
            for(int i = 0; i < size; i++){

                if(encodedData[i] != *" " && !flagForSpace){
                    parsedStr += encodedData[i];
                    if((i + 1) == size){
                        for(int l = 0; l < howMany; l++){
                            last += parsedStr;
                        }
                    }
                } else if(encodedData[i] == *" " && flagForSpace){
                    for(int k = 0; k < howMany; k++){
                        last += " ";
                    }
                    flagForSpace = false;
                } else if(encodedData[i] == *" "){

                    if((i + 1) < size){
                        if(encodedData[i + 1] == *" "){
                            flagForSpace = true;
                        }
                    }

                    try{
                        if(!flagForInt){
                            howMany = stoi(parsedStr);
                            parsedStr = "";
                            flagForInt = true;
                        } else {
                            throw exception();
                        }
                    } catch(exception e){
                        // was not an int for how many, must have been char
                        for(int j = 0; j < howMany; j++){
                            last += parsedStr;
                        }
                        parsedStr = "";
                        flagForInt = false;
                    }

                }


            }

            // initializing string with value of last to then sort it
            string sortedData = last;

            // insertion sorting the sortedData string
            for(int h = 1; h < last.length(); h++){
                for(int m = h -1; m >= 0; m--){
                    if(sortedData[m] > sortedData[m+1]){
                        char temp = sortedData[m+1];
                        sortedData[m+1] = sortedData[m];
                        sortedData[m] = temp;
                    } else{
                        break;
                    }
                }
            }

            // setting up boolean array to check which indexes have been used
            bool used[last.length()];
            // setting each index to false
            for(int i = 0; i < last.length(); i++){
                used[i] = false;
            }

            // declaring int array for which index is next
            int next[last.length()];

            // going through sortedData string index by index and
            // searching for the characters of each index in the last string
            // then taking the index of the character from last and placing inside
            // the next int array
            for(int k = 0; k < sortedData.length(); k++){
                char lookingFor = sortedData[k];
                for(int l = 0; l < last.length(); l++){
                    if(last[l] == lookingFor){
                        if(used[l] == false){
                            next[k] = l;
                            used[l] = true;
                            break;
                        }
                    }
                }
            }

            // declaring string variable for original string
            // and boolean flag to mark the start and int to keep track of place
            string originalData = "";
            bool starting = true;
            int whereAmI;

            // loop through the next array and last string to recreate the original data
            for(int n = 0; n < last.length(); n++){
                if(starting){
                    whereAmI = origindex;
                    starting = false;
                }
                int nextPlace = next[whereAmI];
                originalData += last[nextPlace];
                whereAmI = nextPlace;
            }

            // redirect original data to output
            cout << originalData;

            // checking if we are at the end of the file yet
            if(!cin.eof()){
                cout << endl;
            }

        }

    } else if(sortingAlgo == "quick"){

        while(getline(cin, input)){

            // finding the length of the input data
            int size = input.length();

            // recreating empty lines
            if(size == 0){
                cout << endl;
                continue;
            }

            // getting index of original string
            int found = input.find_first_not_of("1234567890");
            if(found == std::string::npos){
                string index = input;
                origindex = stoi(index);
                continue;
            }

            // declaring and initializing some variables used for recreating the last string
            string encodedData = input, parsedStr = "", last = "";
            bool flagForSpace = false, flagForInt = false;
            int howMany;


            // recreating the last string from encoded data
            for(int i = 0; i < size; i++){

                if(encodedData[i] != *" " && !flagForSpace){
                    parsedStr += encodedData[i];
                    if((i + 1) == size){
                        for(int l = 0; l < howMany; l++){
                            last += parsedStr;
                        }
                    }
                } else if(encodedData[i] == *" " && flagForSpace){
                    for(int k = 0; k < howMany; k++){
                        last += " ";
                    }
                    flagForSpace = false;
                } else if(encodedData[i] == *" "){

                    if((i + 1) < size){
                        if(encodedData[i + 1] == *" "){
                            flagForSpace = true;
                        }
                    }

                    try{
                        if(!flagForInt){
                            howMany = stoi(parsedStr);
                            parsedStr = "";
                            flagForInt = true;
                        } else {
                            throw exception();
                        }
                    } catch(exception e){
                        // was not an int for how many, must have been char
                        for(int j = 0; j < howMany; j++){
                            last += parsedStr;
                        }
                        parsedStr = "";
                        flagForInt = false;
                    }
                }
            }

            // initializing string with value of last to then sort it
            string sortedData = last;

            // quicksort sorting the sortedData string
            quicksort(sortedData, 0, sortedData.length() - 1);

            // setting up boolean array to check which indexes have been used
            bool used[last.length()];
            // setting each index to false
            for(int i = 0; i < last.length(); i++){
                used[i] = false;
            }

            // declaring int array for which index is next
            int next[last.length()];

            // going through sortedData string index by index and
            // searching for the characters of each index in the last string
            // then taking the index of the character from last and placing inside
            // the next int array
            for(int k = 0; k < sortedData.length(); k++){
                char lookingFor = sortedData[k];
                for(int l = 0; l < last.length(); l++){
                    if(last[l] == lookingFor){
                        if(used[l] == false){
                            next[k] = l;
                            used[l] = true;
                            break;
                        }
                    }
                }
            }

            // declaring string variable for original string
            // and boolean flag to mark the start and int to keep track of place
            string originalData = "";
            bool starting = true;
            int whereAmI;

            // loop through the next array and last string to recreate the original data
            for(int n = 0; n < last.length(); n++){
                if(starting){
                    whereAmI = origindex;
                    starting = false;
                }
                int nextPlace = next[whereAmI];
                originalData += last[nextPlace];
                whereAmI = nextPlace;
            }

            // redirect original data to output
            cout << originalData;

            // checking if we are at the end of the file yet
            if(!cin.eof()){
                cout << endl;
            }

        }

    } else {
        cout << "Incorrect sorting algorithm input, please use 'insertion' or 'quick'" << endl;
    }

    return 0;
}


