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
            temp_node = Queue.front();
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
    int maxLevelSum(alberiPuntatori<int> &t)
    {
        node root = t.root();
        // Base case
        if (root == NULL)
            return 0;

        // Initialize result
        int result = t.read(root);

        // Do Level order traversal keeping track of number
        // of nodes at every level.
        queue<node> q;
        q.push(root);
        while (!q.empty())
        {
            // Get the size of queue when the level order
            // traversal for one level finishes
            int count = q.size() ;

            // Iterate for all the nodes in the queue currently
            int sum = 0;
            while (count--)
            {
                // Dequeue an node from queue
                node temp = q.front();
                q.pop();

                // Add this node's value to current sum.
                sum = sum + t.read(temp);

                // Enqueue left and right children of
                // dequeued node
                if (t.sx(temp) != NULL)
                    q.push(t.sx(temp));
                if (t.dx(temp) != NULL)
                    q.push(t.dx(temp));
            }

            // Update the maximum node count value
            result = max(sum, result);
        }

        return result;
    }
};

#endif //TEST_BUILD_RICHIESTE_H
