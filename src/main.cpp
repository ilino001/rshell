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
#include "Exit.h"

int main(int argc, char *argv[]) {
      
  // extra credit      
  //
  //      char *user = getlogin();            
  //      char host[1000];
  //      
  //      gethostname(host, sizeof host); 
  //      cout << user << "@" <<  host << "$ ";   
        
    string cmd[100];
    string input; 
    string input2;
    char cline[100], *command; 
    char strDelims[] = ";|&#\n"; 
    int x = 0; 
    
    
    ifstream inFS;
    string filename = argv[1]; //sets second argument to filename 
    //string filename = "../tests/exit.sh"
    inFS.open(filename.c_str()); //opens filename passed in 
    
    //if filename cannot be opened 
    if (!inFS.is_open()) {
        cout << "ERROR: cannot open " << argv[1]; 
        return 0; 
    }
    
    else {
        
        //while inFS isn't at the end of file 
        while (!inFS.eof()) {
        x = 0;
        getline(inFS, input); //reads in each line from file 
        
        //if x does not equal zero, it copies input to input2 
        input2 = input;

        
        strcpy(cline, input.c_str()); //copies from string to char 
        command = strtok(cline, strDelims); //copies cline to command, does not takes into consideration the symbols 
  
        while (command != NULL) {
            //if command does not equal, insert into string cmd 
            if (command[0] != '#') {
              cmd[x] = command; //insert current command into string 
              cout << "Command at " << x <<  " is: " << cmd[x] << endl;
            }
            
            //continues to next char 
            command = strtok(NULL, strDelims); 
            ++x; //increment x 
        }
        

        
        int z = 0; //index for the connector array
        char dline[100]; //used for conversion from string to char
        char *command2; //the result after parsing
        string cnct [100]; //connector array
        strcpy(dline, input2.c_str()); //converts input into char array
        command2 = strtok(dline, " "); //parses dline up to the first space
    
        while (command2 != NULL) { 
          //checks all the parsed words, char by char.
          //checks for any of these symbols: ; && and ||
          //if the symbol is found, add it to the connector array and increment counter
        for (unsigned int i = 0; i < strlen(command2); ++i) { //iterates til end of parsed word
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
      command2 = strtok(NULL, " "); //Moves on to the next word seperated by space
  }
  //ARRAY CMD POPULATED WITH ALL THE COMMANDS
  //ARRAY CNCT POPULATED WITH ALL THE CONNECTORS
  
  vector<Base*> commandVector; //vector for all commands
  for (int j = 0; j < x; ++j) {
    Base* comm;   //default for command to be added 
      if (cmd[j] == "exit") { //if the command is exit, declare as Exit object
        comm = new Exit();
      }
      else {    //if command is not exit, declare as regular command object
        comm = new Command(cmd[j]);
      }
      commandVector.push_back(comm);  //add command to vector
  }
  
  
  vector<Base*> connectorVector;
  int i = z - 1; //highest index of connectors
  int j = x - 1; //highest index of  commands

  //Create the first part of the tree, using the last two commands in the array as parameters
  //in the declaration of the last connector in the array
  //decrement j since you already used 2 of the commands in the treee
  //decrement i since you just used the 1 of the connectors in the tree
    if (cnct[i] == ";") {
        Semicolon* A = new Semicolon(commandVector.at(j-1), commandVector.at(j));
        connectorVector.push_back(A);
        --j;
        --j;
        --i;
    }
    if (cnct[i] == "|") {
        Or* B = new Or(commandVector.at(j-1), commandVector.at(j));
        connectorVector.push_back(B);
        --j;
        --j;
        --i;
    }
    if (cnct[i] == "&") {
        And* C = new And(commandVector.at(j-1), commandVector.at(j));
        connectorVector.push_back(C);
        --j;
        --j;
        --i;
    }
  

  //Checks which connector is in the cnct array to decide which contructor to call
  //Now the right child of every connector will be another connecter
  //The left child will be a command
  //Decrement j and i after you add a signle connector and command to the tree
  while (i >= 0 && j >= 0) { //Continue as long as we don't run out of connecters or commands
    if (cnct[i] == ";") {
        Semicolon* A = new Semicolon(commandVector.at(j), connectorVector.at(connectorVector.size()-1));
        connectorVector.push_back(A);
        --j;
        --i;
    }
    if (cnct[i] == "|") {
        Or* B = new Or(commandVector.at(j), connectorVector.at(connectorVector.size()-1));
        connectorVector.push_back(B);
        --j;
        --i;
    }
    if (cnct[i] == "&") {
        And* C = new And(commandVector.at(j), connectorVector.at(connectorVector.size()-1));
        connectorVector.push_back(C);
        --j;
        --i;
    }
  }

//connectorVector.at(connectorVector.size() - 1)->execute(0, 1);
// connectorVector.at(connectorVector.size() - 1); 
//executing the root of the tree recursively executes its children
        }
       
    } 

    return 0; 
  
}