# Path finding program

## What is this?

An enviroment if anything using Raylib to boost my skill in writing bot path finding algorithms!
in its current state is got a few simpe algorithms for the bot to follower the player

## HOW TO USE

simply change the alogrithm being used by clicking 1-3 on the number row

W A S D to move the camera, bots go after after the blue square

<img width="850" height="687" alt="image" src="https://github.com/user-attachments/assets/ca857f6b-0056-4f44-b9b4-22245b9a75cc" />

## Path finding algorithms

### simple follow

gors towards the goal coordinates directly with no care for
anything in its way


### Advanced follow

like simple follow, but avoids the bad sectors and trys to go around them

### Mimic

Mimics the targets actions

<hr>

## If you would like to build it yourself

for linux run in the root of the directory:

```

  ./build.sh

```

This file simply compiles the code using g++ and will run the output file.

<br>

## Dependancies

This game uses **raylib** and is compiled using **g++**. OpenGL devlopment liraries are required.

### to install

(assuming your on a debian distro of linux which uses apt)

```

  sudo apt install g++
  sudo add-apt-repository ppa:texus/raylib
  sudo apt install libraylib5-dev libgl1-mesa-dev
