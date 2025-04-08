import sys
import os # Import os module to work with file paths

# Increase recursion depth limit for potentially deep paths in large mazes
# Be cautious with this in resource-constrained environments
try:
    # Increased limit slightly more for safety, adjust if needed
    sys.setrecursionlimit(2500)
except Exception as e:
    print(f"Warning: Could not set recursion depth limit. {e}", file=sys.stderr)

def solve():
    # --- Input Reading ---
    try:
        rows, cols = map(int, sys.stdin.readline().split())
        maze = [list(map(int, list(sys.stdin.readline().strip()))) for _ in range(rows)]
    except Exception as e:
        print(f"Error reading maze input: {e}", file=sys.stderr)
        return

    # --- Find Start/End ---
    start_pos = None
    end_pos = None # Not strictly needed for finding paths, but good to know

    for r in range(rows):
        for c in range(cols):
            if maze[r][c] == 1:
                if start_pos is not None:
                    # Handle multiple start points if necessary, here we just take the last one found
                    pass
                start_pos = (r, c)
            elif maze[r][c] == 2:
                # Handle multiple end points if necessary, here we just take the last one found
                end_pos = (r, c) # Store end position if needed elsewhere

    if not start_pos:
        print("Error: Start position '1' not found in maze.", file=sys.stderr)
        return

    all_paths = []

    # --- Depth-First Search Function ---
    # current_pos: tuple (r, c) of the current position
    # current_path: list of tuples representing the path taken so far
    # visited_in_path: set of tuples visited in the CURRENT exploration branch
    def dfs(current_pos, current_path, visited_in_path):
        # Optimization: Check path length if constraints exist (optional)
        # MAX_PATH_LENGTH = rows * cols # Example limit
        # if len(current_path) > MAX_PATH_LENGTH:
        #     return # Prune excessively long paths

        r, c = current_pos

        # Add current position to the path and visited set for this branch
        current_path.append(current_pos)
        visited_in_path.add(current_pos)

        # Check if we reached the end
        if maze[r][c] == 2:
            # Found a path! Store a COPY of the current path
            all_paths.append(current_path.copy())
            # Backtrack immediately after finding the end
            # No need to explore further from the end node in this path
            # Important: Backtrack state correctly before returning
            visited_in_path.remove(current_pos)
            current_path.pop()
            return # Return after finding a path

        # Explore neighbors (Up, Down, Left, Right)
        # dr = delta row, dc = delta column
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]: # U, D, L, R
            next_r_raw = r + dr
            next_c_raw = c + dc

            # --- Apply Wrap-Around Logic ---
            next_r = next_r_raw % rows
            next_c = next_c_raw % cols
            # -----------------------------

            next_pos = (next_r, next_c)

            # --- Check Validity of Next Move ---
            # 1. Bounds check (implicitly handled by wrap-around)
            # 2. Not a wall (value is not 7)
            # 3. Not already visited IN THIS SPECIFIC PATH (prevents cycles)
            try:
                next_val = maze[next_r][next_c]
                if next_val != 7 and next_pos not in visited_in_path:
                    dfs(next_pos, current_path, visited_in_path)
            except IndexError:
                 # This shouldn't happen with wrap-around, but good practice
                 print(f"Warning: Calculated invalid index ({next_r}, {next_c})", file=sys.stderr)


        # --- Backtrack ---
        # Remove current position from visited set and path list
        # when returning from this recursive call (explored all options from here)
        # Ensure this happens *after* exploring all neighbors from current_pos
        visited_in_path.remove(current_pos)
        current_path.pop()
        # -----------------

    # --- Start the Search ---
    # Initial call: start at start_pos, path starts empty, visited set starts empty
    # The function will immediately add start_pos to the path and visited set.
    try:
        dfs(start_pos, [], set())
    except RecursionError:
         print("Error: Maximum recursion depth exceeded. Maze might be too large or complex, or contain unexpected cycles.", file=sys.stderr)
         # Optionally write partial results or an error message to the file
         output_filename = "testcase.txt"
         try:
            with open(output_filename, 'w') as f:
                 f.write("Error: Maximum recursion depth exceeded during pathfinding.\n")
         except IOError as e:
            print(f"Error writing recursion error to file {output_filename}: {e}", file=sys.stderr)
         return # Stop execution


    # --- Write Results to File ---
    output_filename = "testcase.txt"
    # Get the directory where the script is running
    script_dir = os.path.dirname(os.path.abspath(__file__))
    output_filepath = os.path.join(script_dir, output_filename)
    
    original_stdout = sys.stdout # Store original stdout just in case

    try:
        print(f"Attempting to write output to: {output_filepath}", file=sys.stderr) # Debug print
        with open(output_filepath, 'w') as f:
            sys.stdout = f # Redirect stdout to the file

            # --- Original Print Logic (now writes to file 'f') ---
            if not all_paths:
                print("No paths found from start (1) to end (2).")
            else:
                # Sort paths by length (optional, but can be nice)
                # all_paths.sort(key=len)

                # print(f"Found {len(all_paths)} possible paths:") # This line now goes to the file
                for i, path in enumerate(all_paths):
                    print(len(path)) # Print path length
                    for r_coord, c_coord in path:
                        print(f"{r_coord} {c_coord}") # Print coordinates
                    # Add a separator between paths in the file if desired
                    # if i < len(all_paths) - 1:
                    #      print("-" * 10)

    except IOError as e:
        # If file writing fails, print error to original stderr
        sys.stdout = original_stdout # Restore stdout first
        print(f"\nError: Could not write to output file {output_filepath}: {e}", file=sys.stderr)
    except Exception as e:
        # Catch other potential exceptions during output formatting
        sys.stdout = original_stdout
        print(f"\nAn unexpected error occurred during output generation: {e}", file=sys.stderr)
    finally:
        # Ensure stdout is always restored
        sys.stdout = original_stdout
        # Optional: Notify user on console that process finished and where output is
        if os.path.exists(output_filepath):
             print(f"Processing complete. Output written to {output_filepath}", file=sys.stderr)
        else:
             print(f"Processing complete, but output file {output_filepath} might not have been created due to errors.", file=sys.stderr)


# --- Run the solver ---
if __name__ == "__main__":
    solve()