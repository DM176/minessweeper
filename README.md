# minessweeper
Minesweeper in c++ console based

1. Setup_Board- to setup the board. This function will perform two tasks
a. It will use rand () function to randomly decide the number of mine and the cells where mines will be placed. Create
a function Place_Mines for this task.
b. For all the cells without a mine, you will calculate the number of mines in their neighboring cells. Think of an efficient
way to do this. Create a function Count_Neighboring_Mines for this task.
You will call functions Place_Mines and Count_Neighboring_Mines in the function Setup_Board.
2. Display_Board- to display the board on the screen. Before printing the board, you can clear the screen and display the new
board at the same location. Use system("CLS") to clear the screen, for this you will have to include standard library header
file <stdlib.h>.
3. Play_Game - to implement the game logic. It will ask the user which cell to open or Flag. If user opens a cell having a bomb
then game ends. If user opens a cell having a number greater then 0, then your game will simply reveal its content. However,
if user opens a cell having no neighboring mines (in any of the surrounding eight cells) then all the neighboring eight cells are
automatically revealed to the user. Your program should allow the user to Flag the cell he thinks contains bomb.
