# Enemy.h && Enemy.cpp

This is the enemy class, an interface to describe an enemy

ENEMY CLASS PROPERTIES:

| Type | Name | Description |
|:-----------:|:-----------:|------------:| 
| String | name | name of the enemy |
| int | health | how much health remains |    
| int | maxHealth |how much health he starts at |
| int | speed | turn order calculations (higher is better) |     
| int | damage | how much damage the monster does |
| int | level | level of the monster |

ENEMY CLASS FUNCTIONS:

most functions are to recall the private properties
format of each function is in camel case:
```css
get(propertyName)();
```

i.e. to get the max health of a monster do:
```css
getMaxHealth();
```
same goes for setting a value as well:
```css
setMaxHealth();
```

to inflict damage upon the monster do
```css
takeDamage(damage);
```
int damage = well you know damage...



## Game philosophy

### What is an enemy?

Enemies are obstacles the player has to overcome in the game.

ENEMY STATS:

-- LEVEL (Identifier for a baseline of the other stats)  
-DAMAGE (How much ~damage the enemy can deal in one turn)  
-HEALTH (How many HP (Hit Points) the monster has)  
-SPEED (Defines turn order)  

These stats are raw numbers and primarily if the player has bigger numbers they will win.

These stats are stored as private properties of the class. There are other stats hidden for both computational and functionality purposes.
