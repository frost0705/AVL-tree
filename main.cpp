#include <iostream>
#include <vector>
using namespace std;

class AVL_tree
{
private:
	int** m;
	int layer;
	int position;
	int sizeOfLayer;

	void addLayerToEnd()
	{
		layer++;
		sizeOfLayer = involutionOfTwo(layer); 
		m = (int**) realloc(m,(layer+1)*sizeof(int*));
		int* temp = (int*)malloc(sizeOfLayer*sizeof(int*));
		m[layer] = temp;
		position = 0;
	}

	void deleteLastLayer()
	{
		delete[] m[layer];
		layer--;
		sizeOfLayer = involutionOfTwo(layer); 
		position = 0;
	}

	int involutionOfTwo(int degree)
	{
		int answer = 1;
		for (int i = 0; i<degree; i++)
		{
			answer*=2;
		}
		return answer;
	}

	int intLength(int variable)
	{
		int answer=0;
		while (variable)
		{
			variable /= 10;
			answer++;
		}
		return answer;
	}
	
	void printSpace(int number)
	{
		for(int i = 0; i<number; i++)
		{
			cout<<" ";
		}
	}

	int printYN(int layerNumber, int lineNumber, int iter)
	{
		if(condition(lineNumber, layerNumber)&&condition2(lineNumber, layerNumber, iter))
		{
			return 1;
		}
		else
		{
			return 0;
		}
		

	}

	int condition(int line, int layerNumber)
	{
		if(line >= involutionOfTwo(layer))
		{
			line-=involutionOfTwo(layer);
		}

		int x = layer-layerNumber;

		if(x == (line&x))
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	}

	int condition2(int line, int layerNumber, int iter)
	{
		if((layerNumber==layer)&&(iter > position))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	

public:
	
	AVL_tree(int variable)
	{
		layer = 0;
		sizeOfLayer = 1;
		position = 0;
		int* temp = new int[1];
		m = (int**) malloc(sizeof(int*));
		m[0] = temp;
	}

	~AVL_tree()
	{
		for(int i = 1; i<=layer; i++)
		{
			delete[] m[i];
		}
		delete[]m;
	}

	void addElementToEnd(int variable)
	{
		m[layer][position] = variable;
		position++;
		if (position == sizeOfLayer)
		{
			addLayerToEnd();
		}
	}

	void deleteLastElement()
	{
		position--;
		if(position == -1)
		{
			deleteLastLayer();
		}
	}
	
	void print()
	{
		/*int* lengthS = new int[layer+1];
		int temp;
		
		for (int i = 0; i <=layer; i++)
		{
			lengthS[i] = m[i][0];
			temp = involutionOfTwo(i);
			for(int j = 1; j<=temp; j++)
			{
				if(lengthS[i]<intLength(m[i][j]))
				{
					lengthS[i] = intLength(m[i][j]);
				}
			}
		}

		int* iter = new int[layer+1];
		
		for(int i = 0; i<=layer; i++)
		{
			iter[i] = 0;
		}

		int numberOfLayers = involutionOfTwo(layer+1);

		for(int i = 0; i <numberOfLayers;i++)
		{
			for(int j = 0; j<=layer;j++)
			{
				if(printYN(j,i,iter[layer]))
				{
					cout<<m[j][iter[j]];
					printSpace(lengthS[j]-intLength(m[j][iter[j]]));
					iter[j]++;
				}
				else
				{
					printSpace(lengthS[j]);
				}

			}

			cout<<"\n";
		}*/

		for(int i = 0; i <= layer;i++)
		{
			for(int j = 0; j<involutionOfTwo(i);j++)
			{
				if(((j<position)&&(i==layer))||(i<layer))
				{
					cout<<m[i][j]<<' ';
				}
			}
			cout<<'\n';
		}


	}

};


void main()
{
	AVL_tree tree(0);

	for(int i = 1; i <8; i++)
	{
		tree.addElementToEnd(i);
	}
	tree.print();
	int a = 7654;
	a++;
}


