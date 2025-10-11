#include <stdio.h>
#include <string.h>

struct playerData
{
    char name[50];
    int health;
    int mana;
    int level;
};

void userProfile(struct playerData *player)
{

    printf("Welcome to the Dark Ruins!\n");
    printf("Please enter your profile name.\n\n");
    char playerName[50];

    fgets(playerName, sizeof(playerName), stdin);
    
    int pNameLength = strlen(playerName);

    if (pNameLength > 0 && playerName[pNameLength - 1] == '\n') 
    {
        playerName[pNameLength - 1] = '\0';
    }
    else
    {
    int buffer = 0;
    while ((buffer = getchar()) != '\n' && buffer != EOF);
    }

    printf("\nHero %s is coming to the village at the late night!\n\n", playerName);
   
    strcpy(player->name, playerName);
    player->health = 100;
    player->mana = 50;
    player->level = 1;

    printf("Player account: %s\nHealth: %d\nMana: %d\nLevel: %d\n", 
        player->name, 
        player->health, 
        player->mana, 
        player->level);
}

void Tavern(){

}

void Dungeon(){

}

void Monster(){
}

void savePlayerToJSON(struct playerData *player) {

    char filename[100];
    sprintf(filename, "characters/%s.json", player->name);

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "{\n");
    fprintf(file, "  \"name\": \"%s\",\n", player->name);
    fprintf(file, "  \"health\": %d,\n", player->health);
    fprintf(file, "  \"mana\": %d,\n", player->mana);
    fprintf(file, "  \"level\": %d\n", player->level);
    fprintf(file, "}\n");

    fclose(file);
    printf("Player saved!\n");
}



int main(void)
{
struct playerData player;
userProfile(&player);
savePlayerToJSON(&player);
return 0;
}




