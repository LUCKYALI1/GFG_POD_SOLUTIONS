/*
We are given a linked list where:
- `next`  points to the head of the next linked list (horizontally)
- `bottom` points to the nodes of a sorted linked list (vertically)

Goal:
Flatten everything into ONE sorted list using only `bottom` pointers.

------------------------------------------------------------
APPROACH (Store -> Sort -> Rebuild)
------------------------------------------------------------

1️⃣ Traverse the structure:
   - Move across using `next`
   - For every node, move down using `bottom`
   - Store ALL values in a vector

2️⃣ Sort the collected values.

3️⃣ Build a new linked list:
   - Create a dummy node
   - Attach nodes in sorted order using `bottom`
   - Ignore all `next` pointers (final list uses only bottom links)

------------------------------------------------------------
WHY THIS WORKS
------------------------------------------------------------
Every column is already sorted individually,
so by collecting everything and sorting once, we guarantee
a globally sorted list.

------------------------------------------------------------
TIME & SPACE COMPLEXITY
------------------------------------------------------------

Let N = total number of nodes across the entire structure.

Traversal        -> O(N)
Sorting          -> O(N log N)
Building list    -> O(N)

Total Time       -> O(N log N)
Extra Space      -> O(N)  (because we store all values in a vector)

------------------------------------------------------------
Note:
There is a more optimal in-place approach using merge technique
(O(1) extra space), but this solution is simple, clean, and reliable.
*/

class Solution {
public:
    Node *flatten(Node *root) {

        // Step 1: collect all values from both `next` and `bottom`
        Node* temp = root;
        vector<int> vals;

        while (temp != NULL) {

            Node* bottomTemp = temp;

            while (bottomTemp != NULL) {
                vals.push_back(bottomTemp->data);
                bottomTemp = bottomTemp->bottom;
            }

            temp = temp->next;
        }

        // Step 2: sort the collected values
        sort(vals.begin(), vals.end());

        // Step 3: rebuild the flattened sorted list using bottom pointers
        Node* dummy = new Node(0);
        Node* curr = dummy;

        for (int x : vals) {
            curr->bottom = new Node(x);
            curr = curr->bottom;
        }

        // The flattened list starts at dummy->bottom
        return dummy->bottom;
    }
};
