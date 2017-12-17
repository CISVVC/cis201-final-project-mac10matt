/* File: main.finalcpp
  Description: This program will take in data from a given file remove all punction and search for a word
  and count how many times a word is within the file.
  Programmed by: Matthew Misenheimer
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Concordance {
  public:
    void createArray();
    void wordSearch();
    //Concordance();
  
  private:
    int linenumber = 1;
    std::string word, line;
    std::vector<int> sourceSentences;
    int SentenceEnd = 0;
    std::ifstream myFile;
  
  
};

//this function will create an array that removes punctuation and make all charaters lowercase
void Concordance::createArray() {
  std::ifstream myFile;  //creates an input file named "myFile"

  myFile.open("finalcppalice.txt"); //opens the text file given
  
  int index = 0;
  if(myFile.is_open())
  {
    while (!myFile.eof()) 
    {
      myFile >> line;       //places the file in a string called line
      //the for loop will create an array 
      for (size_t j=0; j < line.length(); ++j)
      {
        //makes every word lowercase
        line[j] = tolower(line[j]);
        //scan the array for punctuation and deletes them
        if(ispunct(line[j]))
        {
          //erases the punctuation from the array
          line.erase(j--, 1);
        }
      }
  std::vector<std::string> sentences;
      //std::cout << index++ << line <<std::endl;
      int lastSentenceTerminator = 0;
      for(int c = 0; c < line.length(); c++)
      {
        if(line[c] == '.') //any sentence separator
        {
          //sentences.insert(sentences.end(), &line[c], &line[lineSize]);
          std::string sentence = line.substr(lastSentenceTerminator, c);
          sentences.push_back(sentence);
        }
      std::cout  << line[c];
      }
    }
    
    myFile.close();
  }
  
  else std::cout << "failure to open file.";
}

int main()
{
  Concordance c;
  
  c.createArray();
  //c.wordSearch();

  return 0;
}
