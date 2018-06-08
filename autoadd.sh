#!/bin/sh

echo -n "write your username: "
read user

# the username should be at least 6 characters
# just letter and numbers allowed, no spaces,
# symbols, etc

echo "$user" | egrep "[a-zA-Z0-9]{6,}$" >/dev/null

if [ "$?" = "1" ]; then
  echo "the username doesn't meet the requirements, try again"
  exit 1
fi


stty_settings=$(stty -g)
stty -echo
echo -n "Set your password for user "$user" $  "
read pw
stty $stty_settings

# now call the C program to encrypt the password with crypt(3)
# and get back the encrypted password

pwe=$(./crypt "$pw")
echo ""

# now call useradd with the encrypted password
# since it requires the output of crypt(3)
useradd $user -p $pwe -m -s /bin/bash 

