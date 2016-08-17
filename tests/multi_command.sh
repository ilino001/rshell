echo "testing multi command..." || ls -a; ps
ls -a && mkdir folder
rm -r folder; ls
echo "first testing..." || echo "test failed" && ls;
mkdir second_folder && echo second folder cretated
rm -r second_folder; ls
echo clear; clear
echo || mkdir || ls
ls -R && ps
ls -a || ls && ls
exit


#../bin/rshell < multi_command
