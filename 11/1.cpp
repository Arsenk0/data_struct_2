#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;


bool isFullGraph(int a[][4])
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] > 0 && i != j)
                count++;
        }
        if (count != 3)
        {
            return false;
        }
        count = 0;
    }
    return true;
}

void printAdjacencyList(int a[][4])
{
    for (int i = 0; i < 4; i++)
    {
        cout << endl << i + 1 << ": ";
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] > 0)
                cout << j + 1 << ", ";
        }
    }
}

float calculateAverageDistance(int a[][4])
{
    float sum = 0;
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] > 0)
            {
                sum += a[i][j];
                count++;
            }
        }
    }
    if (count > 0)
        return sum / count;
    else
        return 0.0f;
}

bool isIsolatedVertex(int a[][4], int vertex)
{
    int degree = 0;
    for (int j = 0; j < 4; j++)
    {
        if (a[vertex][j] > 0)
            degree++;
        if (degree > 1)
            return false;
    }
    return true;
}

void showIsolatedVertices(int a[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (isIsolatedVertex(a, i) && a[i][j] > 0)
                cout << i + 1 << " - distance to nearest: " << a[i][j] << endl;
        }
    }
}

void showNumberOfIsolatedVertices(int a[][4])
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (isIsolatedVertex(a, i))
            count++;
    }
    cout << "\nNumber of isolated vertices: " << count << ":";
    for (int i = 0; i < 4; i++)
    {
        if (isIsolatedVertex(a, i))
            cout << " " << i + 1;
    }
}

int findLongestDistance(int a[][4], int vertex)
{
    int longest = 0;
    for (int j = 0; j < 4; j++)
    {
        if (a[vertex][j] > longest)
            longest = a[vertex][j];
    }
    return longest;
}

void showLongestPath(int a[][4])
{
    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        if (isIsolatedVertex(a, i))
        {
            cout << "(" << i + 1 << ")";
            counter++;
            for (int l = i; l < 4; l++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (a[l][j] == findLongestDistance(a, l))
                    {
                        cout << " --- " << findLongestDistance(a, l) << " --- (" << j + 1 << ")";
                        counter++;
                        l = j - 1;
                        break;
                    }
                }
                if (counter == 3)
                    break;
            }
        }
    }
}

bool canVisitAllVerticesOnce(int a[][4])
{
    int oddDegreeCount = 0, degree;
    for (int i = 0; i < 4; i++)
    {
        degree = 0;
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] != 0)
                degree++;
        }
        if (degree % 2 != 0)
            oddDegreeCount++;
    }
    return (oddDegreeCount == 0 || oddDegreeCount == 2);
}

int main()
{
    int graph[4][4] = {
            {0, 0, 4, 0},
            {0, 0, 6, 3},
            {4, 6, 0, 7},
            {0, 3, 7, 0}
    };

    if (isFullGraph(graph))
        cout << "Graph is complete.";
    else
        cout << "Graph is not complete.";

    cout << "\nAdjacency list:";
    printAdjacencyList(graph);
    cout << "\nAverage distance: " << calculateAverageDistance(graph);
    cout << "\nIsolated vertices: ";
    showIsolatedVertices(graph);
    showNumberOfIsolatedVertices(graph);
    cout << "\nThe longest path: ";
    showLongestPath(graph);
    if (canVisitAllVerticesOnce(graph))
        cout << "\nIt's possible to visit all vertices once!";
    else
        cout << "\nIt's not possible to visit all vertices once.";

    return 0;
}
