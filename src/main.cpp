#include <iostream>
#include <string>
#include <cstring>
#include <fstream> 
#include <vector> 
#include <boost/tokenizer.hpp> 

using namespace std;

#include "Connector.h"
#include "Command.h"
#include "Semicolon.h"
#include "And.h"
#include "Or.h"

int main(int argc, char *argv[]) {
    
    
    string cmd[100];
    string input; 
    string input2;
    char cline[100], *command; 
    char strDelims[] = ";|&"; 
    int x = 0; 
    ifstream inFS;
    string filename = argv[1]; //sets second argument to filename 
    inFS.open(filename.c_str()); //opens filename passed in 
    
    //if filename cannot be opened 
    if (!inFS.is_open()) {
        cout << "ERROR: cannot open " << argv[1]; 
        return 0; 
    }
    
    else {
        
        while (!inFS.eof()) {
            
        //cout << "Able to open file\n"; 
        getline(inFS, input); //reads in each line from file 
        if (x == 0) {
            input2 = input; 
        }
        //cout << "past getline" << " "; 
        strcpy(cline, input.c_str()); //copies from string to char 
        command = strtok(cline, strDelims); 
  
        while (command != NULL) {
            //cout << "inside while loop\n"; 
            cmd[x] = command; //insert current command into vector 
            cout << "Command at " << x <<  " is: " << cmd[x] << endl; 
            command = strtok(NULL, strDelims); 
            ++x; //increment x 
        }
        
        }
       
    }

  

    int z = 0;
    char dline[100]; 
    char *command2; 
    string cnct [100];
    strcpy(dline, input2.c_str()); //converts input into char array
    command2 = strtok(dline, " ");
    
  while (command2 != NULL) {
      for (unsigned int i = 0; i < strlen(command2); ++i) {
        //   cout << command2[i] << " ";
          if (command2[i] == ';') {
            cnct[z] = command2[i];
            cout << "Connector Array at " << z << " is: " << cnct[z] << endl;
            ++z;
          } 
          if (command2[i] == '&' && command2[i+1] == '&') {
            cnct[z] = command2[i];
            cout << "Connector Array at " << z << " is: " << cnct[z] << endl;
            ++z;
          }
          if (command2[i] == '|' && command2[i+1] == '|') {
            cnct[z] = command2[i];
            cout << "Connector Array at " << z << " is: " << cnct[z] << endl;
            ++z;
          }
      }
      command2 = strtok(NULL, " "); 
  }
  //SUCCESFULLY POPULATED CMD WITH ALL THE COMMANDS
  //SUCCESSFULLY POPULATED CNCT WITH ALL THE CONNECTORS
  
  // CREATE ALL THE COMMANDS
  vector<Command*> commandVector;
  for (int j = 0; j < x; ++j) {
      Command* comm = new Command(cmd[j]);
      commandVector.push_back(comm);
  }
  
 

    return 0; 
}