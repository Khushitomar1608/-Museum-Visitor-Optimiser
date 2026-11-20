
#ifndef MUSEUM_H
#define MUSEUM_H

#define V 6
#define E 6
#define INF 999999

struct Exhibit {
    int id;
    char name[40];
    int time;
    int value;
};

extern int graph[V][V];
extern const char rooms[V][20];
extern struct Exhibit exhibits[E];

void displayRooms(void);
void displayConnections(void);
void displayExhibits(void);

void dijkstra(int source, int destination);
void floydWarshall(void);
void primsAlgorithm(void);

void mergeSort(struct Exhibit arr[], int left, int right);
void sortExhibits(void);
int binarySearch(struct Exhibit arr[], int n, int key);
void searchExhibit(void);

void selectExhibits(void);

void generateMuseumGraph(void);
void generateDijkstraGraph(int source, int destination);
void generatePrimGraph(void);

#endif
