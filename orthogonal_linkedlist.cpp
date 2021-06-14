#include <bits/stdc++.h>
using namespace std;

struct MatrixNode
{
    int _val;
    MatrixNode* _u; // pointer to node above
    MatrixNode* _d; // pointer to node below
    MatrixNode* _l; // pointer to node towrads left
    MatrixNode* _r; // pointer to node towards righ

    // Constructor for MatrixNode
    MatrixNode( int val = 0, 
                MatrixNode* u = nullptr,
                MatrixNode* d = nullptr,
                MatrixNode* l = nullptr,
                MatrixNode* r = nullptr )
        {
            _val = val;
            _u = u;
            _d = d;
            _l = l;
            _r = r;
        }
};

MatrixNode* BuildOrthogonalList(int matrix[][3], int r, int c)
{
    // an unordered_map to store the {value, pointers} pair
    // for easy access while building the list
    unordered_map<int, MatrixNode*> mp;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            // create a newNode for each entry in the matrix
            MatrixNode* newNode = new MatrixNode(matrix[i][j]);
            // store the pointer of the new node
            mp[matrix[i][j]] = newNode; 

            // set the up and down pointing pointers correctly
            if(i != 0)
            {
                newNode->_u = mp[matrix[i - 1][j]];
                mp[matrix[i - 1][j]]->_d = newNode;
            }

            // similarly set the left and right pointing pointers
            if(j != 0)
            {
                newNode->_l = mp[matrix[i][j - 1]];
                mp[matrix[i][j - 1]]->_r = newNode;
            }
        }
    }

    // return the start of the list
    return mp[matrix[0][0]];
}

void PrintOrthogonalList(MatrixNode* head)
{
    MatrixNode* curRow; // will point to the begin of each row
    MatrixNode* cur; // will traverse each row and print the element
    for(curRow = head; curRow != nullptr; curRow = curRow->_d)
    {
        for(cur = curRow; cur != nullptr; cur = cur->_r)
        {
            cout << cur->_val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    MatrixNode* list = BuildOrthogonalList(matrix, 3, 3);
    PrintOrthogonalList(list);

    return 0;
}