echo "testing exit..."
exit
echo command && exit # exit after command using &&
echo command || exit # exit after command using ||
echo command; # exit after command by ; without spaces
