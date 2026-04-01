# Cleaned-Up Project Structure

A cleaner beginner-friendly version of the project has been added with separate header and implementation files.

## New folders
- `include/` contains header files
- `src/` contains implementation files and the new main program

## Files
- `include/Payment.h`
- `src/Payment.cpp`
- `include/MonthRecord.h`
- `src/MonthRecord.cpp`
- `include/ExpenseTracker.h`
- `src/ExpenseTracker.cpp`
- `src/main.cpp`

## Notes
- This version avoids `vector`
- It uses fixed-size arrays instead
- Comments were added after variable declarations and function declarations
- The original top-level `main.cpp` is still in the repo because I could not safely overwrite existing files with the GitHub actions available here
