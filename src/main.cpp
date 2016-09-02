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
    
    Parse_Cmd parser;

    cout << "\nwelcome to rshell!" << endl;
  
    for ( ; ; )
    {
<<<<<<< HEAD
        cout << "> ";
        string str;
        getline(cin, str); 
=======
         cout << "> ";
         string str;
         getline(cin, str); 
>>>>>>> ca86d66754e257184db49770dac4c856efb094dc
        
        stringstream input(str);
         
        Base* cmd;
        cmd = parser.parse(input);
        
<<<<<<< HEAD
        cmd->execute(); 
        delete cmd;
=======
         cmd->execute(); 
          delete cmd;
>>>>>>> ca86d66754e257184db49770dac4c856efb094dc
         
    }
    
   return 0;
}
