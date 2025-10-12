

### Display the path of your current directory

```bash
pwd
```
### Create a new directory called `LabFiles` in your home directory

```bash
mkdir LabFiles
```
### Navigate into `LabFiles` directory

```bash
cd LabFiles
```

### Create new directories inside `LabFiles`

-   📁 FileDir1
-   📁 FileDir2

```bash
mkdir FileDir1 FileDir2
```

### Create three new files inside the new directories

-   📄 **file1.txt** inside 📁 **FileDir1**
-   📄 **file2.txt** inside 📁 **FileDir2**

```bash
touch FileDir1/file1.txt
touch FileDir2/file2.txt
```

### List the files in the `LabFiles` directory

```bash
ls
```

### Add some contents in the `file1.txt` and `file2.txt` file using terminal

```bash
nano FileDir1/file1.txt
nano FileDir2/file2.txt
```

### Display the contents of `file1.txt`

```bash
cat FileDir1/file1.txt
```

### Make a copy of `file1.txt` called `backup.txt` in `LabFiles` directory

```bash
cp FileDir1/file1.txt backup.txt
```

### Rename `file2.txt` to `newfile.txt`

```bash
mv file2.txt newfile.txt
```

### Move `newfile.txt` to the `FileDir3` changing its name to `newfile2.txt`

```bash
mv newfile.txt ../FileDir3/newfile2.txt
```

### Remove `file1.txt` from the `FileDir1` directory

```bash
rm file`.txt
```

## User Management

### Identify the currently logged-in users on the system.

```bash
who
```

### Create a new user named developer1

```bash
sudo useradd -m developer1
```

### Set a password for the newly created user

```bash
sudo passwd
```

### Create a new group named development

```bash
sudo groupadd development
```

### Add the user developer1 to the development group

```bash
sudo usermod -aG development developer1
```
### Check and display the group memberships of the user developer1

```bash
groups developer1
```

### Change the ownership of the project_files directory to developer1 and the group to development 

```bash
chown developer1 project_files
chgrp development project_files
```

### Ensure that only the owner (developer1) has write permissions in the project_files directory.

```bash
chmod ua+w project_files
```

### Test network connectivity

```bash
ping google.com
```

### View running processes

```bash
ps aux
```
### Archive files

```bash
tar -czvf
```
### Extract files

```bash
tar -xzvf
```

