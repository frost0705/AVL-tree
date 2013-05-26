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

	int printYN(int layerNumber,int numberOfLayers, int lineNumber)
	{
		int answer = 1;
		if((lineNumber&(involutionOfTwo(numberOfLayers-layerNumber-1)-1))!=(involutionOfTwo(numberOfLayers-layerNumber-1)-1))
		{
			answer = 0;
		}
		return answer;
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
		int printedLayer = layer;
		if (position = 0)
		{
			printedLayer--;
		}
		int tempLayerSize;
		int max;
		int temp;
		//Определение длинны строки для каждого уровня
		int *lengthS = new int[printedLayer];//длины строк
		//То самое определение
		for(int i = 0; i<=printedLayer;i++)
		{
			max = intLength( m[i][0]);
			tempLayerSize = involutionOfTwo(i);

			for(int j = 0; j<tempLayerSize;j++)
			{
				temp = intLength( m[i][j]);
				if(temp>max)
				{
					max = temp;
				}	
			}
			lengthS[i] = max;
		}
		//Количество строк? необходимых для вывода
		int numberLines = involutionOfTwo(printedLayer+1)-1;
		//итерратор для каждого слоя
		int *j = new int[printedLayer+1];
		for(int i = 0;i<printedLayer+1;i++)
		{
			j[i] = 0;
		}
		//сейчас попробуем вывести
		for(int i = 0; i < numberLines; i++)
		{
			cout<<i<<' ';
			//t - иттератор слоев
			//i - построчный итератор
			//j - итерратор внутри слоя
			for(int t = 0; t <= printedLayer; t++)
			{
				if (printYN(t,printedLayer+1,i))
				{
					cout<<m[t][j[t]]<<' ';
					j[t]+=1;
					printSpace(lengthS[t]-intLength(m[t][j[t]]));
				}
				else
				{
					printSpace(lengthS[t]);
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


