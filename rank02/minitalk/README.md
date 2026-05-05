*This project has been created as part of the 42 curriculum by vasukmua.*

# Minitalk

## Description
A simple Client-Server chat program. They talk to each other using only UNIX signals (`SIGUSR1` and `SIGUSR2`).
* `SIGUSR1` represents bit `1`.
* `SIGUSR2` represents bit `0`.

**How it works:**
This project has two programs:
1. **Server** : It runs and waits to receive messages.
2. **Client** : It sends a text message to the server using the server's Process ID (PID).

The Client changes each character into bits (0 and 1). It sends `SIGUSR1` for 1 and `SIGUSR2` for 0. The Server receives these signals, puts them back together into characters, and prints the message!


## Instructions

### Compilation
To compile the code, just run this command in your terminal at the root of the repository:
```bash
make
```
This will create two files inside the bin/ folder: server and client.

### Other commands
- `make clean`	Deletes the .o (object) files.

- `make fclean`	Deletes the .o files and the server / client programs.

- `make re`		Cleans everything and builds the project again.


### Project Files
- `src/server.c`	The server program.
- `src/client.c`	The client program.
- `src/utils.c`		Helper functions (like printing numbers or strings).
- `src/minitalk.h` 	The header file.
- `Makefile`		The build script.

## Resources
**People**
- p'pun [] 
- sky []

**Documentation & References**
- bit shift operations 
	- https://www.geeksforgeeks.org/cpp/left-shift-right-shift-operators-c-cpp
	- https://www.w3schools.com/c/c_bitwise_operators.php
	


**AI Usage**

cwqhpvqwpcsdlkvc'sd;lcslac;lsxc;cvxzvlx;zcvlzhsd'/vs;cvjxcklh lxc klxc zl;jclxzljzxlkvhxzlvhzxcxlkvhzxclvxlc

## How to Use (Step-by-Step Example)
`You need to open two terminal windows to test this.`

### Step 1: Start the Server (Terminal 1)
Run the server program first.

```Bash
./bin/server
```
Output:

```Plaintext
Server PID : 12345
```
The server is now waiting. Keep this terminal open!

### Step 2: Send a Message (Terminal 2)
Open a new terminal. Run the client using the PID from Step 1 and type your message.

```Bash
./bin/client 12345 "Hello from the client!"
```

### Step 3: Check the Result
Look back at `Terminal 1`. You will see your message printed:

```Plaintext
Server PID : 12345
Hello from the client!
```

