/**
 * Two threads playing songs
 */
#include <thread>
#include <chrono>
#include <stdio.h>


bool playing = true;

void music_player(const char* name) 
{
    unsigned int song_count = 0;
    while (playing) 
    {
        song_count++;
    }
    printf("%s played %u songs.\n", name, song_count);
}


int main() 
{
    // Threads do not start at the same time, but close enough
    std::thread player_1(music_player, "Player_1");
    std::thread player_2(music_player, "Player_2");
    
	printf("player_2 and player_1 are playing songs...\n");

    // wait 1 sec
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // this will kill loops in each thread
    playing = false;
    player_2.join();
    player_1.join();
}

/*

player_2 and player_1 are playing songs...
Player_2 played 700311306 songs.
Player_1 played 702603958 songs.

*/