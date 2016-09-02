#include <iostream> 
#include <sstream>
#include <unistd.h>
#include "Base.h"
#include "Connector.h"
#include "Command.h"
#include "Precedence.h"
#include "Parse_Cmd.h"

using namespace std;

int main() 
{
    
    Parse_Cmd parser;

    cout << "\nwelcome to rshell!" << endl;
  
    for (;;)
    {
        cout << "> ";
        string str;
        getline(cin, str); 
        
        stringstream input(str);
         
        Base* cmd;
        cmd = parser.parse(input);
        
        cmd->execute(); 
//        delete cmd;
         
    }
    
   return 0;
}
