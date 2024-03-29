#pragma once
#include "pch.h"

struct GameData {
	static inline const char Intro[INTRO_Y][INTRO_X] = {
   "########    #######    #######   #       #  ########   #########  ########           #########  #       #",
   "#       #  #       #  #       #  ##     ##  #       #  #          #       #          #       #  #       #",
   "#       #  #       #  #       #  # #   # #  #       #  #          #       #          #       #  #       #",
   "#       #  #       #  #       #  #  # #  #  #       #  #          #       #          #       #  #       #",
   "########   #       #  #       #  #   #   #  ########   #########  ########           #########  #########",
   "#       #  #       #  #       #  #       #  #       #  #          #       #                  #          #",
   "#       #  #       #  #       #  #       #  #       #  #          #       #                  #          #",
   "#       #  #       #  #       #  #       #  #       #  #          #       #                  #          #",
   "########    #######    #######   #       #  ########   #########  #       #                  #          #",
   "                                                                                                         ",
   "                                                                                                         ",
   "                                                                                                         ",
   "                                                                                                         ",
   "                                          PRESS ANY KEY TO START                                         "
	};

	static inline const char Map1[MAP_Y][MAP_X] = {
	"################################################",
	"#    @@@          @@##@@@@##@@          @@@    #",
	"#    @@@          @@##@@@@##@@    m     @@@    #",
	"#    @@@     m    @@##@@@@##@@          @@@    #",
	"#    @@@          @@##@@@@##@@          @@@    #",
	"#@@@@@@@          @@##@@@@##@@          @@@@@@@#",
	"#@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@#",
	"#@@@@@@@    @@@@@              @@@@@    @@@@@@@#",
	"#           @@@@@    m         @@@@@           #",
	"#           @@@@@          m   @@@@@      M    #",
	"#@@@@@@@    @@@@@              @@@@@    @@@@@@@#",
	"#@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@#",
	"#@@@@@@@                                @@@@@@@#",
	"#@@@@@@@               +                @@@@@@@#",
	"#@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@#",
	"#@@@@@@@    @@@@@      m       @@@@@    @@@@@@@#",
	"#           @@@@@       m      @@@@@           #",
	"#@@@@@@@    @@@@@              @@@@@    @@@@@@@#",
	"#@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@#",
	"#@@@@@@@          @@##@@@@##@@          @@@@@@@#",
	"#    @@@          @@##@@@@##@@          @@@    #",
	"#    @@@    M     @@##@@@@##@@          @@@    #",
	"#    @@@          @@##@@@@##@@   M      @@@    #",
	"#    @@@          @@##@@@@##@@          @@@    #",
	"################################################",
	};
	static inline const char Map2[MAP_Y][MAP_X] = {
	"################################################",
	"#    @@@@@@@@@@                  @@@@@@@@@@    #",
	"#    @@@@@@@@@@    m        m    @@@@@@@@@@    #",
	"#    @@@@@@@@@@                  @@@@@@@@@@    #",
	"#    @@@@@@@@@@    ##      ##    @@@@@@@@@@    #",
	"#@@@@@@@@@@@@@@    ##  m   ##    @@@@@@@@@@@@@@#",
	"#@@@@@@@@          ##      ##          @@@@@@@@#",
	"#     @@@          ##      ##   M      @@@     #",
	"#   M @@@     m        +               @@@  m  #",
	"#     @@@                              @@@     #",
	"#@@@@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@@@@#",
	"#@@@@@@@@@@@@@@@@@@    ##    @@@@@@@@@@@@@@@@@@#",
	"#######    ########    ##    ########    #######",
	"#######    ######## m  ##    ########    #######",
	"#@@@@@@@@@@@@@@@@@@    ##    @@@@@@@@@@@@@@@@@@#",
	"#@@@@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@@@@#",
	"#     @@@              m               @@@     #",
	"#  m  @@@                        M     @@@  m  #",
	"#     @@@ M        ##      ##          @@@     #",
	"#@@@@@@@@          ##      ##          @@@@@@@@#",
	"#    @@@@@@@@@@    ##  m   ##    @@@@@@@@@@    #",
	"#    @@@@@@@@@@    ##      ##    @@@@@@@@@@    #",
	"#    @@@@@@@@@@       M          @@@@@@@@@@    #",
	"#    @@@@@@@@@@                  @@@@@@@@@@    #",
	"################################################",
	};
	static inline const char Map3[MAP_Y][MAP_X] = {
	"################################################",
	"#    @@@@     @@   @@ m    @@   @@     @@@@    #",
	"#    @@@@  M  @@   @@      @@   @@     @@@@    #",
	"#    @@@@     @@   @@  ##  @@   @@     @@@@    #",
	"#    @@@@     ##   ##  ##  ##   ##  m  @@@@    #",
	"#@@@@@@@@     ##   ##  ##  ##   ##     @@@@@@@@#",
	"#@@@@@@@@     ##   ##  ##  ##   ##     @@@@@@@@#",
	"#                     @@@@                     #",
	"#  m      ###    M    @@@@    M    ###         #",
	"#                     @@@@                     #",
	"#########     #######      #######     #########",
	"#m    @@@     @@   @@      @@   @@     @@@    m#",
	"#########     @@ + @@      @@ + @@     #########",
	"#m    @@@     @@   @@  m   @@   @@     @@@    m#",
	"#########     #######      #######     #########",
	"#                     @@@@                     #",
	"#   M     ###         @@@@         ###    m    #",
	"#                     @@@@   M                 #",
	"#@@@@@@@@     ##@@@##  ##  ##@@@##     @@@@@@@@#",
	"#@@@@@@@@  m  ##@@@##  ##  ##@@@##     @@@@@@@@#",
	"#    @@@@     ##@@@##  ##  ##@@@##     @@@@    #",
	"#    @@@@     @@   @@  ##  @@   @@     @@@@    #",
	"#    @@@@     @@ M @@      @@ M @@     @@@@    #",
	"#    @@@@     @@   @@      @@   @@     @@@@    #",
	"################################################",
	};



	static inline const char Over[OVER_Y][OVER_X] = {
	"       #######       #      #       #  #########          #######   #       #  #########  ########       ",
	"      #             # #     ##     ##  #                 #       #  #       #  #          #       #      ",
	"      #            #   #    # #   # #  #                 #       #  #       #  #          #       #      ",
	"      #           #     #   #  # #  #  #                 #       #  #       #  #          #       #      ",
	"      #   #####  #########  #   #   #  #########         #       #  #       #  #########  ########       ",
	"      #      ##  #       #  #       #  #                 #       #   #     #   #          #       #      ",
	"      #      ##  #       #  #       #  #                 #       #    #   #    #          #       #      ",
	"      #     # #  #       #  #       #  #                 #       #     # #     #          #       #      ",
	"       #####  #  #       #  #       #  #########          #######       #      #########  #       #      ",
	"                                                                                                         ",
	"                                                                                                         "
	};
};