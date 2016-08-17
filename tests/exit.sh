echo "testing exit..."
#exit                    # plain exit 
echo command && exit    # exit after command using &&
echo command || exit    # exit after command using ||
echo command;           # exit after command by ; without spaces

#../bin/rshell < test_exit
