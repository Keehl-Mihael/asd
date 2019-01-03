//
// Created by arcangelo on 02/01/19.
//

#ifndef TEST_BUILD_RICHIESTE_H
#define TEST_BUILD_RICHIESTE_H

#include <queue>

class richieste{

public:
    typedef typename TreeLink<int>::node node;


    int maxLevelSum(TreeLink<int> &t)
    {
        node root = t.root();
        // Base case
        if (root == NULL)
            return 0;

        // Initialize result
        int result = t.readNode(root);

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
                sum = sum + t.readNode(temp);
                node appoggio;
                // Enqueue left and right children of
                // dequeued node
                appoggio = t.firstChild(temp);
                if ( appoggio != NULL){
                    q.push(appoggio);
                    while (t.lastSibling(appoggio) == false){
                        appoggio = t.nextSibling(appoggio);
                        if ( appoggio != NULL)
                            q.push(appoggio);
                    }
                }

            }

            // Update the maximum node count value
            result = max(sum, result);
        }

        return result;
    }
};

#endif //TEST_BUILD_RICHIESTE_H
