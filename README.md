Splendid Mines
===

An advanced Minesweeper clone, filled with extra features and options for better gameplay.

Splendid Mines is a fork of the great [Mines-Perfect](http://www.czeppi.de/english/index.html) by Christian Chepluch. Development on the original project has stopped back in 2001, and Splendid Mines is an effort to continue work on this software.

Because of Mines-Perfect is now a slightly old software, it does not support modern machines very well. Also, it was always developed for Windows only, and while there are traces of limited Linux support, the original game has never worked on non-Windows machines. Splendid Mines aims to solve these problems.

### Compiling and running
Create a `build` directory. Run `cmake ..` inside. When cmake finishes, run `make` to begin compiltion. Once it is done, run `./splendidmines`.

At this very early stage of development do not expect to see anything working at all.

### Goals

- Porting the GUI to a modern toolkit.
- Ensuring multi-platform compatibility (at least Windows and Linux).
- Modernizing source code - removing depracated and non-standard functions, making use of C++14 features.
- Translating comments fo english.
- Tightly doumenting both the API and internal source code.
- Refactoring and restructuring some of internal algorithms for easier maintenance.
- Hosting the source in a public repository, so that everyone can easily contribute.
- Fixing remaining bugs, and generally implementing a number of improvements.

### Roadmap
- Version 1.5:
 - A simple, naive port that compiles and runs successfully on Linux.
 - The goal is to mimic the original 1.4 as closely as possible.
 - No new features or game logic improvements.
 - Using only original textures.
 - Keeping changes in the original code to minimum.
- Version 1.6
 - Cleaning up the original code. Restructuring and modernizing the source code for C++14.
 - Refactoring the frontend API.
 - Documenting the source code.
 - Translating comments.
 - Providing binary releases for Windows and Linux.
- Version 1.7
 - At this point new features will be welcome.
 - Fixes for game logic.
 - [Optionally] updated textures.

### Questions

##### Why C++?
The original Mines-Perfect source was written in C++. I understand that you would prefer to write in a higher-level language, like Python or Lisp, and I respect that, but please notice that it would require to re-implement a lot of complex algorithms (check `core/board.cpp` for examples).

##### Why GTK?
Mines-Perfect 1.4 used wxWindows for GUI. 15 years have passed and wxWindows/wxWidgets have evolved into a significantly differrent API, porting the GUI to modern wxWindows would require rewriting mostly of the GUI source code, so writing an entirely new GUI frontnend requires a similar amount of effort.

I've chosen GTK because I have a lot of experience with it and know it inside-out.  However, if you wish to have a GUI using a different toolkit, I believe it will be pretty easy to prepare it as an alternative.

##### What's up with the versioning, why start at 1.5?
The last release of Mines-Perfect was numbered 1.4. Because Splendid Mines is not re-implementing it's features, but merely porting original software and updating with new features, this fork can be considered as one of possible continuations for Mines-Perfect. Therefore I decided to keep the original versioning and start with 1.5, as if it was simply a next relase.
