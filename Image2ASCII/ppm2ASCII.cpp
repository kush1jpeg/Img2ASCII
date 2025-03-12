#include <iostream>
#include <fstream>
#include <cstdlib> //cmd tool
#include <vector>
#include <string>
// can use openCV for jpg to ppm format
using namespace std;

int main()
{
  string file;
  cout << "Enter the IMG file name- ";
  cin >> ws >> file;
  string ext = file.substr(file.find('.') + 1);
  cout << "extension- " << ext << "- ";
  if (ext != "ppm")
  {             //magick pra.jpeg -compress none -depth 8 -colorspace RGB -define "ppm:format=p3" output.ppm   terminal cmd
    string output = "output.ppm";
    string cmd = "magick " + file + " -compress none -depth 8 -colorspace RGB -define \"ppm:format=p3\" -resize 30% " + output;
    int res = system(cmd.c_str());
    if (res==0)
    {
      file = output;
      // cout << file <<"\n" ;
      cout << "the file is being generated into .ppm format"<< "\n" ;
    }
    else
    {
      cout << "unable to convert to ppm";
    }
  }
  // cout<< file ;
  ifstream inFile(file);
  if (!inFile)
  {
    cout << "File cannot be opened";
  }
  // Skip Comment Lines
     //i am inadeqate and impotent to write the  logic to skip the commented line so i basically just assigned it a variable- comment  and 
     //it basically just overwrites till the last word of comment is stored  in it,,,,  so demuree.... but so ugly...  
  
   string format;
   string comment;
  int width, height, maxVal;
  inFile >> format ; 
  if (format != "P3")
  {
      cout << "Unsupported PPM format" << endl;
      return 1;
  }
  while (inFile.peek() == '#') {  
    getline(inFile, comment); // Reads the comment line and stores it in commment
}

inFile >> width >> height >> maxVal;
vector<int> img ;
int pixel ;
while(inFile >> pixel) //to read all the rgb-values
{
 img.push_back(pixel) ;
}
int store=0 ;
int row = 0 ;
ofstream outFile("asciiART.txt");
for(int i = 0 ; i<img.size() ; i+=3)
{
  store = (img[i] + img[i + 1] + img[i + 2]) / 3; 

        if (store < 50) outFile << '#';
        else if (store < 17)   outFile << '@';
        else if (store < 34) outFile << '#';                    //@ # 8 % & $ 5 0 ? + = - : . " "  
        else if (store < 51) outFile << '8';
        else if (store < 68) outFile << '%';
        else if (store < 85) outFile << '&';
        else if (store < 102) outFile << '$';
        else if (store < 119) outFile << '5';
        else if (store < 136) outFile << '0';
        else if (store < 153) outFile << '?';
        else if (store < 170) outFile << '+';
        else if (store < 187) outFile << '=';
        else if (store < 204) outFile << '-';
        else if (store < 221) outFile << ':';
        else if (store < 238) outFile << '.';
        else if (store < 255) outFile << " ";
        row ++ ;

        if(row % width == 0){    //logic didnt cross my mind for new line but fuck gpt
          outFile << "\n" ;
        }
} 
cout << "The art has been generated with name - asciiART.txt -> just open it" ;
inFile.close() ;
}
