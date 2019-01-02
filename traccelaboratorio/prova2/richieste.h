//
// Created by arcangelo on 02/01/19.
//

#ifndef TEST_BUILD_RICHIESTE_H
#define TEST_BUILD_RICHIESTE_H

#include <queue>

class richieste{

public:
    typedef typename alberiPuntatori<int>::Nodo node;

    void breadthFirst(alberiPuntatori<int> &t)
    {
        /* Temporary queue. */
        queue<node> Queue;
        node temp_node;

        /*
         * Gotta put something in the queue initially,
         * so that we enter the body of the loop.
         */

        Queue.push(t.root());

        while (!Queue.empty()) {
            temp_node = Queue.back();
            Queue.pop();

            cout << t.read(temp_node) << endl;



            /*
             * If there is a left child, add it
             * for later processing.
             */
            if (t.sx(temp_node) != NULL)
                Queue.push(t.sx(temp_node));

            /*
             * If there is a right child, add it
             * for later processing.
             */
            if (t.dx(temp_node) != NULL)
                Queue.push(t.dx(temp_node));
        }

    }
void printLevels(alberiPuntatori<int> &t)
{
        int V = 10;
    // array to store level of each node
    int level[V];
    bool marked[V];
    node nx = t.root();
    int x = t.read(nx);

    // create a queue
    queue<int> que;

    // enqueue element x
    que.push(x);

    // initialize level of source node to 0
    level[x] = 0;

    // marked it as visited
    marked[x] = true;

    // do until queue is empty
    while (!que.empty()) {

        // get the first element of queue
        x = que.front();

        // dequeue element
        que.pop();

        // traverse neighbors of node x
        for (int i = 0; i < 10; i++) {
            // b is neighbor of node x
            int b = t.;

            // if b is not marked already
            if (!marked[b]) {

                // enqueue b in queue
                que.push(b);

                // level of b is level of x + 1
                level[b] = level[x] + 1;

                // mark b
                marked[b] = true;
            }
        }
    }

    // display all nodes and their levels
    cout << "Nodes"
         << "    "
         << "Level" << endl;
    for (int i = 0; i < V; i++)
        cout << " " << i << "   -->   " << level[i] << endl;
} */
};

#endif //TEST_BUILD_RICHIESTE_H
