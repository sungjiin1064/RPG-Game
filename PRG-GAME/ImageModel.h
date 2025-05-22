#pragma once



struct ImageModel
{
    const char* backGround = R"(
                                               .
                                             .' `.
                                           .' .'. `.
                                         .' .'   `. `. 
                                       .' .'       `. `.
                                     .' .'           `. `.
                                   .' .'|  _________  |`. `.
                                    `'| | |         | | |`'
                                      | | |   _ _   | | |
                                      | | |  ( " )  | | |
                                      | | |   \ /   | | |
                                      | | |    "    | | |
                                      | | |         | | |
                                      | | |         | | |
                                      | | |         | | |
                                      | | |         | | |
                                      | | |         | | |
                                      | | |         | | |
                                      | | |         | | |
                                      | | |         | | |
                                      | | |         | | |
                                      | | |         | | |
============================================================
)";

    string SwordIdle = R"(
   :
   +
 0/
/|
/ \
)";
    const char* SwordMove = R"(
    :
    +
__0/
  |
 / \
)";
    const char* SwordBattle = R"(
   :
   +
 0__ +--
/|_
/  |
)";

    const char* SlimeIdle = R"(




  ( ''  )
)";
    const char* SlimeMove = R"(



  ( ''  )
         ``
)";
    const char* SlimeBattle = R"(




( ''    )
)";
};

