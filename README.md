# CSFML_WorkShop_2

Welcome to the CSFML_WorkShop_2! This workshop is designed to enhance your skills in game development using the CSFML library in C. Below, you'll find a structured guide to navigate through the repository and specific tasks to complete.

## Repository Structure

### Main Files:
- **[main.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/main.c):** The main entry point of the program.
- **[Makefile](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/Makefile):** For compiling the project.

### Header Files:
- **[my.h](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/includes/my.h):** Function declarations and library inclusions.
- **[struct.h](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/includes/struct.h):** Definitions of structures used in the project.

### Source Files:
- **[analyse_event.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/analyse_event.c):** Event analysis.
- **[animation.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/animation.c):** Game animations.
- **[create_sprites.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/create_sprites.c):** Sprite creation functions.
- **[create_text.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/create_text.c):** Text element creation functions.
- **[display.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/display.c):** Display management.
- **[free_funcs.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/free_funcs.c):** Memory freeing functions.
- **[game.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/game.c):** Core game logic.
- **[init_struct.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/init_struct.c):** Structure initialization.
- **[menu.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/menu.c):** Game menu management.
- **[read_map.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/read_map.c):** Map reading functionality.
- **[settings.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/settings.c):** Game settings.
- **[tools.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/tools.c):** Utility functions.

### Resources:
- Various assets in the `ressources` directory.

## Tasks

### Step 1: Implement `game_asset` Function
- **File:** [game.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/game.c)
- **Task:** Complete the `game_asset` function to load all sprites for the game map.
- **Explanation:** This function should read the game map and create corresponding sprites for each element (e.g., walls, player, flags). Use the provided sprite creation functions and map data to dynamically generate the game world.

### Step 2: Implement Player Movement Initialization and Stopping
- **File:** [analyse_event.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/analyse_event.c)
- **Task:** Fill in the `init_move_player` and `stop_move_player` functions.
- **Explanation:**
  - `init_move_player`: Initialize player movement when a key is pressed. This function should set the movement direction and speed based on the key pressed.
  - `stop_move_player`: Stop the player's movement when the key is released. Ensure the player stops moving smoothly and responds correctly to input changes.

### Step 3: Enhance Player Animation and Collision Detection
- **File:** [animation.c](https://github.com/gredzy/CSFML_WorkShop_2/blob/main/src/animation.c)
- **Task:** Improve the player's animation and implement collision detection.
- **Explanation:**
  - Enhance the player's movement animations for a more dynamic experience.
  - Implement collision detection to prevent the player from moving through obstacles.
