# CPP PERSONAL PROJECT 5
## Created by Brynjólfur Helgi Trevor Björnsson and Vésteinn Bjarnason



### Emails: brynjolfur19@ru.is & vesteinn19@ru.is
# About the Program:
### This program is largely based on PA4 which was focused on classes and polymorphism
### That assignment allowed the user to create species, roles etc and create custom characters based on that. In this assignment we decided to take that a step further. In this program we decided to base our game flow around Dungeons and Dragon 5th Edition.
## 1. Create a new Character (NPC/PC)
### Works alot like the creating of individual in the last assignment the user selects if he wants to create a PC or NPC and then gets a number of selected roles from which he can create his character from - He can then either create a basic character of that role or a custom one - where he can use what ever stats he likes.
## 2. Create a new encounter
### This is a new functionality, here the can create a new encounter which are used in the encounter enviornment. The first choice is selecting if he wants a to select a enemy from the roster or create a new enemy to add to the roster. When the user is done adding/creating enemies to the roster he can then save the current encounter and set the difficulty.
## 3. Create a new weapon / attack
### Here the user can create either a new weapon or a new attack.
### After creating a new weapon he can than add a weapon to that attack.
## 4. Add attack to weapon / being
### Here the user can add attacks to either weapon or a being. A Being can be PC/NPC or a creature.
## 5. Add weapon to character/enemy
### Pretty self explanatory
## 6. Edit character 
### Here the user can edit whatever stat he wishes on a character.
## 7. Edit / remove encounter
### Here the user can go through the steps of editing or removing an encounter.
## 8. Select or remove playable character to/from game session
### Here the user adds a PC to the game session , he takes that character to the encounter with him to face off against mighty(or not so mighty) enemies!
## 9. Start encounter
### Here we start the encounter!
# Encounters
### Encounters have a pretty basic and easily understandable flow the program starts off by rolling initive for the player characters and the enemies and sorts them in a correct order. On each turn the user selects what attack to perform and on what target and then informs the user whether or not the attack was a hit or a miss. After each characters turn the program checks if enemies are dead or if all characters are dead and lets the user know wheater or not he has won or lost. 
# To Run
### Run the following command in shell in same directory as all the files.
```
g++ -std=c++11 *.cpp -o role && ./role
```