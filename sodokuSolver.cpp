#include <iostream>
using namespace std;

class cnode
{
public:


	int x[9][9] = { { 0, 1, 6, 5, 7, 8, 4, 9, 0 },
					{ 0, 2, 9, 1, 3, 4, 7, 6, 8 },
					{ 0, 8, 7, 6, 2, 9, 5, 3, 1 },
					{ 0, 6, 3, 4, 1, 5, 9, 8, 7 },
					{ 9, 7, 4, 8, 6, 3, 1, 2, 5 },
					{ 8, 5, 1, 7, 9, 2, 6, 4, 3 },
					{ 1, 3, 8, 9, 4, 0, 2, 5, 6 },
					{ 6, 9, 2, 3, 5, 1, 0, 7, 4 },
					{ 7, 4, 5, 2, 8, 6, 3, 1, 9 }
	};

	int v = 1;
	cnode* pnext;
};

class clist
{
public:
	cnode* phead;
	cnode* ptail;
	clist()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clist()
	{
		cnode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(cnode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void display()
	{
		cnode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			for (int r = 0; r < 9; r++)
			{
				for (int c = 0; c < 9; c++)
				{
					cout << ptrav->x[r][c] << " ";
				}
				cout << endl;
			}
			ptrav = ptrav->pnext;
		}
	}
};
class cstack
{
public:
	cnode* phead;
	cstack()
	{
		phead = NULL;
	}
	~cstack()
	{
		cnode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void display()
	{
		cnode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			for (int r = 0; r < 9; r++)
			{
				for (int c = 0; c < 9; c++)
				{
					cout << ptrav->x[r][c] << " ";
				}
				cout << endl;
			}
			ptrav = ptrav->pnext;
		}
	}
	void push(cnode* pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	}
	cnode* pop()
	{
		cnode* ptrav;
		ptrav = phead;
		phead = ptrav->pnext;
		ptrav->pnext = NULL;
		return ptrav;
	}
};
 
void copy(cnode* pcurr, cnode* pnn)
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			pnn->x[r][c] = pcurr->x[r][c];
		}
	}
	pnn->v = pcurr->v;
}



int IS_OK(cnode* pnn)
{

	int ct = 0;
	int flag = 1;

	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			if (pnn->x[r][c] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}


int isgood2(cnode* pnn, int row, int col)
{
	int v;
	int ct; int rsabta = row; int csabta = col;
	for (int r = row; r < row + 3; r++)
	{
		for (int c = col; c < col + 3; c++)
		{
			if (pnn->x[r][c] != 0)
			{
				v = pnn->x[r][c];
				ct = 0;
				for (int Rcheck = rsabta; Rcheck < rsabta + 3; Rcheck++)
				{
					for (int Ccheck = csabta; Ccheck < csabta + 3; Ccheck++)
					{
						if (pnn->x[Rcheck][Ccheck] == v)
						{
							ct++;
							if (ct == 2)
							{
								return 0;
							}
						}
					}
				}
			}


		}
	}
	return 1;
}


int isgood(cnode* pnn, int rbig, int cbig)
{
	int ct;
	int v;

	if (pnn->x[rbig][cbig] != 0)
	{
		v = pnn->x[rbig][cbig];
		ct = 0;

		for (int col = 0; col < 9; col++)
		{
			if (pnn->x[rbig][col] == v)
			{
				ct++;
			}
			if (ct == 2)
			{
				return 0;
			}
		}

		ct = 0;

		for (int row = 0; row < 9; row++)
		{
			if (pnn->x[row][cbig] == v)
			{
				ct++;
			}
			if (ct == 2)
			{
				return 0;
			}
		}

	}

	int z;

	z = isgood2(pnn, 0, 0);
	if (z == 0)
	{
		return 0;
	}
	z = isgood2(pnn, 0, 3);
	if (z == 0)
	{
		return 0;
	}

	z = isgood2(pnn, 0, 6);

	if (z == 0)
	{
		return 0;
	}

	z = isgood2(pnn, 3, 0);

	if (z == 0)
	{
		return 0;
	}

	z = isgood2(pnn, 3, 3);

	if (z == 0)
	{
		return 0;
	}

	z = isgood2(pnn, 3, 6);

	if (z == 0)
	{
		return 0;
	}

	z = isgood2(pnn, 6, 0);

	if (z == 0)
	{
		return 0;
	}

	z = isgood2(pnn, 6, 3);

	if (z == 0)
	{
		return 0;
	}

	z = isgood2(pnn, 6, 6);

	if (z == 0)
	{
		return 0;
	}

	return 1;

}


void expandchildren(cnode* pcurr, cstack& s, clist& Lvisited)
{
	cnode* pnn;

	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			for (int i = 1; i < 10; i++)
			{
				pnn = new cnode;
				pnn->pnext = NULL;
				copy(pcurr, pnn);

				if (pnn->x[r][c] == 0)
				{
					pnn->x[r][c] = i;
					if (isgood(pnn, r, c))
					{
						s.push(pnn);
					}
				}
			}

		}

	}

}

void dispall(cnode* pnn)
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			cout << pnn->x[r][c] << " | ";
		}
		cout << endl;
	}
}

void main()
{
	int ct = 0;
	int ct2 = 0;

	clist Lvisited;
	cstack s;
	cnode* pnn;
	cnode* pcurr;
	pnn = new cnode;
	pnn->pnext = NULL;
	s.push(pnn);
	while (s.phead)
	{
		pcurr = s.pop();

		if (IS_OK(pcurr))
		{
			dispall(pcurr);
			break;
		}
		//Lvisited.attach(pcurr);
		expandchildren(pcurr, s, Lvisited);
	}

}