#include "characters.h"
#include "mappack.h"
#include "menufunctions.h"


void interact(hero player, int lvl){
    if(lvl == 0){
        switch(mapsCollision[lvl][player.y][player.x]){
            case 'e':
                interactMenu(player, "Reading", "Raymond's house.", 8, 33);
            break;
            case 'f':
                interactMenu(player, "Reading", "Ernest's house.", 9, 33);
            break;
            case 'g':
                interactMenu(player, "Reading", "Lucao's house.", 9, 33);
            break;
            case 'h':
                interactMenu(player, "Reading", "Abandoned house\n\t DO NOT ENTER", 8, 33);
            break;
            case 'j':
                interactMenu(player, "Reading", "Douglas' house.", 8, 33);
            break;
            default:
                interactMenu(player, "", "Nothing's here!", 8, 33);
            break;
        }
    } else if(lvl == 2){
        switch(mapsCollision[lvl][player.y][player.x]){
            case 'e':
                interactMenu(player, "Melanie", "Hello! Have you heard of \nthe ghouls that are tormenting \n    people all around town?", 3, 33);
                interactMenu(player, "Melanie", "I'm too afraid to leave \n     the city so we can't \n       go out to hunt.", 3, 33);
                interactMenu(player, "Melanie", "I'm afraid we're gonna \n     starve sometime soon", 4, 33);
            break;
            case 'f':
                interactMenu(player, "Raymond", "This is it.\n    We're all going to die.", 10, 33);
            break;
            case 'g':
                interactMenu(player, "Interacting", "An unconfortable looking bed.", 1, 33);
            break;
            case 'h':
                interactMenu(player, "Reading", "Abandoned house\n\t DO NOT ENTER", 8, 33);
            break;
            case 'j':
                interactMenu(player, "Reading", "Douglas' house.", 8, 33);
            break;
            default:
                interactMenu(player, "", "Nothing's here!", 8, 33);
            break;
        }
    } else if(lvl == 3){
        switch(mapsCollision[lvl][player.y][player.x]){
            case 'e':
                interactMenu(player, "Ernest", "My daughter recently ran away, \n so my wife desperately left \n   the town looking for her.", 0, 33);
                interactMenu(player, "Ernest", "It has been four days since \n that happened and they still\n       haven't returned...", 2, 33);
            break;
            case 'f':
                interactMenu(player, "Interacting", "Ernest's and his wife's bed.", 2, 33);
            break;
            case 'g':
                interactMenu(player, "Interacting", "Ernest's daughter's bed.", 3, 33);
            break;
            case 'h':
                interactMenu(player, "Interacting", "A pile of toys", 9, 33);
            break;
            default:
                interactMenu(player, "", "Nothing's here!", 8, 33);
            break;
        }
    }
}
