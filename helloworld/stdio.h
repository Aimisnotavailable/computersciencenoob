#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <time.h>

// Initialize character list
// Add more characters by appending to the existing list
std::string letters = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void helloworld(std::string print);
int char_pos(char c);

void helloworld(std::string print){
    std::string word = "Hello world";
    int word_counter = 0;
    int word_length = strlen(word.c_str());
    int delay = 100;
    // Seeds the pseudo random number using the current time to have a different output everytime the code compiles
    srand(time(0)); 

    for(int i = 0; i < (word_length * 100); i++){
        system("cls");
        // Sets a delay of 100 iteration before printing the right letter
        if((i % delay) == 0){
            word_counter++;
        }
        // Prints the right valued characters of the word
        for(int j = 0; j < word_counter; j++){
            std::cout<<word[j];
        }
        // Prints randomized letters for the remaining part of the word
        for(int j = word_counter; j < (word_length); j++){
            std::cout<<letters[rand()%word_length];
        }
        if (word_counter == word_length) return;
    }

    // Alternate route to also include memory storage for character position the character list
    // std::vector<int> c_pos;
    // for(int i = 0; i < word_length; i++){
    //     c_pos.push_back(char_pos(word[i]));
    // }

    // for(int i = 0; i < (word_length * 100); i++){
    //     system("cls");
    //     if((i % 100) == 0){
    //         word_counter++;
    //     }
    //     for(int j = 0; j < word_counter; j++){
    //         std::cout<<letters[c_pos[j]];
    //     }
    //     for(int j = word_counter; j < (word_length); j++){
    //         std::cout<<letters[rand()%27];
    //     }
    //     if (word_counter == word_length) return;
    // }
    
}

int char_pos(char c){
    // Perform a linear search to find and return the index of the characters in the list
    // Note: if letter has too much character, implement a binary search using ASCII values
    int i = 0;
    while(true){
        if(letters[i] == c){
            return i;
        }
        i++;
    }
}