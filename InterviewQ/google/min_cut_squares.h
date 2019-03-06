#ifndef MIN_CUT_SQUARES_H_INCLUDED
#define MIN_CUT_SQUARES_H_INCLUDED

//THANKS TO NILPATEL (I DID NOT SOLVE THIS)

// https://www.geeksforgeeks.org/paper-cut-minimum-number-squares-set-2/
// Given a paper of size A x B. Task is to cut the paper into squares of any size.
// Find the minimum number of squares that can be cut from the paper.

const int MAX = 100;
int dp[MAX][MAX];

// Returns min number of squares needed
int minimumSquare(int m, int n)
{
    // Initializing max values to vertical_min
    // and horizontal_min
    int vertical_min = INT_MAX;
    int horizontal_min = INT_MAX;

    // If the given rectangle is already a square
    if (m == n)
        return 1;

    // If the answer for the given rectangle is
    // previously calculated return that answer
    if (dp[m][n])
            return dp[m][n];

    /* The rectangle is cut horizontally and
       vertically into two parts and the cut
       with minimum value is found for every
       recursive call.
    */

    for (int i = 1;i<= m/2;i++)
    {
        // Calculating the minimum answer for the
        // rectangles with width equal to n and length
        // less than m for finding the cut point for
        // the minimum answer
        horizontal_min = min(minimumSquare(i, n) +
                minimumSquare(m-i, n), horizontal_min);
    }

    for (int j = 1;j<= n/2;j++)
    {
        // Calculating the minimum answer for the
        // rectangles with width less than n and
        // length equal to m for finding the cut
        // point for the minimum answer
        vertical_min = min(minimumSquare(m, j) +
                minimumSquare(m, n-j), vertical_min);
    }

    // Minimum of the vertical cut or horizontal
    // cut to form a square is the answer
    dp[m][n] = min(vertical_min, horizontal_min);

    return dp[m][n];
}



#endif // MIN_CUT_SQUARES_H_INCLUDED
