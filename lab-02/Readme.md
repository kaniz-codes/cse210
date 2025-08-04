# Lab 02: User Management
**Name** Kaniz Fatema  
**ID:** 20245103154

## Table of Contents
- [1. Troubleshooting](#1-troubleshooting)
- [2. User Management](#2-user-management)
- [3. File Permission Adjustment](#3-file-permission-adjustment)
- [4. Conclusion](#4-conclusion)
- [5. Additional Tasks](#5-additional-tasks)

## Summary of Commands Used

| Command                            | Description                                |
|------------------------------------|--------------------------------------------|
| `who`                              | Show currently logged-in users             |
| `useradd -m developer2`            | Create a new user with a home directory    |
| `passwd`                           | Set user password                          |
| `groupadd development2`           | Create a new group                         |
| `usermod -aG group user`           | Add user to group                          |
| `chown` / `chgrp`                  | Change ownership and group of a file/dir   |
| `chmod 740`                        | Set permissions for owner, group, others   |
| `cat`                              | Display file contents                      |
| `tar -czvf` / `tar -xzvf`          | Archive and extract files                  |
| `ps aux`                           | View running processes                     |
| `ping google.com`                  | Test network connectivity                  |


## 1. Troubleshooting

**Task 1.1:** Use the `who` command to identify the currently logged-in users on the system.

```bash
who
```

![Task 1.1](images/1.1.png)

## 2. User Management

**Task 2.1:** Create a new user named **developer2** using the `useradd` command.

```bash
sudo useradd -m developer2
```
![Task 2.1](images/2.1.png)

**Task 2.2:** Set a password for the newly created user using the `passwd` command.

```bash
sudo passwd
```

![Task 2.2](images/2.2.png)

**Task 2.3:** Create a new group named **development2** using the `groupadd` command.

```bash
sudo groupadd development2
```
![Task 2.3](images/2.3.png)

**Task 2.4:** Add the user **developer2** to the **development2** group using the `usermod`
command.

```bash
sudo usermod -aG development2 developer2
```
![Task 2.4](images/2.4.png)

**Task 2.5:** Check and display the group memberships of the user **developer2** using the `groups` command.

```bash
groups developer2
```

![Task 2.5](images/2.5.png)

**Task 2.6:** Deletion of created group and user **developer2** using the `groupdel` `userdel` command.

```bash
sudo groupdel development2
sudo userdel -r developer2

```

![Task 2.6](images/2.6.png)

## 3. File Permission Adjustment

**Task 3.1:** Create a directory named **project_files** in the home directory of **developer1** using the `mkdir` command.

Logging into the **developer2** account:

```bash
sudo su - developer2
```

![Logging into the developer1 account](images/3.1.0.png)

Verifying that we are logged in as **developer2**:

```bash
who
whoami
```

![Verifying that we are logged in](images/3.1.1.png)

Verifying that we are in the correct working directory:

```bash
pwd
```

![Verifying the present working directory](images/3.1.2.png)

Creating the **project_files** directory:

```bash
mkdir project_files
```
![Creating the project_files directory](images/3.1.3.png)

**Task 3.2:** Change the ownership of the **project_files** directory to **developer2** and the group to **development2** using the `chown` and `chgrp` commands.

```bash
chown developer2 project_files
chgrp development2 project_files
```

![Task 3.2](images/3.2.png)

**Task 3.3:** Ensure that only the owner (**developer2**) has write permissions in the **project_files** directory.

```bash
chmod ua+w project_files
```

![Task 3.3](images/3.3.png)

## 4. Conclusion

**Task 4.1:** Summarize your troubleshooting findings and the actions taken to resolve any issues.

During the setup process, commands such as `useradd`,`groupadd` and `usermod` required administrative access. 
To execute these commands, we used `sudo` along with the user's password to gain the necessary privileges.

```bash
sudo groupdel development2
sudo userdel -r developer2
```

**Task 4.2:** Confirm that the new user developer1 has been successfully created, added to the development group, and that file permissions are set correctly.

![Task 4.2](images/2.5.png)

## 5. Additional Tasks

**Task 5.1:** Concatenate **file1.txt** and **file2.txt** to make a **file3.txt** with all the contents of **file1.txt** and **file2.txt**.

Creating a subdirectory named **kaniz154** in the **home directory** and navigating into it:

```bash
mkdir kaniz154
cd kaniz154
```


Creating two new files:

```bash
touch file1.txt
touch file2.txt
```
![Task 5.1](images/5.0.1.1.png)

Adding contents to the newly created files using `nano`:

```bash
nano file1.txt
nano file2.txt
```

Verifying the contents of **file1.txt** and **file2.txt**:

```bash
cat file1.txt
cat file2.txt
```
![Task 5.1](images/5.0.1.2.png)

Concatenate the contents of these two files into **file3.txt**:

```bash
cat file1.txt file2.txt > file3.txt
```

Verifying the contents of **file3.txt**:

```bash
cat file3.txt
```
![Task 5.1](images/5.0.1.3.png)


**Task 4.2:** Show the list of all running processes.

```bash
ps aux
```

![Task 5.2](images/5.0.2.png)

**Task 5.3:** Ping google.com.

```bash
ping google.com
```

![Task 5.3](images/5.0.3.png)

**Task 5.4:** Create an archive of the created folder.

```bash
tar -czvf archive.tar.gz *
```

**Task 5.5:** Decompress the archived folder.

```bash
tar -xzvf archive.tar.gz
```

![Task 5.4](images/5.0.4.png)

