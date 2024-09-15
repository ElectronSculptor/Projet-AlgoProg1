
# Wind Turbine Simulation Project

## Description

The simulation folder contains the following files:  
- **`main.c`**: Contains the program's `main()` function.  
    - **`init.h`**: Header file called by `main.c`.  
    - **`init.c`**: Implements the functions defined in `init.h`.  
    - **`matrice_transition_vent.txt`**: Text file containing the wind speed transition probability matrix, day by day, which influences daily production.  
- **`Makefile`**: Used to compile the program's source files.

## Data Structures

To encapsulate all the intrinsic information of each wind turbine, a structure named `eolienne` is defined with the following members:  
- `fonctionne`: A boolean indicating if the turbine is operational (true) or not (false).  
- `coutEolienne`: An integer representing the total cost of the turbine over the year.  
- `nbIntervention`: An integer counting the total number of interventions by the end of the simulation.  
- `joursIntervention`: An integer tracking when an intervention on the turbine is completed.

## Module Breakdown

The program consists of two main modules:  
- **`main.c`**: Contains the `main()` function which controls the execution of the simulation.  
- **`init.c`** / **`init.h`**: Handles the initialization of variables such as wind speed, intervention costs, production vectors, and more.

## Libraries

The following libraries are used in this project:  
- **`<stdio.h>`**: For input/output management.  
- **`<stdlib.h>`**: For standard utility functions.  
- **`<stdbool.h>`**: For boolean data type support.  
- **`<time.h>`**: For time management, used for random seed generation.

## Compilation & Execution

### Linux

The provided Shell script compiles, runs the simulation, displays the results, and saves them in a file.  
To run the simulation on Linux:

1. Open a terminal in the project source folder.
2. Run the command: `./Shell`

This will:
- Compile the program using the `Makefile`.
- Run the simulation.
- Display the results.
- Save the results in a file called `Resultats`.

### Windows

1. Open the command prompt.
2. Navigate to the project source folder.
3. Run the command: `Simulation_windows`.

**Note:** On Windows, the results are not automatically saved. Use the Linux version to generate the results file.

## Challenges Faced

During development, I encountered issues when running the program. Initially, the program was developed on Windows and compiled into an `.exe`.  
When moving to Linux (specifically on Kali Linux), I found that `gcc` did not work as expected.  
The issue was traced back to a failure to declare external variables in `init.h` using the `extern` keyword, which was necessary for proper linking across files.

## Results

The simulation results are saved in the `Resultats` file.
