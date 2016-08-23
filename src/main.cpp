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
      
    string cmd[100]; //Array for storing all of the commands
    string cnct[100]; //Array for storing all of the connectors
    string input; //Input parsed for commands
    char cline[100]; //Used for conversion from string to char
    char *command; //The result of the parsed input
    char strDelims[] = ";|&#\n";  //These characters tell strtok when to parse
    int x = 0; //Index for the command array
    int z = 0; //Index for the connector array

    //Opens the file and checks if is_open() fails
    ifstream inFS;
    string filename = argv[1]; //sets second argument to filename 
    //string filename = "../tests/exit.sh"
    inFS.open(filename.c_str());
    if (!inFS.is_open()) {
        cout << "ERROR: cannot open " << argv[1]; 
        return 0; 
    }
    
    else {
        
        while (!inFS.eof()) {
            x = 0;
            z = 0;
            getline(inFS, input); //Reads in each line from file
            //Checks for any comments and resizes before comment happens
            for (unsigned i = 0; i < input.length(); ++i) {
                if (input.at(i) == '#') {
                    input.resize(i);
                }
            }
            if (input == "") {
                exit(0);
            }
            strcpy(cline, input.c_str()); //Copies the input into char for strtok
            command = strtok(cline, strDelims); //Parses cline to isolate commands
  
            while (command != NULL) {
                  cmd[x] = command; //Inserts command into cmd array
                  cout << "Command at " << x <<  " is: " << cmd[x] << endl;
            
                //Continues onto next command
                command = strtok(NULL, strDelims); 
                ++x; 
            }
  
            strcpy(cline, input.c_str()); //Copies the input into char for strtok
            command = strtok(cline, " "); //Parses cline up to the first space
    
            while (command != NULL) { 
              //checks all the parsed words, char by char.
              //checks for any of these symbols: ; && and ||
              //if the symbol is found, add it to the connector array and increment counter
                for (unsigned int i = 0; i < strlen(command); ++i) { //iterates til end of parsed word
                    if (command[i] == ';') {
                        cnct[z] = command[i];
                        cout << "Connector Array at " << z << " is: " << cnct[z] << endl;
                        ++z;
                    }  
                    if (command[i] == '&' && command[i+1] == '&') {
                        cnct[z] = command[i];
                        cout << "Connector Array at " << z << " is: " << cnct[z] << endl;
                        ++z;
                    }
                    if (command[i] == '|' && command[i+1] == '|') {
                        cnct[z] = command[i];
                        cout << "Connector Array at " << z << " is: " << cnct[z] << endl;
                        ++z;
                    }
                }
            command = strtok(NULL, " "); //Moves on to the next word seperated by space
            }
            
    
    
            vector<Base*> commandVector; //Vector for all commands
            vector<Base*> connectorVector; //Vector for all connectors
            
            if (x != 0) {
                for (int j = 0; j < x; ++j) {
                    Base* comm;   
                    if (cmd[j] == "exit") { //If the command is exit, declare Exit object
                        comm = new Exit();
                    }
                    else {  //If command is not exit, declare regular command object
                        comm = new Command(cmd[j]);
                    }
                    commandVector.push_back(comm); //Add command to commandVector
                }
            }
            
            cout << "number of commands " << x << endl;
            cout << "number of connectors " << z << endl;
           
            if (z != 0) {
                 
                int i = z - 1; //Highest index of connectors
                int j = x - 1; //Highest index of commands
    
                    //in the declaration of the last connector in the array
                //decrement j since you already used 2 of the commands in the treee
 1               //decrement i since you just used the 1 of the connectors in the tree
                while (i >= 0 && j >= 0) { //Continue as long as we don't run out of connecters or commands
                    if (cnct[i] == ";") {
                        Semicolon* A = 0;
                        if (i == z - 1) {
                            A = new Semicolon(commandVector.at(j-1), commandVector.at(j));
                            --j;
                        }
                        else {
                            A = new Semicolon(commandVector.at(j), connectorVector.at(connectorVector.size()-1));
                        }
                        --j;
                        --i;    
                        connectorVector.push_back(A);

                    }
                    else if (cnct[i] == "|") {
                        Or* B = 0;

                        if (i == z - 1) {
                            B = new Or(commandVector.at(j-1), commandVector.at(j));
                            --j;
                        }
                        else {
                            B = new Or(commandVector.at(j), connectorVector.at(connectorVector.size()-1));
                        }
                        --j;
                        --i;
                        connectorVector.push_back(B);
                    }
                    else if (cnct[i] == "&") {
                        And* C = 0;
                        if (i == z - 1) {
                            C = new And(commandVector.at(j-1), commandVector.at(j));
                            --j;
                        }
                        else {
                            C = new And(commandVector.at(j), connectorVector.at(connectorVector.size()-1));
                        }
                        --j;
                        --i;
                        connectorVector.push_back(C);
                    }
                }
            }
            
            cout << "Connector Vector size: " << connectorVector.size() << endl;
            cout << "----------------------------------" << endl;

            if (z == 0 && x == 1) {
                commandVector.at(commandVector.size() - 1)->execute(0, 1);
            }
            else {
                connectorVector.at(connectorVector.size() - 1)->execute(0, 1);
            }
        }
    } 

    return 0; 
  
}
