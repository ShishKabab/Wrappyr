/*
Dummy library with some basic functions used to unit test API generation.
*/
#include <stdlib.h>
#include <stdio.h>

/*
 * Test functions
 */
int gFirstCalled = 0;
int first(){
    gFirstCalled = 1;
    return 0;
}

int gSecondCalled = 0;
int second(int v){
    gSecondCalled = 1;
    return v;
}

/*
 * Test classes
 */
struct Point {
    int x;
    int y;
};

int gPointCreated = 0;
struct Point* Point_Create(int x, int y){
    gPointCreated = 1;

    struct Point* p = malloc(sizeof(struct Point));
    p->x = x;
    p->y = y;
    return p;
}

int gZeroPointCreated = 0;
struct Point* Point_CreateZero(){
    gZeroPointCreated = 1;

    struct Point* p = malloc(sizeof(struct Point));
    p->x = 0;
    p->y = 0;
    return p;
}

int gPointDestroyed = 0;
void Point_Destroy(struct Point* p){
    gPointDestroyed = 1;
    free(p);
}

int gPointDistanceSquared = 0;
int Point_DistanceSquared(struct Point* p){
    gPointDistanceSquared = 1;
    return (p->x * p->x) + (p->y * p->y);
}

int gPointGetX = 0;
int Point_GetX(struct Point* p){
    gPointGetX = 1;
    return p->x;
}

int gPointSetX = 0;
void Point_SetX(struct Point* p, int v){
    gPointSetX = 1;
    p->x = v;
}


/*
 * Test inheritance
 */
struct Animal;
struct AnimalVTable {
    void (*speak)(struct Animal*);
};
struct Animal {
    struct AnimalVTable* vtable;
};

int gAnimalSpeakDefault = 0;
void Animal_SpeakDefault(struct Animal* animal){
    gAnimalSpeakDefault = 1;
}

int gAnimalCreated = 0;
struct Animal* Animal_Create(){
    gAnimalCreated = 1;

    struct AnimalVTable* vtable = malloc(sizeof(struct AnimalVTable));
    vtable->speak = Animal_SpeakDefault;

    struct Animal* animal = malloc(sizeof(struct Animal));
    animal->vtable = vtable;

    return animal;
}

int gAnimalDestroyed = 0;
void Animal_Destroy(struct Animal* animal){
    gAnimalDestroyed = 1;
    free(animal->vtable);
    free(animal);
}

int gAnimalSpeakDispatched = 0;
void Animal_Speak(struct Animal* animal){
    gAnimalSpeakDispatched = 1;
    animal->vtable->speak(animal);
}

struct UserVTable {
    void (*speak)(void*);
};
struct UserAnimal {
    struct AnimalVTable* vtable;
    struct UserVTable* userVTable;
    void* obj;
};

int gUserAnimalSpeakDispatched = 0;
void UserAnimal_Speak(struct UserAnimal* animal){
    gUserAnimalSpeakDispatched = 1;
    animal->userVTable->speak(animal->obj);
}

int gUserAnimalCreated = 0;
struct UserAnimal* UserAnimal_Create(void* obj, struct UserVTable* userVTable){
    gUserAnimalCreated = 1;

    struct AnimalVTable* vtable = malloc(sizeof(struct AnimalVTable));
    vtable->speak = UserAnimal_Speak;

    struct UserAnimal* animal = malloc(sizeof(struct UserAnimal));
    animal->vtable = vtable;
    animal->userVTable = userVTable;
    animal->obj = obj;

    return animal;
}

int gUserAnimalDestroyed = 0;
void UserAnimal_Destroy(struct UserAnimal* animal){
    gUserAnimalDestroyed = 1;
    Animal_Destroy(animal);
}

//void MySpeak(int* obj){
//    printf("Speak: %p, %d\n", obj, *obj);
//}
//
//int main(int argc, char** argv){
//    int obj = 7542;
//    printf("Main: %p, %d\n", &obj, obj);
//    printf("Size of user vtable: %d\n", sizeof(struct UserVTable));
//
//    struct Animal* animal = Animal_Create();
//    Animal_Speak(animal);
//
//    struct UserVTable* vtable = malloc(sizeof(struct UserVTable));
//    vtable->speak = MySpeak;
//
//    struct UserAnimal* userAnimal = UserAnimal_Create(&obj, vtable);
//    Animal_Speak(userAnimal);
//}