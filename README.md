# An Example Of a Binary Search Tree Implementation

     -First of all this program can be thought as a mini console game
     
     -When it starts it reads benim.txt and rakip.txt files 
      In these two files containing random numbers, the numbers are separated by a space
      
     -Both files must contain an equal number of numbers
      
     -One of the binary search trees will consist of numbers read from the file named benim and
      the other will consist of numbers read from the file named rakip
     
     -Each node has a variable named soy_sayisi, and counts the number of all nodes under the node that can be reached from the node
     
     -The one with the lowest total soy_sayisi wins the round
     
     -If the soy_sayilari are equals in the round, the root nodes are given to each other and deleted from them
     
     -If the soy_sayilari are not equals in the round, the winning side adds the node with the highest value from the other side's tree
      to its own tree, and deletes it from the other side's tree. After this operation, the winning side gives the root node of
      its own tree to the other side's tree and deletes it from its own tree
      
     -Equal values can be found in the tree. In this case one of the nodes will be placed on the left
     
     -Pressing a key starts the next round
     
     -Winner of 5 rounds or the highest score at the end of 20 rounds wins the game
      
     -Postorder traversal is used in this BST
     
     
