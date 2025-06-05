#pragma once

//ascii art archive

struct ImageModel
{
    bool isIdle;
    const char* CurrentImage;
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

    const char* SwordIdle = R"(
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

    const char* KingSlimeIdle = R"(

    _ _
  _     _
 _ ..     _
_ _ _ _ _ _ _
)";
    const char* KingSlimeMove = R"(

     _ _
   _     _
  _ ..     _
_ _ _ _ _ _ _
)";
    const char* KingSlimeBattle = R"(
   _ _
 _     _
_ ..     _
 _ _       _
    -- --_ _ _
)";
      
};



