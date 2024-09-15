The simulation folder contains two files:  
- `main.c` which contains the program's `main()` function  
    - `init.h` called by `main.c`  
    - `init.c` calls `init.h`  
        - `matrice_transition_vent.txt`: contains the wind speed transition probability matrix, day by day, which influences daily production  
- `Makefile`: Makefile for compiling the program's source files

Data Structures  
~~~~~~~~~~~~~~~~~~~~  
To encapsulate all the intrinsic information of each wind turbine, a structure named `eolienne` is created containing:  
- A boolean that is true if the turbine is operational, false otherwise (fonctionne)  
- An integer representing the total cost of the turbine over the year (coutEolienne)  
- An integer representing the total number of interventions by the end of the simulation (nbIntervention)  
- An integer tracking when an intervention on the considered turbine is completed (joursIntervention)

Module Breakdown  
~~~~~~~~~~~~~~~~~~~~  
The two modules of the program:  
- `main.c`: contains the `main()` function which executes the program’s functions for the simulation  
- `init.c` (`init.h`): contains the definition of variables such as wind speed, intervention cost, production vectors, etc.

Libraries  
~~~~~~~~~~~~~~  
- `<stdio.h>`: Input/output management  
- `<stdlib.h>`: Standard library  
- `<stdbool.h>`: Boolean implementation  
- `<time.h>`: Time management (for random seed generation)

Compile/Run (Linux / Windows)  
-----------------------------------  
**Linux:**  

The provided Shell script displays the results and then saves them in a file.  
Open a terminal in the project source folder and run: `./Shell`  

This will execute the Shell code, which will:  
- Compile using make  
- Run the simulation  
- Display the results  
- Save these results in a file called `Resultats`

**Windows:**  

Open the command prompt  
Navigate to the project's source folder  
Then run: `Simulation_windows`  
(Note: On Windows, the program does not save results; for this, use Linux.)

Challenges Faced  
------------------------  
We encountered an issue when executing the program. Initially, the work was done on Windows with an `.exe` to launch.  
We realized that `gcc` did not work on Linux (at least not on Kali).  
The issue was due to our oversight of not redefining the external variables in `init.h` with the `extern` keyword.

----------------------------------------------------------------------------------------------  
RESULTS:  

See the `Resultats` file
