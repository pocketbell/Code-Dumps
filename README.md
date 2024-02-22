2/22/24:

First ever C++ program, 
just trying to get notebook ideas to function, so far the "game" contains.

Functions so far.
Draw a background.
Draw "rectangles" for the UI from a class of rectangles.

Draw over UI screen with a game view.
Player moving around world grid.
Player colliding with anything that isn't empty space.
A "camera system" with a soft boundry that follows the player.

Menu screen key (just doesn't draw the world view over the main screen UI).

THINGS I AM LOOKING INTO AND NEED TO GO.

//TOP PRIO FOR FUN
//REAL TIME INPUT, EITHER STEPPING PER INPUT, OR HOLDING INPUT FOR NEXT REFRESH.

//Text overlay as a last draw on top
//Enemy class
//Enemy Icons on the map, (class again, and movement)
//Enemy combat screen.

///Maybe a "range scanner on the world array" and monsters within X distance from player are active to move or follow player.

///Need to pick a combat type, real time overworld means scanning player world array surroundings and locking damage to the target at that location.
///Maybe the icons on the world array are not instanced objects while outside that range, then pass the new ones into an array.
///Can I make a string array hold a word that holds a pointer to the enemy so I can track it's location?
///Learn C++.
