# Install Instructions
***Download, compile, build and run the project for a specific Operating Systems (OS)***

The Chosen OS is *Windows 10*.
The Compilers being uses within the group are:
- *Geany & Visual Studio Community 2019*.

----------------------------------------------------------------------------------------------------------------------------------------

### **Downloading**
Downloading tools and creating the project
Most of the project tools are located on the following Victoria University page:
- *https://ecs.wgtn.ac.nz/Courses/ENGR101_2020T1/Project3*

If you scroll down to the bottom, several file are avaliable to download. You will need to install the *'Virtual_AVC.zip'* Folder

Once successfully downloaded, you will need to *unzip* the folder and move it somewhere you'll remember. 
After this has happened, you will need to go back to the webpage shown above and download the following file *'AVC_Win10.zip'*.

Once downloaded, you will need to *unzip* it and move it into the *'Virtual_AVC'* Folder beside its contents.
This folder contains the following two folders *'AVC_robot'* and *'AVC_server'*. These are the folders used to write the program.

----------------------------------------------------------------------------------------------------------------------------------------

### **Compiling using a 'C Compilier'**
**If you already have a C compiler skip this step** - Now that the files have been downloaded, we will need to download 
a *C compiler* to build and compile them and download the SFML Library.

To compile our program, we will need a C compilier, An example of one could be Geany and/or Visual Studio Community 2019. 
Both are great C compilers and it doesnt matter which one you choose to install. 
Below are the places you can install both C compiliers:
- https://www.geany.org/
- https://visualstudio.microsoft.com/vs/community/

If you have the wrong installer downloaded or a eariler unpatched or later version of a compiler. 
The best thing u can do is to redownload the C compilier and/or ask for tutor assistance in a ENGR101 Lab.

----------------------------------------------------------------------------------------------------------------------------------------

### **Downloading SFML**
**If you dont want to install MinGW scroll down to the section *Test installation*.
Simple and Fast Multi-media Library (SMFL) is a library providing an application programing interface written in C++
Below is how to install SMFL on windows 10:
Go to the following website: 
- https://www.sfml-dev.org/download/sfml/2.5.1/.

Once here, Select the latest MinGW version of SFML and download it.
After downloaded, unzip the folder into C:SFML. This can be changed later.

**Test installation**
There are two different procedures to test installation. The first is if you installed the above 'MinGW' and geany and the 
second is using visual studio community 2019. Both procedures have installation guides and manuals on the following website: 
* https://ecs.wgtn.ac.nz/Courses/ENGR101_2020T1/Project3
----------------------------------------------------------------------------------------------------------------------------------------

### **Creating our own executable**
We need to delete the following files to create our own executable:
After these files are deleted, we then are using our own robot.cpp executable.
- **server3.exe** and **server3.io** (Both located in AVC_server)
- **robot.exe** and **robot.o** (located in AVC_robot)

----------------------------------------------------------------------------------------------------------------------------------------

### **Changing the Maze**
To change the Mazefile, you will need to the following:
- Open File explorer
- Go to the following file location: VirtualAVC > AVC_Win10 > AVC_server > config.txt
- Open config.txt file in a text editor
- Change the “Core” text to either “Completion” or “Challenge”
- Remember to save after changes have been made  

----------------------------------------------------------------------------------------------------------------------------------------

### **Issues with C Compilier**
The following are issues discovered while trying to download the C Compilier:
- A later version was downloaded/installed. This was fixed by reinstalling an up to date software.
- We asked a tutor how to properly install SFML on windows 10 as it was playing up and not working, we didn’t know how to fix this
but after talking in a lab we we're told how to do it.
- Previous SFML were accidently downloaded causing confusion and problems. 

----------------------------------------------------------------------------------------------------------------------------------------
