//Elleson Tran
//Roberts
//World Scrambler 2.0
//Scrambles any phrase the user wants and how many times the user wants, also has a descrambler test
//FINAL

#include <iostream>
#include <string>
#include <ctime>

using namespace std;


//this function splits a phrase into three parts and shuffles it around once
string split(string &phrase){
  int leftNum = rand()%(phrase.length()-2) + 1;//chooses a random number between 1 and the length of the word minus two, because the two are for the other two piece
  int remaining = phrase.length() - leftNum;//how many letters are left after taking left out of the total
  int midNum = rand()%(remaining - 1) + 1;//chooses a random number between 1 and the length of the word minus the left chunk AND ONE for the right chunk
  int rightNum = phrase.length() - (leftNum + midNum);//whatever is left from the left and middle.

  string left = phrase.substr(0, leftNum);//from the start of the phrase, left size chunk
  string mid = phrase.substr(leftNum, midNum);//from the end of the left chunk, mid size chunk
  string right = phrase.substr(leftNum + midNum, rightNum);//from the end of the mid size chunk (has to add left size), right size chunk

  phrase = right + mid + left;//the actual shuffle
  return phrase;
}


int main() {
  srand(time(0));

  string tempPhrase;//keep outside of loop
  int yesOrNo;
  bool answer = true;
  int shufflePhrase;

  do{


  cout<<"How would you like to shuffle the phrase?"<<endl<<"1) Specify a number of times"<<endl<<"2) Run some trials"<<endl;
  cin>>shufflePhrase;

  if(shufflePhrase == 1){//the 1.0 part, standard shuffle
    int amountShuffle;
    cout<<"How many times would you like to shuffle the phrase? ";
    cin>>amountShuffle;

    cin.ignore();

    cout<<endl<<"Enter the phrase to shuffle: ";
    getline(cin, tempPhrase);

    string phrase;
    for(int x = 0; x < amountShuffle; x++){//shuffles for how many they want to shuffle for
      phrase = split(tempPhrase);
      cout<<"Permutation #"<<x + 1<<": "<<phrase<<endl;
   }
  }
  
  if(shufflePhrase == 2){//if they want to find out how many times to descramble a word, 2.0 part

    string abc = "abcdefghijklmnopqrstuvwxyz";

    int stringSize;
    cout<<endl<<"What size of the string to test? ";
    cin>>stringSize;

    string phrase = abc.substr(0, stringSize);//creates the test phrase from how much the user wants the length to be
    
    int trials;
    cout<<endl<<"How many trials?";
    cin>>trials;

    int totalPermutation = 0;//to keep track of the total permutations after each trial is over
    string tempPhrase = phrase;//so i can change the phrase without changing the original

    for(int x = 0; x < trials; x++){//for each trial
      int permutationNum = 1;//only to print and keep track of the permutations in ONE trial
      tempPhrase = split(tempPhrase);//permutes the phrase once so i can compare it to the original


      cout<<endl<<endl<<endl<<endl<<"*****TRIAL: "<<x + 1<<" *************"<<endl<<endl;
      cout<<"Permutation #1:"<<tempPhrase<<endl;//prints the first permutation that we are trying to convert back to the original

      while(phrase != tempPhrase){//keeps going if the tempphrase isnt back to the original
        tempPhrase = split(tempPhrase);//scrambles the phrase
        cout<<"Permutation #"<<permutationNum + 1<<": "<<tempPhrase<<endl;//prints the phrase
        permutationNum = permutationNum + 1;//adds it to the permutations of THIS ONE trial
      }
      totalPermutation = totalPermutation + permutationNum;//adds the amount of permutations of THIS ONE trial, to the total
    }
    cout<<endl<<endl<<endl<<"Average Permutations Required: "<<totalPermutation/trials;//after every trial is over, it divides the total permutation by the total amount of trials to find the average permutation required to descramble
  }


  cout<<endl<<endl<<"Again? 1=Yes, 2=No: ";
  cin>>yesOrNo;
  cin.ignore();

  if(yesOrNo == 1){//if they want to play again
    system("clear");
    answer = true;
  }
  if(yesOrNo == 2){//if they dont want to play again
    answer = false;
  }
  }while(answer != false);

  cout<<endl<<"Goodbye.";


}