import sys

# Increase recursion depth limit for potentially deep paths in large mazes
# Be cautious with this in resource-constrained environments
try:
    sys.setrecursionlimit(2000) # Adjust as needed
except Exception as e:
    print(f"Warning: Could not set recursion depth limit. {e}", file=sys.stderr)

def solve():
    rows, cols = map(int, sys.stdin.readline().split())
    maze = [list(map(int, list(sys.stdin.readline().strip()))) for _ in range(rows)]

    start_pos = None
    end_pos = None # Not strictly needed for finding paths, but good to know

    for r in range(rows):
        for c in range(cols):
            if maze[r][c] == 1:
                start_pos = (r, c)
            elif maze[r][c] == 2:
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
            visited_in_path.remove(current_pos)
            current_path.pop()
            return

        # Explore neighbors (Up, Down, Left, Right)
        # dr = delta row, dc = delta column
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            next_r_raw = r + dr
            next_c_raw = c + dc

            # --- Apply Wrap-Around Logic ---
            next_r = next_r_raw % rows
            next_c = next_c_raw % cols
            # -----------------------------

            next_pos = (next_r, next_c)
            next_val = maze[next_r][next_c]

            # --- Check Validity of Next Move ---
            # 1. Not a wall (can move to 0 or 2)
            # 2. Not already visited IN THIS SPECIFIC PATH (prevents cycles)
            if next_val != 7 and next_pos not in visited_in_path:
                dfs(next_pos, current_path, visited_in_path)


        # --- Backtrack ---
        # Remove current position from visited set and path list
        # when returning from this recursive call (explored all options from here)
        visited_in_path.remove(current_pos)
        current_path.pop()
        # -----------------

    # --- Start the Search ---
    # Initial call: start at start_pos, path starts empty, visited set starts empty
    # The function will immediately add start_pos to the path and visited set.
    dfs(start_pos, [], set())

    # --- Print Results ---
    if not all_paths:
        print("No paths found from start (1) to end (2).")
    else:
        print(f"Found {len(all_paths)} possible paths:")
        for path in all_paths:
            print(len(path)) # Print path length
            for r_coord, c_coord in path:
                print(f"{r_coord} {c_coord}") # Print coordinates
            # print("-" * 10) # Separator between paths

# --- Run the solver ---
solve()
