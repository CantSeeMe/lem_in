LEM_IN

The goal of lem in is to look for a path to let ant reach from start to end nodes with the less amount of round possible

MAKEFILE

The makefile has been provided with "all" "clean" "fclean" "re" rule.

USAGE

./lem-in < map

The first line of the map shall always be a positive integer determining the number of ants.                                                      
The the second part of the line shall be room's bane with their position, each room is seperated with a newline. It must have at least one ##start and ##end to determine where the ants should start and where they should be going.                                                      
The last part shall tell how the room are linked. each link is sperated with a newline, one line shall only contains 2 rooms linked.

BNF:

\<number of ants\> ::= DIGIT                                                                                                                                        
\<room name\>      ::= CHAR                                                                                                                                       
\<rooms\>          ::= \<room name\> DIGIT DIGIT                                                                                                            
\<node link\>      ::= \<room-name\>"-"\<room-name\>                                                                                                            

NOTE

The program will only show the shortest path and will not look for any other path.
