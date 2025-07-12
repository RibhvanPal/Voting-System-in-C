# Voting-System-in-C

Voting System in C:

This is a simple console-based Voting System written in C. The program allows users to:
- Register candidates with unique voting symbols
- Cast votes for candidates
- Display live candidates and symbols during voting
- Determine the winner or declare a tie

> Designed as a mini project or academic assignment for beginners in C programming.

---

Features:

- Allows up to 6 candidates with distinct symbols.
- Prevents duplicate symbols using a pool of preset choices.
- Accepts input from any number of voters.
- Displays the winner based on highest votes.
- Handles ties gracefully.
- Uses dynamic memory allocation with `calloc()` and `free()`.
- Validates input to prevent invalid votes or selections.

---

Compilation and Execution:

  Compile-
  ```bash
  gcc voting_system.c -o voting_system
