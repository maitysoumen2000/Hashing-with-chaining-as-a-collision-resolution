# Hashing-with-chaining-as-a-collision-resolution in C

## Overview
This program implements a **chained hash table** in C to handle collisions using linked lists. It supports the following operations:
1. **Insert**: Add elements to the hash table.
2. **Lookup**: Search for elements in the hash table.
3. **Delete**: Remove elements from the hash table.

---

## Features

1. **Hash Table with Chaining**:  
   - Uses an array of pointers (`start[MAX]`), where each slot points to the head of a linked list.
   - Collisions are resolved by chaining: multiple elements hashing to the same key are stored in a linked list.

2. **Dynamic Memory Management**:  
   - Dynamically allocates memory for new nodes in the linked list.

3. **Basic Operations**:  
   - **Insert**: Inserts an element into the hash table.
   - **Lookup**: Searches for an element in the hash table and indicates its presence.
   - **Delete**: Removes an element from the hash table, updating the linked list as necessary.

---

## Files

### `chained_hash_table.c`
This file contains the source code for:
- `insert(int val)`
- `lookup(int val)`
- `delete(int val)`

---

## Functions

### 1. `void insert(int val)`
- **Purpose**: Inserts a value into the hash table.
- **Parameters**:
  - `val`: The value to be inserted.
- **Logic**:
  - Compute the hash key: `hkey = val % MAX`.
  - Create a new node.
  - If the hash key slot is empty, assign the node to the slot.
  - Otherwise, append the node to the end of the linked list at that slot.

---

### 2. `void lookup(int val)`
- **Purpose**: Searches for a value in the hash table and prints whether it is found.
- **Parameters**:
  - `val`: The value to search for.
- **Logic**:
  - Compute the hash key: `hkey = val % MAX`.
  - Traverse the linked list at the computed hash key slot.
  - If the value is found, print that it exists; otherwise, print that it is not found.

---

### 3. `void delete(int val)`
- **Purpose**: Removes a value from the hash table.
- **Parameters**:
  - `val`: The value to be deleted.
- **Logic**:
  - Compute the hash key: `hkey = val % MAX`.
  - Traverse the linked list at the computed hash key slot.
  - If the value is found, remove the corresponding node and adjust the pointers.

---

## Usage

1. **Compilation**: Compile the code using a C compiler:
   ```bash
   gcc -o chained_hash_table chained_hash_table.c
