#include <bits/stdc++.h>

using namespace std;

bool* column;
bool* rdiagonal;
bool* ldiagonal;
uint n;
uint count;

bool check_point(uint x, uint y) {
    if (column[x] || rdiagonal[x + y] || ldiagonal[(n - x) + y]) {
        return false;
    }
    return true;
}

void set_queen(uint x, uint y) {
    column[x] = rdiagonal[x + y] = ldiagonal[(n - x) + y] = true;
}

void remove_queen(uint x, uint y) {
    column[x] = rdiagonal[x + y] = ldiagonal[(n - x) + y] = false;
}

void search (uint y) {
    if (y == n) {
        ::count++;
    }

    for (uint x = 0; x < n; x++) {
        if (check_point(x, y)) {
            set_queen(x, y);
            search(y + 1);
            remove_queen(x, y);
        }
    }
}

int main() {
    cin >> n;

    column = new bool[n];
    rdiagonal = new bool[2*n];
    ldiagonal = new bool[2*n];

    search(0);
    cout << ::count << "\n";
    /*
    We know that queens cannot be in the same row, column or diagonal.
    => If there are n rows and columns, and n queens, then all solutions
    require there be only 1 queen in every row, every column
    and every possible diagonal.

    Observation: For a queen placed at (p, q) next queen cannot be placed
    at (p + 1, q + 1 / q / q - 1)

    We can either maintain a record of the positions of all the queens,
        and for each point calculate if it comes in any column or diagonal
        where a queen is already placed, or
        maintain an array where we blot out all the areas of
        a column or diagonal.
    So what we really want to do is blot out the column and diagonals.
    No need to mark all the cells of the diagonal,
        we want to mark the diagonal ITSELF.
    We can express a diagonal by:
       0 1 2 3 
      ________
    0| 0 1 2 3
    1| 1 2 3 4
    2| 2 3 4 5
    3| 3 4 5 6

    i.e. there are 2n diagonals
    and we can determine diagonal of a point by formula (x + y)

    The other diagonal is similar, except the x-axis is inverted,
    so to calculate the diagonal using point co-ordinates, we have to
    re-invert x. So formula is: ((n - x) + y)

    Hybrid:
        Three arrays: column[n], diagonal1[2n-1], diagonal2[2n-1]
        when queen placed at (p, q), mark 
            column[p],
            diagonal1[p+q],
            diagonal2[(n-p)+q] (since x-axis gets inverted)
    */
}