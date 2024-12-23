# rhythm-mania

## Gameplay
[![Watch the gameplay](assets/rhythm_mania_gameplay.mp4)]

## Build Dependencies
* [Git](https://git-scm.com/)
* [CMake](https://cmake.org/)
* make(Linux) / [GnuWin32: Make(Windows)](https://gnuwin32.sourceforge.net/downlinks/make.php)
* C++ Compiler: [gcc](https://gcc.gnu.org/) / [mingw-w64](https://winlibs.com/) (Choose POSIX threading library for best compatibility, UCRT runtime library for Windows 10/11 or MSVCRT runtime library if you are targetting older version of Windows and without LLVM/Clang/LLD/LLDB, also choose the Win64 version)

## Build instructions
```sh
# Clone this repo
git clone https://github.com/theculturedteam/rhythm-mania
cd rhythm-mania

# Create a build folder
mkdir build
cd build

# Build
# For Windows
cmake .. -G "MinGW Makefiles"
# For Linux
cmake ..

make

# Running the game
./rhythm-mania
```

## ~~SDL Setup Windows~~
## Windows Setup
1. `git clone https://github.com/theculturedteam/rhythm-mania` or (if your already have cloned it) `git fetch --all` then manually switch to updated branch with `git switch <branch_name>` and `git push`
2. Download [CMake](https://cmake.org/download/#latest) and run through the installation (Make sure to select add it to the current user path or add it to all user path, during the installation)
3. Download and install GnuWin32:Make using `win-get` or from this link "https://gnuwin32.sourceforge.net/downlinks/make.php". And add `C:\Program Files(x86)\GnuWin32\bin` to your user path after installation.
4. Download mingw-w64 from the link above and the extract it and move the mingw64 folder to C:\
5. Add `C:\mingw64` and `C:\mingw64\bin` to your user path.
6. Now cd to rhythm-mania and run the following commands:
    `mkdir build`,
    `cd build`,
    `cmake .. -G "MinGW Makefiles"`
7. Run `make` and the run `./rhythm-mania.exe`
8. But the game will not run, you will have to copy and paste dlls to the folder where the exe is located.
9. Run these commands to copy the dlls. **Note: you need to be inside build directory to run these commands, if you are not inside build then these will not work**:
    `cp ..\.sdl2\bin\*.dll .\`

**Note: The above setup is only needed to run once.**
To build and run the game after that just run `make` then `./rhythm-mania.exe` in your terminal, while inside build directory.
