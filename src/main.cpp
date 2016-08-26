#include <iostream> 
#include <sstream>
#include <unistd.h>
#include "Base.h"
#include "Connector.h"
#include "Command.h"
#include "Precedence.h"
#include "Parse_Cmd.h"


using namespace std;
int main() {
    
    Command composer;

    //main loop
    while (true) { // main loop
        //cout << u << "@" << h << "$ "; //print prompt
        cout << "$";
        string str;
        getline(cin, str); //get line of command
        istringstream ss(str); //set up strin stream
        Command* bc = composer.parse(ss); //compose command into tree
        bc->execute(); //execute command
        delete bc; //deallocate memory-- no memory leaks allowed
    }
    
   
    
    return 0;
}