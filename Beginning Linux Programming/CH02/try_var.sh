#!/bin/sh

salutation="Hello"
echo $salutation
echo "The program $0 is now running"
echo "The second parametrs was $2"
echo "The first parameters was $1"
echo "The parameter list was $*"
echo "The user's home directory is $HOME"

echo "Please enter a new greeting"
read salutation

echo $salutation
echo "The script is now complete"

exit 0
