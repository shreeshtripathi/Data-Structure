#include <iostream>
#include <climits>

using namespace std;

class IOperator
{
public:
    virtual int operation(int lhs, int rhs) = 0;
    virtual int identity() = 0;
};

class SumOperator : public IOperator
{
public:
    int operation(int lhs, int rhs)
    {
        return lhs + rhs;
    }
    int identity()
    {
        return 0;
    }
};

class MinOperator : public IOperator
{
public:
    int operation(int lhs, int rhs)
    {
        return min(lhs, rhs);
    }
    int identity()
    {
        return INT_MAX;
    }
};
class MaxOperator : public IOperator
{
public:
    int operation(int lhs, int rhs)
    {
        return max(lhs, rhs);
    }
    int identity()
    {
        return INT_MIN;
    }
};
class ProductOperator : public IOperator
{
public:
    int operation(int lhs, int rhs)
    {
        return lhs * rhs;
    }
    int identity()
    {
        return 1;
    }
};

class mstree
{
private:
    int getLog(int n)
    {
        int log = 0;
        while ((1 << log) < n)
        {
            log++;
        }
        return log;
    }

public:
    int *ba = NULL;
    int *sa = NULL;
    int s = 0;   // sizeof segment tree
    int bas = 0; // size of base array;
    IOperator *opr = NULL;

    mstree(int *arr, int s, IOperator *operation)
    {
        this->ba = arr;
        this->bas = s;
        this->opr = operation;
        int h = getLog(s) + 1;
        this->s = (1 << h) - 1;
        sa = new int[s];
        build(0, s - 1, 0);
    }

    void build(int ss, int se, int si)
    {
        if (ss == se)
        {
            sa[si] = ba[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(ss, mid, 2 * si + 1);
        build(mid + 1, se, 2 * si + 2);
        sa[si] = opr->operation(sa[2 * si + 1], sa[2 * si + 2]);
    }

    void update(int idx, int nval, int ss, int se, int si)
    {
        if (se == ss)
        {
            ba[idx] = nval;
            sa[si] = nval;
            return;
        }
        int mid = (ss + se) / 2;
        if (idx <= mid)
        {
            update(idx, nval, ss, mid, 2 * si + 1);
        }
        else
        {
            update(idx, nval, mid + 1, se, 2 * si + 2);
        }
        sa[si] = opr->operation(sa[2 * si + 1], sa[2 * si + 2]);
    }

    int query(int qs, int qe, int ss, int se, int si)
    {
        if (ss >= qs && se <= qe)
        {
            //completely inside query
            return sa[si];
        }
        else if (qs > se || qe < ss)
        {
            // outside the segment
            return opr->identity();
        }
        else
        {
            int mid = (ss + se) / 2;
            int lc = query(qs, qe, ss, mid, 2 * si + 1);
            int rc = query(qs, qe, mid + 1, se, 2 * si + 2);
            return opr->operation(lc, rc);
        }
    }

    void display()
    {
        for (int i = 0; i < s; i++)
        {
            cout << sa[i] << " ";
        }
        cout << endl;
    }
};

int main(int argv, char** argc)
{
    IOperator* opr = NULL;
    cout << "Please Select th eoperation " << endl;
    cout << "1. Get Sum \n2. Get Product" <<endl;
    cout << "3. Get Min \n4. Get Max" << endl;
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
        case 1:
            opr = new SumOperator();
            break;
        
        case 2:
            opr = new ProductOperator();
            break;
        
        case 3:
            opr = new MinOperator();
            break;
        
        case 4:
            opr = new MaxOperator();
            break;
        default:
            break;
    }

    int* ba = new int[7]{2, 5, 3, 1, 7, 4, 9};
    mstree ms(ba, 7, opr);
    cout << ms.query(2, 5, 0, 6, 0) << endl;
    cout << ms.query(1, 4, 0, 6, 0) << endl;
    cout << ms.query(0, 6, 0, 6, 0) << endl;

    ms.update(3, 11, 0, 6, 0);

    cout << ms.query(2, 5, 0, 6, 0) << endl;
    cout << ms.query(1, 4, 0, 6, 0) << endl;
    cout << ms.query(0, 6, 0, 6, 0) << endl;
}