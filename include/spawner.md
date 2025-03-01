## spawner.h & spawner.cpp

## EnemyAttributes
For the actual idea of what the spawner object does it is important to know what the enemyAttributes struct is.
```c++
struct EnemyAttributes (minAttack, maxAttack, minSpeed, maxSpeed, minhealth...)
```
of course not the actual formating, but the enemyAttributes lay as a ground work for mapping out an enemy stats

## Spawner object

|            Type            |     Name      |                                               Description |
|:--------------------------:|:-------------:|----------------------------------------------------------:| 
| map<int, Enemy Attributes> | difficultyMap | holds the data for enemy stats based on difficulty/level. |

The spawner object has 3 default "difficulty settings"

```c++
getAttributes(int difficulty) const
```
This grabs the enemy stats based on difficulty
for example:  
if the difficulty is 1:  
``
EnemyAttributes(4,15,5,10,20,30);  ``  
The enemy will have a damage stat around 4-15, speed from 5-10, and health from 20-30

```c++
static Enemy createTrueRandom();
```
creates a monster with random stats and random name.

```c++
unsigned long long addDifficultyMap(const std::map<int, EnemyAttributes>& newMap);
```
This is quite a handful so let's go one by one  
`unsigned long long` means that this will return a positive potentionally long number. Like really long number, subsequentially it will reserve space for the long number.  
`addDifficultyMap` is the name of this method  
`const std::map<int, EnemyAttriburtes>` means that the function is expecting a value of 
```c++
{4, EnemyAttributes(50, 75, 12, 18, 100, 150)}
```

4 standing as the difficulty level 4, and well we alrady talked what [enemyAttributes](#enemyAttributes) is  
`&` means it's being passed on by reference and `newMap` is the name of the variable  

#### this function basically adds another difficulty to the spawner object

```c++
[[nodiscard]] std::unique_ptr<Enemy> spawnByDifficulty(int difficulty, const std::string& name, int focus = 0) const; // focus makes one value stand out more... 0 means nothing happens
```
another handful method but again let's go one by one:
`[[nodiscard]]` is a flag alerting that we should use the return value in some fashion.  
Speaking of which the return value:  
`std::unique_ptr<Enemy>` is a smart pointer allowing us to not truly worry about freeing the memory up. It's a pointer pointing to an Enemy class  
`spawnByDifficulty` is the name  
`difficulty` is the integer for what the enemy's stat will be based off
`std::String& name` is the string value passed by reference to the name of the monster  
`focus` allows the monster to focus one stat over other stats

| Focus Number |                   stat change effect                   |                                                     description |
|:------------:|:------------------------------------------------------:|----------------------------------------------------------------:|
|      3       |                     speed+(10-30)%                     |                                    speed is increased by 10-30% |
|      2       |                    damage+(10-30)%                     |                                   damage is increased by 10-30% |
|      1       |                    health+(10-30)%                     |                                   health is increased by 10-30% |
|      0       |                          null                          |                                              No stat is changed |
|      -1      | health+(10-50)%<br/>damage-(10-20)%<br/>speed-(10-20)% | health is increased by 10-30% other stats are lowered by 10-20% |
|      -2      | damage+(10-50)%<br/>health-(10-20)%<br/>speed-(10-20)% | damage is increased by 10-30% other stats are lowered by 10-20% |
|      -3      | speed+(10-50)%<br/>health-(10-20)%<br/>damage-(10-20)% |  speed is increased by 10-30% other stats are lowered by 10-20% |
