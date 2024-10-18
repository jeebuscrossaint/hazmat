# hazmat cli notes

so what im thinking here for cli commands
is that we can have a list of commands
and then we can have a list of arguments

so for example
hazmat list add <name> <description>

so i will make a list of commands which are hazmat <command>
so first command
gotta be
```
list // manipulate lists
add // add a password or username
delete // delete a password or username
update // update a password or username
show // shows a password
help // this will be a command taht shows the user's hint
```

next we will have a list of arguments for each command i.e hazmat <command> <argument>
**list**
```
add // add a list
delete // delete a list
update // update a list (change name or description or hint)
```

**add**
```
item // add an item to a list (username and password)
```

**delete**
```
item // delete an item from a list
```

**update**
```
item // update an item from a list or update the description or hint or a username or password from a list
```

**show**
```
item // show an item from a list or print all lists or print all usernames or hint or description
```

**help**
```
item // show the help message for a command
```