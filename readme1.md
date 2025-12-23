# Simple Breakout

This project presents a complete implementation of a **Simple Breakout** game, developed incrementally with a focus on clean structure, extensibility, and gameplay polish. Functionality was added through a sequence of well-defined commits, each addressing a specific layer of the game.

## Commit #1 — Core Gameplay Foundation

The first commit established the architectural backbone of the project. A structured approach to game states enabled the implementation of multiple screens, including the menu, gameplay, pause, victory, and loss states. By the end of this stage, the fundamental mechanics were in place, with `breakout.cpp` acting as the central orchestration file.

## Commit #2 — Audio Integration

In the second commit, audio feedback was introduced. Sound effects were declared and managed through `assets.h` and `assets.cpp`, ensuring proper initialization and cleanup. Three distinct sound effects were triggered inside the `move_ball()` function, each corresponding to collisions with different in-game objects. Additionally, background music was added to the victory screen and controlled from the `update()` function.

## Commit #3 — Victory State Bug Fix

During testing, a logic error was identified: after completing the game and returning to the menu, restarting would incorrectly load the final level instead of beginning from the first. This issue was resolved by explicitly resetting `current_level_index` to `0` when entering the `menu_state`, ensuring a fresh game start.

## Commit #4 — Level Expansion

Three additional levels were introduced in this stage, each designed directly within `game.h`. Difficulty was intentionally scaled, with the third level presenting the highest challenge and therefore designated as the final level of the game.

## Commit #5 — Game Over Screen Implementation

Previously, losing a level caused an immediate restart, resulting in an abrupt user experience. To address this, a delay buffer and a dedicated Game Over screen were implemented. The screen, primarily rendered in `graphics.cpp`, now appears upon loss and prompts the player to restart the game by pressing Enter, significantly improving usability and feedback.
